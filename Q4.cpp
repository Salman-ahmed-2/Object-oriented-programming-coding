// salman ahmed khan
// i243004
//section c

#include<iostream>
#include<string.h>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <windows.h>

using namespace std;


//prototype

void addvalues(int **,int,int);
void showarray(int **,int,int);
void play(int **, int ,int);
void choice(int **,int ,int);
bool canMove(int **, int ,int );
void color();
void deleteLastLine();
void input_validation( int &);

//constants
int prow,pcol;
int index;

int main()
{
    int row,col;index=0;
    row:
    cout<<"------->Select row ";
    input_validation( row); 
    if (row<1) goto row;
    col:
    cout<<endl<<"------->select column ";
    input_validation( col);
    if (col<1) goto col;
system("cls");


//allocate
int **A= new int*[row];
    for   (int i=0; i < row; i++) {
        A[i] = new int[col]; }
        addvalues(A,row,col);
         play( A, row,col);

         // de allocated memory

         for (int i=0; i<row; i++)
    delete[] A[i];
delete[] A;

}
void addvalues(int **array,int row,int col){


srand(time(NULL));
add:
    for(int i=0;i<row;i++)
    {

        
         for(int j=0;j<col;j++)
{
      int z=-1+rand()%(1-(-1)+1);
array[i][j]=z;
          
          
          
} 

} if(array[0][0]==-1) goto add;
}
void showarray(int **array, int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (array[i][j]==8) {
                cout<< "\033[31m"<<setw(5)<<array[i][j]<<"\033[0m "; // Red color
            } else {
                cout<<setw(5) <<array[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}



void play(int **A, int row,int col)
{
    showarray(A,row,col);

// select:
//     cout<<"                             select row and column to start:" <<endl;
//     row:
//     cout<<" ------->start row (0-"<<row-1<<") : " ;
//     input_validation( prow);   if(prow<0||prow>=row) { deleteLastLine(); goto row;}
//     col:
//     cout<<"------->start column (0-"<<row-1<<") : ";
//     input_validation( pcol);   if(pcol<0||pcol>=col)  { deleteLastLine(); goto col;}
//     if(A[prow][pcol]==-1)  {  deleteLastLine(); deleteLastLine();
//         cout<<"Invalid choice"<<endl;
//         cout<<"-------------->select  0 or 1 point<------------"<<endl;
//     goto select;}


    A[0][0]=8;// start point
    
    choice(A,row,col);

}

void choice(int **A,int row,int col){

    while(true)

    {

        system("cls");
        color();
        showarray(A,row,col);
    int choice;
    choice:


    if (!canMove(A, row, col)) {
        cout<<"No more moves!"<<endl;
        cout<<"Your score: "<<index<<endl;
        return;
    }

    
    cout<<"1. Up"<<endl;
    cout<<"2. Down"<<endl;
    cout<<"3. Left"<<endl;
    cout<<"4. Right"<<endl;
    cout<<"Enter choice"<<endl;
    input_validation( choice);

   
        if (choice==2&&prow+1<row&&(A[prow+1][pcol]==0||A[prow+1][pcol]==1))  //canmove
        {

        if (A[prow+1][pcol]==0||A[prow+1][pcol]==1)
          {  cout<<"correct move"<<endl; 
            prow++; 
             index++;
              A[prow][pcol]=8;}
     else
     
     {
        for(int i=0;i<5;i++)
            
            deleteLastLine();
            cout<<"Cannot move down :"<<endl;   
             goto choice; 
            }
            }

       else if(choice==1&&prow-1>=0&&(A[prow-1][pcol]==0||A[prow-1][pcol]==1)){

        if (A[prow-1][pcol]==0||A[prow-1][pcol]==1)
     { cout<<"correct move"<<endl; prow--;   index++; A[prow][pcol]=8;}
        else { for(int i=0;i<5;i++)  deleteLastLine();
            cout<<"Cannot move up"<<endl;    goto choice; }}

       else if(choice==4&&pcol+1 <col&&(A[prow][pcol+1]==0||A[prow][pcol+1]==1)){
        if (A[prow][pcol+1]==0||A[prow][pcol+1]==1)  {  cout<<"correct move"<<endl; pcol++; index++; A[prow][pcol]=8;}
        else {
            for(int i=0;i<5;i++)  deleteLastLine(); cout<<"Cannot move right"<<endl;    goto choice; }}

        else if(choice==3&&pcol-1>=0&&(A[prow][pcol-1]==0||A[prow][pcol-1]==1)){
        if (A[prow][pcol-1]==0||A[prow][pcol-1]==1)   { cout<<"correct move"<<endl; pcol--; index++;  A[prow][pcol]=8;}
        else {
            for(int i=0;i<5;i++)  deleteLastLine();
            
            cout<<"Cannot move left"<<endl;    goto choice; }}

        else 
        {for(int i=0;i<5;i++)  deleteLastLine();
            cout<<"Enter right choice"<<endl;
            continue;
        }
        
    
    }
}

bool canMove(int **A, int row, int col) {
    if (prow+1<row&& (A[prow+1][pcol]==0|| A[prow+1][pcol]==1)) return true;
    if (prow-1>=0&&(A[prow-1][pcol]==0||A[prow-1][pcol]==1)) return true;
    if (pcol+1<col&&(A[prow][pcol+1]==0 || A[prow][pcol+1]==1)) return true;
    if (pcol-1>=0&& (A[prow][pcol-1]==0||A[prow][pcol-1]==1)) return true;
    return false;
}

void color() {    // for color
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode=0;
    GetConsoleMode(hOut,&dwMode);
    SetConsoleMode(hOut,dwMode|ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void deleteLastLine() { //deleteLastLine
    cout<<"\033[A\33[2K\r";
}

void input_validation(int & num){
    while (!(cin>>num)) {
      cout<<"Invalid input----> Please enter a number: >";  
        cin.clear(); 
        cin.ignore(1000,'\n');
      
    }

}