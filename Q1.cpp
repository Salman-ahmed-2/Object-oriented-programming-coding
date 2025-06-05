#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(const string& name_input) : name(name_input) {
        cout<<"Person constructor called for "<<name<<endl;
    }
    virtual ~Person() {
        cout<<"Person destructor called for "<<name<<endl;
    }
    virtual void print() const {
        cout<<"Name: "<<name<<endl;
    }
};
class Student:public Person {
private:
    double gpa;
public:

    Student(const string& name_input, double gpa_input)
        : Person(name_input), gpa(gpa_input) {
        cout<<"Student constructor called for "<<name<<endl;
    }
    ~Student() override {
        cout<<"Student destructor called for "<<name<<endl;
    }
    void print() const override {
        Person::print(); 
        cout<<"GPA: "<<gpa<<endl;
    }
};


int main() {
    const int SIZE=4;
    Person* people[SIZE];
    people[0]=new Person("Alice");
    people[1]=new Student("Bob", 3.7);
    people[2]=new Person("Charlie");
    people[3]=new Student("Diana", 3.9);

    for (int i=0; i<SIZE; ++i) {
        cout<<endl<<"Object "<<i+1<<":"<<endl;
        people[i]->print();
}
    for (int i=0; i<SIZE; ++i) {
        delete people[i];
    }
    return 0;
}
