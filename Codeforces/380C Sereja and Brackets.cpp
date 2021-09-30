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

const int nax = 1e6 + 5;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
struct data
{
    int res, open, close;
    data(){}
    data(int res, int open, int close)
    {
        this -> res = res;
        this -> open = open;
        this -> close = close;
    }
}tree[4 * nax];
string s;
int n;

data combine(data a, data b)
{
    data ret;
    int t = min(a.open, b.close);
    ret.res = a.res + b.res + t;
    ret.open = a.open + b.open - t;
    ret.close = a.close + b.close - t;
    return ret;
}

void build(int node = 1, int l = 0, int r = n - 1)
{
    if (l == r){
        tree[node].res = 0;
        if (s[l] == '('){
            tree[node].open = 1;
            tree[node].close = 0;
        }
        else{
            tree[node].open = 0;
            tree[node].close = 1;
        }
        return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = combine(tree[left], tree[right]);
}

data query(int x, int y, int node = 1, int l = 0, int r = n - 1)
{
    if (l > y || r < x){
        return data(0, 0, 0);
    }
    if (l >= x && r <= y){
        return tree[node];
    }
    return combine(query(x, y, left, l, mid), query(x, y, right, mid + 1, r));
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    cin >> s;
    n = s.size();
    trace(n, s);
    build();
    int m;
    cin >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        cout << query(x - 1, y - 1).res * 2 << endl;
    }
    return 0;
}

