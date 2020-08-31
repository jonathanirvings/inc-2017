// Solution by Jonathan Irvin Gunawan

#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int maximum_number_of_elements(int N, const vector<int> &A, int dif) {
  int last = A[0];
  int ans = 1;
  for (int i = 1; i < N; ++i) {
    if (last + dif <= A[i]) {
      last = A[i];
      ++ans;
    }
  }
  return ans;
}

int main() {
  int N, K;
  scanf("%d %d", &N, &K);
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &A[i]);
  }
  sort(A.begin(), A.end());
  int L = 0;
  int R = INF;
  int ans = -1;
  while (L <= R) {
    int M = (L + R) >> 1;
    if (maximum_number_of_elements(N, A, M) >= K) {
      ans = M;
      L = M + 1;
    } else {
      R = M - 1;
    }
  }
  printf("%d\n", ans);
}
