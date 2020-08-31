#include <bits/stdc++.h>
using namespace std;

#define NODE 25
#define CHAR_START 'A'
#define NUM_TRIANGLE NODE*(NODE-1)/6

int wa() {
    cout << "WA" << endl;
    return 0;
}

int ac() {
//    cout << "AC" << endl;
    return 0;
}

int con_triangle;
bool flag[NODE][NODE];
string con_ans;

int main(int argc, char* argv[]) {
  ifstream tc_in(argv[1]);
  ifstream tc_out(argv[2]);

  while (getline(cin,con_ans) > 0) {
    if (++con_triangle > NUM_TRIANGLE) return wa();
    if (con_ans.length() != 3) return wa();
    
    for (int i = 0; i < 3; i++) {
      if (con_ans[i] < CHAR_START || con_ans[i] > CHAR_START + NODE - 1) return wa();
    }
      
    for (int i = 0; i < 3; i++) {
      for (int j = i+1; j < 3; j++) {
        int x = con_ans[i] - CHAR_START;
        int y = con_ans[j] - CHAR_START;
        if (x == y || flag[x][y] || flag[y][x]) return wa();
        flag[x][y] = flag[y][x] = true;
      }
    }
  }
  
  if (con_triangle != NUM_TRIANGLE) return wa();
  return ac();
}
