#include<iostream>
using namespace std;
void symm(int arr[2][2]){
    if(arr[0][1]==arr[1][0]&&arr[0][0]==arr[1][1]){
        cout<<"Symmetric"<<endl;
    } else {
        cout<< "Not Symmetric"<<endl;}
}

int main(){
    int met[2][2];
    cout << "Enter row-wise elements of 2x2 matrix:" << endl;
    for(int i = 0; i<2; i++){
        for(int j=0; j<2; j++){
            cin>>met[i][j];}}
    symm(met);
    return 0;
}