/*
1. Assign MATMOD
2. Declare MAT with row and col.
*/
ll MATMOD;
struct MAT{
    ll a[x][x];///Maximum dimension of the matrix
    int row, col;
    MAT(){}
    MAT(int r, int c){
        row = r;
        col = c;
        mem(a, 0);
    }
    void assign ( int r, int c ) {
        row = r;
        col = c;
    }
    void identity(){
        mem(a, 0);
        for ( int i = 0; i < row; i++ ) a[i][i] = 1;
    }
    void print() { ///For debugging purpose
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < col; j++ ) printf ( "%llu ", a[i][j] );
            printf ( "\n" );
        }
    }
    MAT operator * ( MAT b ) { ///Matrix Multiplication N^3
        MAT res ( row, b.col );
        for ( int i = 0; i < row; i++ ){
            for ( int j = 0; j < b.col; j++ ){
                for ( int k = 0; k < col; k++ )
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * b.a[k][j] ) % MATMOD; ///Change here if no mod.
            }
        }
        return res;
    }
    MAT operator ^ ( ll p ) { ///Matrix Exponentiation
        MAT res ( row, col ); res.identity();
        MAT x = *this;
        while ( p ){
            if ( p & 1 ){
                res = res * x;
            }
            x = x * x;
            p >>= 1;
        }
        return res;
    }
};

int main ()     /// Nt'h Tribonacci Number;
{
    ll n;
    cin >> n;
    MAT F(3, 1);
    F.a[0][0] = 2;
    F.a[1][0] = 1;
    F.a[2][0] = 0;
    MAT M(3, 3);
    M.a[0][0] = 1;  M.a[0][1] = 1;  M.a[0][2] = 1;
    M.a[1][0] = 1;  M.a[1][1] = 0;  M.a[1][2] = 0;
    M.a[2][0] = 0;  M.a[2][1] = 1;  M.a[2][2] = 0;
    MAT ans = (M ^ (n - 1)) * F;
    printf ("%lld\n", ans.a[2][0]);
    return 0;
}
