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

void startMenu(Timetable& timetable);
bool login();
void saveFiles(Timetable& timetable);
void loadFiles(Timetable& timetable);

int main()
{
    Timetable timetable;
    // Example usage
    Course Math("Math");
    Teacher SirShareef("Sir Shareef");
    loadFiles(timetable);
    saveFiles(timetable);

    timetable.printRoomTimetable("4-17");
    timetable.getTeacherAtTime("Monday", "12:00");

    startMenu(timetable);

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
    cout << "Student registered successfully!" << endl;
    cout << "Student ID: " << newStudent.id << endl;

    students.push_back(newStudent);
}

void Student::saveStudentFile() 
{
    ofstream outFile("students.txt");
    if (!outFile) 
    {
        cerr << "Error: Unable to open file: " << "students.txt" << endl;
        return;
    }

    outFile << "Student ID" << setw(15) << "Name" << setw(20) << "Semester" << endl;
    for (const auto& stu : students) 
    {
        outFile << stu.id << setw(20) << stu.name << setw(15) << stu.semester << endl;
    }

    outFile.close();
}
// method to load student file 
 
 // Teacher methods

string Teacher::getName() const
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

string Admin::getAdminName()
{
    return name;
}
string Admin::getAdminPassword()
{
    return password;
}
void Admin::setName(string name)
{
    this->name = name;
}
void Admin::setPassword(string password)
{
    this->password = password;
}

string Course::getName() const
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
void Timetable::addClass(const Course& course, const Teacher& teacher, const string& room,const string& day, const string& startTime, const string& endTime)
{
    ClassInfo newClass;
    newClass.course = course;
    newClass.teacher = teacher;
    newClass.room = room;
    newClass.day = day;
    newClass.startTime = startTime;
    newClass.endTime = endTime;
    classes.push_back(newClass);
}
void Timetable::saveTimetable(const string& room, const string& filename)
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
            outFile << "Day: " << cls.day << ", Course: " << cls.course.getName() << ", Teacher: " << cls.teacher.getName() << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }

    outFile.close();
}
void Timetable::loadTimetable(const string& filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error: Unable to open file: " << filename << endl;
        return;
    }
    string room;
    string line;
    while (getline(inFile, line))
    {
        if (line.find("Room: ") != string::npos) //First line in the file i.e room number
        {
            room = line.substr(6);
        }
        else if (line.find("Day: ") != string::npos) //Data in the file
        {
            stringstream ss(line);
            string temp, day, courseName, teacherName, startTime, endTime;

            //Remove prefix, so when data will save it will be in the correct format
            //Day
            ss >> temp >> day;
            day = day.substr(0, day.size() - 1);

            //Course
            getline(ss, courseName, ',');
            courseName = courseName.substr(courseName.find(":") + 2);

            //Teacher
            getline(ss, teacherName, ',');
            teacherName = teacherName.substr(teacherName.find(":") + 2);

            //Time
            ss >> temp >> startTime >> temp >> endTime;

            classes.push_back({courseName, teacherName, room, day, startTime, endTime});
        }
    }
    inFile.close();
}
void Timetable::printTeacherTimetable(const string& teacherName)
{
    cout << "Teacher Wise Timetable for " << teacherName << ":" << endl;
    for(const auto& cls : classes)
    {
        if(cls.teacher.getName() == teacherName)
        {
            cout << "Day: " << cls.day << ", Course: " << cls.course.getName() << ", Room: " << cls.room << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
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
            cout << "Day: " << cls.day << ", Course: " << cls.course.getName() << ", Teacher: " << cls.teacher.getName() << ", Time: " << cls.startTime << " - " << cls.endTime << endl;
        }
    }
}
void Timetable::getTeacherAtTime(const string& day, const string& time)
{
    bool flag = false;
    cout << " \nTeacher at this time: ";
    for(const auto& cls : classes)
    {
        if(cls.day == day && cls.startTime <= time && time < cls.endTime)
        {
            cout << cls.teacher.getName();
            flag = true;
        }
    }
    if(!flag)
    {
        cout << "No teacher available at this time";
    }
}
//-------------------------------------------------------------------------

void startMenu(Timetable& timetable)
{
    bool flag = true;
    Student student;
    char choice;
    do
    {
        
        cin.ignore();
        cout << "Welcome to Bahria University LMS" << endl;
        cout << "Do you want to:" << endl;
        cout << "1.login" << endl;
        cout << "2.Register" << endl;
        cin >> choice;
        if(choice == '1')
        {
            do
            {
                cin.ignore();
                cout << "\nDo you want to log in as \n1.Student \n2.Teacher \n3.Admin" << endl;
                cout << "Enter your choice:";
                cin >> choice;
                string room, day , time;
                if(choice == '1')
                {
                    do
                    {
                        cin.ignore();
                        cout << "\n1. View timetable" << endl;
                        cout << "2. Exit" << endl;
                        cin >> choice;
                        switch(choice)
                        {
                            case '1':
                                cout << "You chose to view the timetable" << endl;
                                timetable.printRoomTimetable("4-17");
                                timetable.printRoomTimetable("4-18");
                                timetable.printRoomTimetable("4-19");
                                timetable.printRoomTimetable("4-01");
                                timetable.printRoomTimetable("4-02");
                                flag = true;
                                break;
                            case '2':
                                cout << "You chose to exit." << endl;
                                flag = false;
                                break;
                            default:
                                cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
                                break;
                        }

                    }while(flag == true);
                }
                else if(choice == '2')
                {
                    do
                    {
                        cin.ignore();
                        cout << "\n1. View timetable" << endl;
                        cout << "2. Exit" << endl;
                        cin >> choice;
                        switch(choice)
                        {
                            case '1':
                                cout << "You chose to view the timetable" << endl;
                                cout << "Enter your room number (formate should be 4-17): ";
                                cin >> room;
                                timetable.printRoomTimetable(room);
                                flag = true;
                                break;
                            case '2':
                                cout << "You chose to exit." << endl;
                                flag = false;
                                break;
                            default:
                                cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
                                break;
                    }
                    } while (flag == true);
                }
                else if(choice == '3')
                {
                    Admin admin("admin", "admin");
                    bool flag = false;
                    cout << "Welcome to the login page." << endl;
                    string username, password;
                    do
                    {
                        cin.ignore();
                        cout << "\nEnter your username: ";
                        getline(cin, username);
                        cout << "\nEnter your password: ";
                        getline(cin, password);
                        if(username == admin.getAdminName() && password == admin.getAdminPassword())
                        {
                            cout << "You have successfully logged in." << endl;
                            flag = true;
                        }
                        else
                        {
                            cout << "Invalid username or password. Please try again." << endl;
                            flag = false;
                        }    
                    }while(flag == false);
                    cin.ignore();
                    while(flag)
                    {
                        cout << "\n1. View timetable" << endl;
                        cout << "2. View timetable of a teacher" << endl;
                        cout << "3. Exit" << endl;
                        cin >> choice;
                        cin.ignore();
                        switch(choice)
                        {
                            case '1':
                                cout << "You chose to view the timetable" << endl;
                                cout << "Enter your room number (formate should be 4-17): ";
                                getline(cin, room);
                                timetable.printRoomTimetable(room);
                                flag = true;
                                break;
                            case '2':
                                cout << "You chose to view the timetable of a teacher" << endl;
                                cout << "Enter the day(Monday) of the teacher: ";
                                getline(cin, day);
                                cout << "Enter the time of the teacher: ";
                                getline(cin, time);
                                timetable.getTeacherAtTime(day, time);
                                flag = true;
                                break;
                            case '3':
                                cout << "You chose to exit." << endl;
                                flag = false;
                                break;
                            default:
                                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                                break;
                        }
                    }   
                }
            }while(flag == true);
            
        }
        else if(choice == '2')
        {
            cin.ignore();
            student.registerStudent();
        }
        cin.ignore();
        cout << "Do you want to continue (y/n):" ;
        cin >> choice;
        if(choice == 'y')
        {
            flag = true;
        }
        else if(choice == 'n')
        {
            flag = false;
        }
    }while(flag);
    
    student.saveStudentFile();
}
//saving all the files
void saveFiles(Timetable& timetable)
{
    //rooms
    timetable.saveTimetable("4-17", "Room_4-17_Timetable.txt");
    timetable.saveTimetable("4-18", "Room_4-18_Timetable.txt");
    timetable.saveTimetable("4-19", "Room_4-19_Timetable.txt");
    //labs
    timetable.saveTimetable("4-01", "Lab_4-01_Timetable.txt");
    timetable.saveTimetable("4-02", "Lab_4-02_Timetable.txt");
}
//loading all the files
void loadFiles(Timetable& timetable)
{
    //rooms
    timetable.loadTimetable("Room_4-17_Timetable.txt");
    timetable.loadTimetable("Room_4-18_Timetable.txt");
    timetable.loadTimetable("Room_4-19_Timetable.txt");
    //labs
    timetable.loadTimetable("Lab_4-01_Timetable.txt");
    timetable.loadTimetable("Lab_4-02_Timetable.txt");
}
bool Login()
{
    Admin admin("admin", "admin");
    bool flage = false;
    cout << "Welcome to the login page." << endl;
    string username, password;
    do
    {
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);
        if(username == admin.getAdminName() && password == admin.getAdminPassword())
        {
            cout << "You have successfully logged in." << endl;
            return true;
        }
        else
        {
            cout << "Invalid username or password. Please try again." << endl;
            flage = false;
        }    
    }while(flage == false);
    return false;
}