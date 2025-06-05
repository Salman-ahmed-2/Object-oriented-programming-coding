// salman ahmed khan
// i243004
// section c


#include<iostream>
#include<iomanip>
using namespace std;



// //prototype
void show(int **,int ,int*);
void addmarks(int **,int , int* );
void histogram(int **,int , int* );
void histogramofstudent(int **,int, int* );
void input_validation_histogram(int &);
void input_validation(int & );
void deleteLastLine();



//constants
string space;



int main()
{
    int students;
students:
    cout<<"------------------->Enter number of students:";
    input_validation(students);
    if(students<1){
    deleteLastLine();
    goto students;}
    cout<<endl;

    int *count=new int[100];  count[100]={0};
int **student=new int*[students];
for   (int i=0;i<students; i++) {
    student[i]=new int[100]; }


    //calling function
 addmarks(student, students, count);
//  show(student, students, count);
 histogram (student,students,count);
cout<<"Press Enter to exit ";
 cin.ignore();
 getline(cin,space);

 // de allocated memory
    for (int i=0; i<students; i++)
    delete[] student[i];
delete[] student;
delete[] count;
    return 0;
}



  



void addmarks(int **student,int students,int *count)
{
for (int i=0; i<students; i++) {
    cout<<"-------------------------------->Enter marks for student "<<i+1 <<"( Maximum marks = 100 ) (enter -1 to stop): "<<endl;
    count[i]=0;

    while (true) {
     
        int mark;
        mark:
        input_validation(mark);
        if(mark<-1||mark>100) {deleteLastLine(); goto mark;}


        //    incase TA objects
        if((mark>0)&&(mark!=-1)&&(mark%10!=0)) {
            mark=((mark/10)+1); mark=mark*10;   
        
        } 
         

        if (mark==-1) 
            break; // Stops for this student

        if (mark<0) {
            cout<<"Invalid mark. Try again."<<endl;
            continue; }

        count[i]++;
        student[i][count[i]]=mark;
         
    }

    


system("cls");
cout<<"--------------------------->Marks recorded for student "<<i+1<<endl;
}
}



// void show(int **student,int students,int *count){
   
   
//     for (int i=0; i<students; i++) {
//         cout<<"Student "<<i+1<<": ";
//         cout<<endl<<"Marks entered:"<<endl;
//         for (int j=1; j<=count[i]; j++) {
//             cout<<student[i][j]<<" "<<endl;
//         }
//         cout<<endl;
//     }

// }


void histogram(int **student,int students,int *count){
    
  cout<<"------------------------------->To find histogram: ( Press enter) ";
  cin.ignore();
  getline(cin,space);
 system("cls");

  for(int i=0;i<students;i++)
  {
    cout<<"----------------------------->Histogram of student :"<<i+1<<endl;
    histogramofstudent(student,i,count);
  }
   

    }

   
    void histogramofstudent(int **student, int student_number, int *count) {
        int mark=0;
        int *compare=new int[count[student_number]]; // Dynamic array for unique mark
        for (int i=0; i<count[student_number]; i++) {
            compare[i]=-1; // set with -1 
        }
         
        for (int j=1; j<=count[student_number]; j++) { 
             mark=student[student_number][j];
            int index=0;
           
            bool used=false;
            for (int i=0; i<count[student_number]; i++) {
                if (compare[i]==mark) {
                    used=true;
                    break;
                }
            }
            if (used) continue;
           
            // Count occurrences 
            for (int k=0; k<=count[student_number]; k++) {
                if (student[student_number][k]==mark) {
                    index++;
                }
            }
           
            
            compare[j]=mark;// prevent duplicate output , store in duplicate array
    
                   cout<<"Frequency of "<<mark<<" is: "<<index<<endl; 
        }
    
        delete[] compare; // de allocated memory
    }
    
      
   
    void input_validation(int & num){
        while (!(cin>>num)) {
          cout<<"Invalid input----> Please enter a number: >";  
            cin.clear(); 
            cin.ignore(1000,'\n');
          
        }

        
    
    }
    // void input_validation_histogram(int & num){
    //     while (!(cin>>num)) {
    //       cout<<"Invalid input----> Please enter a number: >";  
    //         cin.clear(); 
    //         cin.ignore(1000,'\n');
          
    //     }

        
    
    
    void deleteLastLine() {   //deleteLastLine
        cout<<"\033[A\33[2K\r";
    }

    