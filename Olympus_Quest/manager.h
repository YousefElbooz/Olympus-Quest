#ifndef MANAGER_H
#define MANAGER_H

#include "Receptionist.h"
#include "Gym_classes.h"

class Manager : public Receptionist {
private:
    QString department;

public:
    Manager();
    Manager(int id, const QString& name, const QString& department);

    QString getDepartment() const;
    QString getRole() const override;

    void addClass(const Gym_classes& gymClass);
    void removeClass(int classId);
    void assignCoach(int classId, int coachId);
    void viewReports() const;

    ~Manager();
};

#endif
