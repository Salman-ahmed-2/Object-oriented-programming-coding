
#include <iostream>
#include <cstdlib>
using namespace std;
struct customer {
    string name;
    int room;
    string indate,outdate;
};
int main() {
   customer customer;
   
   
       cout<<"Customer name:"<<endl;
       getline(cin,customer.name);
       cout<<"Customer room number:"<<endl;
       cin>> customer.room;
      
       cout<<"Check in detail:"<<endl;
       getline(cin,customer.indate);
      
       cout<<"Check out detail:"<<endl;
       getline(cin,customer.outdate);
       system("cls");
       
   cout<<"Customer details "<<endl;
    cout<<"Customer name :"<<customer.name<<endl;
     cout<<"Customer room :"<<customer.room<<endl;
      cout<<"Customer check in date :"<<customer.indate<<endl;
       cout<<"Customer check in date: "<<customer.outdate<<endl;
 
   
}