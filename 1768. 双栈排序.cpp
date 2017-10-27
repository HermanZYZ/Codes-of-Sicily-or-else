//´íÎóµÄËã·¨£¬2 5 1 4 6 3 

#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int main()
{
    stack<int> s1,s2;
    string ope;
    int n;
    int a[1000];
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        s1.push(a[0]);
        ope+="a";
        int k=1;
        bool flag=1;
        for(int i=1;i<n;i++)
        {
            while(!s1.empty() && s1.top()==k)
            {
                s1.pop();
                k++;
                ope+=" b";
            }
            if(s1.empty() || a[i]<s1.top())
            {
                s1.push(a[i]);
                ope+=" a";
            }
            else if(!s1.empty() && s1.top()==k)
            {
                s1.pop();
                k++;
                ope+=" b";
            }
            else if(s2.empty() || a[i]<s2.top())
            {
                s2.push(a[i]);
                ope+=" c";
            }
            else if(s1.top() < s2.top() && s1.top()==k)
            {
                s1.pop();
                k++;
                ope+=" b";
                i--;
            }
            else if(s1.top() > s2.top() && s2.top()==k)
            {
                s2.pop();
                k++;
                ope+=" d";
                i--;
            }
            else
            {
                cout<<0<<endl;
                flag=0;
                break;
            }
        }
        while(flag && (!s1.empty() || !s2.empty()))
        {
            if(s2.empty() && !s1.empty())
            {
                if(s1.top()==k)
                {
                    s1.pop();
                    k++;
                    ope+=" b";
                }
                
            }
            else if(!s2.empty() && s1.empty())
            {
                if(s2.top()==k)
                {
                    s2.pop();
                    k++;
                    ope+=" d";
                }
                
            }
            else if(s1.top()==k)
            {
                s1.pop();
                k++;
                ope+=" b";  
            }
            else if(s2.top()==k)
            {
                s2.pop();
                k++;
                ope+=" d";
            }
            else 
                break;
        }
        if(flag)
            cout<<ope<<endl;
        ope.clear();
        while(!s1.empty())
        {
            s1.pop();
        }
        while(!s2.empty())
        {
            s2.pop();
        }
    }
}                                 
