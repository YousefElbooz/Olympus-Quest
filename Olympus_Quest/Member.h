#ifndef MEMBER_H
#define MEMBER_H

#include <QString>
#include <QVector>
#include "Gym_classes.h"

class Member {
private:
    QString id;
    QString name;
    QString age;
    QString email;
    QString address;
    QString password;
    QString paymentDate;
    QString phone;
    QString duration;
    QString gender;
    QString userType;
    QVector<Gym_classes> attendedClasses;
    // QVector<Gym_classes> attendedClasses;

public:
    Member() = default;

    Member(const QString& id, const QString& name, const QString& age, const QString& email,
           const QString& address, const QString& password, const QString& paymentDate,
           const QString& phone, const QString& duration, const QString& gender, const QString& userType);

    // Accessors
    QString getId() const;
    QString getName() const;
    QString getAge() const;
    QString getEmail() const;
    QString getAddress() const;
    QString getPassword() const;
    QString getPaymentDate() const;
    QString getPhone() const;
    QString getDuration() const;
    QString getGender() const;
    QString getUserType() const;
    QVector<Gym_classes>& getAttendedClassesRef(); // Add this to allow editing in request function

    // Attended Classes
    QVector<Gym_classes> getAttendedClasses() const;
    void addAttendedClass(const Gym_classes& gymClass);
    void clearAttendedClasses();

    // File I/O helpers
    QString toLine() const;
    static Member* fromLine(const QString& line);
};

#endif // MEMBER_H
