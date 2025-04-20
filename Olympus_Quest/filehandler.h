#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QString>
#include <QMap>
#include <QList>
#include <QQueue>
#include <QTableWidget>
#include "Member.h"
#include "Manager.h"
#include "Receptionist.h"
#include "Coach.h"
#include "Gym_classes.h"
#include <QMessageBox>

class FileHandler {
private:
    static QMap<QString, Member*> usersMap;         // Member ID -> Member*
    static QMap<int, Staff*> staffMap;              // Staff ID -> Staff*
    static QMap<int, Gym_classes> classMap;
    static QString filePath;
    static QString classFilePath;
public:
    // Members & Staff
    static void loadMembers(const QString& path);
    static void loadStaff(const QString& path);
    static bool saveMembers(const QString& path);
    static bool saveStaff(const QString& path);

    // Generic user management
    static bool userExists(const QString& email);
    static bool appendStaff(const QStringList& staffFields) ;
    static QString validateLoginById(const QString& id, const QString& email, const QString& password);
    static void freeUsers();
    static QMap<QString, Member*>& getUsers();
    static QMap<int, Staff*>& getStaff();

    // Gym classes
    static void loadAllClasses(const QString& path);
    static bool saveAllClasses();

    // UI logic
    static QString getNextMemberId();
    static QString getNextStaffId();
    static bool appendMember(const QStringList& memberFields);
    static void populateClassesTable(QList<QTableWidget*> tableWidgets);
    static void populateMemberAttendedClasses(QTableWidget* tableWidget, const QString& memberId);
    static bool requestClassesForMember(const QString& memberId, const QStringList& filters);
    static void filterClasses(QTableWidget* tableWidget, const QStringList& filters);
    static void filterMemberClasses(QTableWidget* tableWidget, QString& memberId, QStringList& filters);
    static void logAttendedClass(const QString& filePath, const QStringList& classInfo);
};

#endif // FILEHANDLER_H
