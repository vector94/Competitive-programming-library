#include <bits/stdc++.h>
using namespace std;

const int maxItem = 1e3+9;
const int maxWeight = 1e3+9;
int dp[maxItem][maxWeight];
int price[maxItem];
int weight[maxItem];
int n;

int func(int i, int w)
{
    if (i == n){
        return 0;
    }
    if (dp[i][w] == -1){
        return dp[i][w];
    }
    int profit1 = 0;
    int profit2;
    if (w - weight[i] >= 0){
        profit1 = price[i] + func(i+1, w-weight[i]);
    }
    profit2 = func(i+1, w);
    return dp[i][w] = max(profit1, profit2);
}

int main ()
{
    int capacity;
    cin >> n >> capacity;
    for (int i = 0; i<n; i++){
        cin >> price[i] >> weight[i];
    }
    cout << func(0, capacity);
    return 0;
}
