#include <iostream>
#include <string>

using namespace std;


class HourlyWorker {
public:
    string name;
    string address;
    string phone;
    string ssn;
    double hourlyRate;
    double hoursWorked;

   
    HourlyWorker(string name,string address,string phone,string ssn,double hourlyRate) {
        this->name=name;
        this->address=address;
        this->phone=phone;
        this->ssn=ssn;
        this->hourlyRate=hourlyRate;
        this->hoursWorked=0.0;
    }


    void addHours(double hours) {
        hoursWorked+=hours;
    }

    
    double calculateHourlyPay() {
        return hoursWorked*hourlyRate;
    }

    
    void display() {
        cout<<"Employee: "<<name<<endl;
        cout<<"Address: "<< address<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"SSN: "<<ssn<<endl;
        cout<<"Hourly Rate: $"<<hourlyRate<<endl;
        cout<<"Hours Worked: "<<hoursWorked<<endl;
    }
};


class CommissionWorker {
public:
    string name;
    string address;
    string phone;
    string ssn;
    double hourlyRate;
    double hoursWorked;
    double totalSales;
    double commissionRate;

   
    CommissionWorker(string name, string address,string phone,string ssn,double hourlyRate,double commissionRate) {
        this->name=name;
        this->address=address;
        this->phone=phone;
        this->ssn=ssn;
        this->hourlyRate=hourlyRate;
        this->hoursWorked=0.0;
        this->totalSales=0.0;
        this->commissionRate=commissionRate;
    }

    
    void addHours(double hours) {
        hoursWorked+=hours;
    }


    void addSales(double sales) {
        totalSales+=sales;
    }

    
    double calculateTotalPay() {
        double hourlyPay=hoursWorked*hourlyRate;
        double commissionPay=totalSales*commissionRate;
        return hourlyPay+commissionPay;
    }

    
    void display() {
        cout<<"Employee: "<<name<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<"Phone: "<<phone<<endl;
        cout<<"SSN: "<<ssn<<endl;
        cout<<"Hourly Rate: $"<<hourlyRate<<endl;
        cout<<"Hours Worked: "<<hoursWorked<<endl;
        cout<<"Total Sales: $"<<totalSales<<endl;
        cout<<"Commission Rate: "<<commissionRate<<endl;
    }
};

int main() {
    string name, address, phone, ssn;
    double hourlyRate, commissionRate, hoursWorked, sales;

    cout<<"Enter details for Hourly Worker:"<<endl;
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Address: ";
    getline(cin,address);
    cout<<"Phone: ";
    getline(cin,phone);
    cout<<"SSN: ";
    getline(cin,ssn);
    cout << "Hourly Rate: $";
    cin >> hourlyRate;

    HourlyWorker hourlyWorker(name, address, phone, ssn, hourlyRate);

    cout<<"Enter hours worked for "<<name<<": ";
    cin>>hoursWorked;
    hourlyWorker.addHours(hoursWorked);

    
    cin.ignore();

  
    cout<<"\nEnter details for Commission Worker:" << endl;
    cout<<"Name: ";
    getline(cin,name);
    cout<<"Address: ";
    getline(cin,address);
    cout<<"Phone: ";
    getline(cin,phone);
    cout<<"SSN: ";
    getline(cin,ssn);
    cout<<"Hourly Rate: $";
    cin>>hourlyRate;
    cout<<"Commission Rate: ";
    cin>>commissionRate;

    CommissionWorker commissionWorker(name, address, phone, ssn, hourlyRate, commissionRate);

    cout<<"Enter hours worked for "<<name<<": ";
    cin>>hoursWorked;
    commissionWorker.addHours(hoursWorked);

    cout<<"Enter total sales for "<<name<<": $";
    cin>>sales;
    commissionWorker.addSales(sales);
    cout<<"\n--- Hourly Worker Details ---"<<endl;
    hourlyWorker.display();
    cout<<"Total Pay this period: $" << hourlyWorker.calculateHourlyPay()<<endl;
    cout<<"\n--- Commission Worker Details ---"<<endl;
    commissionWorker.display();
    cout<<"Total Pay this period: $"<<commissionWorker.calculateTotalPay()<<endl;

    return 0;
}

