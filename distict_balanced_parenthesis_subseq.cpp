#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 100
int dp[MAX][MAX];
int solve(string s, int last, int c) {
	int N =s.size();
	if(dp[last][c] != -1) return dp[last][c];
	int ans=0;
	if(c==0) ans =1;
	int next = last+1;
	while(next<= N && s[next-1] != '(') next++;
	if(next <=N) ans+=solve(s,next,c+1);
	if(c>0) {
		next = last+1;
		while(next<=N && s[next-1] != ')') next++;
		if(next<=N) ans += solve(s,next,c-1);
	}
	dp[last][c] = ans;
	return ans;
}

int main() {
	string s;
	cin>>s;
	memset(dp,-1,sizeof(dp));
	cout<<endl<<solve(s,0,0)<<endl;
}
