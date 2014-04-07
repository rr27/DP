#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long inf=((long long)1<<62);
vector<long long int> solve(string s) {
	int n = (s.size()+1)/2;
	long long int dp1[51][51],dp2[51][51];
	for(int i=0;i<=n-1;i++) {
		dp1[i][i] = dp2[i][i] = s[2*i]-'0';
		if(i<n-1) {
		  if(s[2*i+1]=='+') dp1[i][i+1]=dp2[i][i+1]=s[2*i]+s[2*i+2]-2*'0';
		  else dp1[i][i+1]=dp2[i][i+1]=(s[2*i]-'0')*(s[2*i+2]-'0');
		}
	}
	for(int len=3;len<=n;len++) {
		for(int i=0;i<n-len+1;i++) {
			int j= i+len-1;
			dp1[i][j]=0;
			dp2[i][j]=inf;
			for(int k=i;k<j;k++) {
				if(s[2*k+1]=='+') {
					dp1[i][j] = max(dp1[i][j],dp1[i][k]+dp1[k+1][j]);
					dp2[i][j] = min(dp2[i][j],dp2[i][k]+dp1[k+1][j]);
				}
				else {
                                        dp1[i][j] = max(dp1[i][j],dp1[i][k]*dp1[k+1][j]);
                                        dp2[i][j] = min(dp2[i][j],dp2[i][k]*dp1[k+1][j]);
				}
			}
		}
	}
	vector<long long> res;
	res.push_back(dp1[0][n-1]);
	res.push_back(dp2[0][n-1]);
	return res;
}
int main() {
	int t;
	inf=2*(inf-1)+1;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		vector<long long int> res= solve(s);
		cout<<res[0]<<" "<<res[1]<<endl;
	}
	return 0;
}
