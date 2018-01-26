#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

long long int n,ans;

int dfs(int now,vector<int> list[])
{
  if(list[now].empty())
     return 1;
  else if(list[now].size()==1)
  {
    long long int a=dfs(list[now][0],list);
    
    ans+=a;
    
    return a+1;
  }
  else
  {
    long long int max0=-1;
    
    for(long long int i=0;i<n;i++)
    {
      long long int a;
      
      a=dfs(list[now][i],list);
      
      if(a>max0)
         max0=a;
    }
    
    ans+=max0;
    
    return max0+1;
  }
}

int main()
{
  while(cin >> n)
  {
    ans=0;
    vector<int> list[100001];     //save son points
    bool test[n+1];
    
    for(long long int i=1;i<=n;i++)
    {
      list[i].clear();
      test[i]=true;
    }
    
    for(long long int i=1;i<=n;i++)
    {
      int a;
      
      cin >> a;
      
      if(a==0)
         continue;
         
      for(long long int j=0;j<a;j++)
      {
        int b;
        
        cin >> b;
        list[i].push_back(b);
        test[b]=false;
      }
    }
    
    int oldest;
    
    for(long long int i=1;i<=n;i++)
    {
      if(test[i])
      {
        cout << i << endl;
        oldest=i;
      }
    }
    
    dfs(oldest,list);
    
    cout << ans << endl;
    
  }
  
  return 0;
}
