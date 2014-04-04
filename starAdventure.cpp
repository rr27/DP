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
#define MAXN 20
using namespace std;

int w, h;
char city[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];

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
			    for(int x2=0;x2<=x1;x2++) {
				int y0= steps-x0;
				int y1= steps-x1;
				int y2= steps-x2;
				if(y0>=h || y1 >=h || y2>=h ) {
					dp[steps][x0][x1][x2]=dp[steps][x1][x0][x2]= dp[steps][x0][x2][x1]=dp[steps][x1][x2][x0]=dp[steps][x2][x0][x1]=dp[steps][x2][x1][x0]=0;
				}
				else {
					int c=0;
					if(steps >0) {
						c = max(c, dp[steps-1][x0][x1][x2]);
						if(x0>0) c = max(c,dp[steps-1][x0-1][x1][x2]);
						if(x1>0) c= max(c,dp[steps-1][x0][x1-1][x2]);
						if(x2>0) c= max(c,dp[steps-1][x0][x1][x2-1]);
						if(x0>0 && x1>0) c = max(c,dp[steps-1][x0-1][x1-1][x2]);
						if(x0>0 && x2>0) c = max(c,dp[steps-1][x0-1][x1][x2-1]);
						if(x1>0 && x2>0) c = max(c,dp[steps-1][x0][x1-1][x2-1]);
						if(x1>0 && x2>0 && x0>0) c = max(c,dp[steps-1][x0-1][x1-1][x2-1]);
					}
					c += (city[y0][x0])- '0';
					if(x1 != x0) c += city[y1][x1] - '0';  
					if(x2 != x0 && x2 != x1) c += city[y2][x2] - '0';
					dp[steps][x0][x1][x2]=dp[steps][x1][x0][x2]= dp[steps][x0][x2][x1]=dp[steps][x1][x2][x0]=dp[steps][x2][x0][x1]=dp[steps][x2][x1][x0] = c;
				}
			   }
			}
		}
	}
        printf("%d\n", dp[h+w-2][w-1][w-1][w-1]);
    }
    
    return 0;
}

