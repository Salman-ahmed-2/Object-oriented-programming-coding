#include<iostream>
#include<string.h>
using namespace std;


int student (int students[],int size,int index){
	if(index==size) return 0;
	return 1+student(students,size,index+1);
}
int main(){



int index=0;
int students[9]={1,1,1,1,1,1,1,1,1};
int size=sizeof(students)/sizeof(students[0]);
cout<<"number of students behind you:";
cin>>index;
cout<<student(students,size,index);

}

