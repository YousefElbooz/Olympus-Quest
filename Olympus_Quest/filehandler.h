#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QMap>
#include <QTableWidget>
#include "Member.h"
#include <QMessageBox>
class FileHandler {
private:
    static QMap<QString, Member*> usersMap;
    static QString filePath;

public:
    static void loadUsers(const QString& path);
    static bool userExists(const QString& email);
    static bool appendUser(const QStringList& userFieldsWithoutId);
    static bool validateLoginById(const QString& id, const QString &email, const QString& password, QString& userType);
    static QString getNextId();
    static bool saveUsers(); // save once at the end
    static void freeUsers(); // cleanup

    static void loadClassesFromFile(QTableWidget* tableWidget, const QString& filePath);
    static void filterClasses(QTableWidget* tableWidget, const QString& filePath, const QStringList& filters);
    static void logAttendedClass(const QString& filePath, const QStringList& classInfo);
};

#endif // FILEHANDLER_H
