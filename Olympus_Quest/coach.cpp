#include "Coach.h"
#include <iostream>

Coach::Coach() : Staff() {}
Coach::Coach(int id, const QString& name) : Staff(id, name) {}

QString Coach::getRole() const {
    return "Coach";
}

void Coach::assignClass(const Gym_classes& gymClass) {
    assignedClasses.push_back(gymClass);
}

void Coach::viewAssignedClasses() const {
    std::cout << "Classes for Coach " << name.toStdString() << ":\n";
    for (const auto& cls : assignedClasses) {
        std::cout << "- " << cls.getClassName().toStdString() << "\n";
    }
}

void Coach::trackAttendance(int classId, const std::vector<int>& presentMemberIds) {
    // logic to mark attendance (could integrate with class object or attendance log)
}

Coach::~Coach() {}
