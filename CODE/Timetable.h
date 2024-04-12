#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Course.h"
#include "Teacher.h"
#include "Room.h"
#include "Student.h"

class Timetable : public Student, public Teacher, public Room
{
    private:
        vector<Teacher> teacher;
        vector<Student> student;
        vector<Room> room;
        /*struct ClassInfo
        {
            Course course;
            Teacher teacher;
            std::string room;
            std::string startTime;
            std::string endTime;
            std::string day;
            std::string semester;

            ClassInfo() = default;

            ClassInfo(const Course& course, const Teacher& teacher , const std::string& room, const std::string& day, const std::string& semester, const std::string& startTime, const std::string& endTime)
            : course(course), teacher(teacher), room(room), day(day), semester(semester), startTime(startTime), endTime(endTime) {}
        };

        std::vector<ClassInfo> classes;*/

    public:
        Timetable() = default;
        Timetable(const vector<Teacher>& teacher, const vector<Student>& student, const vector<Room>& room) : teacher(teacher), student(student), room(room) {}
        ~Timetable() = default;
        void addClass(const Teacher& teacher, const Student& student, const Room& room);
        void removeClass(const Teacher& teacher,const Student& student, const Room& room);
        //void addClass(const Course& course, const Teacher& teacher, const std::string& room, const std::string& day, const std::string& semester, const std::string& startTime, const std::string& endTime);
        void saveTimetable(const std::string& room, const std::string& filename);
        void loadTimetable(const std::string& filename);
        void printTeacherTimetable(const std::string& teacherName);
        void printRoomTimetable(const std::string& room);
        void getTeacherAtTime(const std::string& day, const std::string& time, const std::string& room);
        void printStudentTimetable(const std::string& semester);
        void printDayTimetable(const std::string& day, const std::string room);
};

#endif
