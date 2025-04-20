#ifndef COACH_H
#define COACH_H

#include "Staff.h"
#include "Gym_classes.h"
#include <vector>

class Coach : public Staff {
private:
    std::vector<Gym_classes> assignedClasses;

public:
    Coach();
    Coach(int id, const QString& name);

    QString getRole() const override;

    void assignClass(const Gym_classes& gymClass);
    void viewAssignedClasses() const;
    void trackAttendance(int classId, const std::vector<int>& presentMemberIds);

    ~Coach();
};

#endif
