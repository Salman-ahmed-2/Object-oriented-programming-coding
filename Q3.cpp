// salman ahmed khan
// i243004
//section c

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;



//constants
int row;
int col;
string space;  // space is string having enter as value


//prototype
void showarray(int **);
void showarrays(int **, int **, int **);
void addvalues(int **);
void choice(int **,int ** ,int **);
int  equality(int **, int **,int **);
void CheckEqualSumArrays(int ** ,int ** , int **);
void CheckDifferentArrays(int **, int ** , int **);
void CheckEqualArrays(int **, int **, int **);
bool samerow(int **);
void FindSameRows(int ** , int ** , int **);
void RotateArrays(int ** , int ** , int ** );
void rotatearray(int **);
void input_validation(int &);


int main()
{

// taking row and col 
      row:  cout<<"                              Enter rows of matrix:";     input_validation(row);      if (row<1)   goto row;
      col:  cout<<"                              Enter columns of matrix:";    input_validation(col);    if (col<1)   goto col;

    int index=0;


    // allocate
    int **A1= new int*[row];
    for   (int i=0; i < row; i++) {
        A1[i] = new int[col]; }
        int **A2= new int*[row];
    for   (int i=0; i < row; i++) {
        A2[i] = new int[col]; }
        int **A3= new int*[row];
    for   (int i=0; i < row; i++) {
        A3[i] = new int[col]; }

      
        cout<<"                            Enter values of A1"<<endl;
        addvalues(A1);
        cout<<"                            Enter values of A2"<<endl;
        addvalues(A2);
        cout<<"                            Enter values of A3"<<endl;
        addvalues(A3);
        choice(A1, A2,A3);
        

        //deallocate
        for   (int i=0; i<row; i++) {
            delete[] A1[i];}
           delete[] A1;


           for   (int i=0; i <row; i++) {
            delete[] A2[i];}
           delete[] A2;


           for   (int i=0; i<row; i++) {
            delete[] A3[i];}
           delete[] A3;
 
    return 0;
}


void showarray(int **array)  //part of mainn
{
    for(int i=0;i<row;i++)
    {
        
         for(int j=0;j<col;j++)
{

cout<<setw(5)<<*(*(array+i)+j)<<" ";
          
          
} cout<<endl;

}

}

void showarrays(int **A1, int **A2, int **A3){ // main
    cout<<"                           Array 1"<<endl<<endl<<endl;
    showarray(A1);
    cout<<"                           Array 2"<<endl<<endl<<endl;
    showarray(A2);
    cout<<"                           Array 3"<<endl<<endl<<endl;
    showarray(A3);
    cout<<"press enter to continue";
    cin.ignore();
    getline(cin,space);
}

void addvalues(int **array){

    for(int i=0;i<row;i++)
    {
        
         for(int j=0;j<col;j++)
{
cout<<"Enter value of A["<<i<<"]"<<"["<<j<<"]: ";

input_validation(*(*(array+i)+j));
          
          
} 

}}


void choice(int **A1,int ** A2,int **A3)
{
    int choice;

    do{
        system("cls");
    choice:
   
   //manu
    cout<<"1. Check Equal Sum Array"<<endl;
    cout<<"2. Check Equal Difference Array"<<endl;
    cout<<"3. Equal Arrays"<<endl;
    cout<<"4. Rotate Arrays"<<endl;
    cout<<"5. Check same row in arrays"<<endl;
    cout<<"6. Show Arrays"<<endl;
    cout<<"7. Exit"<<endl;

    cout<<"Enter choice :";
     input_validation(choice);
    
    if(choice==1)
     CheckEqualSumArrays(A1 ,A2 , A3); 
    else if (choice==3)
    CheckEqualArrays(A1 ,A2, A3);
    else if(choice==2)
    CheckDifferentArrays(A1, A2 , A3 );
    else if(choice==4)
    RotateArrays(A1 , A2 ,A3 );
    else if (choice==5)
    FindSameRows(A1,A2,A3);
    else if (choice==6)
    showarrays(A1,A2,A3);
   
     else if (choice==7)
     return;
    else
    {
        cout<<"Enter a valid number"<<endl;
        goto choice;
    }
system("cls");}
    while(true);
}

int equality(int **a, int **b,int **c){

    int suma=0,sumb=0,sumc=0;  //      suma=sum of array a, sumb=sum of array b
    for (int i=0;i<row;i++)
    {
           
        for (int j=0;j<col;j++)
        {
          suma=suma+(*(*(a+i)+j));
          sumb=sumb+(*(*(b+i)+j));
          sumc=sumc+(*(*(c+i)+j));
                
        }
    }

    if       (suma+sumb==sumc) return 1; // return 1 means sum exists
    else if  ((suma-sumb==sumc)) return 2;// return 2 means difference exists
    else if ((suma==sumb)&&(sumb==sumc)) return 6; // return 6 means A1=A2=A3
    else if (suma==sumb) return 3; // return 3 means A1=A2
    else if (sumc==sumb) return 4; // return 4 means A3=A2
    else if (suma==sumc) return 5; // return 5 means A1=A3
   
   else return 0; 

}

void CheckEqualSumArrays(int **A1 ,int **A2 , int **A3){

    
 if(equality(A1,A2,A3)==1)
   cout<<"Sum of A1 and A2 is equal to A3"<<endl;
   else 
   cout<<"Sum of A1 and A2 is not equal to A3"<<endl;


   cout<<"Press enter to continue";
   cin.ignore();
   getline(cin,space);   // space is string having enter as value, by using system cls , result of function clears , result will stay unless enter 
      system("cls");
}


void CheckDifferentArrays(int **A1, int **A2 , int **A3 ){
 
    if(equality(A1,A2,A3)==2)
    cout<<"Difference of A1 and A2 is equal to A3"<<endl;
    else
    cout<<"Difference of A1 and A2 is not equal to A3"<<endl;


   cout<<"Press enter to continue";
   cin.ignore();
   getline(cin,space);  
   system("cls"); 
  // space is string having enter as value, by using system cls , result of function clears , result will stay unless enter 
}
void CheckEqualArrays(int **A1 , int **A2, int **A3){

    int result = equality(A1, A2, A3);

    if ((result==6))
    cout<<"A1 , A2 , A3 are equal"<<endl;
    else if ((result==3))
    cout<<"A1 , A2  are equal"<<endl;
    else if (result==4)
    cout<<"A2 , A3 are equal"<<endl;
    else if (result==5)
    cout<<"A1 , A3 are equal"<<endl;

    else {
        cout<<"None are equal"<<endl;
    }

    cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,space); system("cls"); // space is string having enter as value, by using system cls , result of function clears , result will stay unless enter 
}

bool samerow(int **array){
    int a=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++){
        if((*(*(array+i)+0)==*(*(array+i)+(j))))    a++;}
        if(a==col){cout<<"Row "<<i+1<<" elements are equal:"<<endl;} else {cout<<"Row "<<i+1<<" elements are not equal:"<<endl;}
a=0;
    }
    return 0;

}
void FindSameRows(int **A1 , int **A2 , int **A3){

   cout<<"------------------------------------------------> A1 <---------------------------------"<<endl; samerow(A1);
   cout<<"------------------------------------------------> A2 <---------------------------------"<<endl; samerow(A2);
   cout<<"------------------------------------------------> A3 <---------------------------------"<<endl; samerow(A3);

    cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,space);  system("cls"); // space is string having enter as value ,by using system cls , result of function clears , result will stay unless enter 
}
void rotatearray(int **array){// part of main
    
    
    int **sum= new int*[col];
    for   (int i=0; i < col; i++) {
        sum[i] = new int[row]; }

        
            for(int j=0;j<row;j++)
            {
                for(int k=0;k<col;k++)
                {
                    *(*(sum+j)+k)=*(*(array+k)+j);//transpose
                }
            }
            
            for (int i =0; i <row; i++) {
                for (int j=0, k=row- 1; j<k; j++, k--) 
                    swap((*(*(sum+i)+j)), (*(*(sum+i)+k)));

                    
                }

showarray(sum);

}
void RotateArrays(int **A1 , int **A2 , int **A3 ){ // main

system("cls");
showarrays(A1, A2, A3);
    cout<<endl<<endl<<endl<<"                       Rotated Array 1"<<endl<<endl<<endl;
    rotatearray(A1);
    cout<<endl<<endl<<endl<<"                       Rotated Array 2"<<endl<<endl<<endl;
    rotatearray(A2);
    cout<<endl<<endl<<endl<<"                       Rotated Array 3"<<endl<<endl<<endl;
    rotatearray(A3);

    cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,space); // space is string having enter as value
}

void input_validation(int & num){
    while (!(cin>>num)) {
      cout<<"                      Invalid input. Please enter a number:";  
        cin.clear(); 
        cin.ignore(1000,'\n');
      
    }
}