#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n,max0;
bool test[100000];
vector<int> list[100000];    // save son point"s"

int dfs(int now)
{
  int big1=-9999999,big2=-999999;
  
  if(list[now].empty())
      return 1;
  else if(list[now].size()==1)
  {
    int save=dfs(list[now][0]);
    if(save>max0)
       max0=save;
      return save+1;
  }
  else
  {
    for(int i=0;i<list[now].size();i++)
    {
      int save=dfs(list[now][i]);
      
      if(save>big1 || save>big2)
      {
        if(big1>big2)
           big2=save;
        else
           big1=save;
      }
    }
    
    if(big1+big2>max0)
       max0=big1+big2;
       
    if(big1>big2)
       return big1+1;
    else 
       return big2+1;
  }
  
}

int main()
{
  while(cin >> n)
  {
    max0=-99;
    
    for(int i=0;i<n;i++)
    {
       list[i].clear();
       test[i]=false;
    }
       
    for(int i=1;i<n;i++)
    {
      int a,b;
      
      cin >> a >> b;
      list[a].push_back(b);
      test[b]=true;
    }
    
    int oldest;
    
    for(int i=0;i<n;i++)
       if(!test[i])
           oldest=i;
    
    dfs(oldest);
    
    cout << max0 << endl;
  }
}
