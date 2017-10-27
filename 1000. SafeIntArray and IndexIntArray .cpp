#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std; 

///////////////////////////////////////////////////////////////////////////////////////////////////

class  SafeIntArray
{
	int size;
	int* arr;
public:
//	 SafeIntArray(){
//	 	size=1;
//	 	arr=new int[1];
//	 	arr[0]=0;
//	 }
	 SafeIntArray(int size){
	 	this -> size=size;
	 	arr=new int[size];
	 	for(int i=0;i<size;i++)
	 		arr[i]=0;
	 }
	 ~SafeIntArray(){
	 	delete [] arr;
	 }
	 void set(int i,const int value){
	 	if(i>=0 && i<size){
	 		arr[i]=value;
	 	}
	 	else
	 		cout<<"Outside the boundary!"<<endl;
	 }
	 int get(int i){
	 	if(i>=0 && i<size)
	 		return arr[i];
	 	else{
	 		cout<<"Outside the boundary!"<<endl;
	 		return -1;
	 	}
	 }
};

class IndexIntArray : public SafeIntArray
{
	 int first,last;

public:
//	IndexIntArray():SafeIntArray(1){
//		first=0,last=0;
//	}
	IndexIntArray(int f,int l):SafeIntArray(l-f+1){
		this -> first=f;
		this -> last=l;
	}
	void set(int i,const int value){
		i-=first;
		SafeIntArray::set(i,value);
	}
	int get(int i){
		i-=first;
		return SafeIntArray::get(i);
	}
};

///////////////////////////////////////////////////////////////////////////////////////////////////

 

int main(int argc, char** argv) {
    int test;
    cin >> test;
    while (test --) {
        int size, n;
        cin >> size;
        SafeIntArray sia(size);
        // test SafeIntArray::set(int,int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            sia.set(index, data);
        }
        // test SafeIntArray::get(int) of SafeIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = sia.get(index);
            if (value != -1) {
                cout << value <<"*"<< endl;
            }
        }
        int begin, end;
        cin >> begin >> end;
        IndexIntArray iia(begin, end);
        // test IndexIntArray::set(int,int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index, data;
            cin >> index >> data;
            iia.set(index, data);
        }
        // test IndexIntArray::get(int) of IndexIntArray
        cin >> n;
        while (n --) {
            int index;
            cin >> index;
            int value = iia.get(index);
            if (value != -1) {
                cout << value <<"*"<< endl;
            }
        }
    }
    return 0;
}
