struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool union_set(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool find_set(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int _size(int x) {
    return -data[root(x)];
    }
};
