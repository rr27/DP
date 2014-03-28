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
using namespace std;

struct e
{
 int len;
 int weight;       
} el[5005];
bool operator<(const e x,const e y)
{
 if(x.len==y.len) return x.weight< y.weight;
 return x.len < y.len;
}
bool flag[5010];
int N,T,result;

int main(){
    cin >> T;    
    int i,j,x,y,temp;
    while(T>0){
            result=0;
            cin >> N;
            for(i=0;i<N;i++) {      
			    cin >> x >> y;
                            el[i].len=x;
                            el[i].weight=y;
            }                         
            sort(el,el+N);
            memset(flag,false,sizeof(flag));
            for(i=0;i<N;i++) {             
		temp=el[i].weight;
                if(flag[i]==false){   
                   for(j=i+1;j <N;j++) {
	                if(flag[j]==false&&temp<=el[j].weight){
                            flag[j]=true;
                            temp=el[j].weight;
                        }
                   }
		   result++;
		}
            }
            cout << result << endl;
            T--;
    }
    return 0; 
}
