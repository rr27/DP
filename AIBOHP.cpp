#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int MAX=6105;
int dp[MAX][MAX];
int minInsertionsToMakePalin(string s) {
	int n= s.size();
	for(int l=0;l<n;l++) {
		for(int i=0,j=l;j<n;j++,i++) {
			if(i==j) dp[i][j]=0;
			else if(i+1 == j) dp[i][j] = (s[i] == s[j] ? 0 :1);
			else {
			if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
			else dp[i][j] = min(dp[i][j-1],dp[i+1][j])+1;
			}
		}
	}
	return dp[0][n-1];
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		string s;
		cin>>s;
		int res= minInsertionsToMakePalin(s);
		cout<<res<<endl;
	}
	return 0;
}
