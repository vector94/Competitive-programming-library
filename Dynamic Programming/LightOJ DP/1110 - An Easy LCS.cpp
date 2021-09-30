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

string a, b;
string dp[105][105];
int mark[105][105];
int cs;

string cmp(string x, string y)
{
    if (x.size() != y.size()){
        if (x.size() > y.size())    return x;
        return y;
    }
    else{
        return min(x, y);
    }
}
string add(string x, char ch)
{
    string ret;
    ret.pb(ch);
    ret += x;
    return ret;
}

string solve(int i, int j)
{
    if (i == a.size() || j == b.size()){
        return "";
    }
    string &ret = dp[i][j];
    if (mark[i][j] == cs){
        return ret;
    }
    mark[i][j] = cs;
    ret = "";
    if (a[i] == b[j]){
        ret = cmp(ret, add(solve(i + 1, j + 1), a[i]));
    }
    else{
        ret = cmp(ret, solve(i + 1, j));
        ret = cmp(ret, solve(i, j + 1));
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
    for (cs = 1; cs <= t; cs++){
        cin >> a >> b;
        string res = solve(0, 0);
        cout << "Case " << cs << ": ";
        if (res.size() == 0){
            cout << ":(\n";
        }
        else{
            cout << res << endl;
        }
    }
    return 0;
}
