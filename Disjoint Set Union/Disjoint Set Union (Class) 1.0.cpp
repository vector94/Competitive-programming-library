class UnionFind {
private:
    //static const int nax = 1e5 + 5;
    int n;                                  /// total number of nodes
    int group;                              /// total disconnected group;
    int sz[nax];                            /// size of a network
    int parent[nax];                        /// parent of a node
public:
    inline void Init(int n){
        this -> n = group = n;
        for(int i = 0; i <= n; i++){
            parent[i] = i, sz[i] = 1;
        }
    }
    inline int find(int p){                 /// finds parent of p
        return p == parent[p] ? p : parent[p] = find(parent[p]);
    }
    inline int connected(int p, int q){     /// checks p and q is connected or not
        return find(p) == find(q);
    }
    inline int groupCnt(){                  /// gives number of disconnected group
        return group;
    }
    inline int total(){                     /// gives total number of nodes in network
        return n;
    }
    inline int size(int p){                 /// gives the size of the group of p
        return sz[ find(p) ];
    }
    inline void merge(int p, int q){        /// merges the group of p and q
        int par1 = find(p);
        int par2 = find(q);
        if(par1 == par2){
            return;
        }
        else{
            group--;
        }
        if(sz[par1] > sz[par2]){
            parent[par2] = par1, sz[par1] += sz[par2];
        }
        else{
            parent[par1] = par2, sz[par2] += sz[par1];
        }
    }
}DSU;
