#ifndef GYM_CLASSES_H
#define GYM_CLASSES_H

#include<iostream>
using namespace std;

class Gym_classes{
    int id;
    string name;
    string teacher;
    int capacity;
    int enrolled;

    public:
    Gym_classes();
    Gym_classes(int id, string name, string teacher, int capacity, int enrolled);
    void setid(int id);
    void setname(string name);
    void setteacher(string teacher);
    void setcapacity(int capacity);
    void setenrolled(int enrolled);
    int getid() const;
    string getname() const;
    string getteacher() const;
    int getcapacity() const;
    int getenrolled() const;
};

#endif