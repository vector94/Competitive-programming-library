#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
int ara[nax];
int tree[4 * nax];
int n;

void build(int node = 1, int l = 0, int r = n){
	if(r - l < 2){	            ///	l + 1 == r
		tree[node] = ara[l];
		return ;
	}
	int mid = (l+r)/2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void modify(int p, int x, int node = 1, int l = 0, int r = n){
	tree[node] += x - ara[p];
	if(r - l < 2){	            ///	l = r - 1
		ara[p] = x;
		return;
	}
	int mid = (l + r) / 2;
	if(p < mid){
		modify(p, x, node * 2, l, mid);
	}
	else{
		modify(p, x, node * 2 + 1, mid, r);
	}
}

int sum(int x, int y, int node = 1, int l = 0, int r = n){        /// interval [l, r)
	if(x >= r || l >= y){
        return 0;
	}
	if(x <= l && r <= y){
        return tree[node];
	}
	int mid = (l + r) / 2;
	return sum(x, y, node * 2, l, mid) + sum(x, y, node * 2 + 1, mid, r);
}
/// [Note: every node contains the range [l, r). r is not included]

int main ()
{
    #ifdef Lollipop
        //freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ara[i];
    }
    build();            /// 0 - based
    int q;
    cin >> q;
    while (q--){
        int type;
        cin >> type;
        if (type == 1){
            int i, v;
            cin >> i >> v;
            modify(i, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << sum(l, r + 1) << endl; 	/// interval [l, r)
        }
    }
    return 0;
}
