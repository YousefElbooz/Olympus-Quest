#ifndef STAFF_H
#define STAFF_H

#include <QString>

class Staff {
protected:
    int id;
    QString name;

public:
    Staff();
    Staff(int id, const QString& name);

    virtual int getId() const;
    virtual QString getName() const;

    virtual QString getRole() const = 0;  // Pure virtual (abstract base)

    virtual ~Staff();
};

#endif
