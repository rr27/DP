#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool comp(string a, string b) {
	int n= a.size();
	int m=b.size();
	int sum1=0,sum2=0;
	for(int i=0;i<n;i++) sum1+= a[i]-'0';
	for(int i=0;i<m;i++) sum2+= b[i]-'0';
	return sum1>=sum2;
}
void helper(string s,string prev,int idx,int &res) {
	int n = s.size();
	if(idx>n) return;
	if(idx == n) {res++;return;}
	for(int i=idx;i<n;i++) {
		string temp= s.substr(idx,i-idx+1);
		if(comp(temp, prev)) {helper(s,temp,i+1,res);}
	}
}
int helper2(string s,int prev,int idx) {
	int n = s.size();
	if(idx==n) {return 1;}
	int res =0;
	for(int i=idx,sum=0;i<n;i++) {
		sum += s[i]-'0';
		if(sum>=prev) res+=helper2(s,sum,i+1);
	}
	return res;
}
int solve(string s) {
	int res=0;
	//helper(s,"0",0,res);
	res =helper2(s,0,0);
	return res;
}
int main() {
	string s;
	int c=1;
	while(1) {
		cin>>s;
		if(s== "bye") break;
		cout<<c<<"."<<" "<<solve(s)<<endl;
		c++;
	}
	return 0;
}
