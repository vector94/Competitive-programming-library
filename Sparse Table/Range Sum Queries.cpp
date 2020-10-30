#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define endl                    "\n"
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef Lollipop
    #define line                    cout << "\n===================\n"
    #define trace(...)              __f( #__VA_ARGS__ , __VA_ARGS__ )
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " = " << arg1 << "\n";
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');
        cerr.write(names, comma - names) << " = " << arg1 << " , ";
    __f(comma + 1, args...);
    }
#else
    #define line
    #define trace(...)
#endif

const int nax = 1e5 + 5;
ll sparse_table[nax][25];
ll ara[nax];
int n;

void build()
{
    for (int i = 0; i < n; i++){
        sparse_table[i][0] = ara[i];
    }
    for (int j = 1, j <= 25; j++){
        for (int i = 0; i + (1 << j) <= n; i++){
            sparse_table[i][j] = sparse_table[i][j - 1] + sparse_table[i + (1 << (j - 1))][j - 1];
        }
    }
}

ll query(int x, int y)
{
    ll sum = 0;
    for (int j = 25; j >= 0; j--){
        if ((1 << j) <= y - x + 1){
            sum += sparse_table[x][j];
            x += (1 << j);
        }
    }
    return sum;
}

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;

    return 0;
}

