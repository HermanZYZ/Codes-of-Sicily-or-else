#include<iostream>
#include <stdexcept>
#include<cstdlib>
#include<cstring>
using namespace std;

int parseHex(const char* hexString){
	int result=0; 
	int len = strlen(hexString);
	int dec = 0;
	for(int i=0; i<len; i++){
		if(hexString[i]>='0' && hexString[i]<='9') dec=hexString[i]-'0';
		else if(hexString[i]>='A' && hexString[i]<='F') dec=hexString[i]-'A'+10;
		else if(hexString[i]>='a' && hexString[i]<='f') dec=hexString[i]-'a'+10;
		else throw runtime_error("Hex number format error");
		result=16*result+dec; 
	}
	return result;
}

int main()
{
	string s;
	while (cin >> s) {
		try {
			cout << parseHex(s.c_str()) << endl;
		} catch (runtime_error &ex) {
			cout << ex.what() << endl;
		}
	}
	return 0;

}
