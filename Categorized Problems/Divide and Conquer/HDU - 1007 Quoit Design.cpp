#include <bits/stdc++.h>
using namespace std;
#define ll                      long long int
#define fi                      first
#define se                      second
#define pb                      push_back
#define pbb                     pop_back
#define mp                      make_pair
#define pii     	            pair<int,int>
#define all(x)                  x.begin(), x.end()
#define mem(array, value)       memset(array, value, sizeof(array))
#define fastRead 	            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define eps     	            1e-10
#define FABS(x)                 ((x) + eps < 0 ? -(x) : (x))
#define SQ(x)                   ((x) * (x))

const double inf = 1e18;
const int nax = 1e5 + 5;
struct point
{
    double x, y;
    point() {}
    point(double x, double y){
        this -> x = x;
        this -> y = y;
    }
};
point ara[nax], v[nax];
bool cmpx(point &a, point &b)
{
    return a.x < b.x;
}
bool cmpy(point &a, point &b)
{
    return a.y < b.y;
}
double get_distance(point a, point b)
{
    return sqrt(SQ(a.x - b.x) + SQ(a.y - b.y));
}
double closest_pair(int left, int right)
{
    double ret = inf;
    if (left == right){
        return ret;
    }
    if (left + 1 == right){
        return get_distance(ara[left], ara[right]);
    }
    int mid = (left + right) >> 1;
    double ret1 = closest_pair(left, mid);
    double ret2 = closest_pair(mid, right);
    ret = min(ret1, ret2);
    int len = 0;
    for (int i = left; i <= right; i++){
        if (FABS(ara[i].x - ara[mid].x) <= ret){
            v[len++] = ara[i];
        }
    }
    sort(v, v + len, cmpy);
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len && v[j].y - v[i].y <= ret; j++){
            double d = get_distance(v[i], v[j]);
            ret = min(ret, d);
        }
    }
    return ret;
}

int main ()
{
    #ifdef Lollipop
        freopen ("input.txt", "r", stdin);
        //freopen ("output.txt", "w", stdout);
    #endif
    //fastRead;
    int n;
    while (scanf("%d", &n)){
        if (n == 0){
            break;
        }
        for (int i = 0; i < n; i++){
            double x, y;
            scanf ("%lf %lf", &x, &y);
            ara[i] = point(x, y);
        }
        sort(ara, ara + n, cmpx);
        double res = closest_pair(0, n - 1) / 2;
        printf ("%.2f\n", res);
    }
    return 0;
}

