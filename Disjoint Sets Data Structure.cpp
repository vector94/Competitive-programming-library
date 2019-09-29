#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+9;
int parent[maxn];

//int Fing(int n) // without path compression
//{
//    if (parent[n] == -1){
//        return n;
//    }
//    return Find(parent[n]);
//}

int Find(int n) // with path compression
{
    if (parent[n] == -1){
        return n;
    }
    parent[n] =  Find(parent[n]);
    return parent[n];
}
void Union(int set1, int set2)
{
    parent[set1] = set2;
}

int main ()
{
    memset(parent, -1, sizeof(parent));
    int node, edge;
    cin >> node >> edge;
    int u, v;
    while (edge--){
        cin >> u >> v;
        int set1, set2;
        set1 = Find(u);
        set2 = Find(v);
        if (set1 != set2){
            Union(set1, set2);
        }
        else{
            cout << "Already in same set\n";
        }
    }
    for (int i = 1; i<=node; i++){
        cout << parent[i] << " ";
    }
    return 0;
}
