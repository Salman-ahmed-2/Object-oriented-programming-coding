#include <iostream> 
  using namespace std; 
 

 void movediscs(int number_of_disc, int fromPeg, int toPeg, int TEMP) 
 { 
 if (number_of_disc>0) 
 { 
 movediscs(number_of_disc-1, fromPeg, TEMP, toPeg); 
 cout << "move a disc from peg "<<fromPeg <<" to peg "<<toPeg<<endl; 
 movediscs(number_of_disc- 1, TEMP, toPeg, fromPeg); 
 } 
 } 
 int main() 
 { 
 const int number_of_disc=3; 
 const int fromPeg=1; 
 const int toPeg=3; 
 const int TEMP=2;  


 movediscs(number_of_disc, fromPeg,toPeg,TEMP); 
 cout<<"all the pegs are moved"<<endl; 
return 0; 
 } 
