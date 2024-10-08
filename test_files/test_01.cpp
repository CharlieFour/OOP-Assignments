#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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
    std::string courseId;
public:
    Course() = default;
    Course(std::string courseName, std::string courseId) : courseName(courseName), courseId(courseId) {}
    ~Course() = default;
    std::string getCourseName() const
    {
        return this->courseName;
    }
    std::string getCourseId() const
    {
        return this->courseId;
    }
    void setCourseName(std::string courseName)
    {
        this->courseName = courseName;
    }
    void setCourseId(std::string courseId)
    {
        this->courseId = courseId;
    }
    std::string courseDetails(std::string courseId)
    {
        if (this->getCourseId() == courseId)
        {
            return this->getCourseName();
        }
        return "";
    }
};
class Teacher : public Person
{
public:
    Course* course;
    Teacher() = default;
    Teacher(std::string id, std::string name, Course* course) : Person(id, name) {
        this->course = course;
    }
    ~Teacher() = default;
    void setCourseId(string courseId)
    {
        course->setCourseId(courseId);
    }
    std::string getCourseId()
    {
        return course->getCourseId();
    }
};

class Room
{
private:
    std::string roomNumber;
    int slot;
    std::string day;
    std::string semester;
    std::string courseId;
public:
    Room() = default;
    Room(std::string roomNumber, int slot, std::string day, std::string semester, std::string courseId) : roomNumber(roomNumber), slot(slot), day(day), semester(semester), courseId(courseId) {}
    std::string checkRoomSlot(int slot)
    {
        if (slot == 1)
        {
            return "8:30 - 9:25";
        }
        else if (slot == 2)
        {
            return "9:30 - 10:25";
        }
        else if (slot == 3)
        {
            return "10:30 - 11:25";
        }
        else if (slot == 4)
        {
            return "11:30 - 12:25";
        }
        else if (slot == 5)
        {
            return "12:30 - 1:25";
        }
        else if (slot == 6)
        {
            return "1:30 - 2:25";
        }
        else if (slot == 7)
        {
            return "2:30 - 3:25";
        }
        else if (slot == 8)
        {
            return "3:30 - 4:25";
        }
        return "Invalid Slot";
    }
    std::string getRoomNumber() const
    {
        return this->roomNumber;
    }
    int getSlot() const
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
    std::string getCourseId() const
    {
        return this->courseId;
    }
    void setCourseId(std::string courseId)
    {
        this->courseId = courseId;
    }
};

class Student : public Person
{
public:
    vector<Student*> students;
    std::string semester;
    Student() = default;
    Student(std::string semester, std::string name, std::string id) : Person(id, name), semester(semester) {}
    std::string getSemester()
    {
        return this->semester;
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
    Course* courses;
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
    void registerTeacher(std::string name, std::string courseName, std::string courseId)
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
        Course* course = new Course(courseName, courseId);
        Teacher* teacher = new Teacher(id, name, course);
        cout << "\nTeacher registered successfully!" << endl;
        cout << "\nTeacher ID: " << id << endl;
        teachers.push_back(teacher);
        system("pause");
    }
    void removeTeacher(std::string id)
    {
        for (auto it = teachers.rbegin(); it != teachers.rend(); ++it)
        {
            if ((*it)->getId() == id)
            {
                teachers.erase(std::next(it).base());
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
            outFile << cls->getId() << "," << cls->getName() << "," << cls->course->getCourseName() << "," << cls->course->getCourseId() << endl;
        }
        cout << "Teacher saved successfully!" << endl;

        outFile.close();
    }
    void loadTeacherFile()
    {
        string id, name, courseName, courseId;
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
                getline(ss, courseName, ',');
                getline(ss, courseId, ',');

                Teacher* t = new Teacher(id, name, (new Course(courseName, courseId)));

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
        for (auto it = students.rbegin(); it != students.rend(); ++it)
        {
            if ((*it)->getId() == id)
            {
                students.erase(std::next(it).base());
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
};

class Timetable
{

private:
    Admin* admin;
    vector<Room*> rooms;
    Course* course;
public:
    void setadminptr(Admin* a) {
        admin = a;
    }

    void addClass(string courseId, string roomNumber, string day, int slot, string semester)
    {
        for (const auto& te : admin->teachers)
        {
            if (te->getCourseId() == courseId)
            {
                rooms.push_back(new Room(roomNumber, slot, day, semester, courseId));
            }
        }
        //rooms.push_back(new Room(roomNumber, slot, day, semester, courseId));
    }
    void removeClass(string slot, string day, string roomNumber)
    {
        for (auto it = rooms.rbegin(); it != rooms.rend(); ++it)
        {
            if ((*it)->getSlot() == stoi(slot) && (*it)->getDay() == day && (*it)->getRoomNumber() == roomNumber)
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
            file << r->getRoomNumber() << "," << r->getSlot() << "," << r->getDay() << "," << r->getSemester() << "," << r->getCourseId() << endl;
        }
        file.close();
        cout << "Timetable saved successfully!" << endl;
    }
    void loadTimetable()
    {
        ifstream file("timetable", std::ios::in);
        string roomNumber, slot, day, semester, courseId, line;
        while (getline(file, line))
        {
            if (line != " " || line != "") {
                std::stringstream ss(line);

                getline(ss, roomNumber, ',');
                getline(ss, slot, ',');
                getline(ss, day, ',');
                getline(ss, semester, ',');
                getline(ss, courseId);
                rooms.push_back(new Room(roomNumber, stoi(slot), day, semester, courseId));
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
                    if (r->getCourseId() == t->getCourseId())
                    {
                        cout << r->getRoomNumber() << " " << r->getSlot() << " " << r->getDay() << " " << r->getSemester() << " " << course->courseDetails(r->getCourseId()) << endl;
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
                cout << r->getRoomNumber() << " " << r->getSlot() << " " << r->getDay() << " " << r->getSemester() << " " << course->courseDetails(r->getCourseId()) << endl;
            }
        }
    }
    void getTeacherAtTime(const std::string& day, const std::string& time, const std::string& room)
    {
        for (const auto& r : rooms)
        {
            if (r->getDay() == day && r->checkRoomSlot(r->getSlot()) == time && r->getRoomNumber() == room)
            {
                for (const auto& t : admin->teachers)
                {
                    if (t->getCourseId() == r->getCourseId())
                    {
                        cout << t->getName() << endl;
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
                cout << r->getRoomNumber() << " " << r->getSlot() << " " << r->getDay() << " " << r->getSemester() << " " << course->courseDetails(r->getCourseId()) << endl;
            }
        }
    }
    void printDayTimetable(const std::string& day, const std::string roomNumber)
    {
        for (const auto& r : rooms)
        {
            if (r->getDay() == day && r->getRoomNumber() == roomNumber)
            {
                cout << r->getRoomNumber() << " " << r->getSlot() << " " << r->getDay() << " " << r->getSemester() << " " << r->getCourseId() << endl;
            }
        }
    }
    void switchClass(std::string slot1, std::string roomNumber1, std::string day1, std::string slot2, std::string roomNumber2, std::string day2)
    {
        for (const auto& r : rooms)
        {
            if (r->getSlot() == stoi(slot1) && r->getRoomNumber() == roomNumber1 && r->getDay() == day1)
            {
                r->setSlot(slot2);
                r->setRoomNumber(roomNumber2);
                r->setDay(day2);
            }
            else if (r->getSlot() == stoi(slot2) && r->getRoomNumber() == roomNumber2 && r->getDay() == day2)
            {
                r->setSlot(slot1);
                r->setRoomNumber(roomNumber1);
                r->setDay(day1);
            }
        }
    }
};

int main()
{
    /*
    Student student;
    int i=0;
    student.loadStudentFile();
    while(i == 0)
    {
        student.registerStudent();
        cin >> i;
    }
    student.saveStudentFile();*/
    Admin admin;
    Timetable timetable;
    timetable.setadminptr(&admin);
    string a;
    admin.loadTeacherFile();
    admin.loadStudentFile();
    admin.loadAdminFile();
    timetable.loadTimetable();
    timetable.addClass("1234", "4-17", "Monday", 1, "2B");
    admin.registerStudent("Ahmed", "1B");
    cout << "Enter student ID to check : ";
    cin >> a;
    bool chk = admin.checkStudent(a);
    if (chk)
    {
        cout << "\ntrue" << endl;
    }
    else
        cout << "\nfales" << endl;
    /*string name = "Dr.Tamim", courseName = "OOP", courseId = "1234";
    admin.registerTeacher(name, courseName, courseId);*/
    admin.saveStudentFile();
    admin.saveTeacherFile();
    admin.saveAdminFile();
    timetable.saveTimetable();
}