// Problem#: 20437
// Submission#: 5071532
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<bits/stdc++.h>
using namespace std;
int n;
char charcount[26];
char charset[26];
void resetCount(){
    for(int i=0;i<26;i++){
        charcount[i]=-1;
    }
    for(int i=0;i<n;i++){
        charcount[charset[i]-'a']=0;
    }
}
bool judgeChar(char c){
    if(c<'a'){
        return false;
    }
    if(charcount[c-'a']==-1||charcount[c-'a']>0){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    for(int Case=1;Case<=t;Case++){
        int total_count=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>charset[i];
        }
        string str;
        cin>>str;
        int strLen=str.size();
        for(int i=0;i<strLen;i++){
            resetCount();
            if(judgeChar(str[i])){
                charcount[str[i]-'a']++;
                total_count++;
            }else{
                continue;
            }
            //cout<<"*"<<str[i]<<endl; 
            int j=0;
            while(++j){
                if(i-j<0||i+j>=strLen){
                    //cout<<"fail: "<<str[i]<<" "<<i<<" "<<j<<" len:"<<strLen<<endl;
                    break;
                }
                //cout<<"judge: "<<str[i-j]<<" "<<str[i+j]<<" "<<judgeChar(str[i-j])<<endl;
                if(str[i-j]==str[i+j]&&judgeChar(str[i-j])){
                    charcount[str[i-j]-'a']+=2;
                    //cout<<"*"<<str.substr(i-j,2*j+1)<<endl; 
                    total_count++;
                }else{
                    break;
                }
            }
            
            if(strLen>1&&str[i]==str[i+1]){
                resetCount();
                charcount[str[i]-'a']+=2;
                total_count++;
                j=0;
                while(++j){
                    if(i-j<0||i+j+1>=strLen){
                        break;
                    }
                    if(str[i-j]==str[i+j+1]&&judgeChar(str[i-j])){
                        charcount[str[i-j]-'a']+=2;
                        //cout<<"*"<<str.substr(i-j,2*j+2)<<endl; 
                        total_count++;
                    }else{
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<Case<<": "<<total_count<<endl;
    }
}                                 