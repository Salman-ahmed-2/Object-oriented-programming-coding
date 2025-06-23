#include <iostream>
using namespace std;

struct Course {
    string title,courseCode,semester;
    bool enrollment;
};
Course courses[100];
int n=0; 

void AddCourse() {
    if (n>=100) {
        cout<< "Cannot add more courses. The course list is full." << endl;
        return;
    }

    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, courses[n].title);
    cout << "Enter Course Code: ";
    getline(cin, courses[n].courseCode);
    cout << "Enter Semester: ";
    getline(cin, courses[n].semester);
    cout << "Enrollment Status (1 for Enrolled, 0 for Not Enrolled): ";
    cin >> courses[n].enrollment;
    cout << "Course added successfully!" << endl;
    n++;
}
void DisplayCourse(const Course &course) {
    cout<<"Course Code: "<<course.courseCode
        <<"Course Title: "<<course.title
         <<"Semester: " << course.semester
         <<"Enrollment Status:  "<<(course.enrollment ? "Enrolled":"Not Enrolled")<<endl;}
void SearchCourse(const string &code) {
    bool found = false;

    for (int i=0; i<n;i++) {
        if (courses[i].courseCode == code) {
            DisplayCourse(courses[i]);
            found=true; }
    }
    if (!found) {
        cout << "Course not found!" << endl;}
}

int main() {
    int input;
    string code;
    do {
        cout<<endl
             <<"Enter:"<<endl
             <<"1. Add Course"<<endl
             <<"2. Search Course"<<endl
             <<"3. Exit"<<endl
             <<"Choice: ";
        cin>>input;

        if (input==1) {
            AddCourse();} else if (input==2) {
            cout<<"Enter Course Code: ";
            cin.ignore();
            getline(cin, code);
            SearchCourse(code); } else if (input==3) {
            cout<<"Exiting program..."<<endl;} else {
            cout<<"Invalid input, please try again." << endl;}
} while (input!=3);

}
