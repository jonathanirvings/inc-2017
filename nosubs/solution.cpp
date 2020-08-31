// Solution by Suhendry Effendy

#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)      for ( int i = 0, _n = (n); i < _n; i++ )
#define FOR(i,a,b)    for ( int i = (a), _n = (b); i <= _n; i++ )
#define FORD(i,a,b)   for ( int i = (a), _n = (b); i >= _n; i-- )
#define FORS(i,a,b,c) for ( int i = (a), _n = (b); i <= _n; i += c )
#define FOREACH(p,s)  for ( __typeof((s).begin()) p=(s).begin(); p!=(s).end(); p++)

const int maxn = 1005;

char s[maxn];

int main(int argc, char *argv[]) {
	
	scanf( "%s", s );

	int hi = 0, curr = 0;
	REP(i,strlen(s)) {
		if ( s[i] == 'a' ) curr++;
		else curr = 0;
		hi = max(hi,curr);
	}

	REP(i,hi+1) putchar( 'a' );
	puts("");
	
	return 0;
}
