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
int Set(int num, int pos)
{
    return num | (1 << pos);
}

struct node
{
    node *next[2];
    node(){
        next[0] = NULL;
        next[1] = NULL;
    }
} *root;

void Insert(int num)
{
    node *cur = root;
    for (int i = 20; i >= 0; i--){
        int id = Check(num, i);
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
    }
}

int Compute_Max(int num)
{
    node *cur = root;
    int ret = 0;
    for (int i = 20; i >= 0; i--){
        int id = Check(num, i);
        if (cur -> next[id ^ 1] != NULL){
            ret = Set(ret, i);
            cur = cur -> next[id ^ 1];
        }
        else if (cur -> next[id] != NULL){
            cur = cur -> next[id];
        }
    }
    return ret;
}

int Compute_Min(int num)
{
    node *cur = root;
    int ret = 0;
    for (int i = 20; i >= 0; i--){
        int id = Check(num, i);
        if (cur -> next[id] != NULL){
            cur = cur -> next[id];
        }
        else if (cur -> next[id ^ 1] != NULL){
            ret = Set(ret, i);
            cur = cur -> next[id ^ 1];
        }
    }
    return ret;
}

void del(node *cur)
{
    if (cur -> next[0]){
        del(cur -> next[0]);
    }
    if (cur -> next[1]){
        del(cur -> next[1]);
    }
    delete(cur);
}

const int inf = 1e9;
const int nax = 5e4 + 5;
int ara[nax];
int n;

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> ara[i];
        }
        int mn = inf;
        int mx = 0;
        root = new node();
        Insert(0);
        int Xor = 0;
        for (int i = 0; i < n; i++){
            Xor ^= ara[i];
            mx = max(mx, Compute_Max(Xor));
            mn = min(mn, Compute_Min(Xor));
            Insert(Xor);
        }
        cout << "Case " << cs << ": " << mx << " " << mn << endl;
        del(root);
    }
    return 0;
}


