#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
int parent[nax];
//int sz[nax];

void makeset(int u) {
    parent[u] = u;
//    sz[u] = 1;
}

void init_DSU(int N) {
    for(int i = 0; i <= N; i++) {
        makeset(i);
    }
}

int Find(int r) { //with path compression
    if(parent[r] == r) {
        return r;
    }

    parent[r] = Find(parent[r]);

    return parent[r];
}

//int FindSize(int r)
//{
//    return sz[Find(r)];
//}

void Union(int a, int b) {
    int u = Find(a);
    int v = Find(b);

    if(u != v) {
        parent[u] = v;
//        sz[v] += sz[u];
    }
}

int main()
{
    #ifdef Lollipop
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // Lollipop

    int n, m;
    scanf("%d %d", &n, &m);

    init_DSU(n);

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
    for (int i = 1; i <= node; i++){
        cout << parent[i] << " ";
    }
    return 0;
}
