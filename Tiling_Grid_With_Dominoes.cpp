#include <cstdio>
 
using namespace std;
//my code
int main(){
    unsigned int x[1001],a[1001],b[1001];
    x[0]=1;a[0]=b[0]=0;
    x[1]=a[1]=b[1]=1;
 
 
    for(int i = 2;i <= 1000;++i)
    {
        x[i]=x[i-1]+x[i-2]+2*a[i-1]+b[i-1];
        a[i]=x[i-1]+a[i-1];
        b[i]=x[i-1]+b[i-2];
    }
 
    int T,n;
 
    scanf("%d",&T);
 
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        printf("%d %u\n",tc,x[n]);
    }
 
    return 0;
}
