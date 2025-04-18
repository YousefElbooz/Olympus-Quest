#ifndef MANAGER_H
#define MANAGER_H
#include "Member.h"
#include "Gym_classes.h"
#include <string>
using namespace std;

class manager
{
private:
    int id;
    string name;
    const string filename = "courses.txt";
public:
    manager();
    manager(int id, string name);
    int getid() ;
    string getname() ;
    void addCourse();
    void removeCourse(int courseId);
    void displayCourses() const;
    void workout_tracking(int memberId,Member member);
    ~manager();
};

#endif


