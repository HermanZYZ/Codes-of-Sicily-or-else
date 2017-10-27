#include <iostream>

using namespace std;




class Date

{

public:

         Date(int newYear, int newMonth, int newDay);

         int getYear();

         int getMonth();

         int getDay();

         void setYear(int newYear);

         void setMonth(int newMonth);

         void setDay(int newDay);  

private:

int year;

int month;

int day;

};




class Person

{

public:

Person(int id, int year, int month, int day);

~Person();

int getId();

Date* getBirthDate();

static int getNumberOfObjects(); //return the number of Person objects 


private:

int id;

Date *birthDate; 

static int numberOfObjects; //count the number of Person objects

};


////////////////////////////////////////////////////////

Date:: Date(int newYear, int newMonth, int newDay)
{
	year = newYear;
	month = newMonth;
	day = newDay;
}

int Date::getYear(){
	return year;
}
	
int Date::getMonth()
{
	return month;
}

int Date::getDay(){
	return day;
}
	
void Date::setYear(int newYear){
	this ->year=newYear;
}
	
void Date::setMonth(int newMonth){
	this ->month=newMonth;
}
	
void Date::setDay(int newDay){
	this ->day =newDay;
}

Person::Person(int id, int year, int month, int day)
{
	this -> id=id;
	birthDate = new Date(year,month,day);
	numberOfObjects++;
	
}
	
Person::~Person()
{
	delete birthDate;
	numberOfObjects--;
}
	
int Person::getId()

{
	return id;
}
	
Date* Person::getBirthDate()
{
	return birthDate;
}
	
int Person::getNumberOfObjects()
{
	return numberOfObjects;
}
// your code will be here


//////////////////////////////////////////////////////


 

void displayPerson(Person &person)

{

cout << "\tperson id: " << person.getId() << endl;

cout << "\tperson birth year: " <<

person.getBirthDate() -> getYear() << endl <<

"\tperson birth month: " <<

person.getBirthDate() -> getMonth() << endl <<

"\tperson birth day: " <<

person.getBirthDate() -> getDay() << endl;

}


 

int Person::numberOfObjects = 0;


int main()

{

Person person1(111, 1970, 5, 3);

cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;

displayPerson(person1);




Person person2(112, 1977, 2, 22);

cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;


displayPerson(person2);

person2.getBirthDate() -> setYear(1963);

person2.getBirthDate() -> setMonth(1);

person2.getBirthDate() -> setDay(19);

cout << "After modifying person2's birthDate" << endl;

displayPerson(person2);

cout << (person1.getBirthDate() == person2.getBirthDate()) << endl;

  

{

Person person3(113, 1981, 5, 5);

cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;

displayPerson(person3);

}

cout << "number of Person objects: " << Person::getNumberOfObjects() << endl;


return 0;

}
