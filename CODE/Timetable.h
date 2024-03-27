#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

class Timetable
{
    private:
        struct ClassInfo
        {
            std::string courseName;
            std::string teacherName;
            std::string room;
            std::string startTime;
            std::string endTime;
            std::string day;
        };

        std::vector<ClassInfo> classes;

    public:
        void addClass(const std::string& courseName, const std::string& teacherName, const std::string& room, const std::string& day, const std::string& startTime, const std::string& endTime);
        void saveRoomTimetable(const std::string& room, const std::string& filename);
        void saveLabTimetable(const std::string& lab, const std::string& filename);
        void printTeacherTimetable(const std::string& teacherName);
        void printRoomTimetable(const std::string& room);
        std::string getTeacherAtTime(const std::string& day, const std::string& time);
};

#endif
