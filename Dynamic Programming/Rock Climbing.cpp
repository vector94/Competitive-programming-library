#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+9;
int dp[maxn][maxn];
int matrix[maxn][maxn];
int n;

int call(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < n){
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int ret = 0;
        ret = max(ret, call(i+1, j) + matrix[i][j]);
        ret = max(ret, call(i+1, j-1) + matrix[i][j]);
        ret = max(ret, call(i+1, j+1) + matrix[i][j]);
        return dp[i][j] = ret;
    }
    else{
        return 0;
    }
}

int main ()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << call(0, 0) << endl;
    return 0;
}
