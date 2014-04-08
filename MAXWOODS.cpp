#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int solve(vector<vector<char> > arr) {
	int n = arr.size();
	int m = arr[0].size();
	vector<vector<vector<int> > > dp(n+2,vector<vector<int> >(m+2,vector<int>(2,0)));
	for(int i=n;i>0;i--){
		for(int j=1;j<=m;j++) {
			 if(arr[i-1][j-1] != '#') {
				dp[i][j][1] = max(dp[i+1][j][0],dp[i][j-1][1]) + (arr[i-1][j-1] == '0' ? 0 : 1);
			}
	 	}
		for(int j=m;j>0;j--) {
			if(arr[i-1][j-1] != '#') {
				dp[i][j][0] = max(dp[i][j+1][0],dp[i+1][j][1]) + (arr[i-1][j-1] == '0' ? 0 : 1);
			}
		}
	}
	return dp[1][1][0];
					
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		vector<vector<char> > arr(n,vector<char>(m,'0'));
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
		cout<<solve(arr)<<endl;
	}
	return 0;
}
