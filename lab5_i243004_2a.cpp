#include<iostream>
using namespace std;
int winner(int n,int i){
if(n==0) return i-1;
int divisor;
   cout<<"current  num "<<n<<endl;
   cout<<"Player";
       i%2==0?cout<<"2":cout<<"1";
     cout<<" enter a divisor ";
       cin>>divisor;
   if(n%divisor==0){
   i=winner(n-divisor,i+1); return i;
}return i;}



int main(){
	
int n,i=1;  
    cout<<"Enter Number: ";
    cin>>n;
      i=winner(n,i);
    if(i%2==0){
     cout<<"Player1 win";
     } else {
    cout<<"Player2 win";
}return 0;
}



