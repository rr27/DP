#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define llong long long
const llong MOD=1000000007;

int main() {
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int n= s.size();
		vector<llong> ans(n+1,0);
		vector<int> prev(27,-1);
		ans[0]=1;
		for(int i=1;i<=n;i++) {
			ans[i] = (2*ans[i-1])%MOD;
			if(prev[s[i-1]-'A'] > 0) ans[i] = (ans[i] -ans[prev[s[i-1]-'A']-1] + MOD)%MOD;
			prev[s[i-1]-'A'] = i;
		}
		
		cout<<ans[n]<<endl;
	}
}
