#include<iostream>
using namespace std;

void new_user_discount(int &bill) {
    cout<<"Discounted bill for new user: "<<bill-100<<endl;
}

void bulk_order_discount(int &bill) {
    cout<<"Discounted bill for bulk order: " <<bill-150<<endl;
}

void festival_sale_discount(int &bill) {
    cout<<"Discounted bill for festival sale: "<<bill-200<<endl;
}

void calculate(int &bill, void (*operation)(int &)) {
    operation(bill);
}

int main() {
    int bill=1000;
    char new_user, bulk_order, festival_sale;
    cout<<"Are you a new user (y for yes, n for no)? ";
    cin >> new_user;
    if (new_user=='y') {
        calculate(bill, new_user_discount);
    }
    cout<<"Are you buying in bulk (y for yes, n for no)?";
    cin>>bulk_order;
    if (bulk_order=='y') {
        calculate(bill, bulk_order_discount);
    }
    cout << "Is there a festival sale (y for yes, n for no)? ";
    cin >> festival_sale;
    if (festival_sale=='y') {
        calculate(bill,festival_sale_discount);
    }

    return 0;
}

