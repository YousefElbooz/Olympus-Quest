#include "Coach.h"
#include <iostream>

// Default constructor
Coach::Coach() : Staff() {}

// Parameterized constructor
Coach::Coach(int id, const QString& name) : Staff(id, name) {}

// Get role method (Override from Staff class)
QString Coach::getRole() const {
    return "Coach";  // Returns the role of the staff as "Coach"
}

// Assign a class to the coach
void Coach::assignClass(const Gym_classes& gymClass) {
    assignedClasses.push_back(gymClass);  // Add the class to the list of assigned classes
}

// Assign a member to this coach's list
void Coach::assignMember(Member* member) {
    assignedMembers.push_back(member);  // Add the member to the list of assigned members
}

// View all classes assigned to the coach
void Coach::viewAssignedClasses() const {
    std::cout << "Classes for Coach " << name.toStdString() << ":\n";
    for (const auto& cls : assignedClasses) {
        std::cout << "- " << cls.getClassName().toStdString() << "\n";
    }
}

// View all members assigned to the coach
void Coach::viewAssignedMembers() const {
    std::cout << "Members assigned to Coach " << name.toStdString() << ":\n";
    for (const auto& member : assignedMembers) {
        std::cout << "- " << member->getName().toStdString() << "\n";
    }
}


// View all classes assigned to the coach
QVector<Gym_classes> Coach::getAssignedClasses() const {
    return this->assignedClasses;
}

// View all members assigned to the coach
QVector<Member*> Coach::getAssignedMembers() const {
    return this->assignedMembers;
}


// Destructor
Coach::~Coach() {}
