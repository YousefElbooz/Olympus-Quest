#include "Staff.h"

Staff::Staff() : id(0), name("") {}
Staff::Staff(int id, const QString& name) : id(id), name(name) {}

int Staff::getId() const {
    return id;
}

QString Staff::getName() const {
    return name;
}

Staff::~Staff() {}
