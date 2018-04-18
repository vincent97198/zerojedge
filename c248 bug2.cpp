#include <iostream>
#include <map>
#include <vector>


using namespace std;

int mm=1000000007;
int N=9999;
int ans[1048576+1];
bool primeTest[1048576+1];

int main(void)
{
	int t;

	while(cin >> t)
	{
		int n;

		map<int,int> son;
		vector<int> prime;

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
			long long int ansTmp=1;

			vector<int>::iterator iter=prime.begin();

			while(tmp>1 && iter!=prime.end())
			{
				if(tmp%*iter==0)
				{
					tmp/=*iter;
					son[*iter]++;
				}
				else
                    iter++;
			}

			iter=prime.begin();

			while(tmp2>1 && iter!=prime.end())
			{
				if(tmp2%*iter==0)
				{
					tmp2/=*iter;
					son[*iter]--;
				}
				else
                    iter++;
			}

			for(map<int,int>::iterator iter2=son.begin();iter2!=son.end();iter2++)
			{
				for(int i=iter2->second;i>0;i--)
				{
					ansTmp=(ansTmp*iter2->first)%mm;
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
