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
int ara[nax];
int block[350];
int n, block_size;

int block_id(int index)
{
    return (index / block_size);
}
void update1(int pos)
{
    int idx = block_id(pos);
    block[idx] -= ara[pos];
    ara[pos] = 0;
}
void update2(int pos, int value)
{
    int idx = block_id(pos);
    block[idx] += value;
    ara[pos] += value;
}
int query(int l, int r)
{
    int ret = 0;
    int left_block = block_id(l);
    int right_block = block_id(r);
    while (block_id(l) == left_block && l <= r){
        ret += ara[l];
        l++;
    }
    while (block_id(r) == right_block && right_block != left_block){
        ret += ara[r];
        r--;
    }
    for (int i = left_block + 1; i <= right_block - 1; i++){
        ret += block[i];
    }
    return ret;
}
void build()
{
    mem(block, 0);
    block_size = sqrt(n);
    for (int i = 1; i <= n; i++){
        block[block_id(i)] += ara[i];
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    int t;
    scanf ("%d", &t);
    for (int cs = 1; cs <= t; cs++){
        int q;
        scanf ("%d %d", &n, &q);
        for (int i = 1; i <= n; i++){
            scanf ("%d", &ara[i]);
        }
        build();
        printf ("Case %d:\n", cs);
        while (q--){
            int type;
            scanf ("%d", &type);
            if (type == 1){
                int pos;
                scanf ("%d", &pos);
                printf ("%d\n", ara[pos + 1]);
                update1(pos + 1);
            }
            else if (type == 2){
                int pos, value;
                scanf ("%d %d", &pos, &value);
                update2(pos + 1, value);
            }
            else{
                int l, r;
                scanf ("%d %d", &l, &r);
                printf ("%d\n", query(l + 1, r + 1));
            }
        }
    }
    return 0;
}



