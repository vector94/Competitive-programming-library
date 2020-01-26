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
    return (bool) (num & (1LL << pos));
}
int Set(int num, int pos)
{
    return num | (1LL << pos);
}

struct node
{
    int cnt;
    node *next[2];
    node(){
        cnt = 0;
        next[0] = NULL;
        next[1] = NULL;
    }
} *root;

void Add(int num)
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

void Erase(int num)
{
    node *cur = root;
    for (int i = 30; i >= 0; i--){
        int id = Check(num, i);
        cur = cur -> next[id];
        cur -> cnt--;
    }
}

int Compute(int num)
{
    node *cur = root;
    int ret = 0;
    for (int i = 30; i >= 0; i--){
        int id = Check(num, i);
        if (cur -> next[id ^ 1] != NULL && cur -> next[id ^ 1] -> cnt > 0){
            ret = Set(ret, i);
            cur = cur -> next[id ^ 1];
        }
        else if (cur -> next[id] != NULL && cur -> next[id] -> cnt > 0){
            cur = cur -> next[id];
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

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    root = new node();
    Add(0);
    int q;
    cin >> q;
    while (q--){
        char type;
        int num;
        cin >> type >> num;
        if (type == '+'){
            Add(num);
        }
        else if (type == '-'){
            Erase(num);
        }
        else{
            cout << Compute(num) << endl;
        }
    }
    del(root);
    return 0;
}
