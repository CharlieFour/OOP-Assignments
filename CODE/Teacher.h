#ifndef Teacher_H
#define Teacher_H

#include <string>

class Course; //forward declaration
class Teacher 
{
    private:
    std::string teacherName;
    std::string teacherID;
    std::string teacherCourse;
    std::string teacherPassword;
    
    public:
    Teacher(std::string name, std::string id, std::string course, std::string password):
    teacherName(name), teacherID(id), teacherCourse(course), teacherPassword(password) {}
    
    string getName();
    string getID();
    string getCourse();
    string getPassword();

    void setName(string name);
    void setID(string id);
    void setCourse(string course);
    void setPassword(string password);
    
};

#endif






