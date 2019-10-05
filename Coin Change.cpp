#include <bits/stdc++.h>
using namespace std;

const int maxCoin = 1e3+9;
const int maxAmount = 1e3+9;
int dp[maxCoin][maxAmount];
int n;
int coin[maxCoin];

int call(int i, int amount)
{
    if (i >= n){
        if (amount == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (dp[i][amount] != -1){
        return dp[i][amount];
    }
    int ret1 = 0;
    int ret2 = 0;
    if (amount - coin[i] >= 0){
        ret1 = call(i, amount - coin[i]);
    }
    ret2 = call(i+1, amount);
    return dp[i][amount] = ret1 | ret2;
}

int main ()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> coin[i];
    }
    int amount;
    cin >> amount;
    cout << call(0, amount) << endl;
    return 0;
}
