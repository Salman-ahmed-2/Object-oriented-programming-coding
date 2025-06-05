#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
#include <sstream>
#include<cstdlib>
#include<ctime>
#include<string.h>
#include<cmath>
#define count 100
#define feature 3
#define max 10
#define max_geo 5    
#define max_sub 3
using namespace std;



                               //deallocation occured in 1139 and 659 , 470,1374,440,1370



//structs
struct Store;
struct GeoCoordinates;
struct Employee;
struct StoreAnalytics;
struct saleData;
struct Pridict;
struct Report;
struct Product;
struct Centroid;
struct SubCluster;
struct Cluster;





// structures
struct GeoCoordinates {
   
    double gLat;
    double gLong;
};


struct Employee {
   
    int eID;
    char * eName;
    double salary;
};

struct Products
{
   
    int pID;
    char* SKU;
    char* pName;
    string Date;
    string Time;
    double unitPrice;
    int numbersale;
    int unittime;
};

struct saleData
{

    int id;
    Products *product;
    double TotalSaleAmount;
    double profit;
    int saledata[24];
    
    
};

struct Store {

    char* sName;
    int sID;
    GeoCoordinates location;
    double sMonthlyCost;
    Employee Manager;
    Employee *Staff;
    
    saleData  sA;
    int customerCountMonthly[24];
    int numofemployee;
    int numofproduct;
    


// initializing all detail of a store raning from name of store to employees and products

void initialstore(Store &store, int i) {  


    int countempid=1; //employee id 

    int countproid=1; //product id

    
    // id
    store.sID=i+1;

    // store name
    string name="UrbanEase branch -> " + to_string(i+1);
    int len=name.length();
    
    store.sName=new char[len+1]; 
    for (int j=0; j<len; j++) { 
        store.sName[j]=name[j];
    }
    store.sName[len]='\0'; 

    // location
    double random1=(double)(rand()%1800)-9000;  
    store.location.gLat=random1/100;
    double random2=(double)(rand()%1800)-9000;  
    store.location.gLong=random2/100;

    // monthly cost
    double random3=(rand()%200000)+300000;
    store.sMonthlyCost=random3/10;

    // monthly revenue
    double random99=(rand()%9000000)+320000;
    store.sA.TotalSaleAmount=random99/10;

    //profitable
    store.sA.profit=store.sA.TotalSaleAmount-store.sMonthlyCost;

     // Manager Name
    char man_name[10][10]={ "Ali","Salman","Saad","Ahmed","Hamna","Areej","Fatima","Seneha","Areeb","Hassam"};
    int random5=rand()%10;

    int man_len=strlen(man_name[random5]);
    store.Manager.eName=new char[man_len+1]; 
   for (int j=0; j<man_len; j++) { 
        store.Manager.eName[j]=man_name[random5][j];
    }
    store.Manager.eName[man_len]='\0'; 

     //manager salery
     double random6=(rand()%1700000)+900000;
     store.Manager.salary=random6/100;

    //number of employee
    store.numofemployee=(rand()%4)+2;
    store.Staff=new Employee[store.numofemployee];

     //staff name
    for (int ii=0; ii<store.numofemployee; ii++) {
    char staff_name[10][10]={ "Ali" , "Asad" , "Sara" , "Ammar" , "Jake"  , "Arman" , "Osama" , "Laden" , "Hitler" , "Saddam" };
    int name2=rand()%10;
    int staff_len=strlen(staff_name[name2]);

    store.Staff[ii].eName=new char[staff_len+1]; 
    for (int j=0; j<staff_len; j++) { 
        store.Staff[ii].eName[j]=staff_name[name2][j];
    }
    store.Staff[ii].eName[staff_len]='\0'; 
    

    //staff id
    for(int ii=0 ; ii<store.numofemployee;ii++){
    store.Staff[ii].eID=countempid; 
     countempid++;
    }

    // salery
    for(int ii=0 ; ii<store.numofemployee;ii++){
    double random9=(rand()%170000)+90000;
    store.Staff[ii].salary=random9/100;
    }

    //number of prod
    store.numofproduct=rand()%(50)+35;
    store.sA.product=new Products[store.numofproduct];
    

    //product id
    for(int ii=0 ; ii<store.numofproduct;ii++){
    store.sA.product[ii].pID=countproid; 
    countproid++;
    }

    // product namme
    for(int ii=0 ; ii<store.numofproduct;ii++){


        char pro_name[10][10]={ "Shirt","jeans","Watch","Tie","Shoes","Cap","Watch","Burka","Abaya","Joggers"};
        int name3=rand()%10;
        int pro_len=strlen(pro_name[name3]);
        store.sA.product[ii].pName=new char[pro_len+1]; 
       for (int j=0; j<pro_len; j++) { 
            store.sA.product[ii].pName[j]=pro_name[name3][j];
        }
        store.sA.product[ii].pName[pro_len]='\0'; 
        store.sA.product[ii].unitPrice=((rand()%500000)+200000)/100;//prize
        store.sA.product[ii].unittime=(rand()%100)+50;//unit sell
        }

    //sale date
   
    for(int ii=0 ; ii<store.numofproduct;ii++){
        int day=(rand()%30)+1;
        int month=(rand()%12)+1;
        int year=(rand()%3)+2023;
    store.sA.product[ii].Date=to_string(day) +"-"+ to_string(month)+"-"+to_string(year);} 
    
      //time

for(int ii=0 ; ii<store.numofproduct;ii++){
    int hour=(rand()%23)+0;
int min=(rand()%59)+0;
    store.sA.product[ii].Time=to_string(hour)+" : "+to_string(min);}



for(int ii=23;ii>=0;ii--)
{
    if (ii==23)  store.sA.saledata[ii]=(rand()%500000)+520000;
    store.sA.saledata[ii]=(rand()%500000)+500000;
}
}
}};

struct Report{
    
    int *topstoreoverall;
    int *bottomstoreoverall;
    int *topstorebyrevenue;
    int *bottomstorebyrevenue;
    int *topstorebyprofit;
    int *bottomstorebyprofit;
    int *topstorebyprogress;
    int *bottomstorebyprogress;

};
struct Predict {
    
int future;
int past;
};

struct Centroid {
    double totalSales;
    double avgSalesPerDay;
    int numCustomers;
    double Euclidean;
};

struct SubCluster {
    char* subClusterID;
    char* subClusterName;
    Centroid subCenter;
   
};

struct Cluster {
    char* clusterID;
    char* clusterName;
    Centroid center;
    double centroid[max][feature];
   
    
};


//prototypes
void displaydata(const Store &store,int);
void displaydatastore(const Store &store,int);
void savedata(const Store &store);
void loaddata();
void clearfile(const string &filename);
void deleteLastLine();
void displaydata24(const Store &store,int);
void input_validations(float &);
void input_validation(int &);
string& getSpace();
double euclidean(double *A, double *B);       
double euclideanlolati(double *A, double *B);       
void clustering(Store *store);
double computedisc(double *A, double *B ,int dimen, bool check);
void assign(double **data, double **centroids, int *labels, int numPoints, int num_cluster, int dimen, bool isGeo);
void update(double **data, double **centroids, int *labels, int numPoints, int num_cluster, int dimen);
void k_mean(double **data, double **centroids, int *labels, int numPoints, int num_cluster, int dimen, bool isGeo);
void vizualize_cluster(int *labels, int numPoints, int numClusters, const char* title);
void ranking(Store *store,Report report);
void predicts(Store *store, Predict predict,Report report);
void visualization(Store *store,Cluster *cluster);
void deallocateStore(Store& store,int);


//main function 
int main() {

    Store *store=new Store[count];
    Cluster *cluster=new Cluster[count];

    Report report;
    Predict predict;
    
    
   srand(time(0));// for different random output at each run


int choice=0;
clearfile("stores.text"); //clear text file

for(int i=0;i<count;i++){
    store[i].initialstore(store[i],i);
    }

    for(int i=0;i<count;i++){
    savedata(store[i]);
    }

    while (true){   

    cout<<endl<<"|||||||||||||||||||||||||||||||||  Urban Ease Store Management  |||||||||||||||||||||||||||||||||||"<<endl<<endl;
    cout<<"1. Display All Stores Data"<<endl;
    cout<<"2. Display specific Stores Data"<<endl;
    cout<<"3. Display All Stores Sales Data"<<endl;
    cout<<"4. Display specific Stores Sales Data"<<endl;
    cout<<"5. Save Stores to File"<<endl;
    cout<<"6. Load Stores from File"<<endl;
    cout<<"7. Display All Stores Sales Data of last 24 months"<<endl;
    cout<<"8. Display specific Stores Sales Data of last 24 months"<<endl;
    cout<<"9. Perform Geographic Clustering"<<endl;
    cout<<"10. Rank Stores Based on Performance"<<endl;
    cout<<"11. Predict Next Month's Sales"<<endl;
    cout<<"12. Visualize Sales Trends (ASCII Graphs)"<<endl;
    cout<<"13. Exit"<<endl;
    cout<<"Enter your choice: "<<endl;

    input_validation(choice);
    

    if (choice<1||choice>13)  {system("cls"); continue;} //validation

if(choice==1){

    for(int i=0;i<count;i++){
        displaydatastore(store[i], i);
    } 
}
if(choice==2){  
   
    int select1;
    select2:
    cout<<"Enter a store to display"<<endl; 
    
    
    input_validation(select1);
    

    if(select1<=0||select1>count)   goto select2;
    select1--;
    displaydatastore(store[select1],select1); 
    
}
if(choice==3)
{ for(int i=0;i<count;i++){

     displaydata(store[i],i); }
 
}

if(choice==4){  
   
    int select;
    select:
cout<<"Enter a store to display sales data"<<endl; 
    
    
    input_validation(select);

    if(select<=0||select>count)   goto select;
    select--;
    displaydata(store[select],select); 

}
if(choice==5){
    clearfile("stores.text");
    for(int i=0;i<count;i++)
    
    {
        savedata(store[i]);
    }
        cout<<"Store data saved successfully!"<<endl;

    }
if(choice==6){  
    
    loaddata();
    cout<<endl<<"Loaded Stores Data:"<<endl;
   
    }
if(choice==7){   


{ 
    for(int i=0;i<count;i++){

         displaydata24(store[i],i); 
}
}
}
if(choice==8){
     
    int select8;
    select0:
cout<<"Enter a store to display sales data"<<endl; 
    
   input_validation(select8);

    if(select8<=0||select8>count)   goto select0;
    select8--;
    displaydata24(store[select8],select8);   
    
}

if(choice==9){


    clustering(store);
    
}
if (choice==10){

    ranking(store,report);
   
}

if (choice==11){

    predicts(store,predict,report);
  
}

if(choice==12){

    visualization(store,cluster);
}
if (choice==13){
    
    for(int i=0;i<count;i++){
     deallocateStore(store[i],i);}  delete[] store;
    return 0;
}
cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,getSpace());  
system("cls");
 }
 }



 //functions



// display info of products
void displaydata(const Store &store,int i) {

    cout<<endl<<"==========================================================================================================="<<endl;
    cout<<"=============================================  Store "<<i+1<<" Products Details  =========================================";
    cout<<endl<<"==========================================================================================================="<<endl;
   

    cout<<"---------------------------------------------- Products Details ----------------------------------------------"<<endl;
    cout<<"Number of products: "<<store.numofproduct<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------"<<endl;
    
    cout<<left << setw(10)<<"Product"<<setw(20)<<"Name:"<<setw(10)<<"ID:"<<setw(10)<<"Prize:"<<setw(15)<<"Unit Sell:"<<setw(20)<<"Sale date:"<<setw(10)<<"Time:" << endl;

        for (int ii = 0; ii < store.numofproduct; ii++) {
           cout<<left<<setw(10)<<ii+1<<setw(20)<<store.sA.product[ii].pName 
           <<setw(10)<<store.sA.product[ii].pID<<setw(10)<<
           store.sA.product[ii].unitPrice<<setw(15)<<
           store.sA.product[ii].unittime<<setw(20)<<
           store.sA.product[ii].Date<<setw(10)<<
           store.sA.product[ii].Time<<endl;
}}

//display function of stores
void displaydatastore(const Store &store,int i) {

    cout<<endl<<"==========================================================================================================="<<endl;
    cout<<"=============================================  Store "<<i+1<<" Details  ===========================================";
    cout<<endl<<"==========================================================================================================="<<endl;
    cout<<endl<<"Name: "<<store.sName <<endl;
    cout<<"ID: "<<store.sID;
    cout<<endl<<"Location: ("<<store.location.gLat<<","<<store.location.gLong<<")";
    cout<<endl<<"Average Total Revenue per month : $"<<store.sA.TotalSaleAmount;
    cout<<endl<<"Monthly Cost of store: $"<<store.sMonthlyCost;
    if(store.sA.profit>0)
    cout<<endl<<"Monthly Profit : $"<<store.sA.profit;
    else  cout<<endl<<"Monthly Loss : $"<<store.sA.profit*-1;

    cout<<endl<<"Manager: "<<store.Manager.eName <<endl;
    cout<<"Salary: $"<<store.Manager.salary<<endl;
    cout<<"-------------------------------------------- Employee Details ---------------------------------------------"<<endl;
    cout<<"Number of employees: "<<store.numofemployee<<endl;
    cout<<left<<setw(15)<<"Employee"<<setw(15)<<"Name"<<setw(10)<<"ID"<<setw(15)<<"Monthly Salary"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    
    for (int ii=0; ii<store.numofemployee; ii++) {
        cout<<left<<setw(15)<<("Employee "+to_string(ii+1))<<setw(15)<<store.Staff[ii].eName<<setw(10)<<store.Staff[ii].eID<<setw(15)<<store.Staff[ii].salary<<endl;
    }}

    void displaydata24(const Store &store,int i) {

        cout<<endl<<"==========================================================================================================="<<endl;
        cout<<"=============================================  Store "<<i+1<<" Sales Details  =========================================";
        cout<<endl<<"==========================================================================================================="<<endl;
       for(int j=0;j<24;j++)
       {
        cout<<"Month "<<j+1<<" Revenue "<<store.sA.saledata[j]<<endl;  
     
    }
    }    



//save data to text file
void savedata(const Store &store) {
    ofstream file("stores.txt", ios::app);  
    if (!file.is_open()) {
        cout<<"Error opening file for writing!" << endl;
        return;
    }

 // store
    file<<"------------------------------------"<<store.sName<<"------------------------"<<endl;
    file<<"Name                 "<<" Id "<<" Latitude "<<" longitude "<<" total renevue "<<" Monthly cost "<<" Profit "<<" Manager name "<<" Salery "<<endl;
    file <<store.sName<< "  "
         <<store.sID<<"  "<<store.location.gLat<<"           "
         <<store.location.gLong<<"     "<<"    "<<store.sA.TotalSaleAmount<<"     "
         <<store.sMonthlyCost<<"     "<<store.sA.profit<<"     "
         <<store.Manager.eName<<"     "
         <<store.Manager.salary<<endl<<endl;
         file<<"-------------------------------------------------------------------------------"<<endl;

    // employees
    file <<"Number of Employees :"<< store.numofemployee << endl;
    file<<"Name "<<" Id "<<" Salery "<<endl;
    for (int i=0; i<store.numofemployee; i++) {
        
        file<<store.Staff[i].eName<<"  "
            <<store.Staff[i].eID << "  "
            <<store.Staff[i].salary<<endl;
    }
    file<<"-------------------------------------------------------------------------------"<<endl;

    // products
    file<<"number of product :"<<store.numofproduct<<endl;
    file<<"  Name "<<" Id "<<" price "<<" quantity "<<" sale date "<<" sale time "<<endl;
    for (int i=0; i<store.numofproduct; i++) {
        
         file<<store.sA.product[i].pName<<"  "<<store.sA.product[i].pID<<"   "
             <<store.sA.product[i].unitPrice<<"     "<<store.sA.product[i].unittime<<"     "
             <<store.sA.product[i].Date<<"   "<<store.sA.product[i].Time<<endl;
    }

    file<<"---------------------------------------------------------------------------------------" << endl; 
    file.close();
}



//load dataa from text file as output
void loaddata() {
    ifstream file("stores.txt");
    if (!file.is_open()) {
       
        return;
    }

    
    string line;
   
    while (getline(file, line)) {
        cout<<setw(10)<<right<<line<<endl;
    }
    file.close();
}

//clear text file
void clearfile(const string &filename) {
    ofstream file(filename.c_str(), ios::trunc); // Open in truncate mode
    if (file.is_open()) {
        
        file.close();
    } else {
        cout << "Error opening file!" << endl;
    }
}

//deallocation of  store
void deallocateStore(Store& store, int i) {
  
    delete[] store.sName;
    store.sName=nullptr;


    delete[] store.Manager.eName;
    store.Manager.eName=nullptr;

    for (int i=0; i<store.numofemployee; i++) {
        delete[] store.Staff[i].eName;
        store.Staff[i].eName=nullptr;
    }
    delete[] store.Staff;
    store.Staff=nullptr;
   
    for (int i=0; i<store.numofproduct; i++) {
        delete[] store.sA.product[i].SKU;
        delete[] store.sA.product[i].pName;
        store.sA.product[i].SKU=nullptr;
        store.sA.product[i].pName=nullptr;
    }
    delete[] store.sA.product;
    store.sA.product=nullptr;


   

}



//deleteLastLine
void deleteLastLine() { 
    cout<<"\033[A\33[2K\r";
}


//input validation for integers
void input_validation(int & num){
    while (!(cin>>num)) 
{
        
        cin.clear(); 
        cin.ignore(1000,'\n');
      
}
}
//input validation for float
void input_validations(float & num){
    while (!(cin>>num)) {
       
        cin.clear(); 
        cin.ignore(1000,'\n');
      
    }
}
string& getSpace() {
    static string space=" "; //in order to avoid global variable
    return space;
}

//task 3


// rank of stores base upon its data
void ranking(Store* store,Report report){

    srand(time(0));// for different random output at each run
    Report *topstoreoverall=new Report[count];
    Report *bottomstoreoverall=new Report[count];
    Report *topstorebyrevenue=new Report[count];
    Report *bottomstorebyrevenue=new Report[count];
    Report *topstorebyprofit=new Report[count];
    Report *topstorebyprogress=new Report[count];
    Report *bottomstorebyprofit=new Report[count];
    Report *bottomstorebyprogress=new Report[count];
   
   
    int choice;


while(true){

    cout<<endl<<"||||||||||||||||||||||||||||||||| Store Ranking |||||||||||||||||||||||||||||||||||" << endl<<endl;
    cout<<"1. Top 10 Stores by Overall performance" << endl;
    cout<<"2. bottom 5 Stores by Overall performance"<<endl;
    cout<<"3. Top 10 Stores by Total Annual Profit" << endl;
    cout<<"4. bottom 5 Stores by Total Annual Profit"<<endl;
    cout<<"5. Top 10 Stores by Total Annual Sales" << endl;
    cout<<"6. bottom 5 Stores by Total Annual Sales"<<endl;
    cout<<"7. Top 10 Stores by Progress" << endl;
    cout<<"8. bottom 5 Stores by Progress"<<endl;
    cout<<"9. Exit"<<endl;
    cout<<"Enter choice: ";
    
    input_validation(choice);
    if (choice<1||choice>9)  continue; 


    int rank1[count], com[count];

   
    if (choice==1){
        for (int i=0; i<count; i++) {
            rank1[i]=store[i].sA.TotalSaleAmount;
            com[i]=i;
            
        }
        int temp,temp1;
        for (int i=0; i<count-1; i++) {
        for (int j=0; j<count-i-1; j++) {
        if (rank1[j]<rank1[j+1]) {
                    
        temp=rank1[j];
        rank1[j]=rank1[j+1];
        rank1[j+1]=temp;
    
        temp1=com[j];
        com[j]=com[j+1];
        com[j+1]=temp1;
                }
            }
        }
    
    
        for (int i=0; i<count; i++) {
            rank1[i]=store[i].sA.profit;
            
        }
        int ttemp,ttemp1;
        for (int i=0; i<count-1; i++) {
        for (int j=0; j<count-i-1; j++) {
        if (rank1[j]<rank1[j+1]) {
                    
        ttemp=rank1[j];
        rank1[j]=rank1[j+1];
        rank1[j+1]=ttemp;
    
       ttemp1=com[j];
       com[j]=com[j+1];
       com[j+1]=ttemp1;
                }
            }
        }
        // for (int i=0; i<count; i++) {
        //     report.topstorebyprofit[i]=store[com[i]].sID;
        // }
        cout<<endl<<"top 10 Stores by Overall performance:"<<endl;
        for (int i=0; i<10; i++) {
            cout<<i+1<<". Store ID: "<<store[com[i]].sID<<endl;
        }    }
    else if (choice==2){
        for (int i=0; i<count; i++) {
            rank1[i]=store[i].sMonthlyCost;
            com[i]=i+1;
        }
        for (int i=0; i<count-1; i++) {
            for (int j=0; j<count-i-1; j++) {
                if (rank1[j]<rank1[j+1]) {
                    
                    int temp=rank1[j];
                    rank1[j]=rank1[j + 1];
                    rank1[j+1]=temp;
    
                   int temp1=com[j];
                    com[j]=com[j+1];
                    com[j+1]=temp1;
                }
            }
        }
        // for (int i=0; i<5; i++) {
        //     report.bottomstorebyrevenue[i]=store[com[i]].sID;
        // }
    
    
    
        for (int i=0; i<count; i++) {
            rank1[i]=store[i].sA.profit;
            
        }
        for (int i=0; i<count-1; i++) {
            for (int j=0; j<count-i-1; j++) {
                if (rank1[j]<rank1[j+1]) {
                    
                    int temp=rank1[j];
                    rank1[j]=rank1[j + 1];
                    rank1[j+1]=temp;
    
                   int temp1=com[j];
                    com[j]=com[j+1];
                    com[j+1]=temp1;
            }}
        }
        // for (int i=0; i<count; i++) {
        //     report.bottomstorebyprofit[i]=store[com[i]].sID;
        // }
        cout<<endl<<"bottom  5 Stores by Overall performance:"<<endl;
        for (int i=0; i<5; i++) {
            cout<<i+1<<". Store ID: "<<store[com[i]].sID<<endl;
        }
    
    
    
    
    
     }
    

   else if (choice==5){
    for (int i=0; i<count; i++) {
        rank1[i]=store[i].sA.TotalSaleAmount;
        com[i]=i;
    }
    int temp,temp1;
    for (int i=0; i<count-1; i++) {
        for (int j=0; j<count-i-1; j++) {
            if (rank1[j]<rank1[j+1]) {
                
                temp=rank1[j];
                rank1[j]=rank1[j + 1];
                rank1[j+1]=temp;

                temp1=com[j];
                com[j]=com[j+1];
                com[j+1]=temp1;
            }
        }
    }
    // for (int i=0; i<count; i++) {
    //     report.topstorebyrevenue[i]=store[com[i]].sID;
    // }
    
    cout << endl<<"Top 10 Stores by Total Annual Sales"<<endl<<endl;
    for (int i=0; i<10; i++) {
        cout<<i+1<<". Store ID: "<<store[com[i]].sID<<" :::: Annual Revenue: "<<rank1[i]*12<<endl;
    }

    // for (int i = 0; i < count; i++) {
    //     rank1[i] = store[i].sMonthlyCost;
    //     com[i] = i;
    // }
}

   else if (choice==6){
    for (int i=0; i<count; i++) {
        rank1[i]=store[i].sMonthlyCost;
        com[i]=i;
    }
    int temp,temp1;
    for (int i=0; i<count-1; i++) {
        for (int j=0; j<count-i-1; j++) {
            if (rank1[j]>rank1[j+1]) {
                
        temp=rank1[j];
        rank1[j]=rank1[j+1];
        rank1[j+1]=temp;

        temp1=com[j];
        com[j]=com[j+1];
        com[j+1]=temp1;
            }
        }
    }
    // for (int i=0; i<5; i++) {
    //     report.bottomstorebyrevenue[i]=store[com[i]].sID;
    //}
    cout<<endl<<"bottom 5 Stores by Total Annual Sales:"<<endl<<endl;
    for (int i=0; i<5; i++) {
        cout<<i+1<<". Store ID: "<<store[com[i]].sID<<" :::: Annual Revenue: "<<rank1[i]*12<<endl;
    }
   }
   else if (choice==3){
        for (int i=0; i<count; i++) {
            rank1[i]=store[i].sA.profit;
            com[i]=i;
        }
        for (int i=0; i<count-1; i++) {
            for (int j=0; j<count-i-1; j++) {
                if (rank1[j]<rank1[j+1]) {
                    
             int temp=rank1[j];
            rank1[j]=rank1[j + 1];
            rank1[j+1]=temp;
    
            temp=com[j];
            com[j]=com[j+1];
            com[j+1]=temp;
                }
            }
        }
        // for (int i=0; i<10; i++) {
        //     report.topstorebyprofit[i]=store[com[i]].sID;
        // }
        cout<<endl<<"top 10 Stores by annual profit:"<<endl<<endl;
        for (int i=0; i<10; i++) {
            if (rank1[i]>0)
            cout<<i+1<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Profit: "<<rank1[i]*12<<endl;
            else cout<<i+1<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Loss: "<<rank1[i]*-12<<endl;
        }}
       else  if (choice==4){
            for (int i=0; i<count; i++) {
                rank1[i]=store[i].sA.profit;
                com[i]=i;
            }
            for (int i=0; i<count-1; i++) {
                for (int j=0; j<count-i-1; j++) {
                    if (rank1[j]>rank1[j+1]) {
                        
                int temp=rank1[j];
                rank1[j]=rank1[j+1];
                rank1[j+1]=temp;
        
                temp=com[j];
                com[j]=com[j+1];
                com[j+1]=temp;
                    }
                }
            }
            // for (int i=0; i<5; i++) {
            //     report.bottomstorebyprofit[i]=store[com[i]].sID;
            // }
            cout<<endl<<"Bottom 5 Stores by annual profit:"<<endl<<endl;
            for (int i=0; i<5; i++) {
              if(rank1[i]>0)  cout<<setw(10)<<i+1<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Profit: "<<rank1[i]*12<<endl;
              else cout<<setw(10)<<i+1<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Loss: "<<rank1[i]*-12<<endl;
            }
        


}


else if (choice==8){

    int progress[count];
    for (int i=0; i<count; i++) {
    progress[i]=store[i].sA.saledata[23]-store[i].sA.saledata[0];}
        for (int i=0; i<count; i++) {
                rank1[i]=progress[i];
                com[i]=i;
            }
            for (int i=0; i<count-1; i++) {
                for (int j=0; j<count-i-1; j++) {
                    if (rank1[j]>rank1[j+1]) {
                        
                int temp=rank1[j];
                rank1[j]=rank1[j + 1];
                rank1[j+1]=temp;
        
                temp=com[j];
                com[j]=com[j+1];
                com[j+1]=temp;
                    }
                }
            }
            // for (int i=0; i<5; i++) {
            //     report.bottomstorebyprogress[i]=store[com[i]].sID;
            // }
            cout<<endl<<"bottom 5 Stores by progress:"<<endl<<endl;
            for (int i=0; i<5; i++) {
                if(rank1[i]*12>0)
                cout<<setw(10)<<i+1<<setw(10)<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Profit: "<<rank1[i]*12<<endl;
                else 
                cout<<setw(10)<<i+1<<setw(10)<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual loss: "<<rank1[i]*-12<<endl;
            }}
         else   if (choice==7){

                int progress[count];
                for (int i=0; i<count; i++) {
                progress[i]=store[i].sA.saledata[23]-store[i].sA.saledata[0];}
                        for (int i=0; i<count; i++) {
                            rank1[i]=progress[i];
                            com[i]=i;
                        }
                        for (int i=0; i<count-1; i++) {
                            for (int j=0; j<count-i-1; j++) {
                                if (rank1[j]<rank1[j+1]) {
                                    
                            int temp=rank1[j];
                            rank1[j]=rank1[j + 1];
                            rank1[j+1]=temp;
                    
                            temp=com[j];
                            com[j]=com[j+1];
                            com[j+1]=temp;
                                }
                            }
                        }
                        // for (int i=0; i<10; i++) {
                        //     report.topstorebyprogress[i]=store[com[i]].sID;
                        // }
                        cout<<endl<<"top 10 Stores by progress:"<<endl<<endl;
                        for (int i=0; i<10; i++) {
                            if(rank1[i]*12>0)
                            cout<<i+1<<setw(10)<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual Profit: "<<rank1[i]*12<<endl;
                            else 
                            cout<<i+1<<setw(10)<<". Store ID: "<<store[com[i]].sID<<setw(10)<<" :::: Annual loss: "<<rank1[i]*-12<<endl;
                        }}
            

else if (choice==9)
{
    return;
}


    cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,getSpace());  
system("cls");
}


delete[] topstoreoverall;
delete[] bottomstoreoverall;
delete[] topstorebyrevenue;
delete[] bottomstorebyrevenue;
delete[] topstorebyprofit;
delete[] topstorebyprogress;
delete[] bottomstorebyprofit;
delete[] bottomstorebyprogress;
}







//cpp 4
//pridicts next month sale, future sale

void predicts(Store *store,Predict predict,Report report){



    cout<<endl<<"||||||||||||||||||||||||||||||||| Store Future Prediction |||||||||||||||||||||||||||||||||||" << endl<<endl;
        cout<<"  |||||||||||||||||||||||||||||||| Store prediction for next month |||||||||||||||||||||||||||||| "<< endl;
     


  

    int rank1[count], com[count];

    
                for (int i=0; i<count; i++) {
                    rank1[i]=store[i].sA.TotalSaleAmount;
                    com[i]=i;
                }
                for (int i=0; i<count-1; i++) {
                    for (int j=0; j<count-i-1; j++) {
                        if (rank1[j]<rank1[j+1]) {
                            
                            int temp=rank1[j];
                            rank1[j]=rank1[j + 1];
                            rank1[j+1]=temp;
            
                            temp=com[j];
                            com[j]=com[j+1];
                            com[j+1]=temp;
            }
            }
            }
                // for (int i=0; i<10; i++) {
                //     report.topstorebyprofit[i]=store[com[i]].sID;
                // }
                cout<<endl;
                for (int i=0; i<count; i++) {
                    int confidence=rand()%(100)+1;
                    cout<<i+1<<". Store ID: "<<store[i].sID<<" ====> Next month Sale Prediction : "
                    <<store[i].sA.TotalSaleAmount+(store[i].sA.profit*(0.1))   // 1 month revenue +10 %of profit
                    <<endl<<"                 ====> confidence level in prediction "<<confidence<<" %     "
                    <<endl;
                    if(store[i].sA.saledata[23]<store[i].sA.saledata[0])   
                     cout<<"                 ====>    Warning ! Special attention needed"<<endl;
                    cout<<endl;
            }
   
   
            }


//task 5
// show all data in term of bar graph
void visualization(Store *store,Cluster *cluster){

  
    int choice;

while(true){

    cout<<endl<<"||||||||||||||||||||||||||||||||| Store Ranking  Visualization |||||||||||||||||||||||||||||||||||"<<endl<<endl;
    cout<<"1. Monthly Sale Trend " <<endl;
    cout<<"2. Comparative store performance"<<endl;
    cout<<"3. Cluster wise store distribution"<<endl;
    cout<<"4. Pridict Sale trend" <<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter choice: ";
    input_validation(choice);
 

     if (choice<1||choice>5)  continue; //validation

     //Monthly Sale Trend
    if(choice==1)
    {
        for(int i=0;i<count;i++)
        { cout<<setw(10)<<"Store "<<i+1<<" ";
            int pre=store[i].sMonthlyCost/1000;
            for(int j=0;j<pre;j++)
            {
                cout<<"$";
               
    }cout<<endl;
    }
        cout<<endl<<"           $ = 10000 "<<endl;
    }
    //Comparative store performance
    else if(choice==2)
    {
        for(int i=0;i<count;i++)
        { cout<<setw(10)<<"Store "<<i+1<<" ";
            int pre=store[i].sA.TotalSaleAmount/1000;
            
            for(int j=0;j<pre;j++)
            {
                cout<<"$";
               
            }cout<<endl;

        }
        cout<<endl<<"           $ = 10000 "<<endl;

    }
    //Cluster wise store distribution
    else if(choice==3)
    {
        const int num_p=100;
        const int num_geo_cluster=5;  // For geographic clustering.
        const int numClustersSub=3;
   
        int *geo_l=new int[num_p];
        int *sub_l=new int[num_p];
    
        for (int i=0; i<num_p; i++) {
            geo_l[i]=i%num_geo_cluster;
        }
    
        for (int i=0 ;i<num_p; i++) {
            sub_l[i]=i%numClustersSub;
        }
    
        //clustering by location
        vizualize_cluster(geo_l, num_p, num_geo_cluster, "Geographic Clustering Distribution");
    
        // sub-clustering  by sale data
        vizualize_cluster(sub_l, num_p, numClustersSub, "Sales Sub-Clustering Distribution");
    

    }

    
    //exit
    else if(choice==5) return;
    //Pridict Sale trend
    else if ( choice==4){

        for(int i=0;i<count;i++)
        { cout<<setw(10)<<"Store "<<i+1<<" ";
            int pre=(store[i].sA.TotalSaleAmount+store[i].sA.profit)/1000;  // 1 month revenue +10 %of profit 
            
            for(int j=0;j<pre;j++)
            
    {
                cout<<"$";
               
    }cout<<endl;

    }
        cout<<endl<<"           $ = 10000 "<<endl;

    }

    //hold data
        cout<<"Press enter to continue";
    cin.ignore();
    getline(cin,getSpace()); 
    system("cls");
}

}


//task 2
// compute equidean distance 
double euclidean(double *A, double *B) {
    
    double sum=0.0;
    for (int i=0; i<feature; i++) {
        double diff=A[i]-B[i];
        sum=sum+(diff*diff);
    }
    return sqrt(sum);
}

double euclideanlolati(double *A, double *B) {
    
    double diff_lat=A[0]-B[0];
    double diff_long=A[1]-B[1];
    return sqrt((diff_lat*diff_lat)+(diff_long*diff_long));
}


double computedisc(double *A, double *B, int dimen, bool check) {
    if (check&&dimen==2) {
        return euclideanlolati(A,B);
    } else {
        return euclidean(A, B);
    }
}

void assign(double **data, double **centroids, int *labels, int num_p, int num_cluster, int dimen, bool check) {
    for (int i=0; i<num_p; i++) {
        double min_dis=1e9;  // Large initial value
        int best_c=-1;
        for (int j=0; j<num_cluster; j++) {
            double d=computedisc(data[i], centroids[j], dimen, check);
            if (d<min_dis) {
                min_dis=d;
                best_c=j;
    }
    }
        labels[i]=best_c;
    }
    }

void update(double **data, double **centroids, int *labels, int num_p, int num_cluster, int dimen) {
    
    double **sum=new double*[num_cluster];
    int *counts=new int[num_cluster];
    for (int i=0; i<num_cluster; i++) {
        sum[i]=new double[dimen];
        for (int j=0; j<dimen; j++) {
            sum[i][j]=0.0;
    }
        counts[i]=0;
    }
    
    for (int i=0; i<num_p; i++) {
        int cluster=labels[i];
        if (cluster>=0&& cluster<num_cluster) {
            for (int j=0; j<dimen; j++) {
                sum[cluster][j]=sum[cluster][j]+data[i][j];
    }
            counts[cluster]++;
    }
    }
    
    for (int i=0; i<num_cluster; i++) {
        if (counts[i]>0) {
            for (int j=0; j<dimen; j++) {
                centroids[i][j]=sum[i][j]/counts[i];
    }
    }
    }

    for (int i=0; i<num_cluster; i++)
    delete[] sum[i];
    delete[] sum;
    delete[] counts;
}


//explain k mean clustering assign each point to closest centeroid , update centeroid based on updated assignment and repeat
//until label stop changing , use an axillery array to track label 

void k_mean(double **data, double **centroids, int *labels, int num_points, int num_cluster, int dim, bool isGeo) {
    bool converged=false;
    int *old_label=new int[num_points];
    while (!converged) {
       
        for (int i=0; i<num_points; i++) {
            old_label[i]=labels[i];
        }
        assign(data, centroids, labels, num_points, num_cluster, dim, isGeo);
        update(data, centroids, labels, num_points, num_cluster, dim);

        converged=true;
        for (int i=0; i<num_points; i++) {
            if (old_label[i]!=labels[i]) {
                converged=false;
                break;
    }
    }
    }
    delete[] old_label;
}

//clustering function 
// perform clustering based on k_mean
//group store by loacation ==( longitude and latitude)
//sale sub clustering based on , revenue , profit and number of customers 


//
void clustering(Store *stores) {
    int num_stores=count;
    
  
    double **geo_data=new double*[num_stores];
    double **geo_centroid=new double*[max_geo];
    int *geo_label=new int[num_stores];

    for (int i=0; i<num_stores; i++) {
        geo_data[i]=new double[2];
        geo_data[i][0]=stores[i].location.gLat;
        geo_data[i][1]=stores[i].location.gLong;
    }
   
    for (int i=0; i<max_geo; i++) {
        geo_centroid[i]=new double[2];
        geo_centroid[i][0]=stores[i].location.gLat;
        geo_centroid[i][1]=stores[i].location.gLong;
    }
  
    k_mean(geo_data,geo_centroid,geo_label,num_stores,max_geo,2,euclideanlolati);
    
   
    double **sala_data=new double*[num_stores];
    double **sub_c=new double*[max_sub];
    int *sub_L=new int[num_stores];
   
    for (int i=0; i<num_stores; i++) {
        sala_data[i]=new double[feature];
        sala_data[i][0]=stores[i].sA.TotalSaleAmount;
        sala_data[i][1]=stores[i].sA.profit;
        sala_data[i][2]=stores[i].customerCountMonthly[0]; 
    }
   
    for (int i=0; i<max_sub; i++) {
        sub_c[i]=new double[feature];
        sub_c[i][0]=stores[i].sA.TotalSaleAmount;
        sub_c[i][1]=stores[i].sA.profit;
        sub_c[i][2]=stores[i].customerCountMonthly[0];
    }
   k_mean(sala_data, sub_c, sub_L, num_stores, max_sub, feature, euclidean);
    
  
    cout<<"=== Geographic Clustering (Latitude & Longitude) ==="<<endl;
    for (int c=0; c<max_geo; c++) {
        cout<<"Geo Cluster "<<c+1<<": ";
        for (int i=0; i<num_stores; i++) {
            if (geo_label[i]==c) {
                cout<<stores[i].sID<<" ";
            }
        }
        cout<<endl;
    }
    
    cout<<endl<<"=============================== Sales Sub-Clustering (Revenue, Profit, Customers) ========================================="<<endl;
    for (int c=0; c<max_sub; c++) {
        cout<<"Sub Cluster "<<c+1<<": ";
        for (int i=0; i<num_stores; i++) {
            if (sub_L[i]==c) {
                cout<<stores[i].sID<<" ";
            }
        }
        cout<<endl;
    }
    
    cout<<endl<<"============================== Combined Clustering Results ============================================"<<endl;
    for (int i=0; i<num_stores; i++) {
        cout<<"Store "<<stores[i].sID<<" ======> Geo Cluster "<<geo_label[i]<<", Sub Cluster "<<sub_L[i]<<endl;
    }
    
    
    for (int i=0; i<num_stores; i++) {
        delete[] geo_data[i];
        delete[] sala_data[i];
    }
    delete[] geo_data;
    delete[] sala_data;
    for (int i=0; i<max_geo; i++)
    delete[] geo_centroid[i];
    delete[] geo_centroid;
    for (int i=0; i<max_sub; i++)
    delete[] sub_c[i];
    delete[] sub_c;
    delete[] geo_label;
    delete[] sub_L;
}


//vizualize in as bar graph
void vizualize_cluster(int *labels, int numPoints, int num_cluster, const char* title) {
    
    int *counts=new int[num_cluster];
    for (int i=0; i<num_cluster; i++) {
        counts[i]=0;
    }
    
    
    for (int i=0; i<numPoints; i++) {
        if (labels[i]>=0 && labels[i]<num_cluster) {
            counts[labels[i]]++;
    }
    }
    
    
    cout<<endl<<title<<endl;
    
    
    for (int i=0; i<num_cluster; i++) {
        cout<<"Cluster " <<i<<" ("<<counts[i]<<"): ";
        for (int j=0; j<counts[i]; j++) {
            cout<<"$";
    }
        cout<<endl;
    }
    
    delete[] counts;
}