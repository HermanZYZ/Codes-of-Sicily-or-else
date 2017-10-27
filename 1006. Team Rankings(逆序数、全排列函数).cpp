#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getDistance(string A, string B) {
  int pos[5], distance = 0;
  for (int i = 0; i < A.size(); i++) 
  	pos[A[i]-'A'] = i;
  for (int i = 0; i < B.size(); i++) {
    for (int j = i + 1; j < B.size(); j++) {
      if (pos[B[i] - 'A'] > pos[B[j] - 'A']) 
	  	distance++;
    }
  }

  return distance;
}

pair<string, int> getMedian(string ranking[101], int num) {
  int result = 1005, sum;
  string str = "ABCDE", median;
  do {
    sum = 0;
    for (int i = 0; i < num; i++) 
		sum += getDistance(str, ranking[i]);
    if (sum < result) {
      result = sum;
      median = str;
    }
  } while (next_permutation(str.begin(), str.end()));

  return pair<string, int>(median, result);
}

int main() {
  int n;                    
  string ranking[101]; 
  while (cin >> n && n) 
  {
    for (int i = 0; i < n; i++) cin >> ranking[i];
    pair<string, int> median = getMedian(ranking, n);
    cout << median.first << " is the median ranking with value " << median.second << "." << endl;
  }
  return 0;
}



