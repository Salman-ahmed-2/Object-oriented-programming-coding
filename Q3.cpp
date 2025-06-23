
#include <iostream>
#include <cstdlib>
using namespace std;
const int max_item=5;
struct  shop {
    string name[max_item];
    string id[max_item],price[max_item],quantity[max_item];
    
};
int main() {
   shop shop;
   
   for (int i=0;i<max_item;i++){
       cout<<"Item "<<i+1<<" detail"<<endl;
       cout<<"Item name :"<<endl;
       getline(cin,shop.name[i]);
       cout<<"Item ID :"<<endl;
       getline(cin,shop.id[i]);
       
       cout<<"Item price :"<<endl;
      getline(cin,shop.price[i]);
      cout<<"Item quantity :"<<endl;
      getline(cin,shop.price[i]);
        system("cls");
   }
       system("cls");
       

       for (int i=0;i<max_item;i++){
   cout<<"Items "<<i+1<<" details"<<endl;
    cout<<"Item name :"<<shop.name[i]<<endl;
     cout<<"ID:"<<shop.id[i]<<endl;
      cout<<"Quantity :"<<shop.quantity[i]<<endl;
       cout<<"Price :"<<shop.price[i]<<endl;
       }
 
   
}