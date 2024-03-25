#ifndef Admin_H
#define Admin_H

#include <string>
#include "Course.h"
#include "Teacher.h"
#include "Student.h"

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
        void setPassword(std::string password);
        void addCourse(Course course);
        void removeCourse(Course course);
        void addTeacher(Teacher teacher);
        void removeTeacher(Teacher teacher);
        void addStudent(Student student);
        void removeStudent(Student student);
        void printCourses();
        void printTeachers();
        void printStudents();
        void print();
};

#endif // Admin_H