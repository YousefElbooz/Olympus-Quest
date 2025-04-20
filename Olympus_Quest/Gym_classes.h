#ifndef GYM_CLASSES_H
#define GYM_CLASSES_H

#include <QString>
#include <QTime>

class Gym_classes {
private:
    int id;
    QString className;
    QString trainer;
    QString status;     // e.g., "Scheduled", "Ongoing", "Cancelled"
    int capacity;
    int enrolled;       // NEW: Number of enrolled members
    QTime time;

public:
    // Constructors
    Gym_classes();
    Gym_classes(int id, const QString& className, const QString& trainer,
                const QString& status, int capacity, int enrolled, const QTime& time);


    // Setters
    void setId(int newId);
    void setClassName(const QString& name);
    void setTrainer(const QString& trainerName);
    void setStatus(const QString& newStatus);
    void setCapacity(int newCapacity);
    void setEnrolled(int newEnrolled);
    void setTime(const QTime& newTime);

    // Getters
    int getId() const;
    QString getClassName() const;
    QString getTrainer() const;
    QString getStatus() const;
    int getCapacity() const;
    int getEnrolled() const;
    QTime getTime() const;
};

#endif // GYM_CLASSES_H
