#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nax = 1e5 + 5;
int ara[nax];
struct info
{
    int prop, sum;
} tree[nax*3];

void init(int node, int b, int e)
{
    if(b==e) {
        tree[node].sum = ara[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void update(int node, int b, int e, int i, int j, int new_value)
{
    if(e < i || j < b) {
        return;
    }
    if(i <= b && e <= j){
        tree[node].sum += ((e - b + 1) * new_value);
        tree[node].prop += new_value;
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    update(left, b, mid, i, j, new_value);
    update(right, mid+1, e, i, j, new_value);
    tree[node].sum = tree[left].sum + tree[right].sum + ((e - b + 1) * tree[node].prop);
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if(e < i || j < b){
        return 0;
    }
    if(i <= b && e <= j){
        return tree[node].sum + carry * (e - b + 1);
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b + e) >> 1;
    int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(right, mid + 1, e, i, j, carry + tree[node].prop);
    return p1 + p2;
}

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> ara[i];
    }
    init(1, 0, n-1);
    return 0;
}
