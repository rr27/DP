#include<iostream>
#include<algorithm>
#include<vector>
#define MX 1000005
using namespace std;

int main() {
	int K,L,m;
	cin>>K>>L>>m;
	int arr[m];
	for(int i=0;i<m;i++) cin>>arr[i];
	bool dp[MX];
	dp[0] = false;
	for(int i=1;i<MX;i++) {
		dp[i] = false;
		 if(i-1 >=0 && !dp[i-1]) dp[i] = true;
		else if(i-K>=0 && !dp[i-K]) dp[i] = true;
		else if(i-L>=0 && !dp[i-L]) dp[i]= true;
	}
	for(int i=0;i<m;i++) {
		dp[arr[i]] ? cout<<"A" : cout<<"B";
	}
	cout<<endl;
	return 0;
}
