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
    bool endmark;
    node *next[27];
    node(){
        endmark = false;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
} *root;

void Insert(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - 'a';
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
    }
    cur -> endmark = true;
}

vector<string> res;
string key;
void dfs(node *cur)
{
    for (int i = 0; i < 26; i++){
        if (cur -> next[i] != NULL){
            key.pb(i + 'a');
            if (cur -> next[i] -> endmark){
                res.pb(key);
            }
            dfs(cur -> next[i]);
            key.pbb();
        }
    }
}

void solve(string s, int len)
{
    res.clear();
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - 'a';
        if (cur -> next[id] == NULL){
            return;
        }
        cur = cur -> next[id];
    }
    key = s;
    dfs(cur);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    root = new node();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        Insert(s, s.size());
    }
    int q;
    cin >> q;
    for (int cs = 1; cs <= q; cs++){
        string key;
        cin >> key;
        cout << "Case #" << cs << ":\n";
        solve(key, key.size());
        if (res.size() == 0){
            cout << "No match.\n";
        }
        else{
            for (auto it : res){
                cout << it << endl;
            }
        }
    }
    return 0;
}


