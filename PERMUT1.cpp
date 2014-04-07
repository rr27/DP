#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dp[13][99];

int count(int n,int k) {
	if(n==0) return 0;
	if(k==0) return 1;
	if(dp[n][k] != -1) return dp[n][k];
	int val=0;
	for(int i=0;i<n && k-i>=0;i++) val+=count(n-1,k-i);
	return dp[n][k] = val;
}
int count2(int n, int k) {
	for(int i=0;i<=k;i++) dp[0][i]=0;
	for(int i=1;i<=n;i++) dp[i][0] =1;
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) {
		dp[i][j]=0;
		for(int l=0;l<i && j-l>=0;l++) dp[i][j]+= dp[i-1][j-l];
	}
	return dp[n][k];
}

int main() {
	memset(dp,-1,sizeof(dp));
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		cout<<count2(n,k)<<endl;
	}
	return 0;
}
