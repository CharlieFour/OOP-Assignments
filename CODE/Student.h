#ifndef Student_h
#define Student_h

#include <string>
#include "Course.h"

class Student
{
    private:

    int const index=25;
    std::string studentName[index]=0;
    std::int studentID[index]=0i;
    std::int studentSemester[5]=0;
    std::string studentPassword[index]=0;
    
    public:

    Student(std::string name, std::string id, std::string semester, std::string password):
    studentName(name), studentID(id), studentSemester(semester), studentPassword(password) {}

    string getName();
    int getStudentID();
    string getSemester();
    string getPassword();

    void setName(string name);
    void setStudentID();
    void setSemester(int semester);
    void setPassword(string password);


};

#endif 

