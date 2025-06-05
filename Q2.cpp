#include<iostream>
#include<string>
using namespace std;

class Drink {
protected:
    string flavor;
    float temperature;
    float price;
    string expiry_date;
public:
    Drink() : flavor(" "),temperature(0),price(0),expiry_date(" "){}
    Drink(const string& flv, float temp, float pr, const string& exp):flavor(flv), temperature(temp),price(pr),expiry_date(exp){}
    void set_flavor(const string& flv) {flavor=flv;}
    string get_flavor()const { return flavor;}
    void set_temperature(float temp) {temperature=temp;}
    float get_temperature()const {return temperature; }
    void set_price(float pr){price=pr;}
    float get_price() const {return price;}
    void set_expiry_date(const string& exp){expiry_date=exp;}
    string get_expiry_date() const{return expiry_date;}
};
class Water:public Drink {
protected:
    string supplier;
public:
    Water(const string& flv, float temp, float pr, const string& exp, const string& supp):Drink(flv,temp,pr,exp), supplier(supp) {}
    void Display() const {
        cout<<"Flavor: "<<flavor<<endl;
        cout<<"Temperature (best served): "<<temperature<<"°C"<<endl;
        cout<<"Price: $"<<price<< endl;
        cout<<"Expiry Date: "<<expiry_date<<endl;
        cout<<"Supplier: "<<supplier<<endl;
    }
};
class Carbonated:public Water {
private:
    string type;
public:

    Carbonated():Water(" ", 0, 0," "," "), type(" ") {}
    Carbonated(const string& flv, float temp, float pr, const string& exp,const string& supp, const string& typ): Water(flv, temp, pr, exp, supp), type(typ) {}
    
    void Display() const {
        Water::Display();
        cout<<"Type: "<<type<<endl;
    }
};
int main() {
    cout << "Carbonated Drink Object:\n";
    Carbonated c("Lemon", 5.0, 1.5, "2025-12-01", "AquaCorp", "Soda");
    c.Display();

    return 0;
}
