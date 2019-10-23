#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
int ara[nax];
int tree[nax * 3];

void init(int node, int b, int e)
{
    if (b == e){
        tree[node] = ara[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b){
        return 0;
    }
    if (b >= i && e <= j){
        return tree[node];
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid + 1, e, i, j);
    return p1 + p2;
}

void update(int node, int b, int e, int i, int new_value)
{
    if (i > e || i < b){
        return;
    }
    if (b >= i && e <= i){
        tree[node] = new_value;
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, i, new_value);
    update(right, mid + 1, e, i, new_value);
    tree[node] = tree[left] + tree[right];
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> ara[i];
    }
    init(1, 1, n);

    return 0;
}
