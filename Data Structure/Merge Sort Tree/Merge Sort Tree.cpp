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

const int nax = 3e4 + 5;
#define mid ((l + r) / 2)
#define left (node * 2)
#define right (node * 2 + 1)
vector<int> tree[4 * nax];
int ara[nax];
int n;

void merge_sort_tree(int node = 1, int l = 1, int r = n)
{
    int len = r - l + 1;
    tree[node].resize(len, 0);
    if (l == r){
        tree[node][0] = ara[l];
        return;
    }
    merge_sort_tree(left, l, mid);
    merge_sort_tree(right, mid + 1, r);
    int i, j, k;
    i = j = k = 0;
    while (len--){
        if (i == mid - l + 1){
            tree[node][k++] = tree[right][j++];
        }
        else if (j == r - mid){
            tree[node][k++] = tree[left][i++];
        }
        else if (tree[left][i] < tree[right][j]){
            tree[node][k++] = tree[left][i++];
        }
        else{
            tree[node][k++] = tree[right][j++];
        }
    }
}

int query(int x, int y, int k, int node = 1, int l = 1, int r = n)
{
    if (l > y || r < x){
        return 0;
    }
    if (l >= x && r <= y){
        int idx = upper_bound(all(tree[node]), k) - tree[node].begin();
        return tree[node].size() - idx;
    }
    return query(x, y, k, left, l, mid) + query(x, y, k, right, mid + 1, r);
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
    merge_sort_tree();
    int q;
    cin >> q;
    while (q--){
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i, j, k) << endl;
    }
    return 0;
}

