#ifndef Course_H
#define Course_H

#include <string>
#include "Teacher.h"
#include "Student.h"

class Teacher; //forward declaration
class Student; //forward declaration
class Course
{
    private:
        std::string courseName    ;
        Teacher couurseTeacher;
        int courseCredits;
    public:
        std::string getName();
        Teacher getTeacher(std::string courseName);
        int getCredits(std::string courseName);
        void setTeacher(Teacher teacher);
        void setCredits(int courseCredits);
        void addStudent(Student student);
        void removeStudent(Student student);
};

#endif