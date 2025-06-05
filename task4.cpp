#include<iostream>
#include<string.h>
using namespace std;

bool LinearSearch(char array[],char find, int size){
	if (size<0){
		cout<<" not exist";
		return 0;
	}
	if(array[size]==find)
	{
		
		return 1;
	}

		
		return  LinearSearch( array, find, size-1);
}

int main(){

char array[11]={"unfriendly"};

 LinearSearch(array, 'e', 11);
 LinearSearch( array, 'l', 11);
 LinearSearch( array, 'f', 11);
if(LinearSearch(array, 'e', 11)&&LinearSearch( array, 'l', 11)&&LinearSearch( array, 'f', 11))
cout<<" word is elfish";
else 
cout<<"not elfisf";
}

