#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#define mod0 1000000007

using namespace std;

int ans;

void dfs(int tragic,int now,int father,int loli[],int loliSum[],vector<int> brige[])
{
	loliSum[now]=loli[now];

	for(int i=0;i<brige[now].size();i++)
	{
		if(father!=brige[now][i])
		{
			dfs(tragic,brige[now][i],now,loli,loliSum,brige);
			
			loliSum[now]+=loliSum[brige[now][i]];
		}
	}
	
	if(loliSum[now]>=tragic)
	{
		loliSum[now]=0;
		ans++;
	}
}

int main()
{
	long long int n,k;
	
	while(cin >> n >> k)
	{
		int loli[n+1],loliSum[n+1]; 

		vector<int> brige[n+1];
	
		for(int i=0;i<n;i++)
			cin >> loli[i];
			
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			
			cin >> a >> b;
			
			brige[a].push_back(b);
			brige[b].push_back(a);
		}
		
		//memset(visit,0,sizeof(visit));
		
		int R=0,L=1;
		
		for(int i=0;i<n;i++)
				R+=loli[i];
		
		//ans=0;
		
		while(R-L>1)
		{	
			ans=0;		
			dfs((R+L)/2,1,1,loli,loliSum,brige);
			
			if(ans>=k)
				R=(R+L)/2;
			else
				L=(R+L)/2;
				
		}
		
		cout << L << endl;
		
	}
	
	return 0;
}
  