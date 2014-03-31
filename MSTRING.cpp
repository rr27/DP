#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int inf = int(1e6);
string a,b;
int N,M;
vector<vector<int> > dp(1001,vector<int>(1001,-1));
vector<vector<int> > occ(1001,vector<int>(270,-1));
int solve(int n, int m) {
	if(n==N) return inf;
	if(m==M) return 1;
	if(dp[n][m] != -1) return dp[n][m];
	if(occ[m][a[n]] == -1) dp[n][m] = 1;
	else {
		dp[n][m] = solve(n+1,occ[m][a[n]]+1)+1;
		dp[n][m] = min(dp[n][m],solve(n+1,m));
	}
	return dp[n][m];
}
int solve2() {
	for(int i=0;i<=M;i++) dp[N][i] = inf;
	for(int i=0;i<=N;i++) dp[i][M] = 1;
	for(int i=N-1;i>=0;i--) {
		for(int j=M-1;j>=0;j--) {
			if(occ[j][a[i]] == -1) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i+1][occ[j][a[i]]+1]+1;
				dp[i][j] = min(dp[i][j],dp[i+1][j]);
			}
		}
	}
	return dp[0][0];
}
int main() {
	cin>>a>>b;
	N = a.size();M=b.size();
	for(int i= b.size()-1;i>=0;i--) {
		for(int j=0;j<256;j++) {
			if(int(b[i]) == j) occ[i][j] = i;
			else occ[i][j] = occ[i+1][j];
		}
	}
	cout<<solve2()<<endl;
	return 0;
}		
