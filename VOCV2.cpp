#include <cstdio>
#include <iostream>
#include <vector>
#include<algorithm>
#define N 101
using namespace std;
enum { MAXN = 100010, MOD = 10007 };
int Visited[100000+1]={0};
int f[MAXN][2], g[MAXN][2];
vector<int> *AL;
void dfs(int x,int parent)
{
	int with = 1, without = 0;
	int withCnt = 1, withoutCnt = 1;
	Visited[x]=1;
	vector<int> &k = AL[x];
	for (int i =0; i <k.size(); i++) {
		int y = k[i];
		if (y != parent) {
			dfs(y, x);
			with += f[y][1];
			withCnt = (withCnt * g[y][1]) % MOD;
			without += f[y][0];
			withoutCnt = (withoutCnt * g[y][0]) % MOD;
		}
	}

	f[x][0] = with;
	g[x][0] = withCnt;

	f[x][1] = min(with, without);
	if (with < without)
		g[x][1] = withCnt;
	else if (without < with)
		g[x][1] = withoutCnt;
	else
		g[x][1] = (withCnt + withoutCnt) % MOD;
}

int main()
{
	int T;
	scanf("%d", &T);

   for (int cs = 1; cs <= T; cs++) {
        int n,a,b;
        scanf("%d", &n);
        AL = new vector<int>[n+1];
        for(int i=0;i<n-1;i++)
        {
                scanf("%d%d", &a,&b);
                AL[a].push_back(b);
                AL[b].push_back(a);
        }
	int root=1;
        dfs(root,-1);
	printf("%d %d\n", f[root][1], g[root][1]);
        delete []AL;
   }
        return 0;
}
