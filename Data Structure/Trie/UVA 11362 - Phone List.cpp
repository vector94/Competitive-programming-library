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

struct node
{
    node *next[10];
    int cnt;
    node(){
        cnt = 0;
        for (int i = 0; i <= 9; i++){
            next[i] = NULL;
        }
    }
} *root;

void Insert(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - '0';
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
        cur -> cnt++;
    }
}

bool Search(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - '0';
        cur = cur -> next[id];
    }
    return (cur -> cnt > 1);
}

const int nax = 1e4 + 5;
string ara[nax];
int n;

void del(node *cur)
{
    for (int id = 0; id <= 9; id++){
        if (cur -> next[id]){
            del(cur -> next[id]);
        }
    }
    delete(cur);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int t;
    cin >> t;
    while (t--){
        root = new node();
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> ara[i];
            Insert(ara[i], ara[i].size());
        }
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (Search(ara[i], ara[i].size())){
                flag = true;
                break;
            }
        }
        if (flag){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}


