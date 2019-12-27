#include <bits/stdc++.h>
using namespace std;
#define pb                      push_back
#define all(x)                  x.begin(), x.end()
/**
Imagine we have an array b1, b2, ..., bn where bi = 1 if an only if ai > k,
then we can easily answer the query (i, j, k) in O(log(n)) using a simple segment tree (answer is bi + b(i + 1) + ... + bj).
We can do this ! We can answer the queries offline.
First of all
    1. read all the queries and save them somewhere.
    2. then sort them in increasing order of k.
    3. also the array a in increasing order.
At first we'll set all array b to 1 and we will set all of them to 0 one by one.
Consider after sorting the queries in increasing order of their k,
we have a permutation w1, w2, ..., wq (of 1, 2, ..., q) where kw1 ≤ kw2 ≤ kw2 ≤ ... ≤ kwq (we keep the answer to the i - th query in ansi .
Pseudo code : (all 0-based)
**/

const int nax = 2e5 + 5;
int tree[4 * nax];
int n;
struct Query
{
    int l, r, k, idx;
    Query() {}
    Query(int l, int r, int k, int idx)
    {
        this -> l = l;
        this -> r = r;
        this -> k = k;
        this -> idx = idx;
    }
};
vector<Query>query;
struct Data
{
    int val, idx;
    Data(){}
    Data(int val, int idx)
    {
        this -> val = val;
        this -> idx = idx;
    }
};
vector<Data>ara;
int ans[nax];


void build(int id = 1, int l = 0, int r = n)
{
    if (r - l < 2){
        tree[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    int left = id * 2;
    int right = id * 2 + 1;
    build(left, l, mid);
    build(right, mid, r);
    tree[id] = tree[left] + tree[right];
}

void update(int p, int id = 1, int l = 0, int r = n)
{
    if (r - l < 2){
        tree[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    int left = 2 * id;
    int right = 2 * id + 1;
    if (p < mid){
        update(p, left, l, mid);
    }
    else{
        update(p, right, mid, r);
    }
    tree[id] = tree[left] + tree[right];
}

int sum(int x, int y, int id = 1, int l = 0, int r = n) /// [x, y)
{
    if (x >= r || l >= y){      /// [x, y) intersection [l, r) = empty
        return 0;
    }
    if (x <= l && r <= y){      /// [l, r) is a subset of [x, y)
        return tree[id];
    }
    int mid = (l + r) / 2;
    int left = id * 2;
    int right = id * 2 + 1;
    return sum(x, y, left, l, mid) + sum(x, y, right, mid, r);
}

bool cmp1(Query &x, Query &y)
{
    return x.k < y.k;
}
bool cmp2(Data &x, Data &y)
{
    return x.val < y.val;
}
/// [Note: every node contains the range [l, r). r is not included]


int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    scanf ("%d", &n);
    for (int  i = 0; i < n; i++){
        int x;
        scanf ("%d", &x);
        ara.pb(Data(x, i));
    }
    sort(all(ara), cmp2);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        int l, r, k;
        scanf ("%d %d %d", &l, &r, &k);
        query.pb(Query(l, r, k, i));
    }
    sort(all(query), cmp1);
    build();
    int j = 0;
    for (int i = 0; i < q; i++){
        int l, r, k;
        l = query[i].l;
        r = query[i].r;
        k = query[i].k;
        while (j < n && ara[j].val <= k){
            update(ara[j++].idx);
        }
        ans[query[i].idx] = sum(l - 1, r);
    }
    for (int i = 0; i < q; i++){
        printf ("%d\n", ans[i]);
    }
    return 0;
}
