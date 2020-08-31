// Solution by Ammar Fathin Sabili

#include <bits/stdc++.h>
using namespace std;

char nyan(int x, int y) {
	return 'A' + ((x + y) % 25);
}

int main() {
	for (int i = 0; i < 25; i++) {
		printf("%c%c%c\n",nyan(i,0), nyan(i,2), nyan(i,2+4));
		printf("%c%c%c\n",nyan(i,0), nyan(i,1), nyan(i,1+9));
		printf("%c%c%c\n",nyan(i,0), nyan(i,3), nyan(i,3+8));
		printf("%c%c%c\n",nyan(i,0), nyan(i,5), nyan(i,5+7));
	}
}

