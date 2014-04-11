#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*
You have to count how many sequences a[1..k] exist such that :
1) a[1] <= a[2] <=.... <= a[k]
2) a[i] + a[2] + .... + a[k] = N
*/

const int MAX = 5005;
int dp[MAX][MAX];
int solve(int c, int t) {
	if(dp[c][t]) return dp[c][t];
	if(t==1) return 1;
	int res=0;
	for(int i=c/t;i>=0;i--) {
		res+=solve(c-i*t,t-1);
		if(res>= 1988) res%= 1988;
	}
	return dp[c][t]= res;
}
int main() {
	int c,t;
	while(1) {
	   cin>>c>>t;
	   if(!c && !t) break;
	   cout<<solve(c-t,t)<<endl;
	}
	return 0;
}
