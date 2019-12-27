#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5 + 5;
ll ara[nax];
struct info
{
    ll prop, sum;
} tree[nax * 3];

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].sum = ara[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    build(left, b, mid);
    build(right, mid + 1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, ll b, ll e, int i, int j, int x)
{
    if (i > e || j < b){
        return;
    }
    if (b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, i, j, x);
    update(right, mid+1, e, i, j, x);
    tree[node].sum = tree[left].sum + tree[right].sum + (e - b + 1) * tree[node].prop;
}

ll query(int node, ll b, ll e, int i, int j, ll carry = 0)
{
    if (i > e || j < b){
        return 0;
    }
    if (b >= i && e <= j){
        return tree[node].sum + carry * (e - b + 1);
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    ll p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> ara[i];
    }
    build(1, 1, n);         /// 1 - based
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if (type == 1){
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
