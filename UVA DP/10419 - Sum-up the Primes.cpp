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

vector<int> primes;
bool check(int num)
{
    int sqrtN = sqrt(num);
    for (int i = 2; i <= sqrtN; i++){
        if (num % i == 0)   return false;
    }
    return true;
}
void pre_cal()
{
    for (int i = 2; i <= 300; i++){
        if (check(i)){
            primes.pb(i);
        }
    }
}

bool cmp(int a, int b)
{
    return to_string(a) < to_string(b);
}

int n, t, cs, sz;
bool dp[170][15][1005];
int mark[170][15][1005];
int res[15], idx;

bool solve(int pos, int cnt, int num)
{
    if (pos == sz){
        if (cnt == 0 && num == 0)   return true;
        return false;
    }
    bool &ret = dp[pos][cnt][num];
    if (mark[pos][cnt][num] == cs)  return ret;
    mark[pos][cnt][num] = cs;
    ret = false;
    for (int i = 2; i >= 1; i--){
        if (primes[pos] == 2 && i == 2) continue;
        int cur = primes[pos] * i;
        if (cnt - i >= 0 && num >= cur){
            ret |= solve(pos + 1, cnt - i, num - cur);
            if (ret){
                for (int j = 0; j < i; j++){
                    res[--idx] = primes[pos];
                }
                return ret;
            }
        }
    }
    ret |= solve(pos + 1, cnt, num);
    return ret;
}


int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    pre_cal();
    sz = primes.size();
    sort(all(primes), cmp);
    while (scanf ("%d %d", &n, &t) == 2){
        if (n == 0 && t == 0)   break;
        cs++;
        idx = t;
        bool flag = solve(0, t, n);
        printf ("CASE %d:\n", cs);
        if (flag){
            for (int i = 0; i < t; i++){
                cout << res[i];
                if (i != t - 1){
                    cout << "+";
                }
            }
            cout << endl;
        }
        else{
            printf ("No Solution.\n");
        }
    }
    return 0;
}



