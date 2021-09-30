#include <bits/stdc++.h>
using namespace std;

namespace rho{
    const int MAXP = 1000010;
    const int BASE[] = {2, 450775, 1795265022, 9780504, 28178, 9375, 325};

    long long seq[MAXP];
    int primes[MAXP], spf[MAXP];


    unsigned long long gcd(unsigned long long u, unsigned long long v){
        if (!u) return v;
        if (!v) return u;
        if (u == 1 || v == 1) return 1;

        int shift = __builtin_ctzll(u | v);
        u >>= __builtin_ctzll(u);
        do{
            v >>= __builtin_ctzll(v);
            if (u > v)
                v ^= u ^= v ^= u;
            v = v - u;
        } while (v);

        return u << shift;
    }

    inline long long mod_add(long long x, long long y, long long m){
        return (x += y) < m ? x : x - m;
    }

    inline long long mod_mul(long long x, long long y, long long m){
        long long res = x * y - (long long)((long double)x * y / m + 0.5) * m;
        return res < 0 ? res + m : res;
    }

    inline long long mod_pow(long long x, long long n, long long m){
        long long res = 1 % m;
        for (; n; n >>= 1){
            if (n & 1) res = mod_mul(res, x, m);
            x = mod_mul(x, x, m);
        }

        return res;
    }

    inline bool miller_rabin(long long n){
        if (n <= 2 || (n & 1 ^ 1)) return (n == 2);
        if (n < MAXP) return spf[n] == n;

        long long c, d, s = 0, r = n - 1;
        for (; !(r & 1); r >>= 1, s++) {}

        for (int i = 0; i < 7; i++){
            c = mod_pow(BASE[i], r, n);
            for (int j = 0; j < s; j++){
                d = mod_mul(c, c, n);
                if (d == 1 && c != 1 && c != (n - 1)) return false;
                c = d;
            }

            if (c != 1) return false;
        }
        return true;
    }

    inline void init(){
        int i, j, k, cnt = 0;

        for (i = 2; i < MAXP; i++){
            if (!spf[i]) primes[cnt++] = spf[i] = i;
            for (j = 0, k; (k = i * primes[j]) < MAXP; j++){
                spf[k] = primes[j];
                if(spf[i] == spf[k]) break;
            }
        }
    }

    long long pollard_rho(long long n){
        while (1){
            long long x = rand() % n, y = x, c = rand() % n, u = 1, v, t = 0;
            long long *px = seq, *py = seq;

            while (1){
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                *py++ = y = mod_add(mod_mul(y, y, n), c, n);
                if((x = *px++) == y) break;

                v = u;
                u = mod_mul(u, abs(y - x), n);

                if (!u) return gcd(v, n);
                if (++t == 32){
                    t = 0;
                    if ((u = gcd(u, n)) > 1 && u < n) return u;
                }
            }

            if (t && (u = gcd(u, n)) > 1 && u < n) return u;
        }
    }

    vector <long long> factorize(long long n){
        if (n == 1) return vector <long long>();
        if (miller_rabin(n)) return vector<long long> {n};

        vector <long long> v, w;
        while (n > 1 && n < MAXP){
            v.push_back(spf[n]);
            n /= spf[n];
        }

        if (n >= MAXP) {
            long long x = pollard_rho(n);
            v = factorize(x);
            w = factorize(n / x);
            v.insert(v.end(), w.begin(), w.end());
        }

        sort(v.begin(), v.end());
        return v;
    }
}

int main(){
    rho :: init();
    long long x;
    cin >> x;
    auto fact = rho :: factorize(x);
    Unique(fact);
    for (auto p : fact){
        cout << p << " ";
    }
    cout << endl;
    return 0;
}
