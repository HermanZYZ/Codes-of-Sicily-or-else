// Problem#: 20440
// Submission#: 5073576
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<bits/stdc++.h>
using namespace std;

int N;
int a[105][105];
int c[105][105][3];
int rec[105];
bool vis[105];
int tmpAns;
const int mod = 1007;
void dfs(int row, int col, int sum){
    if(row == N-1){
        if(sum % 3 == 0)
            tmpAns++;
        tmpAns %= mod;
        return;
    }
    if(col == 0){
        dfs(row+1, 0, sum+a[row+1][0]);
        dfs(row+1, 1, sum+a[row+1][1]);
    }
    else if(col == N-1){
        dfs(row+1, N-1, sum+a[row+1][N-1]);
        dfs(row+1, N-2, sum+a[row+1][N-2]);
    }
    else{
        dfs(row+1, col-1, sum+a[row+1][col-1]);
        dfs(row+1, col, sum+a[row+1][col]);
        dfs(row+1, col+1, sum+a[row+1][col+1]);
    }
}

int main(){
    while(cin >> N){
        if(!N)
            break;
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                cin >> a[i][j];
        memset(c, 0, sizeof(c)); 
        memset(rec, 0, sizeof(rec));       
        for(int i = N; i >= 1; i--){
            for(int j = N; j >= 1; j--){
                if(i == N){
                    int loc = a[i][j] % 3;
                    int tm = (3 - loc) % 3;
                    c[i][j][tm] = 1;
                }
                else if(i == 1){
                    int num = a[i][j] % 3;
                    for(int p = j-1; p <= j+1; p++)
                        rec[j] += c[i+1][p][num];
                }
                else{
                //  cout << i << " " << j << endl;
                    int loc = a[i][j] % 3;
                    for(int p = j-1; p <= j+1; p++){
                        for(int q = 0; q < 3; q++){
                            c[i][j][q] += c[i+1][p][(q+loc)%3];
                //          cout << c[i+1][p][(q+loc)%3] << " ";
                        }
                    }
                    
                        
                }
                for(int p = 0; p < 3; p++){
                    c[i][j][p] %= mod;
                }
            }
        }
        
        
        int ans = 0;
        for(int i = 1; i <= N; i++){
            ans += rec[i];
         
        }
        cout << ans % mod << endl;
    //  cout << c[0][0][0] << endl;
    }
    
}                                 