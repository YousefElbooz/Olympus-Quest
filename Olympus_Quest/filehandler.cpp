#include "FileHandler.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QMap<QString, Member*> FileHandler::usersMap;
QString FileHandler::filePath;

void FileHandler::loadUsers(const QString& path) {
    filePath = path;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open users.txt";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(":");
        if (parts.size() >= 11) {
            QString id = parts[0];
            Member* member = new Member(id,
                                        parts[1], parts[2], parts[3], parts[4],
                                        parts[5], parts[6], parts[7], parts[8],
                                        parts[9], parts[10]);
            usersMap[id] = member;
        }
    }

    file.close();
}

bool FileHandler::userExists(const QString& email) {
    for (const auto& member : usersMap) {
        if (member->getEmail() == email)

            return true;
    }
    return false;
}

bool FileHandler::appendUser(const QStringList& userFieldsWithoutId) {
    QString id = getNextId();
    Member* newMember = new Member(id,
                                   userFieldsWithoutId[0], userFieldsWithoutId[1], userFieldsWithoutId[2],
                                   userFieldsWithoutId[3], userFieldsWithoutId[4], userFieldsWithoutId[5],
                                   userFieldsWithoutId[6], userFieldsWithoutId[7], userFieldsWithoutId[8],
                                   userFieldsWithoutId[9]);
    usersMap[id] = newMember;
    return true;
}

QString FileHandler::getNextId() {
    int maxId = 0;
    for (const QString& id : usersMap.keys()) {
        bool ok;
        int num = id.toInt(&ok);
        if (ok && num > maxId) maxId = num;
    }
    return QString::number(maxId + 1);
}

bool FileHandler::validateLoginById(const QString& id,const QString& email, const QString& password, QString& userType) {
    if (!usersMap.contains(id)) return false;

    Member* m = usersMap[id];
    if (m->getPassword() == password && m->getEmail()==email) {
        userType = m->getUserType();
        return true;
    }

    return false;
}

bool FileHandler::saveUsers() {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to write users.txt";
        return false;
    }

    QTextStream out(&file);
    for (auto member : usersMap) {
        out << member->toLine() << "\n";
    }

    file.close();
    return true;
}

void FileHandler::freeUsers() {
    for (auto m : usersMap)
        delete m;
    usersMap.clear();
}

void FileHandler::loadClassesFromFile(QTableWidget* tableWidget, const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Could not open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList fields = line.split("|", Qt::KeepEmptyParts);
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);
        for (int col = 0; col < fields.size() && col < tableWidget->columnCount(); ++col) {
            tableWidget->setItem(row, col, new QTableWidgetItem(fields.at(col).trimmed()));
        }
    }
    file.close();
}

void FileHandler::filterClasses(QTableWidget* tableWidget, const QString& filePath, const QStringList& filters) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Error", "Could not open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    auto match = [](const QString& filter, const QString& value) {
        return filter.isEmpty() || filter.compare("any", Qt::CaseInsensitive) == 0 || filter == value;
    };

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        QStringList fields = line.split("|", Qt::KeepEmptyParts);
        if (fields.size() < filters.size()) continue;

        bool matched = true;
        for (int i = 0; i < filters.size(); ++i) {
            if (!match(filters[i], fields[i])) {
                matched = false;
                break;
            }
        }

        if (matched) {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            for (int col = 0; col < filters.size(); ++col) {
                tableWidget->setItem(row, col, new QTableWidgetItem(fields[col].trimmed()));
            }
        }
    }
    file.close();
}

void FileHandler::logAttendedClass(const QString& filePath, const QStringList& classInfo) {
    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << classInfo.join("|") << "\n";
        file.close();
    }
}
