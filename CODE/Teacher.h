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
        Teacher() = default;
        Teacher(std::string name) : teacherName(name) {}
        Teacher(std::string name, std::string id, std::string course) : teacherName(name), teacherID(id), teacherCourse(course) {}
        std::string getName() const;
        std::string getID();
        std::string getCourse();

        void setName(std::string name);
        void setID(std::string id);
        void setCourse(std::string course);
};

#endif 