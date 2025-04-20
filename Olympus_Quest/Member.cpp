#include "Member.h"

// Constructor
Member::Member(const QString& id, const QString& name, const QString& age, const QString& email,
               const QString& address, const QString& password, const QString& paymentDate,
               const QString& phone, const QString& duration, const QString& gender, const QString& userType)
    : id(id), name(name), age(age), email(email), address(address), password(password),
    paymentDate(paymentDate), phone(phone), duration(duration), gender(gender), userType(userType) {}

// Getters
QString Member::getId() const { return id; }
QString Member::getName() const { return name; }
QString Member::getAge() const { return age; }
QString Member::getEmail() const { return email; }
QString Member::getAddress() const { return address; }
QString Member::getPassword() const { return password; }
QString Member::getPaymentDate() const { return paymentDate; }
QString Member::getPhone() const { return phone; }
QString Member::getDuration() const { return duration; }
QString Member::getGender() const { return gender; }
QString Member::getUserType() const { return userType; }

// Attended Classes
QVector<Gym_classes> Member::getAttendedClasses() const {
    return attendedClasses;
}

void Member::addAttendedClass(const Gym_classes& gymClass) {
    attendedClasses.append(gymClass);
}

QVector<Gym_classes>& Member::getAttendedClassesRef() {
    return attendedClasses;
}


void Member::clearAttendedClasses() {
    attendedClasses.clear();
}

// Serialization
QString Member::toLine() const {
    return id + ":" + name + ":" + age + ":" + email + ":" + address + ":" + password + ":" +
           paymentDate + ":" + phone + ":" + duration + ":" + gender + ":" + userType;
}

// Deserialization
Member* Member::fromLine(const QString& line) {
    QStringList parts = line.split(":");
    if (parts.size() < 11) return nullptr;

    return new Member(parts[0], parts[1], parts[2], parts[3], parts[4],
                      parts[5], parts[6], parts[7], parts[8], parts[9], parts[10]);
}

