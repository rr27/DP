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
using namespace std;

int need1, need2, N;
int vol1[2000], vol2[2000], weight[2000];

int best[80][80][1001];

int solve()
{
	memset(best, 0x3f, sizeof(best));
	best[0][0][0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int a = 0; a <=need1; a++)
			for (int b = 0; b <= need2; b++) {
				best[a][b][i] = min(best[a][b][i-1],best[max(0,a-vol1[i-1])][max(0,b-vol2[i-1])][i-1]+weight[i-1]);
			}
	}
	return best[need1][need2][N];
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int cs = 1; cs <= T; cs++) {
		scanf("%d %d %d", &need1, &need2, &N);
		for (int i = 0; i < N; i++)
			scanf("%d %d %d", &vol1[i], &vol2[i], &weight[i]);
		printf("%d\n", solve());
	}
}
