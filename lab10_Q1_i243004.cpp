
#include <iostream>
#include "Header.h"
using namespace std;




class holiday {

	string name;
	int day;
	string month;
	static int count_holiday;

public:

	holiday() {
		name = "";
		day = 0;
		month = "";


	}

	holiday(string name, string month, int day) {
		this->name = name;
		this->month = month;
		this->day = day;
	}

	void setnames(string name)
	{

		if (sizeof(name) > 50)
			cout << "limit exceeded" << endl;
		else
			this->name = name;


	}
	void setmonths(string month)
	{

		if (sizeof(month) > 10)
			cout << "limit exceeded" << endl;
		else
			this->month = month;


	}
	void setdays(int day)
	{

		if (day > 30 || day < 1)
			cout << "limit exceeded" << endl;
		else
			this->day = day;


	}

	string setname()
	{

		
			return name;


	}
	string setmonth()
	{

		return month;


	}
	int setday()
	{

		return day;


	}

};

bool inSameMonth(holiday h1, holiday h2)
{
	if (h1.setmonth() == h2.setmonth())
		return true;
	else return false;

}
double avgDate(holiday array[], int size)
{
	double c = 0;
	for (int i = 0; i < size; size++)
	{
		c = c + array[i].setday();

	}
	return c / size;

}









int main()
{

	holiday h1("sene","january",9);
	holiday h2("salman","August",2);
	holiday h3;
	h3.setnames("hana");
	h3.setdays(6);
	h3.setmonths("novenber");

	
	if(inSameMonth(h1, h2))

		cout << " h1 and h2 are same month" << endl;
	else 

		cout << " h1 and h2 are not same month" << endl;
}

