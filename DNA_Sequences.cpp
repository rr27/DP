#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	while(1) {
		int t;
		cin>>t;
		if(!t) break;
		string a,b;
		cin>>a>>b;
		int l1=a.size();
		int l2=b.size();
		short dp[1001][1001][2];
		short dp1[1001][1001];
		memset(dp1,0,sizeof(dp1));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<l1;i++) for(int j=0;j<l2;j++) 
			dp1[i+1][j+1]=(a[i]==b[j]) ? 1+dp1[i][j] :0 ;
/*
		dp[i][j][0] denotes the length of LCS which follows the constraint that each 
		segment of LCS except the last one is of length>=K and the last segment of it 
		can be of any length>=0 but it should end at index i,j of two string 'a' and 'b' 
		respectively.

		dp[i][j][1] denotes the length of LCS which strictly follows the constraint
		given by problem that each segment of it will be of length>=K
		*/

		for(int i=0;i<l1;i++) for(int j=0;j<l2;j++) {
			dp[i+1][j+1][0] = dp[i+1][j+1][1] = max(dp[i][j+1][1],dp[i+1][j][1]);
			if(a[i] ==b[j]) {
				dp[i+1][j+1][0] = max(dp[i+1][j+1][0],short(1+dp[i][j][0]));
				if(dp1[i+1][j+1] >=t)
					dp[i+1][j+1][1]= max(dp[i+1][j+1][1],short(t+dp[i+1-t][j+1-t][0]));
			}
		}
		cout<<dp[l1][l2][1]<<endl;
	}
	return 0;
} 
