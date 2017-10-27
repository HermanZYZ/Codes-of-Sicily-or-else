#include<iostream>

using namespace std; 

class Date
{
public:
    Date(int y, int m, int d) { year=y; month=m; day=d; }
    int getY()
    {
    	return year;
    }
    int getM()
    {
    	return month;
    }
    int getD()
    {
    	return day;
    }
private:
    int year, month, day;
};
 
class Person
{
public:
	Person(Person& ano)
	{
		id=ano.id;
		birthDate = new Date(ano.birthDate->getY(),ano.birthDate->getM(),ano.birthDate->getD());
	}
    Person(int id, int year, int month, int day) {
        this->id = id;
        birthDate = new Date(year, month, day);
    }
    ~Person() { delete birthDate; }
    int getId() { return id; }
    Date* getBirthDate() { return birthDate; }
    Person& operator=(Person& ano)
    {
    	id=ano.id;
    	birthDate = new Date(ano.birthDate->getY(),ano.birthDate->getM(),ano.birthDate->getD());
    }
private:
    int id;
    Date* birthDate;
};
