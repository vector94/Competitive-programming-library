/// First call the build Function before anything
/// Then modify the tree accordingly
/// 1-based
namespace SegmentTree{
    #define Left (node*2)
    #define Right (node*2+1)
    #define mid ((lo+hi)/2)

    ll lazy[nax * 5];
    ll minTree[nax * 5];
    ll maxTree[nax * 5];

    void build(int node, int lo, int hi){
        minTree[node] = maxTree[node] = lazy[node] = 0;
        if(lo == hi) return;
        build(Left, lo, mid);
        build(Right, mid+1, hi);
    }

    void lazyPropagation(int node, int lo, int hi){
        minTree[node] += lazy[node];
        maxTree[node] += lazy[node];
        if(lo != hi){
            lazy[Left] += lazy[node];
            lazy[Right] += lazy[node];
        }
        lazy[node] = 0;
    }

    void updateRange(int node, int lo, int hi, int i, int j, ll val){
        lazyPropagation(node,lo,hi);
        if(lo > hi || lo > j || hi < i) return;
        if(lo >= i && hi <= j){
            lazy[node] += val;
            lazyPropagation(node,lo,hi);
            return;
        }
        updateRange(Left,lo,mid,i,j,val);
        updateRange(Right,mid+1,hi,i,j,val);
        minTree[node] = min(minTree[Left], minTree[Right]);
        maxTree[node] = max(maxTree[Left], maxTree[Right]);
    }

    ll queryMax(int node, int lo, int hi, int i, int j){
        if(lo > hi || lo > j || hi < i) return LLONG_MIN;
        lazyPropagation(node,lo,hi);
        if(lo >= i && hi <= j) return maxTree[node];
        ll p1 = queryMax(Left, lo, mid,i,j);
        ll p2 = queryMax(Right,mid+1,hi,i,j);
        return max(p1, p2);
    }

    ll queryMin(int node, int lo, int hi, int i, int j){
        if(lo > hi || lo > j || hi < i) return 0;
        lazyPropagation(node,lo,hi);
        if(lo >= i && hi <= j) return minTree[node];
        ll p1 = queryMin(Left, lo, mid,i,j);
        ll p2 = queryMin(Right,mid+1,hi,i,j);
        return min(p1, p2);
    }
}
using namespace SegmentTree;
