#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector<int> solve(int W,vector<pair<int,int> > party) {
	int N = party.size();
	vector<vector<int> > dp(W+1,vector<int>(N+1,0));
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=W;j++) {
			dp[j][i] = dp[j][i-1];
			if(j-(party[i-1].first) >= 0) 
			dp[j][i] = max(dp[j][i],dp[j-(party[i-1].first)][i-1]+party[i-1].second);
		}
	}
	int sec = dp[W][N];
	int l = 0, h = W,m;
	while(l<h) {
		m = (l+h)>>1;
		if(dp[m][N] < sec) {
			l= m+1;
		}
		else h= m;
	} 
	vector<int> res;
	res.push_back(l);
	res.push_back(sec);
	return res;
}
int main() {
     while(1) {
	int b,p;
	cin>>b>>p;
	if(!b && !p) break;
	vector<pair<int,int> > party;
	for(int i=0;i<p;i++) {
		int a,b;
		cin>>a>>b;
		party.push_back(make_pair(a,b));
	}
	vector<int> res = solve(b,party);
	cout<<res[0]<<" "<<res[1]<<endl;
	}
	return 0;
} 
