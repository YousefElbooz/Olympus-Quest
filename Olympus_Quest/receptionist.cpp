#include "Receptionist.h"
#include <iostream>

Receptionist::Receptionist() : Staff() {}
Receptionist::Receptionist(int id, const QString& name) : Staff(id, name) {}

QString Receptionist::getRole() const {
    return "Receptionist";
}

void Receptionist::addMember(const Member& member) {
    // logic
}

void Receptionist::updateMember(int memberId, const Member& updatedMember) {
    // logic
}

void Receptionist::notifyRenewal(const Member& member) {
    // logic
}

void Receptionist::listMembers() const {
    // logic
}

Receptionist::~Receptionist() {}
