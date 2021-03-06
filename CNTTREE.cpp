#include <cstdio>
#include <cstring>
#include <vector>
 
using namespace std;
 
const int MAXN = 65;
 
int n, k;
vector< int > e[MAXN];
 
long long dp[MAXN][MAXN];
long long tmp[MAXN];
long long sol[MAXN];
 
void dfs( int node, int dad ) {
	memset( dp[node], 0, sizeof dp[node] );
	dp[node][0] = 1; //empty 
	sol[node] = 0;
	 
	for( int i = 0; i < (int)e[node].size(); ++i ) {
		int w = e[node][i];
		if ( w == dad ) continue;
		dfs( w, node );
		memcpy( tmp, dp[node], sizeof dp[node] );
		 
		for ( int lc = 0; lc <= k; ++lc )
		for ( int rc = 1; rc+lc <= k; ++rc )
		tmp[max(lc,rc)] += dp[node][lc] * dp[w][rc-1];
		memcpy( dp[node], tmp, sizeof tmp );
		sol[node] += sol[w];
	}
	 
	for ( int i = 0; i <= k; ++i )
	sol[node] += dp[node][i];
}
 
void process() {
	scanf( "%d%d", &n, &k );
	for ( int i = 1; i < n; ++i ) {
		int x, y;
		scanf( "%d%d", &x, &y );
		e[x].push_back( y );
		e[y].push_back( x );
	}
	 
	dfs( 0, -1 );
	printf( "%lld\n", sol[0] );
}
 
int main() {
	int t; scanf( "%d", &t );
		for( int tt = 0; tt < t; ++tt ) {
		for ( int i = 0; i < MAXN; ++i ) e[i].clear();
		process();
	}
}
