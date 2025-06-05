
#include<iostream>
#include<string.h>
using namespace std;

void modifyPointer(string* &address) {
    address = new string("new office"); 
}
int main() {
    string *address = new string("old office"); 
    cout << "Before modifying the pointer: " << *address << endl;
    modifyPointer(address);
    
    cout << "Value at pointer: " << *address << endl;
    delete address;
    return 0;}
