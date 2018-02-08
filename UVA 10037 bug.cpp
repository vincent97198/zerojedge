#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
  
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  int x;
  while(cin >> x)
  {
  int n;
  
  while(cin >> n && x--)
  {
    int num[n],last=n-1,ans=0;
    string str;
    str.clear();
    
    for(int i=0;i<n;i++)
    {
      cin >> num[i];
    }
    
    sort(num,num+n);
    
    while(last>2)
    {
      if(num[last]+2*num[0]+num[last-1]<2*num[1]+num[0]+num[last])
      {
        ans+=(num[last]+2*num[0]+num[last-1]);
        str+=(num[0] +  " " + num[last] + '\n' + num[0] + '\n' + num[0] + " " + num[last-1] + '\n' + num[0] + '\n');
      }
      else
      {
        ans+=(2*num[1]+num[0]+num[last]);
        str+=(num[0] +  " " + num[1] + '\n' + num[0] + '\n' + num[last-1] + " " + num[last] + '\n' + num[1] + '\n');
      }
        
      last-=2;
    }
    
    switch(last)
    {
      case 0:
      
        ans+=num[0];
        str+=(num[0] + '\n');
        break;
        
      case 1:
      
        ans+=num[1];
        str+=(num[0] + " " + num[1] + '\n');
        break;
        
      case 2:
      
        ans+=num[0]+num[1]+num[2];
        str+=(num[0] + " " + num[1] + '\n' + num[0] + '\n' + num[0] + " " + num[2] + '\n');
        break;
    }
    
    cout << ans << '\n' << str;
    
  }
  }
}
