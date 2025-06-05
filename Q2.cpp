// salman ahmed khan
// i243004
//section c

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;


//structure
struct Election {
string name;
int votes;
float percent;
};

Election election[5];

// function prototype 
float percent(int , int );
int winner(Election election[],int );
void outputdata(Election election[],int,int);
void inputdata(Election election[],int &,int);
void validation(int &);


int main()
{
   int total=0;
   int totalcandiate;
   candiate:
   cout<<"Enter total Candiate: ";
   
   validation(totalcandiate);


   if(totalcandiate<1)  
   {system("cls"); 
    cout<<"Enter correct number:"<<endl; goto candiate;
}

    system("cls");


    //calling function
    inputdata(election, total,totalcandiate);
    outputdata(election,total,totalcandiate);
    return 0;
}

float percent(int total,int votes){
    return (votes*100.0)/total;
}

int winner(Election election[],int totalcandiate){
    int winner=election[0].votes;
    int win;
    for (int i=1; i <totalcandiate; i++)
    {
     if (winner<election[i].votes){
     winner=election[i].votes; 
     win=i;}
    }
    return win;
 }

 void outputdata(Election election[],int total,int totalcandiate){
     
cout<<"Name of Candidate     Votes Received     % of Total Votes"<<endl;
    for(int i=0;i<totalcandiate;i++)

    {
        
        cout<<setw(10)<<"      "<<election[i].name;
        
        cout<<"     ";
        cout<<setw(10)<<election[i].votes;
        cout<<"     ";
        election[i].percent=percent(total, election[i].votes);
        cout<<setw(19)<<setprecision(3)<<election[i].percent<<"%";
        cout<<endl;
}


cout<<endl<<endl<<"           Winner is "<<election[winner(election,totalcandiate)].name;
}


void inputdata(Election election[],int& total, int totalcandiate){

    for(int i=0;i<totalcandiate;i++)
    
    {
        cout<<"Candidate "<<i+1<<" Details:"<<endl;
        cout<<"Enter name: ";
       // getline(cin,election[i].name);
        cin>>election[i].name; 
        vote:
        cout<<"Enter votes: ";
        validation(election[i].votes); 
        if(election[i].votes>= 0) cout<<" ";  else {cout<<"Enter valid input:"<<endl; goto vote;}
        system("cls");
        
    }
    for(int i=0;i<totalcandiate;i++)
    
    {
        total=total+election[i].votes;
    }
    }

    void validation(int & num){
        while (!(cin>>num)) {
          cout<<"-------------->Invalid input. Please enter a number:";  
            cin.clear(); 
            cin.ignore(1000,'\n');
          
        }
    }