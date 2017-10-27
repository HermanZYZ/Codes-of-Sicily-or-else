#include<iostream> 

using namespace std;

class Kilometers

{

private:

    double kilometers;

public:

    Kilometers(double kilometers): kilometers(kilometers) {}
    void display()

    {

        cout << kilometers << " kilometeres";

    }

    double getValue()

    {

        return kilometers;

    }
    operator Kilometers()
    {
    	return kilometers;
    }

};

class Miles

{

private:

    double miles;

public:

    Miles(double miles) : miles(miles) {}
	Miles(Kilometers kilometer)
	{
		miles=kilometer.getValue()*1.609;
	}
	
    void display()

    {

        cout << miles << " miles";

    }
	operator Kilometers()
	{
		return Kilometers(miles*1.609);
	}
}; 

int main()
{
	Kilometers k(1);
	Miles m=(Miles)k;
	m.display();
	
}

