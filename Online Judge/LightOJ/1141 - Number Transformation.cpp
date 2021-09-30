#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define fi first
#define se second
#define pb push_back
#define pbb pop_back
#define make_pair mp
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(array, value) memset(array, value, sizeof(array))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a,b))*b
#define line cout << "\n==========\n"
#define mod 1000000007
#define SIZE 1000001

bool visit[1009];
int level[1009];
bool prime[1009];
vector<int> data;
vector<int> primeFact[1009];

void prime_cal()
{
    int sqrtN = sqrt(1000);
    for (int i = 3; i<= sqrtN; i+=2){
        for (int j = i*i; j<=1000; j+= i+i){
            prime[j] = 1;
        }
    }
    data.pb(2);
    for (int i = 3; i<=1000; i+=2){
        if (!prime[i]){
            data.pb(i);
        }
    }
}
void prime_fact()
{
    for (int i = 2; i<=1000; i++){
        for (int j = 0; j<data.size(); j++){
            if (i%data[j] == 0 && i > data[j]){
                primeFact[i].pb(data[j]);
            }
        }
    }
}

int bfs(int s, int t)
{
    mem(visit, 0);
    mem(level, 0);

    queue<int> Q;
    Q.push(s);
    while (!Q.empty()){
        int x = Q.front();
        Q.pop();
        if (x == t){
            return level[x];
        }
        for (int i = 0; i<primeFact[x].size(); i++){
            int y = x + primeFact[x][i];
            if (!visit[y] && y <= t){
                visit[y] = 1;
                level[y] = level[x]+1;
                Q.push(y);
            }
        }
    }
    return -1;
}

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    prime_cal();
    prime_fact();
    int T;
    cin >> T;
    for (int cs = 1; cs<=T; cs++){
        int s, t;
        cin >> s >> t;
        int ans = bfs(s, t);
        printf ("Case %d: %d\n", cs, ans);
    }
    return 0;
}
