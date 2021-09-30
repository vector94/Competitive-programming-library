#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+9;
int dp[maxn][maxn];

int nCr(int n, int r)
{
    if (r == 1){
        return n;
    }
    if (r == n){
        return 1;
    }
    if (dp[n][r] != -1){
        return dp[n][r];
    }
    return dp[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
}

int main ()
{
    memset(dp, -1, sizeof(dp));
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}
