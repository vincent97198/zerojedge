#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <stack>
#define LL long long

using namespace std;

LL ans;

struct bag
{
	LL tragic,now,father,i;
};

int main()
{

	long long int n,k;
	
	
	while(cin >> n >> k)
	{
		LL loli[n+1],loliSum[n+1]; 

		vector<int> brige[n+1];
	
		for(int i=1;i<=n;i++)
			cin >> loli[i];
			
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			
			cin >> a >> b;
			
			brige[a].push_back(b);
			brige[b].push_back(a);
		}
		
		LL R=1,L=1;
		
		for(int i=1;i<=n;i++)
				R+=loli[i];
		
		while(R-L>1)
		{
			stack<bag> stk,stk2;
			bag tmp;  tmp.tragic=(R+L)/2; tmp.now=1; tmp.father=1; tmp.i=0;
			
			stk.push(tmp);
			
			ans=0;
			
 func: while(!stk.empty())
			{
				bag tmp;
			
				tmp=stk.top();
				
				LL now=tmp.now,father=tmp.father,tragic=tmp.tragic; tmp.i=0;
			
				loliSum[now]=loli[now];
				
	func2: int i=tmp.i;

				for(;i<brige[now].size();i++)
				{
					if(father!=brige[now][i])
					{
						bag tmp; tmp.tragic=tragic;  tmp.now=brige[now][i]; tmp.father=now; tmp.i=i;
						
						stk.push(tmp);
						
			 			tmp.now=now; tmp.father=father; tmp.i=i;
						stk2.push(tmp); goto func;
					}
				}
	
				if(loliSum[now]>=tragic)
				{
					loliSum[now]=0;
					ans++;
				}
				
				if(!stk.empty())
					stk.pop();
				
				
				tmp=stk2.top(); stk2.pop();
				
				i=tmp.i; now=tmp.now;
				
			 	loliSum[now]+=loliSum[brige[now][i]];
				
				tmp.i++; 
				
				if(tmp.i<brige[now].size())
					goto func2;
				
			}	
			
			if(ans>=k)
				L=(R+L)/2;
			else
				R=(R+L)/2;
				
				//cout << "r" <<R<<"l"<<L<< endl;
		}
		
		cout << L << endl;
		
	}
	
	return 0;
}
  