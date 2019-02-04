#include <bits/stdc++.h>
using namespace std;

int main ()
{
    string a, b;
    cin >> a >> b;
    
    int len1 = a.size();
    int len2 = b.size();
    int dp[len1+1][len2+1];
        
    for (int i = 0; i<=len1; i++){
        for (int j = 0; j<=len2; j++){
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    printf ("Length of LCS is %d\n", dp[len1][len2]);
    
    deque<char> lcs;
    int i = len1;
    int j = len2;
    while (i > 0 && j > 0){
        if (a[i-1] == b[j-1]){
            lcs.push_front(a[i-1]);
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << "LCS of " << a << " and " << b << " is ";
    for (int i = 0; i<lcs.size(); i++){
        cout << lcs[i];
    }
    return 0;
}
