#include <iostream>
#include <string>
using namespace std;

const int MAX_COURSES=5;
const int MAX_STUDENTS=10;
const int MAX_INSTRUCTORS= 5;
class Student;
class Instructor;
class Course {
public:
    string title;
    string code;
    string description;

    Student* students[MAX_STUDENTS];
    Instructor* instructors[MAX_INSTRUCTORS];
    int studentCount;
    int instructorCount;

    Course() : studentCount(0), instructorCount(0) {}

    void enrollStudent(Student* student);
    void assignInstructor(Instructor* instructor);

    void display();
};

class Student {
public:
    string name;
    int id;
    string email;
    Course* enrolledCourses[MAX_COURSES];
    int enrolledCount;

    Student() : id(0), enrolledCount(0) {}

    void enrollInCourse(Course* course) {
        if (enrolledCount < MAX_COURSES) {
            enrolledCourses[enrolledCount++] = course;}}

    void display();
};

class Instructor {
public:
    string name;
    int id;
    string expertise;

    Instructor() : id(0) {}
};


void Course::enrollStudent(Student* student) {
    if (studentCount<MAX_STUDENTS) {
        students[studentCount++]=student;
        student->enrollInCourse(this);
    }
}
void Course::assignInstructor(Instructor* instructor) {
    if (instructorCount<MAX_INSTRUCTORS) {
        instructors[instructorCount++]=instructor;}}

void Course::display() {
    cout<<"Course: \""<<title<<"\""<<endl;

    cout<<"Instructor(s): ";
    for (int i=0; i<instructorCount; i++) {
        cout<<instructors[i]->name;
        if (i!=instructorCount-1) cout<<", ";
    }
    cout << endl;

    cout<<"Enrolled Student(s): ";
    for (int i=0; i<studentCount; i++) {
        cout<<students[i]->name;
        if (i!=studentCount-1) cout<<", ";
    }
    cout << endl;
}

void Student::display() {
    cout<<"Student: "<<name<<endl;
    cout<<"Enrolled Courses: ";
    
    if (enrolledCount==0) {
        cout<<"None";
    } else {
        for (int i=0; i<enrolledCount; i++) {
            if (enrolledCourses[i]) {  
                cout<<"\""<<enrolledCourses[i]->title<<"\"";
                if (i!=enrolledCount-1) cout<<", ";
            }  } }
    
    cout<<endl;
}
Student students[MAX_STUDENTS];
Instructor instructors[MAX_INSTRUCTORS];
Course courses[MAX_COURSES];

int studentIndex=0, instructorIndex=0, courseIndex=0;

void registerStudent(string name, int id, string email) {
    if (studentIndex<MAX_STUDENTS) {
        students[studentIndex].name=name;
        students[studentIndex].id=id;
        students[studentIndex].email=email;
        studentIndex++;
    }
}

void registerInstructor(string name, int id, string expertise) {
    if (instructorIndex < MAX_INSTRUCTORS) {
        instructors[instructorIndex].name=name;
        instructors[instructorIndex].id=id;
        instructors[instructorIndex].expertise=expertise;
        instructorIndex++;
    }
}

void createCourse(string title, string code, string description) {
    if (courseIndex < MAX_COURSES) {
        courses[courseIndex].title=title;
        courses[courseIndex].code=code;
        courses[courseIndex].description=description;
        courseIndex++;
    }
}

Student* findStudent(string name) {
    for (int i=0; i<studentIndex; i++) {
        if (students[i].name==name) return &students[i];
    }
    return nullptr;
}

Instructor* findInstructor(string name) {
    for (int i=0; i<instructorIndex; i++) {
        if (instructors[i].name==name) return &instructors[i];
    }
    return nullptr;
}

Course* findCourse(string title) {
    for (int i=0; i<courseIndex; i++) {
        if (courses[i].title==title) return &courses[i];
    }
    return nullptr;
}

int main() {
    registerStudent("Salman", 101, "salman@nazi.com");
    registerStudent("Hamna", 102, "hamna@nazi.com");
    registerStudent("Ahmed", 103, "ahmed@nazi.com");

    registerInstructor("Dr. Naveed", 201, "OOP");
    registerInstructor("Dr. Nouman", 202, "PF");

    createCourse("Intro to SE", "SE101", "Basics of SE");
    createCourse("Python", "PY101", "Introductory Python");

    
    Course* pythonCourse=findCourse("Python");
    Course* seCourse=findCourse("Intro to SE");

    if (pythonCourse && seCourse) {
        pythonCourse->enrollStudent(findStudent("Hamna"));
        pythonCourse->enrollStudent(findStudent("Ahmed"));
        seCourse->enrollStudent(findStudent("Salman"));
        seCourse->enrollStudent(findStudent("Hamna"));
        seCourse->assignInstructor(findInstructor("Dr. Naveed"));
        seCourse->assignInstructor(findInstructor("Dr. Nouman"));
    } else {
        cout<<"Error: One or more courses not found." << endl; }

    cout <<endl;
    seCourse->display();
    cout<<endl;
    findStudent("Hamna")->display();

    return 0;
}