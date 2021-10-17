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

const int nax = 2e5 + 5;
vector<int> graph[nax];
int in_degree[nax];
vector<int> result;
int n, m;

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> n >> m;
    while (m--){
        int a, b;
        cin >> a >> b;
        graph[a].pb(b); // a will appear before b
        in_degree[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> Q; // for any ans, use normal queue; priority queue for the lexicographically smaller ans
    for (int i = 1; i <= n; i++){
        if (in_degree[i] == 0){
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int cur = Q.top();
        Q.pop();
        result.pb(cur);
        for (int next : graph[cur]){
            in_degree[next]--;
            if (in_degree[next] == 0){
                Q.push(next);
            }
        }
    }
    if (result.size() != n){
        cout << -1 << endl;
    }
    else{
        for (int x : result){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}

