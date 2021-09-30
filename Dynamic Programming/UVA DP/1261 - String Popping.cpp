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

map<string, bool> dp;

bool solve(string s)
{
    if (s.size() == 0)  return true;
    if (dp.find(s) != dp.end()) return dp[s];
    bool &ret = dp[s];
    ret = false;
    for (int i = 0; i < s.size(); i++){
        int j = i + 1;
        while (j < s.size() && s[i] == s[j]){
            j++;
        }
        j--;
        if (j - i + 1 >= 2){
            string x = s.substr(0, i) + s.substr(j + 1);
            ret |= solve(x);
        }
        i = j;
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        dp.clear();
        cout << solve(s) << endl;
    }
    return 0;
}



