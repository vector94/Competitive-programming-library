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

map<char, int> MP;

struct node
{
    int cnt;
    node *next[4];
    node (){
        cnt = 0;
        for (int i = 0; i < 4; i++){
            next[i] = NULL;
        }
    }
} *root;

void Insert(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = MP[s[i]];
        if (cur -> next[id] == NULL){
            cur -> next[id] = new node();
        }
        cur = cur -> next[id];
        cur -> cnt++;
    }
}

void del(node *cur)
{
    for (int i = 0; i < 4; i++){
        if (cur -> next[i] != NULL){
            del(cur -> next[i]);
        }
    }
    delete(cur);
}

void dfs(node *cur, ll depth, ll &ans)
{
    ans = max(ans, cur -> cnt * depth);
    for (int i = 0; i < 4; i++){
        if (cur -> next[i] != NULL){
            dfs(cur -> next[i], depth + 1, ans);
        }
    }
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    MP['A'] = 0;
    MP['C'] = 1;
    MP['G'] = 2;
    MP['T'] = 3;
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++){
        root = new node();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            string s;
            cin >> s;
            Insert(s, s.size());
        }
        ll res = 0;
        dfs(root, 0, res);
        cout << "Case " << cs << ": " << res << endl;
        del(root);
    }
    return 0;
}

