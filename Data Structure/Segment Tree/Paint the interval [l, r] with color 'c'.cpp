#include <bits/stdc++.h>
using namespace std;
#define mem(array, value)       memset(array, value, sizeof(array))

const int nax = 1e7 + 5;
int n = 1e7 + 1;
int lazy[4 * nax];

/**
We don't need all elements in the interval [1, 10^7].
The only thing we need is the set s1, s2, ..., s-k where for each i, s-i is at least l or r in one of the queries.
We can use interval 1, 2, ..., k instead of that
(each query is running in this interval, in code, we use 0-based, I mean [0, k) ).
For the i - th query, we will paint all the interval [l, r] with color i (1-based).

For each interval, if all it's interval is from the same color,
I will keep that color for it and update the nodes using lazy propagation.

So,we will have a value lazy for each node and there is no any build function
(if lazy[i] ≠ 0 then all the interval of node i is from the same color (color lazy[i])
and we haven't yet shifted the updates to its children. Every member of lazy is 0 at first).
**/

/// A function for shifting the updates to a node, to its children using lazy propagation
void shift(int id)
{
    if (lazy[id]){
        int left = 2 * id;
        int right = 2 * id + 1;
        lazy[left] = lazy[right] = lazy[id];
    }
    lazy[id] = 0;
}

///Update (paint) function (for queries)
void update(int x, int y, int color, int id = 1, int l = 0, int r = n) /// painting the interval [x, y) with color "color"
{
    if (x >= r || l >= y){
        return;
    }
    if (x <= l && r <= y){
        lazy[id] = color;
        return;
    }
    shift(id);
    int mid = (l + r) / 2;
    int left = 2 * id;
    int right = 2 * id + 1;
    update(x, y, color, left, l, mid);
    update(x, y, color, right, mid, r);
}
/// So, for each query you should call update(x, y + 1, i)
/// (i is the query's 1-base index) where sx = l and sy = r.

set<int> st;
void cnt(int id = 1, int l = 0, int r = n)
{
    if (lazy[id]){
        st.insert(lazy[id]);
        return;  /// there is no need to see the children, because all the interval is from the same color
    }
    if (r - l < 2){
        return;
    }
    int mid = (l + r) / 2;
    int left = 2 * id;
    int right = 2 * id + 1;
    cnt(left, l, mid);
    cnt(right, mid, r);
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    int t;
    scanf ("%d", &t);
    while (t--){
        int q;
        scanf ("%d", &q);
        for (int i = 1; i <= q; i++){
            int l, r;
            scanf ("%d %d", &l, &r);
            update(l, r + 1, i);
        }
        cnt();
        printf ("%d\n", st.size());
        mem(lazy, 0);
        st.clear();
    }
    return 0;
}
