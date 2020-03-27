********************** Fraction ****************************/
#define ll long long int
inline ll gcd( ll a , ll b) {
        return b == 0 ? a : gcd( b , a%b );
}
struct Fraction {
        ll n, d;
        Fraction( ) { n = 0, d = 1; }
        Fraction( ll _n, ll _d ) : n(_n), d(_d) { }
        Fraction operator+(const Fraction& p) const{
                ll g = gcd(d, p.d);
                ll td = d * (p.d / g);
                ll tn = n * (td/d) + p.n * (td/p.d);
                g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator-(const Fraction& p) const{
                ll g = gcd(d, p.d);
                ll td = d * (p.d / g);
                ll tn = n * (td/d) - p.n * (td/p.d);
                g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator*(const Fraction& p) const{
                ll g1 = gcd(n, p.d), g2 = gcd(p.n, d);
                ll tn = (n/g1) * (p.n/g2);
                ll td = (d/g2) * (p.d/g1);
                ll g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        Fraction operator/(const Fraction& p) const{
                ll g1 = gcd(n, p.n), g2 = (d, p.d);
                ll tn = (n/g1) * (p.d/g2);
                ll td = (d/g2) * (p.n/g1);
                ll g = gcd(tn, td);
                tn /= g, td /= g;
                return Fraction(tn, td);
        }
        bool operator==(const Fraction& p) const{
                return n == p.n and d == p.d;
        }
        bool operator!=(const Fraction& p) const{
                return !(*this == p);
        }
        bool operator<(const Fraction& b) const {
                if(n == b.n) return d < b.d;
                return n < b.n;
        }
};

ostream& operator<<(ostream &out, Fraction p) {
        out << p.n << "/" << p.d;
}

const Fraction ONE = Fraction(1, 1);
const Fraction ZERO = Fraction(0, 1);
const Fraction NEGO = Fraction(-1, 1);
/************************************************************/
