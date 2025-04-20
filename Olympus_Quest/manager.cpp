#include "Manager.h"
#include <iostream>

Manager::Manager() : Receptionist(), department("") {}
Manager::Manager(int id, const QString& name, const QString& department)
    : Receptionist(id, name), department(department) {}

QString Manager::getDepartment() const {
    return department;
}

QString Manager::getRole() const {
    return "Manager";
}

void Manager::addClass(const Gym_classes& gymClass) {
    // logic
}

void Manager::removeClass(int classId) {
    // logic
}

void Manager::assignCoach(int classId, int coachId) {
    // logic
}

void Manager::viewReports() const {
    // logic
}

Manager::~Manager() {}
