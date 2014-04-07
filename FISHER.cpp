#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int INF = 0x3fffffff;
int travel[51][51], toll[51][51], N, deadline;
int dp[1001][51];

int minTollNode(vector<int> dist,vector<bool> isIncluded) {
	int min_index,min_distant =INT_MAX;
	for(int i=0;i<N;i++) {
		if(!isIncluded[i] && dist[i]<min_distant) {
			min_index=i;
			min_distant=dist[i];
		}
	}
	return min_index;
}
void printVector(vector<int> arr) {
        cout<<endl;
        for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
        cout<<endl;
}
void dijkstra() {
		vector<int> dist(N,INT_MAX);
                vector<bool> isIncluded(N,false);
                dist[0]=0;
                for(int i=0;i<N-1;i++) {
                        int u = minTollNode(dist,isIncluded);
                        isIncluded[u]=true;
                        for(int j=0;j<N;j++) {
                                if(!isIncluded[j] && dist[u]+toll[u][j] < dist[j])
                                        dist[j]=dist[u]+toll[u][j];
                        }
                }
                printVector(dist);

}
void dijkstra2() {
	vector<int> dist(N,INT_MAX);
	dist[0]=0;
	for(int i=0;i<N;i++) {
		if(dist[i] >= INT_MAX) continue;
		for(int j=0;j<N;j++) {
			dist[j]= min(dist[j],dist[i]+toll[i][j]);
		}
	}
	printVector(dist);
}
void dijkstraWithExtraConstraint() {
        vector<vector<int> > dp(deadline+1,vector<int>(N,INT_MAX));
        dp[0][0]=0;
	int bestTime=INT_MAX;
	int bestToll=INT_MAX;
	for(int t=0;t<=deadline;t++) {
          for(int i=0;i<N;i++) {
                if(dp[t][i] >= INT_MAX) continue;
		if(t<deadline) dp[t+1][i]= min(dp[t+1][i],dp[t][i]);
                for(int j=0;j<N;j++) {
			if(t+travel[i][j] <= deadline) {
				int tt = t+travel[i][j];
                        	dp[tt][j]= min(dp[tt][j],dp[t][i]+toll[i][j]);
			}
                }
          }
	  if(dp[t][N-1] < bestToll) {
		bestToll= dp[t][N-1];
		bestTime= t;
	  }
	}
        cout<<bestToll<<" "<<bestTime<<endl;
}

int main() {
	while (scanf("%d %d", &N, &deadline) == 2 && N > 0) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &travel[i][j]);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &toll[i][j]);
		//dijkstra();
		//dijkstra2();
		dijkstraWithExtraConstraint();
	}
	return 0;
}
