// salman ahmed khan
// i243004
//section c

#include<iostream>
#include<cstdlib>
using namespace std;

//prototype
void checkseat(char **,int , int );
void bookseat (int , int  , char **);
void choice   (int  , int ,char** );
void validation(int &);
void deleteLastLine();
bool allseatbook(int ,int ,char **);

//constant
string space;



int main()
{
    char a=65; int totalrows;
    totalrow:
    cout<<"                                   Enter rows(1 to 10) : ";
   
 validation(totalrows);
    if(totalrows<1||totalrows>10) { system("cls");
        cout<<"Incorrect Input"<<endl;
        goto totalrow;  }
    else system("cls"); 
    int row=totalrows,col=4;

    //allocate
    char **seats= new char*[row];
    for   (int i=0; i < row; i++) {
        seats[i] = new char[col]; }

    for(int i=0;i<row;i++)
    {
        
         for(int j=0;j<col;j++)
{

seats[i][j]=a;       //   ascII
        a++;  
          
} 
a=a-4;
 }

choice (row , col,seats);

// de allocated memory

for   (int i=0; i < row; i++) {
         delete[] seats[i];}
        delete[] seats;
}

void checkseat(char **seats,int row , int col){
    for(int i=0;i<row;i++)
    {
        cout<<i+1<<" ";
         for(int j=0;j<col;j++)
{

cout<<seats[i][j]<<" ";
          
          
} cout<<endl;

    }
}


void bookseat(int row, int col , char **seats){
    
    cout<<"                                        [ X ] means booked   "<<endl;
   
    checkseat(seats,row,col);
    int a; char b;
    book:
    
    cout<<"------------------------------------>  Book seat <-------------------------  "<<endl<<endl;
    
    row:
    cout<<"                                        Enter row : ";
   
    validation(a); a--;
     if(a>=0&&a<row) cout<<""; 
    else {  deleteLastLine();cout<<"! Enter correct row"; a=0; goto row;}
col:
    
    cout<<"                                        Enter Column ( Either in numbers or alphaphat ) : ";
    
    cin>>b;
    
    
    if(b=='A'|| b=='B' || b=='C'||b=='D') {
    int c=b-65;
    if(b>=65&&b<65+col) cout<<" "; 
    else {  deleteLastLine();cout<<"! Enter correct column"<<endl;
    goto col;}
    if(seats[a][c]=='X') { cout<<"!!!!!!!!!!!  Seat already booked"<<endl; 
    goto book;}
    else
    {seats[a][c]='X';
     
     cout<<"------------------------------------->Seat Booked :) "<<endl;
                       }
    }
else if (b=='a'|| b=='b' || b=='c'||b=='d')
{
    int c=b-97;
    if(b>=97&&b<97+col) cout<<" "; 
    else {cout<<"! Enter correct column"<<endl;
    goto col;}
    if(seats[a][c]=='X') { cout<<"!!!!!!!!!!!!! Seat already booked"; 
    goto book;}
    else
    {seats[a][c]='X';
        
        cout<<endl<<endl<<"---------------------------------->Seat Booked :) "<<endl;
               }
}
else if (b>48&&b<53){
    int c=b-49;
if(seats[a][c]=='X') { cout<<"!!!!!!!!!! Seat already booked"; 
    goto book;}
    else
    {seats[a][c]='X';
        
        cout<<"---------------------------------->Seat Booked  "<<endl;
               }
    }

    else {cout<<"!Enter correct column "<<endl;
        goto col;}

         
}


    void choice (int row , int col,char** seats){
        while(true){
            system("cls");
        int choice;
        choice:
        
        cout<<"                                 Bus seats managment system "<<endl;
        
        cout<<"1. Book a seat "<<endl;
        cout<<"2. check seats"<<endl;
        cout<<"3. exit "<<endl;
        cout<<"Enter choice :";
        
        validation(choice);
        if(choice==1)
       {if(allseatbook(row,col,seats)) {
        cout<<"!!!!  All seats are booked: " <<endl;
       
        
        return; }
          else bookseat(row,col,seats);}
        else if (choice==3)
        return;
        else if(choice==2)
       {system("cls"); checkseat(seats,row,col);}
        else
        {   system("cls");
            cout<<"! Enter a valid number"<<endl;
            goto choice;
        }
            
        }
    }
void validation(int &num){
    while (!(cin>>num)) {
        cout<<"! Invalid input. Please enter a number:"; 
        cin.clear(); 
        cin.ignore(1000,'\n');
      
    }}
    void deleteLastLine() {  //deleteLastLine
        cout<<"\033[A\33[2K\r";
    }

   bool allseatbook(int row,int col,char ** seats) //incase all bus is booked
   {
    int index=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(seats[i][j]=='X') index++;
        }
    }
    if(index==row*col) return 1;
    else return 0;
   } 