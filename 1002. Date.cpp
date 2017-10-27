#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Date {

    public:

        Date();

        Date(const Date&);

        Date(const string&);

        Date(int, int = 2, int = 29);

        void setDate(const string&);

        void printDate() const;

        int getYear() const;

        int getMonth() const;

        int getDay() const;

    private:

        bool checkFormat(const string&) const;

        bool validate();

        int year, month, day;

        bool pass;

};

 

/******** this part should be submitted ********/

Date::Date() {
	year=2006;
	month=1;
	day=1;
	validate();// your code.
}
Date::Date(const Date& anotherDate) {

	// your code.
	year = anotherDate.year; 
	month= anotherDate.month;
	day = anotherDate.day;
	validate();

}
Date::Date(const string& input) {

	setDate(input);// your code.

}
Date::Date(int year, int month, int day) {

	this -> year=year;
	this -> month=month;
	this -> day=day;
	validate();// your code.
}
void Date::printDate() const {
	if(pass)
	 {
	 	 cout<<setfill('0')<<setw(4)<<right<<year<<"-"
		  	 <<setfill('0')<<setw(2)<<right<<month<<"-"
		  	 <<setfill('0')<<setw(2)<<right<<day<<endl;
	 } 
	 else
	 	cout<<"Invalid Date"<<endl;
	// your code.

}

 

int Date::getYear() const {

	return year; // your code.
}
int Date::getMonth() const {

	return month;// your code
}
int Date::getDay() const {
	
	return day;// your code.
}
void Date::setDate(const string& input) {
	year=month=day=0;
	if(checkFormat(input))
	{
		for(int i=0;i<input.size();i++)
		{
			if(i<4)
			{
				year=year*10+(input[i]-'0');
			}
			else if(i>4 && i<7)
			{
				month=month*10+(input[i]-'0');
			}
			else if(i>7)
			{
				day=day*10+(input[i]-'0');
			}
			validate();
		} 
	}
	else
	{
		year=month=day=233;
		validate();
	}
	// your code.

}

 

bool Date::checkFormat(const string& input) const {

	if(input.size()!=10)
		return false;
	for(int i=0;i<input.size();i++)
	{
		if(i<4)
		{
			if(input[i]<'0' || input[i]>'9')
			{
				return false;
			}
				//return false;
		}
		else if(i==4)
		{
			if(input[i]!=':')
				return false;
		}
		else if(i<7)
		{
			if(input[i]<'0' || input[i]>'9')
				return false;
		}
		else if(i==7)
		{
			if(input[i]!=':')
				return false;
		}
		else if(input[i]<'0' || input[i]>'9')
				return false;
	}
	return true;	// your code.
}

 

bool Date::validate() {
	int daynum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if((year%400==0) || (year%4==0 && year%100!=0))
		daynum[2]++;
	if(year<0 || year>9999)
	{
		//cout<<year<<" "<<month<<endl;
		pass=false;
		return false;
	}
	else if(month<0 || month>12)
	{
		//cout<<year<<" "<<month<<"*"<<endl;
		pass=false;
		return false;
	}
	else if(day<0 || day>daynum[month])
	{
		//cout<<day<<endl;
		pass=false;
		return false;
	}
	else
	{
		pass=true;
		return true;
	}
	// your code.

}

/******** this part should be submitted ********/

 

int main() {

	int T;
	int flag;
	Date* myDate;
	string dateString;
	int year, month, day;
	cin >> T;
	while (T--) {

		cin >> flag;

		if (flag == 1) {

			cin >> dateString;

			myDate = new Date(dateString);			

		}

		else if (flag == 2) {

			cin >> year;

			myDate = new Date(year);

		}

		else if (flag == 3) {

			cin >> year >> month;

			myDate = new Date(year, month);

		}

		else if (flag == 4) {

			cin >> year >> month >> day;

			myDate = new Date(year, month, day);

                }

                else if (flag == 5){
                         myDate = new Date(2016,3,7);
                         myDate -> printDate();
                         cin >> dateString;
                         myDate->setDate(dateString);

                        cout << setw(1);
                         cout << myDate->getYear() << ' ';


                        cout << myDate->getMonth() <<' ';
                         cout << myDate->getDay() << endl;
                 }
                 else if (flag == 6){
                         myDate = new Date();
                         myDate ->printDate();
                         delete myDate;
                         cin >> year >> month >> day;
                         myDate = new Date( Date(year,month,day) );

                        cout << setw(1);
                         cout << myDate->getYear() << ' ';

                        cout << myDate->getMonth() <<' ';
                         cout << myDate->getDay() << endl;

		}
		myDate->printDate();

                delete myDate;
	}
	return 0;
}

