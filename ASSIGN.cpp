#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int adjmat[21][21];
int size;
long long memo[1<<20];

int main() {
   memset(adjmat,0,sizeof(adjmat));
   int nT;
   cin >> nT;
   while (nT-- && cin >> size) {
      memset(adjmat,0,sizeof(adjmat));
      memset(memo,0,sizeof(memo));
      for (int i = 0; i < size; i++) {
         for (int j = 0; j < size; j++) {
            int val; cin >> val;
            adjmat[i][j] = val;
         }
      }
      memo[(1<<size)-1] = 1;
      for (int j = (1 << size)-1; j >= 0; j--) {
         int idx = __builtin_popcount(j);
         for (int k = 0; k < size; k++) {
            if (adjmat[idx][k] == 0 || (j & (1 << k))) continue;
            memo[j] += memo[j | (1 << k)];
         }
      }
      cout << memo[0] << "\n";
   }
   return 0;
}

