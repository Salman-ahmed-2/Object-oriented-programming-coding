#include <iostream>
#include <string>

using namespace std;

#define maxunit 10 

class Unit {
private:
    int id,usagec,completetaskj,assigneqipid;
    string type,status;
   
    
    bool trained;

public:
    Unit() {id=-1;
        type="";
        status="Inactive"; usagec=0;
        trained=false;completetaskj=0;
        assigneqipid=-1;}

    void setUnit(int idd, string typee) {
        id=idd;
        type=typee;
        status=(type=="Equipment")?"Available":"Active";}

    int getid(){return id;}
    string gettype() {return type;}
    string getstatus() {return status;}
    void displaysummery();
    void updatesummery() { trained=true; }
    void completetask() { completetaskj++; }
    void markready() { if (trained) status="Ready"; }
    int getcompletetaskj() { return completetaskj; }
    bool istrained() { return trained; }
    int getAssignedEquipment() { return assigneqipid; }

    void incrementuseage() {
        if (type=="Equipment") {
            usagec
    ++;
            if (usagec
        >=5) status="Under Maintenance";}}

    void assignEquipment(int eqipid) {
        if (type=="Researcher") assigneqipid=eqipid;}

    bool isover() { return usagec
>=3; }};

void Unit::displaysummery() {
    cout<<"ID: "<<id<<" | Type: "<<type<<" | Status: "<<status;
    if (type=="Equipment") cout<<" | Usage Count: "<<usagec;
    else cout<<" | Trained: "<<(trained?"Yes":"No")<<" | Tasks Completed: "<<completetaskj;
    cout<<endl;
}

Unit labunit[maxunit];
int unitCount=0;

void addUnit(string type) {
    if (unitCount>=maxunit) {
        cout<<"Error: Maximum limit reached!"<<endl;
        return;  }
    labunit[unitCount].setUnit(unitCount+1, type);
    cout<<type<<" successfully added! Assigned ID: "<<unitCount+1<< endl;
    unitCount++;}

void updatestatus(int researchid) {
    if (researchid>0&&researchid<=unitCount&&labunit[researchid-1].gettype()=="Researcher") {
        labunit[researchid-1].updatesummery();
        cout<<"Researcher "<<researchid<<" has completed training!"<<endl;
    } else {  cout<<"Invalid Researcher ID!"<<endl;
    }
}

void completetask(int researchid) {
    if (researchid>0&&researchid<=unitCount&&labunit[researchid-1].gettype()=="Researcher") {
        labunit[researchid-1].completetask();
        cout<<"Researcher "<<researchid<<" has completed a task!"<<endl;} else {
        cout<<"Invalid Researcher ID!"<<endl;}}

void assignEquipment(int researchid, int eqipid) {
    if (researchid>0&&researchid<=unitCount &&eqipid>0&&eqipid<=unitCount &&labunit[researchid-1].gettype()=="Researcher"&&labunit[eqipid-1].gettype()=="Equipment") {
        labunit[researchid-1].assignEquipment(eqipid);
        cout<<"Equipment "<<eqipid<<" assigned to Researcher "<<researchid<<endl; } else {
        cout<<"Invalid ID! Please check and try again."<<endl;}}

void incrementuseagee(int eqipid) {
    if (eqipid>0&&eqipid<=unitCount&&labunit[eqipid-1].gettype()=="Equipment") {
        labunit[eqipid-1].incrementuseage();        cout<<"Equipment "<<eqipid<<" usage updated!"<<endl;
} else {
        cout<<"Invalid Equipment ID!"<<endl;}}

void markresearcherready(int researchid) {
    if (researchid>0&&researchid<=unitCount&&labunit[researchid-1].gettype()=="Researcher") {
        labunit[researchid-1].markready();
        cout<<"Researcher "<<researchid<<" is now marked as READY!"<<endl;} else {cout<<"Invalid Researcher ID!"<<endl;}}

void warnoveruse() {
    cout<<"Equipment Overuse Warnings" << endl; for (int i=0; i<unitCount; i++) {
        if (labunit[i].gettype()=="Researcher"&&labunit[i].isover()) {
            cout<<" Warning: Researcher "<<labunit[i].getid()<<" is using equipment excessively!"<<endl;}}}

void reportinterativeresearcher() {
    cout<<"--- Inactive Researchers Report ---" << endl;
    for (int i=0; i<unitCount; i++) { if (labunit[i].gettype()=="Researcher"&&labunit[i].getcompletetaskj()==0) {cout<<"Researcher "<<labunit[i].getid()<<" has not completed any tasks."<<endl;}
}}

void displayall() {
    cout<<"--- Lab Summary ---"<<endl;for (int i=0; i<unitCount; i++) {
        labunit[i].displaysummery();}}

int main() {
    int choice, id1, id2;

    while (true) {
        cout<<endl<<"Lab Management System "<<endl;
        cout<<"1. Register a new Researcher"<<endl;
        cout<<"2. Add new Equipment"<<endl;
        cout<<"3. View Lab Summary"<<endl;
        cout<<"4. Update Researcher Training Completion"<<endl;
        cout<<"5. Log a Completed Task for a Researcher"<<endl;
        cout<<"6. Assign Equipment to a Researcher"<<endl;
        cout<<"7. Increase Equipment Usage Count"<<endl;
        cout<<"8. Mark Researcher as 'Ready'"<<endl;
        cout<<"9. Warn Researchers for Equipment Overuse"<<endl;
        cout<<"10. Generate Inactive Researchers Report"<<endl;
        cout<<"11. Exit System"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if (choice==1) addUnit("Researcher");
        else if (choice==2) addUnit("Equipment");
        else if (choice==3) displayall();
        else if (choice==4) {cout<<"Enter Researcher ID: ";
            cin>>id1;updatestatus(id1); }
        else if (choice==5){    cout<<"Enter Researcher ID: ";cin>>id1;
            completetask(id1);
        }
        else if (choice==6) {
            cout<<"Enter Researcher ID and Equipment ID: ";
            cin>>id1>>id2;
            assignEquipment(id1, id2); }
        else if (choice==7) {
            cout<<"Enter Equipment ID: ";
            cin>>id1;
            incrementuseagee(id1);}
        else if (choice==8) {
            cout<<"Enter Researcher ID: ";
            cin>>id1;
            markresearcherready(id1);}
        else if (choice==9) warnoveruse();
        else if (choice==10) reportinterativeresearcher();
        else if (choice==11) {
            cout<<"Exiting System... Goodbye!"<<endl;
            break;
        }else cout<<"Invalid choice! Please try again."<<endl;}
    return 0;
}
