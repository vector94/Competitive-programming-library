#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
int ara[nax];
int tree[4 * nax];
int lazy[4 * nax];
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

void update(int node, int l, int r, int x){    /// increase all members in this interval by x
	lazy[node] += x;
	tree[node] += (r - l) * x;
}

void shift(int node, int l, int r){             ///pass update information to the children
	int mid = (l + r) / 2;
	update(node * 2, l, mid, lazy[node]);
	update(node * 2 + 1, mid, r, lazy[node]);
	lazy[node] = 0;             /// passing is done
}
void increase(int x, int y, int v, int node = 1, int l = 0, int r = n){
	if(x >= r || l >= y){
        return;
	}
	if(x <= l && r <= y){
		update(node, l, r, v);
		return;
	}
	shift(node, l, r);
	int mid = (l + r) / 2;
	increase(x, y, v, node * 2, l, mid);
	increase(x, y, v, node * 2 + 1, mid, r);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int sum(int x, int y, int node = 1, int l = 0, int r = n){
	if(x >= r || l >= y){
        return 0;
	}
	if(x <= l && r <= y){
        return tree[node];
	}
	shift(node, l, r);
	int mid = (l+r)/2;
	return sum(x, y, node * 2, l, mid) + sum(x, y, node * 2 + 1, mid, r);
}

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
            int l, r, v;
            cin >> l >> r >> v;
            increase(l, r + 1, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << sum(l, r + 1) << endl;          /// interval [l, r)
        }
    }
    return 0;
}
