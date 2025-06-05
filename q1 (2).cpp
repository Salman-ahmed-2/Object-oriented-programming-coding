#include<iostream>
#include<string.h>
using namespace std;


struct Borrower{
	string borrowerName;
	string issueDate;
	string returnDueDate;
};
struct Purchase{
	int price;
	bool isAvailable;
	
};

struct Book {
	string title;
	string author;
	string genre;
	string bookID;
	
	Borrower* borrowerInfo; Purchase* purchaseInfo;
};

void addBook(Book *book,int &index) {
	
	book[index].borrowerInfo = new Borrower;
	book[index].purchaseInfo = new Purchase;
	cout<<"                 Book "<<index+1<<endl;
	cout<<" ---------------------------------------"<<endl;
	cout<<"Enter Book id:"; cin.ignore();getline(cin,book[index].bookID);
	cout<<"Enter Title:"; cin.ignore();getline(cin,book[index].title);
	cout<<"Enter Author name:"; cin.ignore();getline(cin,book[index].author);
	cout<<"Enter Genre:"; cin.ignore();getline(cin,book[index].genre);
	cout<<"Enter Borrower:"; cin.ignore(); getline(cin,book[index].borrowerInfo->borrowerName);
	cout<<"Enter Issue date:"; cin.ignore();getline(cin,book[index].borrowerInfo->issueDate);
	cout<<"Enter Return due date:"; cin.ignore();getline(cin,book[index].borrowerInfo->returnDueDate);
	cout<<"Enter Price:"; cin>>book[index].purchaseInfo->price; again:
	cout<<"Enter Available( Enter 1 for Yes and 0 for No):"; cin>>book[index].purchaseInfo->isAvailable;  if (book[index].purchaseInfo->isAvailable==1||book[index].purchaseInfo->isAvailable==0) cout<<""; else goto again;
cout<<" ---------------------------------------"<<endl;
	
}
 void displayBooks(Book *book,int &index){
 	
 	for (int indexs=0;indexs<index;indexs++){
 		cout<<"----------------------------------------"<<endl;
		cout<<"                 book"<<indexs+1<<endl;
	cout<<" ---------------------------------------"<<endl;
 	cout<<"Book id:"<<book[indexs].bookID<<endl;
	cout<<"Title:"<<book[indexs].title<<endl;
	cout<<"Author name:"<<book[indexs].author<<endl;
	cout<<"Genre:"<<book[indexs].genre<<endl;
	cout<<"Borrower:"<<book[indexs].borrowerInfo->borrowerName<<endl;
	cout<<"Issue date:"<<book[indexs].borrowerInfo->issueDate<<endl;
	cout<<"Return due date:"<<book[indexs].borrowerInfo->returnDueDate<<endl;
	cout<<"Price"<<book[indexs].purchaseInfo->price<<endl;
	cout<<"Availablility"; if(book[indexs].purchaseInfo->isAvailable) cout<<"Available"<<endl; else cout<<"not Available"<<endl;
 		cout<<" ---------------------------------------"<<endl;}
 }
 void releaseMemory(Book *book,int &totalbooks){
 	
 	delete[] book;
 }

int main(){

int choice,totalbooks=5 ;
int index=0;

Book *book=new Book[totalbooks];
choice:
cout<<"-------------------------Library managment system-------------------------------"<<endl;
cout<<"1. Add Book"<<endl;
cout<<"2. Display Books"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter choice :";
cin>>choice;

if(choice==1){

addBook(book, index);index++;}
else if(choice==2)
	displayBooks(book,index);
	else if (choice==3) { releaseMemory(book,totalbooks); cout<<"exiting memory freed";return 0;}
	else {
		system("cls"); 
	}
	cout<<"==================================================================="<<endl;
goto choice;


}

