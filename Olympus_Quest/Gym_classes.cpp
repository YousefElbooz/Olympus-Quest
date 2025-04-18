#include "Gym_classes.h"

Gym_classes::Gym_classes() {
    id = 0;
    name = "";
    teacher = "";
    capacity = 0;
    enrolled = 0;
}

Gym_classes::Gym_classes(int id, string name, string teacher, int capacity, int enrolled) {
    this->id = id;
    this->name = name;
    this->teacher = teacher;
    this->capacity = capacity;
    this->enrolled = enrolled;
} 

void Gym_classes::setid(int id){
    this->id=id;
}

void Gym_classes::setname(string name){
    this->name=name;
}

void Gym_classes::setteacher(string teacher){
    this->teacher=teacher;
}

void Gym_classes::setcapacity(int capacity){
    this->capacity=capacity;
}

void Gym_classes::setenrolled(int enrolled){
    this->enrolled=enrolled;
}

int Gym_classes::getid() const{
    return id;
}

string Gym_classes::getname() const{
    return name;
}

string Gym_classes::getteacher() const{
    return teacher;
}

int Gym_classes::getcapacity() const{
    return capacity;
}

int Gym_classes::getenrolled() const{
    return enrolled;
}


