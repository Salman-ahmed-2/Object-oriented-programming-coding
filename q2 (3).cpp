
#include <iostream>
#include <cstdlib>
using namespace std;
struct traffic {
    string signal;
    int vehicle;
    string intersection;
};
int main() {
   traffic traffic;
   
   
       cout<<"Intersection :"<<endl;
       getline(cin,traffic.intersection);
       cout<<"Vehicle :"<<endl;
       cin>> traffic.vehicle;
       
       cin.ignore();
       cout<<"Signal colour :"<<endl;
       getline(cin,traffic.signal);
       system("cls");
       
   cout<<"Traffic details"<<endl;
    cout<<"Intersection :"<<traffic.intersection<<endl;
     cout<<"Vehicle:"<<traffic.vehicle<<endl;
      cout<<"Signal colour :"<<traffic.signal<<endl;
     
 
   
}