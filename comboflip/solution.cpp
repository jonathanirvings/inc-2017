// Solution by Alham Fikri Aji

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define ll long long
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
using namespace std;

long long fastpow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y) % MOD;
        }
        y = (y*y) % MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n, int MOD)
{
    return fastpow(n,MOD-2,MOD);
}
 
long long f[300000];
bool init;
long long C(int n, int r, int MOD)
{
    if (!init){
        init=1;
        f[0]=1;
        for (int i=1; i<300000;i++)
            f[i]= (f[i-1]*i) % MOD;
        
    }
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int N, Q;
string S;
int bits[111000];
int comboLeft[2][111000];
int comboRight[2][111000];
int comboMid[2][111000];
int isflip[111000];

const int bucket_size = 333;


void rebuild(int bucket_id){

  for (int j=0;j<2;j++){
    comboLeft[j][bucket_id] = 0;
    comboRight[j][bucket_id] = 0;
    for (int i = 0;i < bucket_size; i++){
      int idx = i + bucket_id * bucket_size;
      if (idx >= N) break;
      if ((bits[idx]) == j) comboLeft[j][bucket_id]++;
      else break;
    }
    for (int i = bucket_size - 1;i >= 0; i--){
      int idx = i + bucket_id * bucket_size;
      if (idx >= N) continue;
      if ((bits[idx]) == j) comboRight[j][bucket_id]++;
      else break;
    }

    comboMid[j][bucket_id] = 0;
    int curr = 0;
    for (int i = 0;i < bucket_size; i++){
      int idx = i + bucket_id * bucket_size;
      if (idx >= N) break;
      if ((bits[idx]) == j) curr++;
      else curr=0;
      comboMid[j][bucket_id] = max(comboMid[j][bucket_id], curr);
    }
  }
}

int query(int st, int ed)
{
  //cout<<"Q"<<endl;
  if (st == ed) return 1;
  int l = st;
  int r = ed;
  int best[2] = {0,0};
  int curr[2] = {0,0};
  int last = -1;
  while (l < r && l % bucket_size != 0 && l != 0)
  {
    int bit = bits[l] ^ isflip[l/bucket_size];
    if (bit == last) curr[last]++;
    else {
      curr[0] = 0; curr[1] = 0; curr[bit]++;
    }
    last = bit;
    best[0] = max(best[0], curr[0]); best[1] = max(best[1], curr[1]);
    l++;
  }
  while (l + bucket_size <= r)
  {
    //flip
    int bucket_id = l / bucket_size;
    for (int j=0;j<2;j++) {
      best[j] = max(best[j], curr[j] + comboLeft[j^ isflip[bucket_id]][bucket_id]);
      if (comboLeft[j^ isflip[bucket_id]][bucket_id] == bucket_size) curr[j] += bucket_size;
      else {
        curr[j] = comboRight[j^ isflip[bucket_id]][bucket_id];
      }
    }
    best[0] = max(best[0], comboMid[0 ^ isflip[bucket_id]][bucket_id]);
    best[1] = max(best[1], comboMid[1 ^ isflip[bucket_id]][bucket_id]);

    l += bucket_size;
  }

  last = bits[l - 1] ^ isflip[(l - 1) / bucket_size];
  while (l<=r)
  {
    int bit = bits[l] ^ isflip[l/bucket_size];
    if (bit == last) curr[last]++;
    else {
      curr[0] = 0; curr[1] = 0; curr[bit]++;
    }
    last = bit;
    best[0] = max(best[0], curr[0]); best[1] = max(best[1], curr[1]);
    l++;
  }
  //cout<<l<<endl;
  return max(best[0], best[1]);
}
 
void update(int st, int ed)
{
  int l = st;
  int r = ed;
  //cout<<"up"<<endl;
  while (l < r && l % bucket_size != 0 && l != 0)
  {
    bits[l] = 1 - bits[l];
    l++;
  }
  while (l + bucket_size <= r)
  {
    //flip
    int bucket_id = l / bucket_size;
    isflip[bucket_id] = 1 - isflip[bucket_id];
    l += bucket_size;
  }
  while (l<=r)
  {
    bits[l] = 1 - bits[l];
    l++;
  }
  rebuild(st/bucket_size);
  rebuild(ed/bucket_size);
}


int main(){
  std::ios::sync_with_stdio(false); 
  cin>>N>>Q;
  cin>>S;
  for (int i=0;i<N;i++){
    bits[i] = S[i] - '0';      
  }
  
  for (int i=0;i<bucket_size;i++) rebuild(i);
  //cout<<"DONE"<<endl;

  for (int i=0;i<Q;i++){
    int a,b,c;
    cin>>a>>b>>c;
    b--; c--;
    if (a == 1) update(b, c);
    else cout<<query(b, c)<<endl;

  }

}
