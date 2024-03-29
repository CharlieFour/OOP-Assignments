#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include "Course.h"
#include "Teacher.h"

class Timetable
{
    private:
        struct ClassInfo
        {
            Course course;
            Teacher teacher;
            std::string room;
            std::string startTime;
            std::string endTime;
            std::string day;

            ClassInfo() = default;

            ClassInfo(const Course& course, const Teacher& teacher, const std::string& room, const std::string& day, const std::string& startTime, const std::string& endTime)
            : course(course), teacher(teacher), room(room), day(day), startTime(startTime), endTime(endTime) {}
        };

        std::vector<ClassInfo> classes;

    public:
        void addClass(const Course& course, const Teacher& teacher, const std::string& room, const std::string& day, const std::string& startTime, const std::string& endTime);
        void saveRoomTimetable(const std::string& room, const std::string& filename);
        void saveLabTimetable(const std::string& lab, const std::string& filename);
        void printTeacherTimetable(const std::string& teacherName);
        void printRoomTimetable(const std::string& room);
        void getTeacherAtTime(const std::string& day, const std::string& time);
};

#endif
