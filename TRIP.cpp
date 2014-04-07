#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include<map>
using namespace std;
string s1,s2;
map<string,bool> processed[81][81];
void backtrack(string s1,string s2,int l1,int l2,vector<vector<int> > &table,vector<string> &result,string word) {
	if(processed[l1][l2].find(word) != processed[l1][l2].end()) return;
	if(l1==0 || l2==0) result.push_back(word);
	else if(s1[l1-1]== s2[l2-1]) {
		word = s1[l1-1]+word;
		backtrack(s1,s2,l1-1,l2-1,table,result,word);
	}
	else if(table[l1][l2-1] > table[l1-1][l2]) backtrack(s1,s2,l1,l2-1,table,result,word);
	else if(table[l1-1][l2] > table[l1][l2-1]) backtrack(s1,s2,l1-1,l2,table,result,word);
	else {
		backtrack(s1,s2,l1,l2-1,table,result,word);
		backtrack(s1,s2,l1-1,l2,table,result,word);
	}
	processed[l1][l2][word] = true;
}
void LCS(string s1, string s2, vector<vector<int> > &table,vector<string> &result) {
	int l1= s1.size();
	int l2= s2.size();
	for(int i=1;i<=l1;i++) for(int j=1;j<=l2;j++) {
		if(s1[i-1]==s2[j-1]) table[i][j] = table[i-1][j-1]+1;
		else table[i][j] = max(table[i-1][j],table[i][j-1]);
	}
	backtrack(s1,s2,l1,l2,table,result,"");
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		vector<vector<int> > table(81,vector<int>(81,0));
		cin>>s1>>s2;
		vector<string> result;
		LCS(s1,s2,table,result);
		sort(result.begin(),result.end());
		for(int i=0;i<result.size();i++) cout<<result[i]<<endl;
		cout<<endl;
	}
	return 0;
}
