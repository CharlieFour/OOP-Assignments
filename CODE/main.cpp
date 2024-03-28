#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "Admin.h"    
#include "Teacher.h"
#include "Course.h"
#include "Student.h"
#include "TimeTable.h" 

using namespace std;

void startMenu();
void login();

int main()
{
    Timetable timetable;
    // Example usage
    timetable.addClass("Math", "Sir Shareef", "4-17", "Monday", "08:30", "09:45");
    timetable.addClass("Physics", "Eng Waleed", "4-18", "Wednesday", "09:45", "11:00");
    timetable.addClass("OPP", "Dr. Tamim", "4-19", "Mnnday", "11:00", "12:15");
    timetable.addClass("OPP", "Dr. Tamim", "4-01", "Monday", "11:00", "12:15");
    timetable.addClass("ISE", "Awais", "4-19", "Tuesday", "9:30", "10:30");

    timetable.saveRoomTimetable("4-17", "Room_4-17_Timetable.txt");
    timetable.saveRoomTimetable("4-18", "Room_4-18_Timetable.txt");
    timetable.saveRoomTimetable("4-19", "Room_4-19_Timetable.txt");

    timetable.saveLabTimetable("4-01", "Lab_4-01_Timetable.txt");
    timetable.saveLabTimetable("4-02", "Lab_4-02_Timetable.txt");

    startMenu();

    return 0;
}

//create file for student counter 

void Student::registerStudent() 
{
    StudentInfo newStudent;
    
    cout << "Enter student's name: ";
    getline(cin, newStudent.name);

    cout << "Enter student's semester: ";
    cin >> newStudent.semester;

   
    srand(time(nullptr)); 
    bool uniqueIDFound = false;
    while (!uniqueIDFound) 
    {
        newStudent.id = rand() % 9000 + 1000; 
        bool duplicate = false;
        for (const auto& student : students) 
        {
            if (student.id == newStudent.id) 
            {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) 
        {
            uniqueIDFound = true;
        }
    }

    students.push_back(newStudent);
}

void Student::saveDataToFile() 
{
    ofstream outFile("students.txt");
    if (!outFile) 
    {
        cerr << "Error: Unable to open file: " << "students.txt" << endl;
        return;
    }

    outFile << "Student ID" << setw(15) << "Name" << setw(20) << "Semester" << endl;
    for (const auto& student : students) 
    {
        outFile << student.id << setw(20) << student.name << setw(15) << student.semester << endl;
    }

    outFile.close();
}

 
 // Teacher methods
Teacher::Teacher(string name, string id,string course) :
teacherName(name), teacherID(id), teacherCourse(course) {}

string Teacher::getName() 
{ 
    return teacherName; 
}
string Teacher::getID() 
{ 
    return teacherID; 
}
string Teacher::getCourse() 
{ 
    return teacherCourse; 
}
void Teacher::setName(std::string name) 
{ 
    teacherName = name; 
}
void Teacher::setID(std::string id) 
{ 
    teacherID = id; 
}
void Teacher::setCourse(std::string course) 
{ 
    teacherCourse = course; 
}

//------------------------------------ :D ------------------------------------------

// Admin methods
Admin::Admin(string name, string password) : name(name), password(password) {}

string Admin::getName()
{
    return name;
}
string Admin::getPassword()
{
    return password;
}

Course::Course(string Sname, Teacher teacher, int credits) : courseName(Sname), courseTeacher(teacher), courseCredits(credits) {}
string Course::getName()
{
    return courseName;
}
string Course::getTeacher()
{
    return courseTeacher.getName();
}
int Course::getCredits()
{
    return courseCredits;
}
void Course::setTeacher(Teacher teacher)
{
    courseTeacher = teacher;
}
void Course::setCredits(int credits)
{
    courseCredits = credits;
}
//Timetable methods
void Timetable::addClass(const string& courseName, const string& teacherName, const string& room,const string& day, const string& startTime, const string& endTime)
{
    ClassInfo newClass;
    newClass.courseName = courseName;
    newClass.teacherName = teacherName;
    newClass.room = room;
    newClass.day = day;
    newClass.startTime = startTime;
    newClass.endTime = endTime;
    classes.push_back(newClass);
}
void Timetable::saveRoomTimetable(const string& room, const string& filename)
{
    ofstream outFile(filename);
    if(!outFile)
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    outFile << "Room: " << room << endl;
    for(const auto& cls : classes)
    {
        if(cls.room == room)
        {
            outFile << "Day: " << cls.day << ", Course: " << cls.courseName << ", Teacher: " << cls.teacherName << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }

    outFile.close();
}
void Timetable::saveLabTimetable(const string& lab, const string& filename)
{
    ofstream outFile(filename);
    if(!outFile)
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }

    outFile << "Lab: " << lab << endl;
    for(const auto& cls : classes)
    {
        if(cls.room == lab)
        {
            outFile << "Day: " << cls.day << ", Course: " << cls.courseName << ", Teacher: " << cls.teacherName << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }

    outFile.close();
}
void Timetable::printTeacherTimetable(const string& teacherName)
{
    cout << "Teacher Wise Timetable for " << teacherName << ":" << endl;
    for(const auto& cls : classes)
    {
        if(cls.teacherName == teacherName)
        {
            cout << "Day: " << cls.day << ", Course: " << cls.courseName << ", Room: " << cls.room << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }
}
void Timetable::printRoomTimetable(const string& room)
{
    cout << "Room Wise Timetable for " << room << ":" << endl;
    for(const auto& cls : classes)
    {
        if(cls.room == room)
        {
            cout << "Day: " << cls.day << ", Course: " << cls.courseName << ", Teacher: " << cls.teacherName << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }
}
string Timetable::getTeacherAtTime(const string& day, const string& time)
{
    cout << " \nTeacher at this time: ";
    for(const auto& cls : classes)
    {
        if(cls.day == day && cls.startTime <= time && time < cls.endTime)
        {
            cout << cls.teacherName;
        }
    }
    return "No teacher available at this time";
}
//-------------------------------------------------------------------------

void startMenu()
{
    Timetable timetable;
    int choice, a , x ;
    bool flag = true;

    cout << "Welcome to Bahria University LMS" << endl;
    cout << "Do you want to:" << endl;
    cout << "1.login" << endl;
    cout << "2.Register" << endl;
    cin >> choice;

    do
    {
    if(choice==1)
    {
        do
        {
            cout << "Do you want to log in as \n1.Student \n2.Teacher \n3.Admin" << endl;
            cout << "Enter your choice:";
            cin >> a;
            string room, day , time;
            if(a == 1)
            {
                cout << "\n1. View timetable" << endl;
                cout << "2. Exit" << endl;
                cin >> x;
                switch(x)
                {
                    case 1:
                        cout << "You chose to view the timetable" << endl;
                        cout << "Enter your room number (formate should be 4-17): ";
                        cin >> room;
                        timetable.printRoomTimetable(room);
                        break;
                    case 2:
                        cout << "You chose to exit." << endl;
                        exit(0);
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
                        break;
                }

            }
            else if(a == 2)
            {
                cout << "\n1. View timetable" << endl;
                cout << "2. Exit" << endl;
                cin >> x;
                switch(x)
                {
                    case 1:
                        cout << "You chose to view the timetable" << endl;
                        cout << "Enter your room number (formate should be 4-17): ";
                        cin >> room;
                        timetable.printRoomTimetable(room);
                        break;
                    case 2:
                        cout << "You chose to exit." << endl;
                        exit(0);
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
                        break;
                }
            }
            else if(a == 3)
            {
                cout << "\n1. View timetable" << endl;
                cout << "2. view timetable of a teacher" << endl;
                cout << "3. Exit" << endl;
                cin >> x;
                switch(x)
                {
                    case 1:
                        cout << "You chose to view the timetable" << endl;
                        cout << "Enter your room number (formate should be 4-17): ";
                        cin >> room;
                        timetable.printRoomTimetable(room);
                        break;
                    case 2:
                        cout << "You chose to view the timetable of a teacher" << endl;
                        cout << "Enter the day(Monday) of the teacher: ";
                        cin >> day;
                        cout << "Enter the time of the teacher: ";
                        cin >> time;
                        timetable.getTeacherAtTime(day, time);
                        break;
                    case 3:
                        cout << "You chose to exit." << endl;
                        exit(0);
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
                        break;
                }
            }
        }while(flag == true);
        
    }
    if(choice==2)
    {
        Student student ;
        student.registerStudent();
    }
    }while(x < 1 || x < 3 );
}

void Login()
{
    int a, choice;
    cout << "Welcome to the login page." << endl;
    cin >> a;
    
    do
    {
        cout << "Do you want to log in as \n1.Student \n2.Teacher \n3.Admin" << endl;
        cin >> choice;
        if(choice == )

    }while(choice < 1 || choice > 3);

    if(a == 1)
    {
        string username;
        cout << "Enter your username: " << endl;
     

        cout << "Enter your password: " << endl;
    }
}