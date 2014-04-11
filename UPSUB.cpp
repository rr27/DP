#include<string.h>
#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
char s[110];
int a[110],maximum,n;
stack<string> result;
int main()
{
    int t;
    scanf("%d",&t);
    void show(int l,int h,int val,string pstr);
    void lis();
    while(t--)
    {
        cin>>s;
        n=strlen(s);
        lis();
        show(0,n-1,1,"");
        while(!result.empty())
        {
	  if(result.size()!= 1)
            cout<<result.top()<<"\n";
	  else cout<<result.top();
            result.pop();
        }    
       cout<<endl;
    }
    return 0;
}     
void lis()//LIS of the string
{
        maximum=-1;
        for(int i=0;i<n;i++)
        {   a[i]=1;
            for(int j=0;j<i;j++)
            {
                if(s[i]>=s[j] && a[i]<a[j]+1)
                a[i]=a[j]+1;
                if ( maximum < a[i] )
                maximum = a[i];
            }  // cout<<a[i];
        }     
        return;      
}    

void show(int l,int h,int val,string pstr)//l=start h=end  
{
   for(int i=l;i<=h;i++)
  if( (a[i]==1 && val==1)|| (a[i]>1 && a[i]==val && s[i]>=pstr[val-2]))
   show(i+1,h,val+1,pstr+s[i]);
   if(val>maximum)
   result.push(pstr+'\0');     
}    
