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
short dp[2][MAX];

//below solution will not work as it caluculates diagonally 
int minInsertionsToMakePalin(string s) {
        int n= s.size();
        for(int l=0;l<n;l++) {
                for(int i=0,j=l;j<n;j++,i++) {
                        if(i==j) dp[i%2][j]=0;
                        else if(i+1 == j) dp[i%2][j] = (s[i] == s[j] ? 0 :1);
                        else {
                        if(s[i]==s[j]) dp[i%2][j] = dp[(i+1)%2][j-1];
                        else dp[i%2][j] = min(dp[i%2][j-1],dp[(i+1)%2][j])+1;
                        }
                }
        }
        return dp[0][n-1];
}
//it will work as it calculates row by row bottom-up
int minInsertionsToMakePalin2(string s) {
	memset(dp,0,sizeof(dp));
        int n= s.size();
	 for (int i = n - 1; i >= 0; --i) {
    		for (int j = i + 1; j < n; ++j) {
     			 if (s[i] == s[j]) {
        			dp[i % 2][j] = dp[(i + 1) % 2][j - 1];
      			} else {
        			dp[i % 2][j] = 1 + min(dp[i % 2][j - 1], dp[(i + 1) % 2][j]);
      			}
    		}
  	}
        return dp[0][n-1];
}
int main() {
        int t;
        cin>>t;
        string s;
        cin>>s;
        int res= minInsertionsToMakePalin2(s);
        cout<<res<<endl;
        return 0;
}
