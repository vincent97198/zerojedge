#include <iostream>
#include <algorithm>
 
using namespace std;

int num[100001];

struct line
{
  long long int a,b,c;
};

bool cmp(line n1,line n2)
{
  return n1.c<n2.c;
}

int find(int x)                  //演算法筆記 Disjoint set 有向森林
{
  if(x!=num[x])
     num[x]=find(num[x]);
     
  return num[x];
}

int main()
{
   int n,m,t=0;
   
   while(cin >> n >> m)
   {
     long long ans=0;
     line l[m];
     int tmp=0;
     bool flag=false;
     t++;
     for(int i=0;i<m;i++)
        cin >> l[i].a >> l[i].b >> l[i].c;
       
     for(int i=0;i<n;i++)
        num[i]=i;
     
     sort(l,l+m,cmp);
     
     for(int i=0;i<m;i++)
     {
       if(find(l[i].a)!=find(l[i].b))
       {
          
         if(tmp>=n || n-1>m)
         {
           flag=true;
           break;
         }
         tmp++;   
         ans+=l[i].c;
         
         if(num[l[i].a]>num[l[i].b])
           num[find(l[i].a)]=find(l[i].b);
         else
           num[find(l[i].b)]=find(l[i].a);
         
       }
     }
     
     if(flag)
       cout << -1;
     else
       cout << ans;
       
     cout << endl;
   }
  
	return 0;
}
