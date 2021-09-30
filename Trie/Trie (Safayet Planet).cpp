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

struct node {
    bool endmark;
    node *next[26 + 1];
    node (){
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

bool Search(string s, int len)
{
    node *cur = root;
    for (int i = 0; i < len; i++){
        int id = s[i] - 'a';
        if (cur -> next[id] == NULL){
            return false;
        }
        cur = cur -> next[id];
    }
    return cur -> endmark;
}

void del(node *cur)
{
    for (int i = 0; i < 26; i++){
        if (cur -> next[i]){
            del(cur -> next[i]);
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
    cout << "Enter Number of Words:\n";
    root = new node();
    int num_word;
    cin >> num_word;
    for (int i = 1; i <= num_word; i++){
        string word;
        cin >> word;
        Insert(word, word.size());
    }
    cout << "Enter Number of Query:\n";
    int query;
    cin >> query;
    for (int i = 1; i <= query; i++){
        string key;
        cin >> key;
        if (Search(key, key.size())){
            cout << "Found\n";
        }
        else{
            cout << "Not Found\n";
        }
    }
    del(root);
    return 0;
}


