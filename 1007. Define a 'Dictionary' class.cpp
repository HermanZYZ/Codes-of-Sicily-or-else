#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Dictionary
{
	vector<string> english,chinese;
public:
	void put(const string & english, const string & chinese)
	{
		this->english.push_back(english);
		this->chinese.push_back(chinese);
	}
	string get(const string & english)
	{
		int i=0;
		for(;i<english.size();i++)
		{
			if(english==this->english[i])
				return chinese[i];
		}
		return "[not found]";
	}
};

int main() {
 Dictionary dictionary;
 
 // initialize dictionary
 while (true) {
  string english;
  cin >> english;
  if (english == "end") break;
  string chinese;
  cin >> chinese;
  dictionary.put(english, chinese);
 }
 
 // lookup dictionary
 while (true) {
  string english;
  cin >> english;
  if (english == "end") break;
  cout << dictionary.get(english) << endl;
 }
}
