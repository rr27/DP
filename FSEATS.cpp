#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <ctype.h>
#include <algorithm>
using namespace std;
int n,m,k,DP[301][301],r,ini,fin,aux;
char M[302];
int main() {
	while(scanf("%d%d%d",&n,&m,&k),n+m+k)
	{
		r = 1000000;
		DP[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",M+1);
			for(int j=1;j<=m;j++)
			DP[i][j] = DP[i-1][j] + DP[i][j-1] - DP[i-1][j-1] + (M[j]=='.');
		}
		int _min = min(n,m);
		int _max = max(n,m);
		for(int i=1;i<=_min;i++)
		for(int j=i;j<=_min;j++)
		{
			ini = 1; fin = 1;
			while(1)
			{
				if ((j-i+1)*_max < k) continue;
				if(_max == n) aux = DP[fin][j]-DP[ini-1][j]-DP[fin][i-1] + DP[ini-1][i-1];
				else aux = DP[j][fin]-DP[j][ini-1]-DP[i-1][fin] + DP[i-1][ini-1];
				if(aux>=k)
				{
					r = min(r,(fin-ini+1)*(j-i+1));
					ini++;
					if(ini>_max) break;
				}else{
					if(fin<_max) fin++;
					else break;
				}
			}
		}
		printf("%d\n",r);
	}
return 0;
}
