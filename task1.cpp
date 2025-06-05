#include<iostream>
#include<string.h>
using namespace std;

bool LinearSearch(int array[],int find, int size){
	if (size<0){
		cout<<" not exist";
		return 0;
	}
	if(array[size]==find)
	{
		cout<<"number exist at array["<<size<<"] ";
		return 1;
	}

		
		return  LinearSearch( array, find, size-1);
}
int main()
{
int size=10;
int array[size];

for (int i=0;i<size;i++){

cout<<"enter value if array["<<i<<"] ";
cin>>array[i];
cout<<endl;
}



int find;
cout<<"enter number to find ";
cin>>find;
 LinearSearch( array, find, size);

}
