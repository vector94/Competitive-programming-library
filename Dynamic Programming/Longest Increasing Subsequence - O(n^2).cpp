#include <bits/stdc++.h>
using namespace std;

int lis(int ara[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i<n; i++){
        lis[i] = 1;
        for (int j = 0; j<i; j++){
            if (ara[i] > ara[j]){
                lis[i] = max(lis[i], lis[j]+1); 
            }
        }
    }
    return *max_element(lis, lis+n);
}

int main ()
{
    int n;
    cin >> n;
    int ara[n];
    for (int i = 0; i<n; i++){
        cin >> ara[i];
    }
    printf("Length of LIS is %d\n", lis(ara, n ));
    return 0;
}
