#ifndef Student_h
#define Student_h

#include <string>
#include "Course.h"

class Student
{
    private:

    static int const index = 25;
    std::string studentName[index] = {0};
    int studentID[index] = {0};
    int studentSemester[index] = {0};
    std::string studentPassword[index] = {0};

    public: 

    Student(std::string name[25], int id[25], int semester[25], std::string password[25]):
    studentName(name[25]), studentID(id[25]), studentSemester(semester[25]), studentPassword(password[25]) {}

    string getName(int id);
    int getStudentID();
    string getSemester(int id);
    string getPassword(int id);

    void setName(string name);
    void setStudentID();
    void setSemester(int semester, int id);
    void setPassword(string password);


};

#endif 

