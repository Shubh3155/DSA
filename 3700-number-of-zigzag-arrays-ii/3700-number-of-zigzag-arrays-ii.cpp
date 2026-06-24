class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                long long cur = A[i][k];
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + cur * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix res(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp) {
            if (exp & 1)
                res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        // up(x) = sum_{y<x} down(y)
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < x; y++)
                T[x][m + y] = 1;
        }

        // down(x) = sum_{y>x} up(y)
        for (int x = 0; x < m; x++) {
            for (int y = x + 1; y < m; y++)
                T[m + x][y] = 1;
        }

        Matrix P = power(T, n - 2);

        vector<long long> base(S);

        // length = 2
        for (int x = 0; x < m; x++) {
            base[x] = x;
            base[m + x] = m - 1 - x;
        }

        long long ans = 0;

        for (int i = 0; i < S; i++) {
            long long val = 0;
            for (int j = 0; j < S; j++) {
                val = (val + P[i][j] * base[j]) % MOD;
            }
            ans = (ans + val) % MOD;
        }

        return ans;
    }
};