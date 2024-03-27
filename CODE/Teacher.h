#ifndef Teacher_H
#define Teacher_H
#include <string>

class Teacher 
{  
    private:
        std::string teacherName;
        std::string teacherID;
        std::string teacherCourse;
    
    public:
        Teacher(std::string name, std::string id, std::string course);
        std::string getName();
        std::string getID();
        std::string getCourse();

        void setName(std::string name);
        void setID(std::string id);
        void setCourse(std::string course);
};

#endif 