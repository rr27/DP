#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define inf 1000000000
#define MAXN 100

int dp[MAXN][MAXN][2];
int solve(int ni,int ki,int b, int N, int K) {
	if(ni==N) return (ki==K);
	if(ki>K) return 0;
	int& ref = dp[ni][ki][b];
	if(ref!= -1) return ref;
	ref =0;
	ref+= solve(ni+1,ki,0,N,K);
	ref+= solve(ni+1,ki+b,1,N,K);
	return ref;
}
int main() {
	int t;
	cin>>t;
	for (int tc=1;tc<=t;tc++) {
		memset(dp,-1,sizeof(dp));
		int x,n,k;
		cin>>x>>n>>k;
		cout<<tc<<" "<<solve(0,0,0,n,k)<<endl;
	}
	return 0;
}
