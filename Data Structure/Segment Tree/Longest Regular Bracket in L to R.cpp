#include <bits/stdc++.h>
using namespace std;

/**
For each node (for example x), we keep three integers:
    1. t[x] = Answer for it's interval.
    2. o[x] = The number of '('s after deleting the brackets who belong to the correct bracket sequence in this interval whit length t[x].
    3. c[x] = The number of ')'s after deleting the brackets who belong to the correct bracket sequence in this interval whit length t[x].

Lemma : For merging to nodes 2x and 2x + 1 (children of node 2x + 1) all we need to do is this:
    tmp = min(o[2 * x], c[2 * x + 1])
    t[x] = t[2 * x] + t[2 * x + 1] + tmp
    o[x] = o[2 * x] + o[2 * x + 1] - tmp
    c[x] = c[2 * x] + c[2 * x + 1] - tmp
**/
/// [Note: every node contains the range [l, r). r is not included]

const int nax = 1e5 + 5;
int n;
string s;
int t[4 * nax];     /// Answer for this interval (length of the maximum subsequence)
int o[4 * nax];     /// Number of '(' that does not belong to the subsequence in this interval
int c[4 * nax];     /// Number of ')' that does not belong to the subsequence in this interval

void build(int id = 1, int l = 0, int r = n)
{
    if (r - l < 2){
        if (s[l] == '('){
            o[id] = 1;
            c[id] = 0;
            t[id] = 0;
        }
        else{
            o[id] = 0;
            c[id] = 1;
            t[id] = 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    int left = 2 * id;
    int right = 2 * id + 1;
    build (left, l, mid);
    build(right, mid, r);
    int tmp = min(o[left], c[right]);
    t[id] = t[left] + t[right] + tmp;
    o[id] = o[left] + o[right] - tmp;
    c[id] = c[left] + c[right] - tmp;
}

/// Query function. It returns 3 variables (T, O, C)
typedef pair<int, int> pii;
typedef pair<int, pii> node;
node segment(int x, int y, int id = 1, int l = 0, int r = n)
{
    if (l >= y || x >= r){
        return node(0, pii(0, 0));
    }
    if (x <= l && r <= y){
        return node(t[id], pii(o[id], c[id]));
    }
    int mid = (l + r) / 2;
    int left = id * 2;
    int right = id * 2 + 1;
    node a = segment(x, y, left, l, mid);
    node b = segment(x, y, right, mid, r);
    int T, temp, O, C;
    temp = min(a.second.first, b.second.second);
    T = a.first + b.first + temp;
    O = a.second.first + b.second.first - temp;
    C = a.second.second + b.second.second - temp;
    return node (T, pii(O, C));
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> s;
    n = s.size();
    build();
    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << 2 * segment(l - 1, r).first << endl;
    }
    return 0;
}
