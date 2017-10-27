#include<iostream>

using namespace std;

int main()
{
    int l,p,v;
    int Case=0;
    while(cin>>l>>p>>v && l!=p!=v!=0)
    {
        Case++;
        int result=0;
        result=(int)(v/p)*l+(v%p>l?l:v%p);
        cout<<"Case "<<Case<<": ";
        cout<<result<<endl;
    }
    return 0;
}                                  
