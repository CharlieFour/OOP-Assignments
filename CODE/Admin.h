#ifndef Admin_H
#define Admin_H

#include <string>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"

class Course; //forward declaration
class Student; //forward declaration
class Teacher; //forward declaration

class Admin
{
    private:
        std::string name;
        std::string password;
    public:
        Admin(std::string name, std::string password);
        std::string getName();
        std::string getPassword();
        void setName(std::string name);
        void addTeacher(Teacher teacher);
        void removeTeacher(Teacher teacher);
};

#endif // Admin_H