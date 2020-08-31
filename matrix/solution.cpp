// Solution by Suhendry Effendy

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define FORS(i,a,b,c) for ( int i = (a), _n = (b); i <= _n; i += c )
#define FOREACH(p,s)  for ( __typeof((s).begin()) p=(s).begin(); p!=(s).end(); p++)

const int maxn = 55;

int R, C;
int A[maxn][maxn];
int Q, x, val;
char cmd[10];

int main(int argc, char *argv[]) {
	
	scanf( "%d %d", &R, &C );
	FOR(i,1,R) FOR(j,1,C) scanf( "%d", &A[i][j] );

	scanf( "%d", &Q );
	while ( Q-- ) {
		scanf( "%s %d %d", cmd, &x, &val );
		if      ( cmd[0] == 'r' ) FOR(j,1,C) A[x][j] += val;
		else if ( cmd[0] == 'c' ) FOR(i,1,R) A[i][x] += val;
	}

	int sum = 0;
	int mn = A[1][1];
	int mx = A[1][1];

	FOR(i,1,R) FOR(j,1,C) sum += A[i][j];
	FOR(i,1,R) FOR(j,1,C) mn = min(mn,A[i][j]);
	FOR(i,1,R) FOR(j,1,C) mx = max(mx,A[i][j]);

	printf( "%d %d %d\n", sum, mn, mx );
	
	return 0;
}
