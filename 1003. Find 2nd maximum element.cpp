#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Sequence
{
public:
    Sequence(const vector<int>& v):seq(v) { }
    friend int second_max(const Sequence&);
private:
    vector<int> seq;
};

 int second_max(const Sequence& se)
 {
 	int rank=0,num=-1;
 	vector<int>temp=se.seq;
 	if(temp.size()==0 || temp.size()==1)
 		return num;
	sort(temp.begin(),temp.end());
//	for(int i=0;i<temp.size();i++)
//		for(int j=i+1;j<temp.size();j++)
//		{
//			int a;
//			if(temp[i]>temp[j])
//			{
//				a=temp[j];
//				temp[j]=temp[i];
//				temp[i]=a;
//			}
//		}
	int max=temp[temp.size()-1]; 
 	for(int i=temp.size()-2;i>=0;i--)
	 {
	 	if(max!=temp[i])
	 	{
	 		num=temp[i];
	 		return num;
	 	}
	 } 
	 return num;
 }
 
 int main()
 {
 	vector<int> a;
// 	a.push_back(1);
// 	a.push_back(1);
// 	a.push_back(2);
// 	a.push_back(2);
 	Sequence b(a);
	cout<<second_max(b);
 }
