// Solution by Jonathan Irvin Gunawan

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  vector<int> A(M);
  for (int i = 0; i < M; ++i) {
    scanf("%d", &A[i]);
  }  
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  vector<int> B;
  M = A.size();
  for (int i = 0; i < M; ++i) {
    B.push_back(1);
    if (i > 0) {
      B[i] += (A[i] - A[i - 1] - 1) / 2;
    } else {
      B[i] += A[i] - 1;
    }
    if (i + 1 < M) {
      B[i] += (A[i + 1] - A[i] - 1) / 2;
    } else {
      B[i] += N - A[i];
    }
  }
  for (int i = 0; i < M - 1; ++i) {
    if ((A[i + 1] - A[i]) % 2 == 0) {
      if (B[i] > B[i + 1]) {
        ++B[i];
      } else {
        ++B[i + 1];
      }
    }
  }
  sort(B.rbegin(), B.rend());
  int answer = 0;
  for (int i = 0; i < min(M, K); ++i) {
    answer += B[i];
  }
  printf("%d\n", answer);
}
