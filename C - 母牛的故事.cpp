#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>
using namespace std;
int f(int a)

{

    if(a<=1)

        return 1;

    else if(a==2)

        return 2;

    else if(a==3)

        return 3;

    else if(a==4)

        return 4;

    else

        return f(a-1)+f(a-3);

}

int main()

{

    int a;

    while(cin>>a)
    {
    	if(a==0)
    		break;
    	else
       		cout<<f(a)<<endl;
	}
    return 0;

}
