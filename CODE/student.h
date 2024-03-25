#ifndef Student.h
#define Student.h
#include <string>
#include "Course.h"

class Student
{
    private:

    string StudentName;
    string StudentID;
    string StudentEnrollment;
    string StudentSection;
    string StudentDegree;
    string StudentEmail;
    
    public:
    Student(string name, string id, string enrollment, string section, string degree, string email):
    StudentName(name), StudentID(id), StudentEnrollment(enrollment), StudentSection(section), StudentDegree(degree), StudentEmail(email) {}
};

#endif 

