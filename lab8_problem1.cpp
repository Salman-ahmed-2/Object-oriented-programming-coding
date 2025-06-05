#include<iostream>
#include<string>
using namespace std;

class Book {
    string title,author,genre;

    int pages,borrowcount,dayborrow;
    
    float rating;
   
    bool archived,borrowed;
   

public:
    Book(string t="", string a="", int p=0, string g ="",float r=0.0):title(t),author(a),pages(p),genre(g),rating(r),borrowed(false),archived(false),borrowcount(0),dayborrow(0){}

    void inputbook() {
        cout<<"Enter book details:"<<endl;
        cout<<"Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout<<"Enter book author: ";
        getline(cin, author);
        cout<<"Enter book pages: ";
        cin>>pages;
        cout<<"Enter book genre: ";
        cin.ignore();
        getline(cin, genre);
        cout<<"Enter book rating: ";
        cin>>rating;
        while (rating<0||rating>5) {
            cout<<"Invalid rating. Enter again: "; cin>>rating;     }
    }

    void outputBook() {
        cout<<"Book Details:"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author <<endl;
        cout<<"Pages: "<<pages<< (pages>300?"(Long Read)":"")<< endl;
        cout<<"Genre: "<<genre<< endl;
        cout<<"Rating: "<<rating<< (rating > 4.5 ? " (Highly Rated!)": "") << endl;
        cout<<"Status: "<<(archived ?"Archived": (borrowed?"Borrowed":"Available")) << endl;
        cout<<"Times Borrowed: "<< borrowcount<<endl;
        if (borrowed&&dayborrow>30) {
            cout<<"Reminder: This book is overdue!"<<endl;}}

    void borrowwbook() {
        if (borrowed||archived) {            cout<<"Book is not available for borrowing!"<<endl;
        } else {
            borrowed=true;
            borrowcount++;
            dayborrow=0;     cout<<"Book borrowed successfully!"<<endl;}}

    void returnbook() {
        if (!borrowed) {cout<<"Book is already available!"<<endl;} else {
            borrowed=false;
            cout<<"Book returned successfully!"<<endl;}}

    void archievbook() {
        archived=true;
        cout<<"Book archived successfully!"<<endl;}

    void updatebook() {
        cout<<"Updating book details..."<<endl; inputbook();}
    bool searchbybook(string searchtitle) {
        return title==searchtitle;}
    bool searchbyauthor(string searchaythor) {
        return author==searchaythor;}};

int main() {
    Book books[100]={
        Book("The Great Gatsby", "F. Scott Fitzgerald",180,"Classic", 4.4),
        Book("1984","George Orwell", 328,"Dystopian",4.7),
        Book("To Kill a Mockingbird","Harper Lee", 281, "Fiction", 4.8)
    };
    int bookcount=3;
    int choice, index;
    string searchquary;

    while (true) {
        cout<<endl<<"Library Management System" << endl;
        cout<<"1. Add a Book"<<endl;
        cout<<"2. List Books" <<endl;
        cout<<"3. Borrow a Book"<< endl;
        cout<<"4. Return a Book"<< endl;
        cout<<"5. Archive a Book"<<endl;
        cout<<"6. Update Book Details"<<endl;
        cout<<"7. Search by Title" <<endl;
        cout<<"8. Search by Author"<< endl;
        cout<<"9. Exit"<< endl;
        cout<<"Enter choice: ";
        cin>> choice;
        cin.ignore();

        if (choice==1) {
            books[bookcount].inputbook();
            bookcount++;
        } else if (choice==2) {
            for (int i=0; i<bookcount; i++) {
                cout << endl<<"Book Index: "<<i<<endl;
                books[i].outputBook();}
        } else if (choice==3) {
            cout<<"Enter book index to borrow: ";
            cin>>index;
            if (index>=0&&index<bookcount) {
                books[index].borrowwbook();
            } else {
                cout<<"Invalid book index!"<<endl;}
        } else if (choice==4) {
            cout<<"Enter book index to return: ";
            cin>>index;
            if (index>=0&&index<bookcount) {
                books[index].returnbook();} else {
                cout<<"Invalid book index!"<<endl;}
        } else if (choice==5) {
            cout<<"Enter book index to archive: ";
            cin>>index;
            if (index>=0&&index<bookcount) {
                books[index].archievbook();} else {
                cout<<"Invalid book index!"<<endl;}
        } else if (choice==6) {
            cout<<"Enter book index to update: ";
            cin>>index;
            if (index>=0&& index<bookcount) {
                books[index].updatebook(); } else {
                cout<<"Invalid book index!"<<endl;
            }
        } else if (choice==7) {
            cout <<"Enter book title to search: ";
            getline(cin, searchquary);
            for (int i=0; i<bookcount; i++) {
                if (books[i].searchbybook(searchquary)) { books[i].outputBook();
                }
            }
        } else if (choice ==8) {
            cout << "Enter book author to search: ";
            getline(cin, searchquary);
            for (int i= 0;i< bookcount; i++) {
                if (books[i].searchbyauthor(searchquary)) {
                    books[i].outputBook();}}
        } else if (choice==9) {
            cout<<"Exiting..." << endl;
            return 0;
        } else {
            cout<<"Invalid choice!" << endl; } }}