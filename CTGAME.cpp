#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<stack>
#define MAX 1000
using namespace std;

char arr[MAX][MAX];
int row[MAX];
void printRow(int m) {
	cout<<endl;
	for(int i=0;i<m;i++) cout<<row[i]<<" ";
	cout<<endl;
}
int maxAreaHist(int m) {
	vector<int> left(m,0);
	vector<int> right(m,0);
	stack<int> stk;
//	stk.push(0);
	for(int i=0;i<m;i++) {
		while(!stk.empty() && row[stk.top()]>= row[i]) stk.pop();
		int j= stk.empty() ? -1 : stk.top();
		left[i] = i-j-1;
		stk.push(i);
	}
	while(!stk.empty()) stk.pop();
//	stk.push(m-1);
	for(int i= m-2;i>=0;i--) {
		while(!stk.empty() && row[stk.top()]>= row[i]) stk.pop();
		int j = stk.empty() ? m : stk.top();
		right[i] = j-i-1;
		stk.push(i);
	}
	int res =0;
	for(int i=0;i<m;i++) 
		res = max(res, row[i]*(right[i]+left[i]+1));
	return res;
}
int solve(int n, int m) {
	int res=0;
	memset(row,0,sizeof(row));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			row[j]= (arr[i][j] == 'F' ? row[j]+1 : 0) ;
		}
		res= max(res,maxAreaHist(m));
//		printRow(m);
	}
	return res*3;		
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
		cout<<solve(n,m)<<endl;
	}
	return 0;
}	
