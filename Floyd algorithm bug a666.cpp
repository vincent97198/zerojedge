#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

const int N=5e4;

int (*ans)[N+1]= new int[N+1][N+1];

int main()
{
	int t;

	while(cin >> t)
	{
		int n,k;

		while(cin >> n >> k)
		{
			for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    ans[i][j]=9999999;

            for(int i=1;i<=n;i++)
            {
                int a,b;

                cin >> a >> b;

                if(ans[i][a]>b)
                    ans[i][a]=b;

                if(ans[a][i]>b)
                    ans[a][i]=b;
            }

            for(int k=1;k<=n;k++)
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if(ans[i][j]>ans[i][k]+ans[k][j])
                            ans[i][j]=ans[i][k]+ans[k][j];

            int x=0;

            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    if(ans[i][j]<=k)
                        x++;

            cout << x << endl;
		}
	}

	return 0;
}
