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

const int nax = 2e3 + 5;
int n;

struct edge{
	int u, v;
	ll w;
	edge() { }
	edge(int u, int v, ll w){
		this -> u = u;
		this -> v = v;
		this -> w = w;
	}
	bool operator < (const edge &p) const{
		return w < p.w;
	}
};

vector<edge> graph;

int x[nax], y[nax];
ll c[nax], k[nax];
vector<int> power_station;
vector<pii> connection;
int parent[nax];

void init_DSU(){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
	}
}
int Find(int r){
	if (parent[r] == r){
		return r;
	}
	parent[r] = Find(parent[r]);
	return parent[r];
}

ll kruskal(){
	sort(graph.begin(), graph.end());
	init_DSU();

	ll cost = 0;
	for (int i = 0; i < graph.size(); i++){
		int u = graph[i].u;
		int v = graph[i].v;
		int w = graph[i].w;

		int set1 = Find(u);
		int set2 = Find(v);

		if (set1 != set2){
			parent[set1] = set2;
			cost += w;

			if (v == n + 1){
				power_station.pb(u);
			}
			else{
				connection.pb(mp(u, v));
			}
		}
	}
	return cost;

}

int main (){
    //freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    //fastRead;

    cin >> n;

    for (int i = 1; i <= n; i++){
    	cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++){
    	cin >> c[i];
    }
    for (int i = 1; i <= n; i++){
    	cin >> k[i];
    }

    for (int i = 1; i <= n; i++){
    	graph.pb(edge(i, n + 1, c[i]));
    }
    for (int i = 1; i <= n; i++){
    	for (int j = i + 1; j <= n; j++){
    		ll dst = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    		ll cost = (k[i] + k[j]) * dst;
    		graph.pb(edge(i, j, cost));
    	}
    }

    cout << kruskal() << endl;
    cout << power_station.size() << endl;
    for (int i = 0; i < power_station.size(); i++){
    	cout << power_station[i] << " ";
    }
    cout << endl;
    cout << connection.size() << endl;
    for (int i = 0; i < connection.size(); i++){
    	cout << connection[i].fi << " " << connection[i].se << endl;
    }
    cout << endl;
    return 0;
}