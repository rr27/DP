#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int res =-1,start=0,end=0,curr=0;
	while(end<n) {
		if(curr==m) break;
		curr += arr[end];
		if(curr==m) {res=curr;break;}
		if(curr<m) res=max(res,curr);
		else {
			while(start<=end) {	
				curr -= arr[start];
				if(curr<=m) {res=max(res,curr);break;}
				start++;
			}
		}
		end++;
	}
	cout<<res<<endl;
}
	
