#ifndef COACH_H
#define COACH_H

#include "Staff.h"
#include "Gym_classes.h"
#include <QVector>
#include "Member.h"
class Coach : public Staff {
private:
     // List of members attending the classes taught by the coach

public:
    QVector<Gym_classes> assignedClasses;    // List of classes assigned to the coach
    QVector<Member*> assignedMembers;
    // Constructors
    Coach();  // Default constructor
    Coach(int id, const QString& name);  // Parameterized constructor

    // Getter for the role of the staff (Override the role function from Staff)
    QString getRole() const override;

    // Methods for assigning classes and members
    void assignClass(const Gym_classes& gymClass);     // Assign a class to this coach
    void assignMember(Member* member);                  // Assign a member to this coach's list

    // Methods to view assigned classes and members
    void viewAssignedClasses() const;                   // View all classes assigned to the coach
    void viewAssignedMembers() const;                   // View all members assigned to the coach

    QVector<Gym_classes> getAssignedClasses() const;
    QVector<Member*> getAssignedMembers() const;
    // Destructor
    ~Coach();
};

#endif // COACH_H
