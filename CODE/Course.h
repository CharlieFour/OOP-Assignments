#ifndef Course_H
#define Course_H

#include <string>
#include "Teacher.h"
#include "Student.h"


class Course
{
    private:
        std::string name;
        Teacher teacher;
        int credits;
        int duration;
    public:
        Course(std::string name, Teacher teacher, int credits, int duration);
        std::string getName();
        Teacher getTeacher();
        int getCredits();
        int getDuration();
        void setName(std::string name);
        void setTeacher(Teacher teacher);
        void setCredits(int credits);
        void setDuration(int duration);
        void addStudent(Student student);
        void removeStudent(Student student);
        void printStudents();
        void print();
};

#endif