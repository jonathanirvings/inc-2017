// Solution by Anthony

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
	vector<vector<int>> v;

	Matrix(const vector<vector<int>>& arr) {
		v = arr;
	}

	Matrix(int n, int m) {
		v.assign(n, vector<int>(m, 0));
	}

	Matrix operator * (const Matrix& other) const {
		int n = v.size();
		int m = v[0].size();
		int k = other.v[0].size();

		Matrix res = Matrix(n, k);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < k; ++j) {
				res.v[i][j] = 0;
				for (int l = 0; l < m; ++l) {
					(res.v[i][j] += ((long long)v[i][l] * other.v[l][j]) % MOD) %= MOD;
				}
			}
		}
		return res;
	}

	Matrix operator ^ (long long power) const {
		Matrix base = Matrix(v);
		int n = v.size();
		Matrix res = Matrix(n, n);
		for (int i = 0; i < n; ++i) {
			res.v[i][i] = 1;
		}
		while (power) {
			if (power & 1) res = res * base;
			base = base * base;
			power >>= 1;
		}
		return res;
	}
};

const Matrix initialMatrix = Matrix({{1, 1}, {0, 0}});

int calc(int from, int to, int n, long long dist) {
	Matrix p = Matrix({{n - 1, n - 1}, {0 , -1}}) ^ (dist - 1);
	Matrix res = initialMatrix * p;
	return res.v[0][1] - (from == to) * p.v[1][1];
}

int modExp(int b, long long p) {
	int x = 1;
	while (p) {
		if (p & 1) x = ((long long) x * b) % MOD;
		b = ((long long) b * b) % MOD;
		p >>= 1;
	}
	return x;
}

int main() {
	int n, k, curPos, prevPos;
	long long m, curDist, prevDist;
	scanf("%d %lld %d", &n, &m, &k);
	int ans = 1;
	for (int i = 0; i < k; ++i) {
		scanf("%lld %d", &curDist, &curPos);
		if (i) {
			(ans = ((long long) ans * calc(prevPos, curPos, n, curDist - prevDist)) % MOD) %= MOD;
		} else {
			ans = ((long long) ans * modExp(n - 1, curDist - 1)) % MOD;
		}
		prevDist = curDist;
		prevPos = curPos;
	}
	if (curDist < m) {
		ans = ((long long) ans * modExp(n - 1, m - curDist)) % MOD;
	}
	if (ans < 0) ans += MOD;
	printf("%d\n", ans);
	return 0;
}