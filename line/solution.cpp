// Solution by Winardi Kurniawan

#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAX_N = 50010;

vector<int> v[MAX_N];
bool visited[MAX_N];

int cnt[MAX_N];

int traverse(int src){
	visited[src] = true;
	
	int res = 0;
	int numOdd = (v[src].size() % 2);

	for(int i=0; i<v[src].size(); i++){
		int dest = v[src][i];
		if(!visited[dest]){
			numOdd += traverse(dest);
		}
	}

	return numOdd;
}

int main(){
	int n;
	int first, second;

	memset(visited, false, sizeof(visited));
	memset(cnt, 0, sizeof(cnt));

	for(int i=0; i<MAX_N; i++){
		v[i].clear();
	}
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &first, &second);
		v[first].push_back(second);
		v[second].push_back(first);
		cnt[first]++;
		cnt[second]++;
	}

	int res = 0;
	for(int i=0; i<MAX_N; i++){
		if(cnt[i] != 0 && !visited[i]){
			int val = traverse(i);
			// printf("-- %d %d\n", i, val);
			res += max(1, val / 2);
		}
	}

	printf("%d\n", res);

	return 0;
}