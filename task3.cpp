#include<iostream>
#include<string.h>
using namespace std;

int gcd(int num1,int num2)
{
	
	if(num2==0){
	return num1;
	}
	{
	return gcd(num2,num1%num2);
	}
}
int main(){

int num1,num2;
cout<<"enter number 1  ";
cin>>num1;
cout<<endl;
cout<<"enter number 2   ";
cin>>num2;
cout<<endl;
cout<<"greatest common divisor is "<<gcd(num1,num2);
}

