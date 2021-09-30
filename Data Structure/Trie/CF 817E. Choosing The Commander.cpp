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

bool Check(int num, int pos)
{
    return (bool) (num & (1 << pos));
}
int Reset(int num, int pos){
    return num & ~(1LL << pos);
}
int Set(int num, int pos)
{
    return num | (1 << pos);
}

struct node
{
    int cnt;
    node *next[2];
    node (){
        cnt = 0;
        next[0] = NULL;
        next[1] = NULL;
    }
} *root;

void Join(int num)
{
    node *cur = root;
    for (int i = 30; i >= 0; i--){
        int id = Check(num, i);
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
        cur -> cnt++;
    }
}

void Leave(int num)
{
    node *cur = root;
    for (int i = 30; i >= 0; i--){
        int id = Check(num, i);
        cur = cur -> next[id];
        cur -> cnt--;
    }
}

int num, res;
int l;
void dfs(node *cur, int depth, int p)
{
//    trace(depth, p);
    if (depth < 0){
        if (p < l){
            res += cur -> cnt;
        }
        return;
    }
    int x = Check(p, depth + 1);
    int y = Check(l, depth + 1);
    if (x > y){
//        trace(depth, p);
        return;
    }
    if (x < y){
        res += cur -> cnt;
        return;
    }
    int id = Check(p, depth);
    if (cur -> next[id] != NULL && cur -> next[id] -> cnt > 0){
        dfs(cur -> next[id], depth - 1, Reset(p, depth));
    }
    if (cur -> next[id ^ 1] != NULL && cur -> next[id ^ 1] -> cnt > 0){
        dfs(cur -> next[id ^ 1], depth - 1, Set(p, depth));
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    fastRead;
    root = new node();
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type >> num;
        if (type == 1){
            Join(num);
        }
        else if (type == 2){
            Leave(num);
        }
        else if (type == 3){
            cin >> l;
            res = 0;
            dfs(root, 30, num);
            cout << res << endl;
        }
    }
    return 0;
}


