// Solution by Jonathan Irvin Gunawan

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  vector<int> left_most(N * N + 1, N);
  int answer = -1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int A;
      scanf("%d", &A);
      if (left_most[A] <= j) {
        answer = max(answer, A);
      } else {
        left_most[A] = j;
      }
    }
  }
  printf("%d\n", answer);
}
