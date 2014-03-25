#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define inf 1000000
#define MAXN 202
using namespace std;

int w, h;
char city[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];

int main()
{
    int t;
    
    scanf("%d", &t);
    
    for (int qwertz = 0; qwertz < t; ++qwertz)
    {
        scanf("%d %d", &w, &h);
        
        for (int i = 0; i < h; ++i)
        {
            scanf("%s", city[i]);
        }
        
        memset(dp, 0, sizeof dp);
	for(int steps=0;steps<h+w-1;steps++) {
		for(int x0 =0;x0<w;x0++) {
			for(int x1=0;x1<=x0;x1++) {
				int y0= steps-x0;
				int y1= steps-x1;
				if(y0>=h || y1 >=h || city[y0][x0]=='#' || city[y1][x1] == '#') {
					dp[steps][x0][x1]=dp[steps][x1][x0]=0;
				}
				else {
					int c=0;
					if(steps >0) {
						c = max(c, dp[steps-1][x0][x1]);
						if(x0>0) c = max(c,dp[steps-1][x0-1][x1]);
						if(x1>0) c= max(c,dp[steps-1][x0][x1-1]);
						if(x0>0 && x1>0) c = max(c,dp[steps-1][x0-1][x1-1]);
					}
					if(city[y0][x0] == '*') c++;
					if(city[y1][x1] == '*' && x1 != x0) c++;
					dp[steps][x0][x1] = dp[steps][x1][x0] = c;
				}
			}
		}
	}
        printf("%d\n", dp[h+w-2][w-1][w-1]);
    }
    
    return 0;
}
