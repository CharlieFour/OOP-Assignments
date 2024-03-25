#ifndef Student_h
#define Student_h

#include <string>
#include "Course.h"
class Course; //forward declaration
class Student
{
    private:

    std::string StudentName;
    std::string StudentID;
    std::string StudentEnrollment;
    std::string StudentSemester;
    std::string studentPassword;
    
    public:

    Student(std::string name, std::string id, std::string enrollment, std::string semester, std::string password):
    StudentName(name), StudentID(id), StudentEnrollment(enrollment), StudentSemester(semester), studentPassword(password) {}
};

#endif 

