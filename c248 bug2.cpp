#include <iostream>
#include <map>
#include <vector>
#define mod0 1000000007
#define N 1048576

using namespace std;

int main()
{
	int t;
	
	while(cin >> t)
	{
		int n;
		int ans[N+1];
		map<int,int> son;
		vector<int> prime;
		bool primeTest[N+1];
		
		ans[0]=1;
		
		for(int i=1;i<=N;i++)
			primeTest[i]=true;
			
		for(int i=2;i<=N;i++)
		{
			if(primeTest[i])
			{
				for(int j=i*2;j<=N;j+=i)
					primeTest[i]=false;
					
				prime.push_back(i);
			}
		}
		
		for(int i=1;i<=N;i++)
		{
			int tmp=4*i-2,tmp2=i+1;
			int ansTmp=1;
		
			vector<int>::iterator iter=prime.begin();
			
			while(tmp>1)
			{
				if(tmp%*iter==0)
				{
					tmp/=*iter;
					son[*iter]++;
				}
				
				iter++;
			}
			
			iter=prime.begin();
			
			while(tmp2>1)
			{
				if(tmp2%*iter==0)
				{
					tmp2/=*iter;
					son[*iter]--;
				}
				
				iter++;
			}
			
			for(map<int,int>::iterator iter2=son.begin();iter2!=son.end();iter2++)
			{
				for(int i=iter2->second;i>0;i--)
				{
					ansTmp=(ansTmp*iter2->first)%mod0;
				}
			}
			
			ans[i]=ansTmp;
		}
		
		while(cin >> n && t--)
		{
			cout << ans[n] << endl;
		}
	}
	
	return 0;
}
