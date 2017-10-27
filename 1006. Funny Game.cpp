#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    while (cin >> a >> b) 
    {
        if (a == 0 && b == 0) 
        	break;
        int winner = 0;
        while (a && b) 
        {
            winner ++;
            winner %= 2;
            if (a > b) 
            {
                if (a / b >= 2) 
                	break;
                else a -= b;
    
            }
            else
            {
                if (b / a >= 2) 
                	break;
                else 
                	b -= a;
            }
        }
        if (winner == 1) 
        	cout << "Singa wins"<< endl;
        else 
        	cout << "Suny wins" << endl;
    }
    return 0;
}