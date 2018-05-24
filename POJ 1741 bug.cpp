#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N=1e4;

struct point
{
	int p,d;
};

vector<int> save; //存割點
vector<point> saveSon[N+1];
int d[N+1],dist[N+1];
int minNode,min0=987654321;
int tmp,n,k,ans;
bool visit[N+1];

void dfs(int now,int father,int n) //找重心
{
	d[now]=1;
	int minTreeNode=0;

	for(int i=0;i<=saveSon[now].size();i++)
	{
		if(saveSon[now][i].p!=father)
		{
			dfs(saveSon[now][i].p,now,n);
			
			d[now]+=d[saveSon[now][i].p];
			minTreeNode=max(minTreeNode,d[saveSon[now][i].p]);
		}
	}
	
	minTreeNode=max(minTreeNode,n-d[now]);
	
	if(minTreeNode<min0)
	{
		min0=minTreeNode;
		
		minNode=now;
	}
}

void dSearch(int now,int NowDistance) //子樹中每點到根的距離
{
	dist[tmp]=NowDistance;
	tmp++;
	
	for(int i=0;i<saveSon[now].size();i++)
		if(!visit[saveSon[now][i].p])
			dSearch(saveSon[now][i].p,dist[tmp]+saveSon[now][i].d);
}

int cal(int root,int x)
{
	int ans0=0;

	dSearch(root,x);
	
	sort(dist,dist+tmp);
	
	int i=0,j=tmp-1;
	
	while(j>i)
	{
		while(dist[i]+dist[j]>k && j>i)
			j--;
			
		ans0+=j-i;
		i++;
	}
	
	visit[root]=true;
	
	return ans;
}

void solve(int u)
{
	tmp=0;
	min0=987654321;
	
	dfs(u,0,n);
	
	ans+=cal(minNode,0);
	
	for(int i=0;i<saveSon[u].size();i++)
	{
		if(!visit[saveSon[u][i].p])
		{
			ans-=cal(saveSon[u][i].p, saveSon[u][i].d);
			
			solve(saveSon[u][i].p);
		}
	}
}

int main()
{
	
	while(cin >> n >> k && n!=0)
	{	
		for(int i=0;i<=k;i++)
			visit[i]=false;
		
		for(int i=0;i<n-1;i++)
		{
			int u,v,l;
			
			cin >> u >> v >> l;
			
			point tmp; tmp.p=v; tmp.d=l;
			
			saveSon[u].push_back(tmp);
			tmp.p=u;
			saveSon[v].push_back(tmp);
		}
		
		ans=0;
		
		solve(1);
		
		cout << ans << endl;
		
	}
	
	return 0;
}
