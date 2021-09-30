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

const int nax = 5e4 + 5;
struct data
{
    int sum, prefix_sum, suffix_sum, ans;
};

#define mid ((l + r) / 2)
#define left (2 * node)
#define right (2 * node + 1)
data tree[4 * nax];
const int inf = 15009;
int ara[nax];
int n;

data combine(data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.prefix_sum = max(l.prefix_sum, l.sum + r.prefix_sum);
    res.suffix_sum = max(r.suffix_sum, r.sum + l.suffix_sum);
    res.ans = max({l.ans, r.ans, l.suffix_sum, r.prefix_sum, l.suffix_sum + r.prefix_sum});
    return res;
}

data make_data(int val)
{
    data ret;
    ret.sum = ret.prefix_sum = ret.suffix_sum = ret.ans = val;
    return ret;
}

void build(int node = 1, int l = 1, int r = n)
{
    if (l == r){
        tree[node] = make_data(ara[l]);
        return;
    }
    build(left, l, mid);
    build(right, mid + 1, r);
    tree[node] = combine(tree[left], tree[right]);
}

data query(int x, int y, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return make_data(-inf);
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
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> ara[i];
    }
    build();
    int q;
    cin >> q;
    while (q--){
        int x, y;
        cin >> x >> y;
        cout << query(x, y).ans << endl;
    }
    return 0;
}


