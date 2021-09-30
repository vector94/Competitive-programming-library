#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;
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

const int nax = 3e5 + 5;
int a[nax];
int n, m;
ll u;
vector<int> block[600];
int block_size;

int block_id(int index)
{
    return (index / block_size);
}

void update(int pos, int value)
{
    int idx = block_id(pos);
    int id = lower_bound(all(block[idx]), a[pos]) - block[idx].begin();
    block[idx][id] = value;
    sort(all(block[idx]));
    a[pos] = value;
}

int query(int l, int r, int v)
{
    int ret = 0;
    int left_block = block_id(l);
    int right_block = block_id(r);
    while (block_id(l) == left_block && l <= r){
        if (a[l] < v){
            ret++;
        }
        l++;
    }
    while (block_id(r) == right_block && right_block != left_block){
        if (a[r] < v){
            ret++;
        }
        r--;
    }
    for (int i = left_block + 1; i <= right_block - 1; i++){
        ret += lower_bound(all(block[i]), v) - block[i].begin();
    }
    return ret;
}

void build()
{
    block_size = sqrt(n);
    for (int i = 1; i <= n; i++){
        block[block_id(i)].pb(a[i]);
    }
    for (int i = 0; i <= block_size; i++){
        sort(all(block[i]));
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        freopen ("output.txt", "w", stdout);
    #endif
//    fastRead;
    scanf ("%d %d %d", &n, &m, &u);
    for (int i = 1; i <= n; i++){
        scanf ("%d", &a[i]);
    }
    build();
    while (m--){
        int l, r, v, p;
        scanf ("%d %d %d %d", &l, &r, &v, &p);
        int k = query(l, r, v);
        int val = (u * k) / (r - l + 1);
        update(p, val);
    }
    for (int i = 1; i <= n; i++){
        printf ("%d\n", a[i]);
    }
    return 0;
}

