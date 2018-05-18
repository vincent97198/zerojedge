#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct point 
{
	int l,p;
};

struct cmp
{  
    bool operator()( const point& a , const point& b )const
	  {  
        return a.l < b.l ;      
    }  
}; 

 

int main()
{
	int t;
	
	while(cin >> t)
	{
		int n,k;
		
		while(cin >> n >> k)
		{
			vector<int> d[n+1];
			
			for(int i=0;i<n;i++)
			{
				int a,b;
				cin >> a >> b;
				
				point tmp; tmp.p=a; tmp.l=b;
				
				d[i].puah_back(tmp);
				
				tmp.p=i;
				
				d[a].push_back(tmp);
			}
			
			for(int i=1;i<=n;i++)
			{
				priority_queue<point> q;
				
				for(int j=0;j<d[i].size();j++)
				{
					point a; a.p=d[i][j].p; a.l=d[i][j].l;
					
					q.push(a);
				}
				
				while(!q.empty())
				{
					point a=q.pop();
					
				}
			}
		}
	
	}
	
	return 0;
}