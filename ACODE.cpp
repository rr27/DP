#include <iostream>
#include <vector>
using namespace std;

   int numDecodings2(string & s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (s[i - 1] < '0' || s[i - 1] > '9') return 0;
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) dp[i] += dp[i - 2];
            if (dp[i] == 0) return 0;
        }
        return dp[N];
    }
int main() {
	while(1) {
	string s;
	cin>>s;
	if(s[0] == '0') break;
	cout<<numDecodings2(s)<<endl;
	}
}
	
