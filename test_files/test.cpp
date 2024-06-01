#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person
{
private:
    std::string id;
    std::string name;
public:
    Person() = default;
    Person(std::string id, std::string name) : id(id), name(name) {}
    ~Person() = default;
    std::string getName() const
    {
        return this->name;
    }
    std::string getId() const
    {
        return this->id;
    }
    void setName(std::string name)
    {
        this->name = name;
    }
    void setId(std::string id)
    {
        this->id = id;
    }
};

class Course
{
private:
    std::string courseName;
    std::string courseCode;
    std::string courseSemester;
public:
    Course() = default;
    Course(std::string courseName, std::string courseCode, std::string courseSemester) : courseName(courseName), courseCode(courseCode) , courseSemester(courseSemester) {}
    ~Course() = default;
    std::string getCourseName() const
    {
        return this->courseName;
    }
    std::string getCourseSemester() const
    {
        return this->courseSemester;
    }
    std::string getCourseCode() const
    {
        return this->courseCode;
    }
    void setCourseName(std::string courseName)
    {
        this->courseName = courseName;
    }
    void setCourseSemester(std::string courseSemester)
    {
        this->courseSemester = courseSemester;
    }
    void setCourseCode(std::string courseCode)
    {
        this->courseCode = courseCode;
    }
    std::string courseDetails(std::string courseCode)
    {
        if (this->getCourseCode() == courseCode)
        {
            return this->getCourseName();
        }
        return "";
    }
};

class Teacher : public Person
{
private:
    string courseCode;
public:
    Teacher() = default;
    Teacher(std::string id, std::string name, std::string courseCode) : Person(id, name), courseCode(courseCode) {}
    ~Teacher() = default;
    void setCourse(string courseCode)
    {
        this->courseCode = courseCode;
    }
    std::string getCourseCode()
    {
        return courseCode;
    }
};

class Student : public Person
{
private:
    std::string semester;
public:
    Student() = default;
    Student(std::string semester, std::string name, std::string id) : Person(id, name), semester(semester) {}
    std::string getSemester()
    {
        return this->semester;
    }
    std::string getStudentSemester()
    {
        return this->semester;
    }
    void setStudentSemester(const std::string semester)
    {
        this->semester = semester;
    }
    void setSemester(const std::string semester)
    {
        this->semester = semester;
    }
};      
class Admin : public Person
{
public:
    friend class Timetable;
    vector<Teacher*> teachers;
    vector<Student*> students;
    vector<Course*> courses;
    Admin() = default;
    Admin(std::string password, std::string name) : Person(password, name) {}
    ~Admin() = default;
    bool checkIdPass(std::string name, std::string password)
    {
        if (this->getName() == name && this->getId() == password)
        {
            return true;
        }
        return false;
    }
    void changeIdPassword(const std::string& id, const std::string& password)
    {
        this->setName(id);
        this->setId(password);
    }
    void saveAdminFile()
    {
        ofstream file("admin.txt");
        file << this->getName() << "," << this->getId() << endl;
        file.close();
    }
    void loadAdminFile()
    {
        std::ifstream inFile("admin.txt");
        std::string username, password;
        if (std::getline(inFile, username, ',') && std::getline(inFile, password))
        {
            this->setName(username);
            this->setId(password);
        }

        inFile.close();
    }
    void registerTeacher(std::string name, std::string courseCode)
    {
        std::string id;
        srand(time(nullptr));
        bool uniqueIDFound = false;
        while (!uniqueIDFound)
        {
            id = to_string(rand() % 1000 + 8000);
            bool duplicate = false;
            for (const Teacher* t : teachers)
            {
                if (id == t->getId()) {
                    duplicate = true;
                    break;
                }
            }
            if (!duplicate)
            {
                uniqueIDFound = true;
            }
        }
        Teacher* teacher = new Teacher(id, name, courseCode);
        cout << "\nTeacher registered successfully!" << endl;
        cout << "\nTeacher ID: " << id << endl;
        teachers.push_back(teacher);
        system("pause");
    }
    void removeTeacher(std::string id)
    {
        for (auto it = teachers.begin(); it != teachers.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete (*it);
                teachers.erase(it);
                break;
            }
        }
    }
    bool checkTeacher(const std::string id)
    {
        for (const auto& cls : teachers)
        {
            if (cls->getId() == id)
            {
                return true;
            }
        }
        return false;
    }
    bool checkTeacher(const std::string id, std::string &tn)
    {
        for (const auto& cls : teachers)
        {
            if (cls->getId() == id)
            {
                tn = cls->getName();
                return true;
            }
        }
        return false;
    }
    void saveTeacherFile()
    {
        ofstream outFile("teacher.txt");
        if (!outFile)
        {
            cerr << "Error: Unable to open file: " << "teacher.txt" << endl;
            return;
        }
        for (const auto& cls : teachers)
        {
            outFile << cls->getId() << "," << cls->getName() << "," << cls->getCourseCode() << endl;
        }
        cout << "Teacher saved successfully!" << endl;

        outFile.close();
    }
    void loadTeacherFile()
    {
        string id, name, courseCode;
        ifstream inFile("teacher.txt", std::ios::in);
        if (!inFile)
        {
            cerr << "Error: Unable to open file: " << "teacher.txt" << endl;
            return;
        }

        string line;
        while (getline(inFile, line))
        {
            if (line != " " || line != "") {
                std::stringstream ss(line);

                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, courseCode, ',');

                Teacher* t = new Teacher(id, name, courseCode);

                teachers.push_back(t);
            }
        }

        cout << "Teacher loaded successfully!" << endl;
        inFile.close();
    }
    void registerStudent(std::string name, std::string semester)
    {
        string id;
        srand(time(nullptr));
        bool uniqueIDFound = false;
        while (!uniqueIDFound)
        {
            id = to_string(rand() % 8000 + 1000);
            bool duplicate = false;
            for (const auto& student : students)
            {
                if (student->getId() == id)
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
        Student* student = new Student(semester, name, id);
        cout << "\nStudent registered successfully!" << endl;
        cout << "\nStudent ID: " << id << endl;
        this->students.push_back(student);
        system("pause");
    }
    void removeStudent(std::string id)
    {
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete (*it);
                students.erase(it);
                break;
            }
        }
    }
    bool checkStudent(const std::string id)
    {
        for (const auto& cls : students)
        {
            if (cls->getId() == id)
            {
                return true;
            }
        }
        return false;
    }
    bool checkStudent(const std::string id, std::string &sem)
    {
        for (const auto& cls : students)
        {
            if (cls->getId() == id)
            {
                sem = cls->getSemester();
                return true;
            }
        }
        return false;
    }
    void saveStudentFile()
    {
        ofstream outFile("student.txt");
        if (!outFile)
        {
            cerr << "Error: Unable to open file: " << "student.txt" << endl;
            return;
        }
        for (const auto& cls : students)
        {
            outFile << cls->getId() << "," << cls->getName() << "," << cls->getSemester() << endl;
        }
        cout << "Student saved successfully!" << endl;

        outFile.close();
    }
    void loadStudentFile()
    {
        string name, id, semester;
        ifstream inFile("student.txt", std::ios::in);
        if (!inFile)
        {
            cerr << "Error: Unable to open file: " << "student.txt" << endl;
            return;
        }
        string line;
        while (getline(inFile, line))
        {
            if (line != " " || line != "") {
                std::stringstream ss(line);

                getline(ss, id, ',');
                getline(ss, name, ',');
                getline(ss, semester, ',');

                Student* s = new Student(semester, name, id);
                students.push_back(s);
            }
        }
        cout << "Student loaded successfully!" << endl;
        inFile.close();
    }
    void addCourse(std::string courseName, std::string courseCode, std::string courseSemester)
    {
        Course* course = new Course(courseName, courseCode, courseSemester);
        courses.push_back(course);
        delete course;
    }
    void removeCourse(std::string courseCode)
    {
        for (auto it = courses.begin(); it != courses.end(); ++it)
        {
            if ((*it)->getCourseCode() == courseCode)
            {
                delete (*it);
                courses.erase(it);
                break;
            }
        }
    }
    void saveCourseFile()
    {
        ofstream outFile("course.txt");
        if (!outFile)
        {
            cerr << "Error: Unable to open file: " << "course.txt" << endl;
            return;
        }
        for (const auto& cls : courses)
        {
            outFile << cls->getCourseName() << "," << cls->getCourseCode() << "," << cls->getCourseSemester() << endl;
        }
        cout << "Course saved successfully!" << endl;

        outFile.close();
    }
    void loadCourseFile()
    {
        string courseName, courseCode, courseSemester;
        ifstream inFile("course.txt", std::ios::in);
        if (!inFile)
        {
            cerr << "Error: Unable to open file: " << "course.txt" << endl;
            return;
        }
        string line;
        while (getline(inFile, line))
        {
            if (line != " " || line != "") {
                std::stringstream ss(line);

                getline(ss, courseName, ',');
                getline(ss, courseCode, ',');
                getline(ss, courseSemester, ',');

                Course* c = new Course(courseName, courseCode, courseSemester);
                courses.push_back(c);
            }
        }
        cout << "Course loaded successfully!" << endl;
        inFile.close();
    }
};

class Room
{
private:
    std::string roomNumber;
    std::string slot;
    std::string day;
    std::string semester;
    std::string courseCode;
public:
    Room() = default;
    Room(std::string roomNumber, std::string slot, std::string day, std::string semester, std::string courseCode) : roomNumber(roomNumber), slot(slot), day(day), semester(semester), courseCode(courseCode) {}
    std::string getRoomNumber() const
    {
        return this->roomNumber;
    }
    std::string getSlot() const
    {
        return this->slot;
    }
    std::string getDay() const
    {
        return this->day;
    }
    void setDay(std::string day)
    {
        this->day = day;
    }
    void setRoomNumber(std::string roomNumber)
    {
        this->roomNumber = roomNumber;
    }
    void setSlot(std::string slot)
    {
        this->slot = stoi(slot);
    }
    std::string getSemester() const
    {
        return this->semester;
    }
    void setSemester(std::string semester)
    {
        this->semester = semester;
    }
    std::string getCourseCode() const
    {
        return this->courseCode;
    }
    void setCourseCode(std::string courseCode)
    {
        this->courseCode = courseCode;
    }
};

class Timetable
{
    private:
        Admin* admin;
    public:
        vector<Room*> rooms;
        void setadminptr(Admin* a) {
            admin = a;
        }

        void addClass(string courseCode, string roomNumber, string day, string slot, string semester)
        {
            for (const auto& te : admin->teachers)
            {
                if (te->getCourseCode() == courseCode)
                {
                    rooms.push_back(new Room(roomNumber, slot, day, semester, courseCode));
                }
            }
            //rooms.push_back(new Room(roomNumber, slot, day, semester, courseCode));
        }
        void removeClass(string slot, string day, string roomNumber)
        {
            for (auto it = rooms.rbegin(); it != rooms.rend(); ++it)
            {
                if ((*it)->getSlot() == slot && (*it)->getDay() == day && (*it)->getRoomNumber() == roomNumber)
                {
                    rooms.erase(std::next(it).base());
                }
            }
        }
        void saveTimetable()
        {
            ofstream file("timetable.txt");
            for (const auto& r : rooms)
            {
                file << r->getRoomNumber() << "," << r->getSlot() << "," << r->getDay() << "," << r->getSemester() << "," << r->getCourseCode() << endl;
            }
            file.close();
            cout << "Timetable saved successfully!" << endl;
        }
        void loadTimetable()
        {
            ifstream file("timetable.txt", std::ios::in);
            string roomNumber, slot, day, semester, courseCode, line;
            while (getline(file, line))
            {
                if (line != " " || line != "") {
                    std::stringstream ss(line);

                    getline(ss, roomNumber, ',');
                    getline(ss, slot, ',');
                    getline(ss, day, ',');
                    getline(ss, semester, ',');
                    getline(ss, courseCode);
                    rooms.push_back(new Room(roomNumber, slot, day, semester, courseCode));
                }
            }
            file.close();
            cout << "Timetable loaded successfully!" << endl;
        }
        void printTeacherTimetable(const std::string& teacherName)
        {
            for (const auto& t : admin->teachers)
            {
                if (t->getName() == teacherName)
                {
                    for (const auto& r : rooms)
                    {
                        if (r->getCourseCode() == t->getCourseCode())
                        {
                            for(const auto& c : admin->courses)
                            {
                                if (c->getCourseCode() == t->getCourseCode())
                                {
                                    cout << "Room: " << r->getRoomNumber() << " " << "Slot: " << r->getSlot() << " " << "Day: " << r->getDay() << " " << "Semester: " << r->getSemester() << " " << "Course: " << c->getCourseName() << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        void printRoomTimetable(const std::string& room)
        {
            for (const auto& r : rooms)
            {
                if (r->getRoomNumber() == room)
                {
                    cout << "Room:" << r->getRoomNumber() << " " << "Slot: " << r->getSlot() << " " << "Day: " << r->getDay() << " " << "Semester: " <<  r->getSemester() << " ";
                    for (const auto& t : admin->teachers) {
                        if (t->getCourseCode() == r->getCourseCode()) {
                            for(const auto& c : admin->courses) {
                                if (c->getCourseCode() == t->getCourseCode()) {
                                    cout << "Course: " << c->getCourseName();
                                }
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
        void getTeacherAtTime(const std::string& day, const std::string& time, const std::string& room)
        {
            for (const auto& r : rooms)
            {
                if (r->getDay() == day && r->getSlot() == time && r->getRoomNumber() == room)
                {
                    for (const auto& t : admin->teachers)
                    {
                        if (t->getCourseCode() == r->getCourseCode())
                        {
                            cout << "Name: " << t->getName() << endl;
                        }
                    }
                }
            }
        }
        void printStudentTimetable(const std::string& semester)
        {
            for (const auto& r : rooms)
            {
                if (r->getSemester() == semester)
                {
                    cout << "Room: " << r->getRoomNumber() << " " << "Slot: " << r->getSlot() << " " << "Day: " <<  r->getDay() << " " << "Semester: " <<  r->getSemester() << " ";
                    for (const auto& t : admin->teachers) {
                        if (t->getCourseCode() == r->getCourseCode()) {
                            for(const auto& c : admin->courses) {
                                if (c->getCourseCode() == t->getCourseCode()) {
                                    cout << "Course: " << c->getCourseName();
                                }
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
        void printDayTimetable(const std::string& day)
        {
            for (const auto& r : rooms)
            {
                if (r->getDay() == day)
                {
                cout << "Room: " << r->getRoomNumber() << " " << "Slot: " << r->getSlot() << " " << "Day: " << r->getDay() << " " << "Semester: " << r->getSemester() << " " << "Course: " << r->getCourseCode() << endl;
                }
            }
        }
        void switchClass(std::string slot1, std::string roomNumber1, std::string day1, std::string slot2, std::string roomNumber2, std::string day2)
        {
            for (const auto& r : rooms)
            {
                if (r->getSlot() == slot1 && r->getRoomNumber() == roomNumber1 && r->getDay() == day1)
                {
                    r->setSlot(slot2);
                    r->setRoomNumber(roomNumber2);
                    r->setDay(day2);
                }
                else if (r->getSlot() == slot2 && r->getRoomNumber() == roomNumber2 && r->getDay() == day2)
                {
                    r->setSlot(slot1);
                    r->setRoomNumber(roomNumber1);
                    r->setDay(day1);
                }
            }
        }
};