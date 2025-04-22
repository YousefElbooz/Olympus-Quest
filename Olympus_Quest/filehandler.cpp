// FileHandler.cpp
#include "FileHandler.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QMap<QString, Member*> FileHandler::usersMap;
QMap<int, Staff*> FileHandler::staffMap;
QMap<int, Gym_classes> FileHandler::classMap;
QString FileHandler::filePath;
QString FileHandler::classFilePath;

void FileHandler::loadMembers(const QString& path) {
    filePath = path;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open users.txt";
        return;
    }

    QTextStream in(&file);
    Member* currentMember = nullptr;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line == "---") {
            currentMember = nullptr;
            continue;
        }

        QStringList userParts = line.split(":");
        if (userParts.size() == 11) {
            // User line
            QString id = userParts[0];
            currentMember = new Member(userParts[0], userParts[1], userParts[2], userParts[3],
                                       userParts[4], userParts[5], userParts[6], userParts[7],
                                       userParts[8], userParts[9], userParts[10]);
            usersMap[id] = currentMember;
        } else if (currentMember && line.contains("|")) {
            // Class line: ID|ClassName|Time|Trainer|Status|Capacity/Enrolled
            QStringList classParts = line.split("|");
            if (classParts.size() == 6) {
                QStringList capParts = classParts[5].split("/");
                if (capParts.size() == 2) {
                    int cap = capParts[0].toInt();
                    int enrolled = capParts[1].toInt();

                    Gym_classes gymClass(
                        classParts[0].toInt(),                 // ID
                        classParts[1],                         // Class name
                        classParts[3],                         // Trainer
                        classParts[4],                         // Status
                        cap,
                        enrolled,
                        QTime::fromString(classParts[2], "hh:mm AP") // Time
                        );

                    currentMember->addAttendedClass(gymClass);
                }
            }
        }
    }

    file.close();
}

QMap<int, Staff*>& FileHandler::getStaff() {
    return staffMap;
}

void FileHandler::loadStaff(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open staff file";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line == "---") continue;

        QStringList parts = line.split(":");
        if (parts.size() == 11) {
            int id = parts[0].toInt();
            QString name = parts[1];
            QString role = parts[10].toLower();
            Staff* staff = nullptr;

            if (role == "manager") {
                staff = new Manager(id, name, "");
            } else if (role == "receptionist") {
                staff = new Receptionist(id, name);
            } else if (role == "coach") {
                staff = new Coach(id, name);
            }

            if (staff) staffMap[id] = staff;
        }
    }
    file.close();
}
void FileHandler::populateMemberAttendedClasses(QTableWidget* tableWidget, const QString& memberId) {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(6);
    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << "ID" << "Class Name" << "Time" << "Trainer" << "Status" << "Capacity/Enrolled");

    if (!usersMap.contains(memberId)) {
        QMessageBox::warning(nullptr, "Invalid ID", "No member found with ID: " + memberId);
        return;
    }

    const Member* member = usersMap[memberId];
    const QVector<Gym_classes>& classes = member->getAttendedClasses();

    for (const auto& gc : classes) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(gc.getId())));
        tableWidget->setItem(row, 1, new QTableWidgetItem(gc.getClassName()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(gc.getTime().toString("hh:mm AP")));
        tableWidget->setItem(row, 3, new QTableWidgetItem(gc.getTrainer()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(gc.getStatus()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(QString("%1/%2").arg(gc.getCapacity()).arg(gc.getEnrolled())));
    }
}
bool FileHandler::userExists(const QString& email) {
    for (const auto& member : usersMap) {
        if (member->getEmail() == email)
            return true;
    }
    return false;
}
// Get next member ID
QString FileHandler::getNextMemberId() {
    int maxId = 0;
    for (const QString& id : usersMap.keys()) {
        bool ok;
        int num = id.toInt(&ok);
        if (ok && num > maxId) maxId = num;
    }
    return QString::number(maxId + 1);
}

// Get next staff ID
QString FileHandler::getNextStaffId() {
    int maxId = 0;
    for (const int& id : staffMap.keys()) {
        if (id > maxId) maxId = id;
    }
    return QString::number(maxId + 1);
}

// Append Member
bool FileHandler::appendMember(const QStringList& memberFields) {
    if (memberFields.size() != 10) return false;
    QString id = getNextMemberId();
    Member* newMember = new Member(id,
                                   memberFields[0], memberFields[1], memberFields[2],
                                   memberFields[3], memberFields[4], memberFields[5],
                                   memberFields[6], memberFields[7], memberFields[8],
                                   memberFields[9]);
    usersMap[id] = newMember;
    return true;
}

// Append Staff and save immediately
bool FileHandler::appendStaff(const QStringList& staffFields) {
    if (staffFields.size() != 10) return false;
    int id = getNextStaffId().toInt();
    QString name = staffFields[0];
    QString role = staffFields[9].toLower();

    Staff* staff = nullptr;
    if (role == "manager") {
        staff = new Manager(id, name, "");
    } else if (role == "receptionist") {
        staff = new Receptionist(id, name);
    } else if (role == "coach") {
        staff = new Coach(id, name);
    }

    if (staff) {
        staffMap[id] = staff;
        return true;
    }
    return false;
}

QString FileHandler::validateLoginById(const QString& id,const QString& email, const QString& password) {
    if (!usersMap.contains(id)) return "";

    Member* m = usersMap[id];
    if (m->getPassword() == password && m->getEmail()==email) {
        QString userType = m->getUserType();
        return userType;
    }

    return "";
}

bool FileHandler::saveMembers(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to write members file";
        return false;
    }

    QTextStream out(&file);
    for (auto member : usersMap) {
        out << member->getId() << ":" << member->getName() << ":" << member->getAge() << ":"
            << member->getEmail() << ":" << member->getAddress() << ":" << member->getPassword() << ":"
            << member->getPaymentDate() << ":" << member->getPhone() << ":" << member->getDuration() << ":"
            << member->getGender() << ":" << member->getUserType() << "\n";

        for (const auto& cls : member->getAttendedClasses()) {
            out << QString("%1|%2|%3|%4|%5|%6/%7")
            .arg(cls.getId()).arg(cls.getClassName())
                    .arg(cls.getTime().toString("hh:mm AP"))
                    .arg(cls.getTrainer()).arg(cls.getStatus())
                    .arg(cls.getCapacity()).arg(cls.getEnrolled()) << "\n";
        }
        out << "---\n";
    }

    file.close();
    return true;
}

bool FileHandler::saveStaff(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to write staff file";
        return false;
    }

    QTextStream out(&file);
    for (auto staff : staffMap) {
        out << QString("%1:%2:19:placeholder@mail.com:cairo:123456:4/18/2025:0000000000:0 months:unknown:%3\n---\n")
        .arg(staff->getId())
            .arg(staff->getName())
            .arg(staff->getRole().toLower());
    }

    file.close();
    return true;
}



QMap<QString, Member*>& FileHandler::getUsers() {
    return usersMap;
}

void FileHandler::freeUsers() {
    for (auto m : usersMap)
        delete m;
    usersMap.clear();
    for (auto s : staffMap)
        delete s;
    staffMap.clear();
}


bool FileHandler::requestClassesForMember(const QString& memberId, const QStringList& filters) {
    if (!usersMap.contains(memberId)) return false;

    auto match = [](const QString& filter, const QString& value) {
        QString f = filter.trimmed().toLower();
        QString v = value.trimmed().toLower();
        return f.isEmpty() || f == "any" || f == v;
    };

    Member* member = usersMap[memberId];
    QVector<Gym_classes>& attended = member->getAttendedClassesRef();

    for (auto& cls : classMap) {
        QStringList classData = {
            QString::number(cls.getId()),
            cls.getClassName(),
            cls.getTime().toString("hh:mm AP"),
            cls.getTrainer(),
            cls.getStatus(),
            QString("%1/%2").arg(cls.getCapacity()).arg(cls.getEnrolled())
        };

        bool matched = true;
        for (int i = 0; i < filters.size(); ++i) {
            if (!match(filters[i], classData[i + 1])) {
                matched = false;
                break;
            }
        }

        bool alreadyEnrolled = std::any_of(attended.begin(), attended.end(), [&](const Gym_classes& g) {
            return g.getId() == cls.getId();
        });

        if (matched && cls.getCapacity() > cls.getEnrolled() && !alreadyEnrolled) {
            cls.setEnrolled(int(cls.getEnrolled()) + 1);
            Gym_classes cloned = cls;
            member->addAttendedClass(cloned);

            return true;
        }
    }

    return false;
}

bool FileHandler::saveAllClasses() {
    QFile file(classFilePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Failed to write classes file.";
        return false;
    }

    QTextStream out(&file);
    for (const auto& cls : classMap) {
        out << QString("%1|%2|%3|%4|%5|%6/%7")
        .arg(cls.getId())
                .arg(cls.getClassName())
                .arg(cls.getTime().toString("hh:mm AP"))
                .arg(cls.getTrainer())
                .arg(cls.getStatus())
                .arg(cls.getCapacity())
                .arg(cls.getEnrolled()) << "\n";
    }

    file.close();
    return true;
}


void FileHandler::loadAllClasses(const QString& path) {
    classFilePath = path;
    classMap.clear();

    QFile file(classFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open classes file: " + file.errorString();
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split("|");
        if (parts.size() == 6) {
            int id = parts[0].toInt();
            QString className = parts[1];
            QTime time = QTime::fromString(parts[2], "hh:mm AP");
            QString trainer = parts[3];
            QString status = parts[4];

            QStringList capEnrolled = parts[5].split("/");
            if (capEnrolled.size() != 2) continue;

            int capacity = capEnrolled[0].toInt();
            int enrolled = capEnrolled[1].toInt();

            Gym_classes gc(id, className, trainer, status, capacity, enrolled, time);
            classMap[id] = gc;
        }
    }

    file.close();
}



void FileHandler::populateClassesTable(QList<QTableWidget*> tables) {
    for (QTableWidget* tableWidget : tables) {
        tableWidget->clearContents();
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(6);

        tableWidget->setHorizontalHeaderLabels(QStringList()
                                               << "ID" << "Class Name" << "Time" << "Trainer" << "Status" << "Capacity");

        for (const auto& gc : classMap) {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);

            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(gc.getId())));
            tableWidget->setItem(row, 1, new QTableWidgetItem(gc.getClassName()));
            tableWidget->setItem(row, 2, new QTableWidgetItem(gc.getTime().toString("hh:mm AP")));
            tableWidget->setItem(row, 3, new QTableWidgetItem(gc.getTrainer()));
            tableWidget->setItem(row, 4, new QTableWidgetItem(gc.getStatus()));
            tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(gc.getCapacity()-gc.getEnrolled())));
        }
    }
}


void FileHandler::filterMemberClasses(QTableWidget* tableWidget, QString& memberId, QStringList& filters) {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);
    tableWidget->setColumnCount(6);
    tableWidget->setHorizontalHeaderLabels(QStringList()
                                           << "ID" << "Class Name" << "Time" << "Trainer" << "Status" << "Capacity/Enrolled");

    if (!usersMap.contains(memberId)) {
        QMessageBox::warning(nullptr, "Error", "Member ID not found: " + memberId);
        return;
    }

    const Member* member = usersMap[memberId];
    const QVector<Gym_classes>& classes = member->getAttendedClasses();

    auto match = [](const QString& filter, const QString& value) {
        QString f = filter.trimmed().toLower();
        QString v = value.trimmed().toLower();
        return f.isEmpty() || f == "any" || f == v;
    };

    for (const auto& cls : classes) {
        QStringList classData = {
            QString::number(cls.getId()),
            cls.getClassName(),
            cls.getTime().toString("hh:mm AP"),
            cls.getTrainer(),
            cls.getStatus(),
            QString("%1/%2").arg(cls.getCapacity()).arg(cls.getEnrolled())
        };

        bool matched = true;
        for (int i = 0; i < filters.size(); ++i) {
            if (!match(filters[i], classData[i + 1])) {
                matched = false;
                break;
            }
        }

        if (matched) {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            for (int col = 0; col < 6; ++col) {
                tableWidget->setItem(row, col, new QTableWidgetItem(classData[col]));
            }
        }
    }
}

void FileHandler::filterClasses(QTableWidget* tableWidget, const QStringList& filters) {
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    auto match = [](const QString& filter, const QString& value) {
        return filter.isEmpty() || filter.compare("any", Qt::CaseInsensitive) == 0 || filter == value;
    };

    for (const auto& cls : classMap) {
        QStringList classData = {
            QString::number(cls.getId()),         // 0 - ID
            cls.getClassName(),                   // 1 - Class Name
            cls.getTime().toString("hh:mm AP"),   // 2 - Time
            cls.getTrainer(),                     // 3 - Trainer
            cls.getStatus(),                      // 4 - Status
            QString::number(cls.getCapacity())    // 5 - Capacity
        };

        bool matched = true;
        for (int i = 0; i < filters.size(); ++i) {
            if (!match(filters[i], classData[i + 1])) { // skip ID column
                matched = false;
                break;
            }
        }

        if (matched) {
            int row = tableWidget->rowCount();
            tableWidget->insertRow(row);
            for (int col = 0; col < 6; ++col) {
                tableWidget->setItem(row, col, new QTableWidgetItem(classData[col]));
            }
        }
    }
}
