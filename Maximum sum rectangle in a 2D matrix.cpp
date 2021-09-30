#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    int ara[n][n];
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> ara[i][j];
        }
    }
    int ans = INT_MIN;
    int a[n];
    for (int i = 0; i<n; i++){
        memset(a, 0, sizeof (a));
        for (int j = i; j<n; j++){
            for (int k = 0; k<n; k++){
                a[k] += ara[k][j];
            }
            int c_sum, sum;
            c_sum = sum = a[0];
            for (int k = 1; k<n; k++){
                c_sum = max(c_sum+a[k], a[k]);
                sum = max(sum, c_sum);
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
