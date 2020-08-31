// Solution by Pusaka Kaleb Setyabudi

#include <bits/stdc++.h>

#define __INIT_CC__ ios::sync_with_stdio(false); \
	cin.tie(0);

#ifdef __WIN32__
	char getchar_unlocked() {return getchar();}
#endif

#define FOR(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<(_t);++(_i))
#define FORN(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i<=(_t);++(_i))
#define FORD(_i,_n,_m) for(int (_i)=(_n),_t=(_m);_i>=(_t);--(_i))
#define RESET(_a,_value) memset(_a,_value,sizeof(_a))
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ff first
#define ss second
#define mp make_pair
#define SIZE(_a) (int)_a.size()
#define VSORT(_a) sort(_a.begin(),_a.end())
#define SSORT(_a,_val) sort(_a,_a+(_val))
#define ALL(_a) _a.begin(),_a.end()
#define mt make_tuple
#define _get(_tuple,_i) get<_i>(_tuple)
#define eb emplace_back
 
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;
using ll = long long;
using ull = unsigned long long;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vll = vector<ll>;
using pdd = pair<double,double>;
using vpdd = vector<pdd>;
template <typename T> using uset = unordered_set<T>;
template <typename T> using umultiset = unordered_multiset<T>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using umultimap = unordered_multimap<K, V>;

const int dr[] = { 1, 0,-1, 0, 1, 1,-1,-1};
const int dc[] = { 0, 1, 0,-1, 1,-1,-1, 1};
const double eps = 1e-9;
const int INF = 0x7FFFFFFF;
const ll INFLL = 0x7FFFFFFFFFFFFFFFLL;
const double pi = acos(-1);

template <typename T> T take(queue<T> &O) {T tmp=O.front();O.pop();return tmp;}
template <typename T> T take(stack<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T> T take(priority_queue<T> &O) {T tmp=O.top();O.pop();return tmp;}
template <typename T>
inline bool inRange(const T& z, const T& a, const T& b){return a <= z && z <= b;}

void OPEN(const string& in = "input.txt", const string& out = "output.txt")
{
	freopen(in.c_str(), "r", stdin);
	freopen(out.c_str(), "w", stdout);
	return ;
}

//using sokokaleb's template v4.0

int t, n, r[2], c[2];
const int MOD = 1000000007;
const int INV2 = 500000004;
const int INV6 = 166666668;

template<typename T, typename V>
inline void add(T& val, V added) {
	val += added;
	if (val >= MOD) {
		val -= MOD;
	}
	if (val < 0) {
		val += MOD;
	}
	return ;
}

template<typename T, typename V>
inline void mul(T& val, V muled) {
	val = 1LL * val * muled % MOD;
	return ;
}

template<size_t N, typename T>
struct Matrix {
	T c[N][N];

	Matrix() {
		RESET(c, 0);
	}

	void make_identity() {
		RESET(c, 0);
		FOR (i, 0, N) {
			c[i][i] = 1;
		}
	}

	void clear() {
		RESET(c, 0);
	}

	friend Matrix<N, T> operator * (const Matrix<N, T>& O1, const Matrix<N, T>& O2) {
		Matrix<N, T> res = O1;
		res *= O2;
		return res;
	}

	Matrix<N, T>& operator *= (const Matrix<N, T>& O) {
		T tmp[N][N];
		RESET(tmp, 0);
		FOR (k, 0, N) {
			FOR (i, 0, N) {
				FOR (j, 0, N) {
					add(tmp[i][j], 1LL * c[i][k] * O.c[k][j] % MOD);
				}
			}
		}
		memcpy(&c, &tmp, N * N * sizeof(T));
		return *this;
	}

	friend Matrix<N, T> operator ^ (const Matrix<N, T>& Mat, const int x) {
		Matrix<N, T> res = Mat;
		Mat ^= x;
		return Mat;
	}

	Matrix<N, T>& operator ^= (const int xx) {
		int x = xx;
		Matrix<N, T> res;
		res.make_identity();
		while (x) {
			if (x & 1) res *= *this;
			*this *= *this;
			x >>= 1;
		}
		*this = res;
		return *this;
	}

	friend ostream& operator << (ostream& os, const Matrix<N, T>& O) {
		os << "[\n";
		FOR (i, 0, N) {
			FOR (j, 0, N) {
				os << setw(4) << O.c[i][j] << ",";
			}
			os << endl;
		}
		os << "]";
		return os;
	}
};

/**
 * 1 | 0
 *   |
 * --+--
 *   |  
 * 2 | 3
 */

using Mamat = Matrix<8, int>;

ll ans;
Mamat prec[31];
vi precvec[4] = {
	{1, 1, 3, 1, 1, 1, 3, 0},
	{1, 1, 1, 1, 1, 1, 1, 0},
	{1, 2, 7, 1, 1, 2, 7, 0},
	{1, 1, 5, 1, 1, 1, 5, 0}
};

void init() {
	prec[0].clear();

	Mamat& m = prec[1];
	m.clear();
	m.c[0][0] = 1;
	m.c[0][2] = 8;
	m.c[0][3] = 2;
	m.c[0][4] = 4;
	m.c[0][6] = 16;
	m.c[1][1] = 1;
	m.c[1][5] = 2;
	m.c[2][1] = 1;
	m.c[2][2] = 1;
	m.c[2][5] = 2;
	m.c[2][6] = 2;
	m.c[3][3] = 1;
	m.c[3][4] = 4;
	m.c[3][6] = 8;
	m.c[3][7] = MOD - INV2;
	m.c[4][4] = 1;
	m.c[4][7] = INV2;
	m.c[5][5] = 1;
	m.c[5][7] = 1;
	m.c[6][5] = 1;
	m.c[6][6] = 1;
	m.c[7][7] = 1;

	FORN (j, 2, 30) {
		prec[j] = prec[j - 1] * prec[j - 1];
	}
}

ll linear_solve(int x, int dup, int a0, int b0, bool minus) {
	// x is 0-based
	ll _a = 0LL;
	ll _b = 0LL;
	ll _8 = 0LL;

	add(_a, x + 1);
	mul(_a, a0);

	add(_b, x + 1);
	mul(_b, x);
	mul(_b, INV2);
	mul(_b, b0);

	add(_8, x - 1);
	mul(_8, x);
	mul(_8, x + 1);
	mul(_8, INV6);
	mul(_8, 8);

	ll deduct = 0LL;
	add(deduct, dup);
	mul(deduct, dup - 1);
	mul(deduct, INV2);
	mul(deduct, x + 1);
	if (minus) {
		if (deduct != 0LL)
			deduct = MOD - deduct;
	}

	ll res = 0LL;
	add(res, _a);
	add(res, _b);
	add(res, _8);

	mul(res, dup);
	add(res, deduct);

	return res;
}

ll __solve(int x, int y, int origin, int dminus, int dplus, int idx) {
	if (x < 0 || y < 0) return 0LL;
	ll res = 0LL;

	//cerr << "MASUK " << idx << ": " << x << " " << y << endl;

	int mn = min(x, y) + 1;
	Mamat m;
	const vi& precvec = ::precvec[idx];
	m.make_identity();
	//cerr << "mn-nya " << mn << endl;
	while (mn > 0) {
		int pos = __builtin_ctz(mn) + 1;
		mn ^= (1 << (pos - 1));
		m *= prec[pos];
	}

	//cerr << m << endl;

	FOR (i, 0, 8) {
		add(res, 1LL * precvec[i] * m.c[i][7] % MOD);
	}

	//cerr << "TMP RES " << res << endl;

	mn = min(x, y);
	ll a0, b0, tmp;
	a0 = b0 = 0;

	if (x != mn) {
		tmp = linear_solve(mn, 1, origin, dminus, 0);
		a0 = linear_solve(mn + 1, 1, origin, dminus, 0);
		b0 = linear_solve(mn + 2, 1, origin, dminus, 0);
		add(b0, -a0);
		add(a0, -tmp);
		add(b0, -a0);
		res += linear_solve(x - mn - 1, y + 1, a0, b0, 1);
	}

	if (y != mn) {
		tmp = linear_solve(mn, 1, origin, dplus, 0);
		a0 = linear_solve(mn + 1, 1, origin, dplus, 0);
		b0 = linear_solve(mn + 2, 1, origin, dplus, 0);
		add(b0, -a0);
		add(a0, -tmp);
		add(b0, -a0);
		res += linear_solve(y - mn - 1, x + 1, a0, b0, 0);
	}

	add(res, 0);
	
	//cerr << "final res " << res << endl;

	return res;
}

ll solve0(int r0, int c0, int r1, int c1) {
	if (r0 <= 0 && c1 >= 0);
	else return 0LL;

	c0 = max(c0, 0);
	r1 = min(r1, 0);

	int x0, y0, x1, y1;
	x0 = c0;
	y0 = abs(r1);
	x1 = c1;
	y1 = abs(r0);

	int dm, dp, origin, id = 0;
	tie(dm, dp) = mt(5, 3);
	origin = 1;
	
	ll res = 0LL;
	add(res, __solve(x1, y1, origin, dm, dp, id));
	add(res, __solve(x0 - 1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x0 - 1, y1, origin, dm, dp, id));
	return res;
}

ll solve1(int r0, int c0, int r1, int c1) {
	if (r0 <= -1 && c0 <= -1);
	else return 0LL;

	c1 = min(c1, -1);
	r1 = min(r1, -1);

	int x0, y0, x1, y1;
	x0 = abs(r1);
	y0 = abs(c1);
	x1 = abs(r0);
	y1 = abs(c0);
	
	int dm, dp, origin, id = 1;
	tie(dm, dp) = mt(3, 1);
	origin = 1;
	
	ll res = 0LL;
	add(res, __solve(x1, y1, origin, dm, dp, id));
	add(res, __solve(x0 - 1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x0 - 1, y1, origin, dm, dp, id));
	return res;
}

ll solve2(int r0, int c0, int r1, int c1) {
	if (r1 >= 0 && c0 <= -1);
	else return 0LL;

	r0 = max(r0, 0);
	c1 = min(c1, -1);

	int x0, y0, x1, y1;
	x0 = abs(c1 + 1);
	y0 = r0;
	x1 = abs(c0 + 1);
	y1 = r1;

	int dm, dp, origin, id = 2;
	tie(dm, dp) = mt(9, 7);
	origin = 2;
	
	ll res = 0LL;
	add(res, __solve(x1, y1, origin, dm, dp, id));
	add(res, __solve(x0 - 1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x0 - 1, y1, origin, dm, dp, id));
	return res;
}

ll solve3(int r0, int c0, int r1, int c1) {
	if (r1 >= 1 && c1 >= 0);
	else return 0LL;

	r0 = max(r0, 1);
	c0 = max(c0, 0);

	int x0, y0, x1, y1;
	x0 = r0;
	y0 = c0;
	x1 = r1;
	y1 = c1;

	int dm, dp, origin, id = 3;
	tie(dm, dp) = mt(7, 5);
	origin = 1;
	
	ll res = 0LL;
	add(res, __solve(x1, y1, origin, dm, dp, id));
	add(res, __solve(x0 - 1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x1, y0 - 1, origin, dm, dp, id));
	add(res, -__solve(x0 - 1, y1, origin, dm, dp, id));
	return res;
}

int main(int argc, char** argv) {
	__INIT_CC__;
	init();
	//cin >> t;
	t = 1;
	FORN (tc, 1, t) {
		ans = 0LL;
		cin >> n;
		int mid = (n + 2) >> 1;
		cin >> r[0] >> r[1] >> c[0] >> c[1];
		FOR (i, 0, 2) {
			r[i] -= mid;
			c[i] -= mid;
		}
		add(ans, solve0(r[0], c[0], r[1], c[1]));
		add(ans, solve1(r[0], c[0], r[1], c[1]));
		add(ans, solve2(r[0], c[0], r[1], c[1]));
		add(ans, solve3(r[0], c[0], r[1], c[1]));
		cout << ans << "\n";
	}
}
