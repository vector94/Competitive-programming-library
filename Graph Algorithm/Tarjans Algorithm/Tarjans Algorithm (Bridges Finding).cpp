#include<bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
vector<int> graph[nax];
int cur_time;

void DFS(int u, vector<int>& discovery_time, vector<int>& low, vector<int>& parent, vector<pair<int, int>>& bridge)
{
	discovery_time[u] = low[u] = cur_time;
	cur_time++;

	for(int v : graph[u])
	{
		if(discovery_time[v] == -1)	//If v is not visited
		{
			parent[v] = u;
			DFS(v, discovery_time, low,parent, bridge);
			low[u] = min(low[u], low[v]);

			if(low[v] > discovery_time[u]){
				bridge.push_back({u,v});
			}
		}
		else if(v != parent[u]){	//Ignore child to parent edge
			low[u] = min(low[u], discovery_time[v]);
		}
	}
}

void findBridges_Tarjan()
{
	vector<int> discovery_time(nax, -1), low(nax, -1), parent(nax, -1);
	vector<pair<int,int>> bridge;

    cur_time = 0;

	for(int i = 0; i < nax; i++){
		if(discovery_time[i] == -1){
			DFS(i, discovery_time, low, parent, bridge);
		}
	}
	cout<<"Bridges are: \n";
	for(auto it : bridge)
		cout << it.first << "-->" << it.second << endl;
}

int main()
{
	graph[0].push_back(2);
	graph[2].push_back(0);
	graph[0].push_back(3);
	graph[3].push_back(0);
	graph[1].push_back(0);
	graph[0].push_back(1);
	graph[2].push_back(1);
	graph[1].push_back(2);
	graph[3].push_back(4);
	graph[4].push_back(3);

	findBridges_Tarjan();
	return 0;
}
