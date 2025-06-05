#include<iostream>
#include<string.h>
using namespace std;





using namespace std;

int checkascending(int* array, int total)
{
    if (total<0)
    {
        return 1;
    }
    if (array[total]>array[total-1])
    {
        return checkascending(array, total-1);
    }
    if (array[total]<array[total-1])
    {
        return 0;
    }     
}
int Fibonacci(int n){

    if (n<=1){
        return n;
    }

    return Fibonacci(n-1) + Fibonacci(n-2);
}




bool firstoccurance(int array[],int start,int find,int total)


{
	if (start>total){
		cout<<" first occurance of number not exist ";
		return 0;
	}
	if(array[start]==find)
	{
		cout<<"first occurance exist at number exist at array["<<start<<"] ";
		return 1;
	}

		
		return firstoccurance( array, start+1 , find,total);
}


bool  lastoccurance(int array[],int total,int find)


{
	if (total<0){
		cout<<endl<<" last occurance of number not exist";
		return 0;
	}
	if(array[total]==find)
	{
		cout<<endl<<"last occurance of number exist at array["<<total<<"] ";
		return 1;
	}

		
		return  lastoccurance( array, find, total-1);
}

int main(){
	int find,start=0;
	cout<<" enter number to find ";
	cin>>find;
int array[10]={1,2,3,4,5,11,7,8,9,11};
int total=sizeof(array)/sizeof(array[0]);
firstoccurance( array, start , find,total);
lastoccurance( array, total , find);

if(checkascending(array, total))
cout<<endl<<"array is assending";
else 
cout<<endl<<" array not accending order";
int n;
cout<<endl<<"enter nth term to find fibaconni series";
cin>>n;
int result=Fibonacci(n);
    cout <<result<< endl;
}

