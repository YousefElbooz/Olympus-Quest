#include "Gym_classes.h"

// Default Constructor
Gym_classes::Gym_classes(int id, const QString& className, const QString& trainer,
                         const QString& status, int capacity, int enrolled, const QTime& time)
    : id(id), className(className), trainer(trainer), status(status),
    capacity(capacity), enrolled(enrolled), time(time) {}
Gym_classes::Gym_classes()
    : id(0), className(""), trainer(""), status("Scheduled"), capacity(0), enrolled(0), time(QTime::currentTime()) {}

// Setters
void Gym_classes::setId(int newId) { id = newId; }
void Gym_classes::setClassName(const QString& name) { className = name; }
void Gym_classes::setTrainer(const QString& trainerName) { trainer = trainerName; }
void Gym_classes::setStatus(const QString& newStatus) { status = newStatus; }
void Gym_classes::setCapacity(int newCapacity) { capacity = newCapacity; }
void Gym_classes::setEnrolled(int newEnrolled) { enrolled = newEnrolled; }
void Gym_classes::setTime(const QTime& newTime) { time = newTime; }

// Getters
int Gym_classes::getId() const { return id; }
QString Gym_classes::getClassName() const { return className; }
QString Gym_classes::getTrainer() const { return trainer; }
QString Gym_classes::getStatus() const { return status; }
int Gym_classes::getCapacity() const { return capacity; }
int Gym_classes::getEnrolled() const { return enrolled; }
QTime Gym_classes::getTime() const { return time; }
