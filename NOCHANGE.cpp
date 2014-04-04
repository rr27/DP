#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int x,k;
	cin>>x>>k;
	int cumm[k];
	for(int i=0;i<k;i++) cin>>cumm[i];
	for(int i=1;i<k;i++) cumm[i]+=cumm[i-1];
	vector<bool> dp(x+1,false);
	dp[0] = true;
	for(int i=0;i<k;i++) {
		for(int j=cumm[i];j<=x;j++) {
			dp[j] = dp[j] || dp[j-cumm[i]];
		}
	}
	dp[x] ? cout<<"YES" : cout<<"NO";
	cout<<endl;
	return 0;
} 
