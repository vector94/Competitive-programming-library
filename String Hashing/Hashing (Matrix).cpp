#include <bits/stdc++.h>
using namespace std;
#define ll                  long long int

const int NAX = 2e3+5;
const int MOD[] = {1000000007, 1000000009};
const int Base[] = {37, 43};

int text_row, text_col, pat_row, pat_col;
char text[NAX][NAX], pattern[NAX][NAX];
ll Hash_Matrix[NAX][NAX];

ll Pattern_Hash()
{
    for (int i = 0; i < pat_row; i++){
        ll P = 0;
        for (int j = 0; j< pat_col; j++){
            P = (P * Base[0] + pattern[i][j]) % MOD[0];
        }
        Hash_Matrix[i][0] = P;
    }
    for (int j = 0; j < pat_col; j++){
        ll P = 0;
        for (int i = 0; i < pat_row; i++){
            P = (P * Base[1] + Hash_Matrix[i][j]) % MOD[1];
        }
        Hash_Matrix[0][j] = P;
    }
    return Hash_Matrix[0][0];
}

void Text_Hash()
{
    ll d = 1;
    for (int i = 1; i < pat_col; i++){
        d = (d * Base[0]) % MOD[0];
    }
    for (int i = 0; i<text_row; i++){
        ll P = 0;
        for (int j = 0; j < pat_col; j++){
            P = (P * Base[0] + text[i][j]) % MOD[0];
        }
        for (int j = 0; j <= text_col-pat_col; j++){
            Hash_Matrix[i][j] = P;
            P = (((P - text[i][j] * d) % MOD[0]) * Base[0] + text[i][j+pat_col]) % MOD[0];
            P = (P + MOD[0]) % MOD[0];

        }
    }
    d = 1;
    for (int i = 1; i < pat_row; i++){
        d = (d * Base[1]) % MOD[1];
    }
    for (int j = 0; j <= text_col - pat_col; j++){
        ll P = 0;
        for (int i = 0; i < pat_row; i++){
            P = (P * Base[1] + Hash_Matrix[i][j]) % MOD[1];
        }
        for (int i = 0; i <= text_row - pat_row; i++){
            ll temp = P;
            P = (((P - Hash_Matrix[i][j] * d) % MOD[1]) * Base[1] + Hash_Matrix[i+pat_row][j]) % MOD[1];
            P = (P + MOD[1]) % MOD[1];
            Hash_Matrix[i][j] = temp;
        }
    }
}

int main ()
{
    #ifdef Lollipop
    freopen ("input.txt", "r", stdin);
    //freopen ("output.txt", "w", stdout);
    #endif

	while (scanf ("%d %d %d %d", &pat_row, &pat_col, &text_row, &text_col) != EOF){
        for (int i = 0; i < pat_row; i++){
            scanf ("%s", pattern[i]);
        }
        for (int i = 0; i < text_row; i++){
            scanf ("%s", text[i]);
        }
        ll pat_hash = Pattern_Hash();
        Text_Hash();
        int ans = 0;
        for (int i = 0; i <= text_row - pat_row; i++){
            for (int j = 0; j <= text_col - pat_col; j++){
                if (Hash_Matrix[i][j] == pat_hash){
                    ans++;
                }
            }
        }
        printf ("%d\n", ans);
	}
    return 0;
}
