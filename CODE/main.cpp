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
    timetable.addClass("Math", "Sahreef", "4-17", "Monday", "08:30", "09:45");
    timetable.addClass("Physics", "Eng Waleed", "4-18", "Wednesday", "09:45", "11:00");
    timetable.addClass("OPP", "Dr. Tamim", "4-19", "11:00", "Monday", "12:15");
    timetable.addClass("OPP", "Dr. Tamim", "4-01", "11:00", "Monday", "12:15");

    timetable.saveRoomTimetable("4-17", "Room_4-17_Timetable.txt");
    timetable.saveRoomTimetable("4-18", "Room_4-18_Timetable.txt");
    timetable.saveRoomTimetable("4-19", "Room_4-19_Timetable.txt");

    timetable.saveLabTimetable("4-01", "Lab_4-01_Timetable.txt");
    timetable.saveLabTimetable("4-02", "Lab_4-02_Timetable.txt");

    timetable.printRoomTimetable("4-17");
    timetable.getTeacherAtTime("Monday", "08:40");

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

//-------------------------------------------------------------------------

void startMenu()
{
    
    int choice, a , x ;

    cout << "Welcome to Bahria University LMS" << endl;
    cout << "Do you want to:" << endl;
    cout << "1.login" << endl;
    cout << "2.Register" << endl;
    cin >> choice;

    do
    {
    if(choice==1)
    {
        //login for admin
    }
    if(choice==2)
    {
        //registerStudent();
    }

     cout << "Do you want to (1)Start or (2)Quit?" << endl;
     cin >> x;

     if(x == 1)
     {
        cout << "You have accessed the Start Menu" << endl;
     }
     if(x == 2)
     {
        cout << "You chose to quit. Goodbye" << endl;
        exit(0);
     }

    }while(x < 1 || x < 3 );

     cout << "Do you want to view as:" << endl;
     cout << "1.Student" << endl;
     cout << "2.Teacher" << endl;
     cout << "3.Admin" << endl;
     cout << "4.Exit" << endl;
     cout << "Enter your choice: ";
     cin >> a;

     switch(a)
     {
        case 1:
            cout << "You're viewing as a STUDENT. Would you like to:" << endl;
            cout << "1. View timetable" << endl;
            int choice;
            cin >> choice;
            if(choice==1) 
            {
                cout << "You chose to view the timetable" << endl;
                //student wise time table
            }
             break;

        case 2:
            cout << "You're viewing as a TEACHER. Would you like to:" << endl;
            cout << "1. View Teacher's time table" << endl;
            int a;
            cin >> a;

            if(a == 1)
            {
                cout << "Who's timetable do you want to see? \n1.Sir gwa \n2.Sir hjsd \n3.Sir jhds \n4.sjd \n5. maam gehs" << endl;
                int x;
                cin >> x;

                if(x == 1)
                {
                        //tchr wise time table
                }
                if(x == 2)
                {
                        //tchr wise time table
                }
                if(x == 3)
                {
                        //tchr wise time table
                }
                if(x == 4)
                {
                        //tchr wise time table
                }
                if(x == 5)
                {
                        //tchr wise time table
                }
                else
                {
                    cout << "choose a correct option between 1 to 5."  << endl;
                }
            }
            

        case 3:     
            cout << "You're viewing as ADMIN. Would you like to: " << endl;
            cout << "1. View room wise time table" << endl;
            cout << "2. View teacher wise time table" << endl;
            cout << "3. Who is teaching at what time? " << endl;
            int f;
            cin >> f;

            if(f==1)
            {
                //room wise time table
            }
             if(f==2)
            {
                //teacher wise time table
            }
             if(f==3)
            {
                //who teaching when
            }
        case 4:
            cout << "You have successfully exitted." << endl;
            exit(0);
     }
}

void Login()
{
    int a, choice;
    cout << "Welcome to the login page." << endl;
    cin >> a;
    
     do {

        cout << "Do you want to log in as \n1.Student \n2.Teacher \n3.Admin" << endl;
        cin >> choice;

        if (choice < 1 || choice > 3) 
        {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
        } while (choice < 1 || choice > 3);

    if(a == 1)
    {
        string username;
        cout << "Enter your username: " << endl;
     

        cout << "Enter your password: " << endl;
    }
}