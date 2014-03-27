#include<iostream>
#include<algorithm>
# define MAX 10010
using namespace std;

struct orders {
	int a,b,price;
	bool operator <(const orders &other) const{
		return a < other.a;
	}
};
int dp[MAX];
orders arr[MAX];
int find(int n,int l, int h) {
	while(h-l>0) {
		int m = l+(h-l)/2;
		if(arr[m].a >= n) h=m;
		else l = m+1;
	}
	return h;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++) 
		  cin>>arr[i].a>>arr[i].b>>arr[i].price;
		sort(arr,arr+n);
		dp[n]=0;
		for(int i=n-1;i>=0;i--) {
			dp[i] = max(dp[i+1],dp[find(arr[i].a+arr[i].b,0,n)]+arr[i].price);
		}
		cout<<dp[0]<<endl;
	}
}
