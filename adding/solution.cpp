// Solution by Ammar Fathin Sabili

#include <bits/stdc++.h>
using namespace std;

int i,n,k;
int a[107];
int sum[4][50007], mem[107][50007];

int cum(int minim, int maxim) {
	int mod = minim % 3;
	return sum[mod][maxim] - (minim < 3 ? 0 : sum[mod][minim-3]);
}

int main() {
	scanf("%d",&n);
	for (i=1 ; i<=n ; i++) scanf("%d",&a[i]);
	
	mem[n][0] = 1;
	sum[0][0] = mem[n][0];
	sum[1][1] = mem[n][1];
	sum[2][2] = mem[n][2];
	for (i=3 ; i<=50000 ; i++) {
		sum[i%3][i] = sum[i%3][i-3] + mem[n][i];
	}
	//for (i=0 ; i<=a[n] ; i++) printf("mem[%d][%d] = %d\n",n,i,mem[n][i]); printf("\n");
	
	for (k=n-1 ; k>=1 ; k--) {
		for (i=0 ; i<=a[k] ; i++) {
			int minim = i/2 + (i%2)*2;
			int maxim = min(2*i,a[k+1]);
			while (minim % 3 != (maxim % 3 + 3) % 3) maxim--;
			mem[k][i] = (minim > maxim ? 0 : min(1,cum(a[k+1]-maxim,a[k+1]-minim)));
		}
		
		sum[0][0] = mem[k][0];
		sum[1][1] = mem[k][1];
		sum[2][2] = mem[k][2];
		for (i=3 ; i<=50000 ; i++) {
			sum[i%3][i] = sum[i%3][i-3] + mem[k][i];
		}
		//for (i=0 ; i<=a[k] ; i++) printf("mem[%d][%d] = %d\n",k,i,mem[k][i]); printf("\n");
	}
	
	if (mem[1][a[1]] > 0) printf("YES\n"); else printf("NO\n");
}
