#include<iostream>
#include<cmath>

using namespace std;
//1,2,3,4,5,6,7,8,9,0
//2,5,5,4,5,6,3,7,6,6
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int num;
        cin>>num;
        switch(num)
        {           //smallest largest
            case 2:cout<<1<<" "<<1<<endl;break;
            case 3:cout<<7<<" "<<7<<endl;break;
            case 4:cout<<4<<" "<<11<<endl;break;
            case 5:cout<<2<<" "<<71<<endl;break;
            case 6:cout<<6<<" "<<111<<endl;break;
            case 7:cout<<8<<" "<<711<<endl;break;
            case 8:cout<<10<<" "<<1111<<endl;break;
            default:
                {
                    string Max,Min;
                    if(num%2==0)
                    {
                        for(int i=0;i<num/2;i++)
                            Max+='1';
                    }
                    else
                    {
                        Max+='7';
                        for(int i=0;i<num/2-1;i++)
                            Max+='1';
                    }
                    
                    if(num%7==1)
                    {
                        Min+="10";
                    }
                    else if(num%7==2)
                    {
                        Min+='1';
                    }
                    else if(num%7==3)
                    {
                        Min+="22";
                    }
                    else if(num%7==4)
                    {
                        Min+="20";
                    }
                    else if(num%7==5)
                    {
                        Min+='2';
                    }
                    else if(num%7==6)
                    {
                        Min+='6';
                    }
                    if(num%7!=1 && num%7!=3 && num%7!=4)
                        for(int i=0;i<num/7;i++)
                        {
                                Min+='8';
                        }
                    else
                        for(int i=0;i<num/7-1;i++)
                        {
                                Min+='8';
                        }
                    if(Min.size()>2 && Min[1]=='2' && Min[2]=='8')
					{
						Min[1]=Min[2]='0';
					} 
                    cout<<Min<<" "<<Max<<endl;
                };break;
        }
        
    }
}                                 
