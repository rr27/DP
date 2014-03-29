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

#define INF 0x1fffffff
int solve(int W, vector<pair<int,int > > arr) {
	vector<int> dp(W+1,INF);
	dp[0] =0;
	for(int i=1;i<=W;i++) {
		for(int j=0;j<arr.size();j++) {
			if(i>= arr[j].second) dp[i] = min(dp[i],dp[i-arr[j].second]+arr[j].first);
		}
	}
	return dp[W];
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int a,b;
		cin>>a>>b;
		int n;
		cin>>n;
		vector<pair<int,int> > arr;
		for(int i=0;i<n;i++) {
		int v,w;
		cin>>v>>w;
		arr.push_back(make_pair(v,w));
		}
		int res = solve(b-a,arr);
		if(res>= INF) cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<res<<"."<<endl;
	}
	return 0;
}
