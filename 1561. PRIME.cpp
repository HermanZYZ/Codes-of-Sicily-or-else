#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,num=0,prime=1 ;
    cin>>n;
    while(num<n){
        prime++;
        bool flag=true;
        for(int i=2;i<=sqrt(prime);i++){
            if(prime%i==0){
                flag=false;
                break;
            }
        }
            if(flag==true){
                num++;}
        }
        cout<<prime<<endl;
        return 0;
    }
