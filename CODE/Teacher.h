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
    
    string getName(int id);
    string getID();
    string getCourse(int id);
    string getPassword(int id);

    void setName(string name);
    void setID(string id);
    void setCourse(string course, int id);
    void setPassword(string password);
    
};

#endif