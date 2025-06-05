#include <iostream>
#include <string>

using namespace std;


const double labweight=0.7;
const double testweight=0.3;


struct Student {
    string name;
    int id;
    double labscore;
    double testscore;
    char grade;
};


char Grade(double labscore, double testscore) {
    double total = (labscore*labweight)+(testscore*testweight);
    if (total>=90) return 'A';
    else if (total>=80) return'B';
    else if (total>=70) return'C';
    else if (total>=60) return'D';
    else return 'F';
}


void input
(Student students[], int size) {
	cout<<"Enter detail of students"<<endl;
    for (int i=0; i<size; i++) {
    	
        cout<<"Enter details for student "<<(i+1)<<":"<<endl;
        cout<<"ID: "; cin>>students[i].id; 
        cout<<"Name: "; cin.ignore(); getline(cin, students[i].name);
        cout<<"Lab Score: "; cin>>students[i].labscore;
        cout<<"Test Score: "; cin>>students[i].testscore;
        students[i].grade=Grade(students[i].labscore, students[i].testscore);
    }
}


void display(const Student students[], int size) {
    
    for (int i=0; i<size; i++) {
    	cout<<"------------Detail of student"<<i+1<<"-------------"<<endl;
        cout<<"ID"<<students[i].id<<endl;
		cout<<"Name:"<<students[i].name<<endl;
		cout<<"Lab Score: "<<students[i].labscore<<endl;
        cout<<"Test Score:"<<students[i].testscore<<endl;
		cout<<"Grade:"<<students[i].grade<<endl;
    }
}

int main() {
    const int total=5;
    Student students[total];
    
   
    input(students, total);
    
    
    display(students, total);

    return 0;
}

