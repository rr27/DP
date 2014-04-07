#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int dp[201][201];
string s;
int memo[201][201];
int solve(int l,int r) {
	if(l >r) return 0;
	if(l==r)  return s[l]=='1' ? 1 :0;
	if(memo[l][r] != -1) return memo[l][r];
	int res =0;
	for(int k=l;k<=r;k++) {
		int a = (dp[l][k] > (k-l+1)/2 ? k-l+1 : 0);
		res= max(res,a+solve(k+1,r));
	}
	return memo[l][r]=res;
}	
void noOf1(int n) {
	for(int i=0;i<n;i++) {
		for(int j=i;j<n;j++) {
			if(i==j) dp[i][j] =(s[i]=='1' ? 1:0);
			else dp[i][j] = dp[i][j-1]+(s[j]=='1' ? 1:0);
		}
	}  
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		memset(dp,0,sizeof(dp));
		memset(memo,-1,sizeof(memo));
		int n;
		cin>>n>>s;
		noOf1(n);
		cout<<solve(0,n-1)<<endl;
	}
	return 0;
}
