#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Staff.h"
#include "Member.h"

class Receptionist : public Staff {
public:
    Receptionist();
    Receptionist(int id, const QString& name);

    QString getRole() const override;

    void addMember(const Member& member);
    void updateMember(int memberId, const Member& updatedMember);
    void notifyRenewal(const Member& member);
    void listMembers() const;

    ~Receptionist();
};

#endif
