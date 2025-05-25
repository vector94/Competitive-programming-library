class Solution {
public:
    int mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int p, vector<int>& nums) {
        vector<int> freq(26, 0);

        for (char ch : s){
            freq[ch - 'a']++;
        }

        vector<vector<int> > t(26, vector<int> (26, 0));
        for (int i = 0; i < 26; i++){
            for (int j = i + 1; j <= i + nums[i]; j++){
                t[j % 26][i]++;
            }
        }

        vector<vector<int> > res = matrixExpo(t, p);

        vector<int> finalFreq(26, 0);
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                finalFreq[i] += (1LL * res[i][j] * freq[j]) % mod;
                finalFreq[i] %= mod;

            }
        }

        int result = 0;
        for (int i = 0; i < 26; i++){
            result += finalFreq[i];
            result %= mod;
        }

        return result;
    }

    vector<vector<int> > matrixMultiplication(vector<vector<int> >& A, vector<vector<int> >& B){
        vector<vector<int>> res(26, vector<int>(26));

        for (int i = 0; i < 26; i++){
            for (int j = 0; j < 26; j++){
                for (int k = 0; k < 26; k++){
                    res[i][j] += (1LL * A[i][k] * B[k][j]) % mod;
                    res[i][j] %= mod;
                }
            }
        }

        return res;
    }

    vector<vector<int> > matrixExpo(vector<vector<int> >& t, int p){
        vector<vector<int> > res(26, vector<int> (26, 0));

        for (int i = 0; i < 26; i++){
            res[i][i] = 1;
        }

        while (p){
            if (p & 1){
                res = matrixMultiplication(t, res);
            }

            t = matrixMultiplication(t, t);
            p /= 2;
        }

        return res;
    }
};
