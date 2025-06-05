#include<iostream>
#include<string>
using namespace std;

class Student {
private:
    string name;
    float gpa;
public:
    Student() {
        name="";
        gpa=0.0;
    }
    bool operator>(const Student& other) const {
        return this->gpa>other.gpa;
    }

    bool operator<(const Student& other) const {
        return this->gpa<other.gpa;
    }

    bool operator==(const Student& other) const {
        return this->gpa==other.gpa;
    }

    friend istream& operator>>(istream& in,Student& s);
    
    friend ostream& operator<<(ostream& out, const Student& s);
};


istream& operator>>(istream& in, Student& s) {
    cout<<"Enter student name: ";
    in>>s.name;
    cout<<"Enter GPA: ";
    in>>s.gpa;
    return in;
}


ostream& operator<<(ostream& out, const Student& s) {
    out<<"Name: "<<s.name << ", CGPA: "<<s.gpa;
    return out;
}
int main() {
    const int SIZE = 3; 
    Student students[SIZE];

    
    for (int i=0; i<SIZE; i++) {
        cout<<endl<<"Enter details for student "<<(i+1)<<":"<<endl;
        cin>>students[i];
    }

    
    cout<<endl<<"Student Information:"<<endl;
    for (int i=0; i<SIZE; i++) {
        cout<<students[i]<<endl;
    }
    Student topStudent=students[0];
    for (int i=1; i<SIZE; i++) {
        if (students[i]>topStudent) {
            topStudent=students[i];
        }}

    cout<<endl<<"Student with highest GPA:"<<endl<<topStudent<<endl;
    return 0;
}

