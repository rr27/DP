#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAX= 16;
int n;
int arr[MAX];
int dp[1<<MAX][MAX];
long long np[(1<<MAX)][MAX];

int solve(int mask, int idx) {
	if(mask == (1<<n)-1) {
		np[mask][idx]=1;
		return arr[idx];
	}
	int &ret= dp[mask][idx];
	if(ret != -1) return ret;
	ret =0;
	for(int i=0;i<n;i++) {
		if(!(mask & (1<<i))) {
			int val = solve((mask | (1<<i)),i) + abs(arr[idx]-arr[i]);
			if(val > ret) {
				ret = val;
				np[mask][idx]=0;
			}
			if(val==ret) {
				np[mask][idx] += np[(mask|1<<i)][i];
			}
		}
	}
	return ret;
}
int main() {
	int maxVal=0;
	long long cnt =0;
	while(1) {
		cin>>n;
		if(!n ) break;
		for(int i=0;i<n;i++) cin>>arr[i];
		memset(dp,-1,sizeof(dp));
		memset(np,0,sizeof(np));
		maxVal=0;cnt=0;
		for(int i=0;i<n;i++) {
			int val = solve(1<<i,i)+arr[i];
			if(val>maxVal){
				maxVal= val;
				cnt=0;
			}
			if(val==maxVal) cnt+= np[1<<i][i];
		}
		maxVal += n<<1;
		cout<<maxVal<<" "<<cnt<<endl;
	}
	return 0;
}
				
