#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int N=5e4;
 
struct point
{
	int p,d;
};
 
bool cmp(int a,int b)
{
    return a<b;
}
 
vector<point> saveSon[N+1];
vector<int> dists,circle[N];
int D[N+1],dist[N+1];   // D為子節點數 dist存距離
int minNode,min0=987654321;
int tmp=0,n,k,ans;
bool visit[N+1],circleVisit[N+1];
 
bool findCircle(int now,int father)
{
    if(circleVisit[now])
    {
 
        for(int i=0;i<circle[tmp].size();i++)
        {
            if(circle[tmp][i]!=now)
                circle[tmp].erase(circle.begin()+i);
            else
                return true;
        }
    }
    else
    {
        circleVisit[now]=true;
        circle[tmp].push_back(now);
 
        for(int i=0;i<saveSon[now].size();i++)
        {
            if(saveSon[now][i].p==father)
                continue;
 
            if(!findCircle(saveSon[now][i].p,now))
                circle[tmp].erase(circle.end()-1);
            else
                return true;
        }
 
        return false;
 
    }
}
 
void dfs(int now,int father,int size0) //找重心
{
	D[now]=1;
	int minTreeNode=0;
 
	for(int i=0;i<saveSon[now].size();i++)
	{
		if(saveSon[now][i].p!=father && !visit[saveSon[now][i].p])
		{
			dfs(saveSon[now][i].p,now,size0);
 
			D[now]+=D[saveSon[now][i].p];
			minTreeNode=max(minTreeNode,D[saveSon[now][i].p]);
		}
	}
 
	minTreeNode=max(minTreeNode,size0-D[now]);
 
	if(minTreeNode<min0)
	{
		min0=minTreeNode;
 
		minNode=now;
	}
 
}
 
void dSearch(int now,int father,int NowDistance) //子樹中每點到根的距離
{
	dist[now]=NowDistance;
	circle[now]=true;
	dists.push_back(NowDistance);
 
	for(int i=0;i<saveSon[now].size();i++)
		if(!visit[saveSon[now][i].p] && saveSon[now][i].p!=father)
            dSearch(saveSon[now][i].p,now,NowDistance+saveSon[now][i].d);
}
 
 
int cal(int root,int x) //計算符合的個數
{
    dists.clear();
 
	int ans0=0;
	tmp=0;
 
	dSearch(root,0,x);
 
	sort(dists.begin(),dists.end(),cmp);
 
	int i=0,j=dists.size()-1;
 
	while(j>i)
	{
		while(dists[i]+dists[j]>k && j>i)
		{
			j--;
		}
 
        if(j>i)
            ans0+=j-i;
 
		i++;
	}
 
	return ans0;
}
 
int solve(int u,int size0)  //處理中心
{
	min0=987654321;
 
	dfs(u,0,size0);
 
    ans+=cal(minNode,0);
 
	visit[minNode]=true;
	u=minNode;
 
	for(int i=0;i<saveSon[u].size();i++)
	{
		if(!visit[saveSon[u][i].p])
		{
			ans-=cal(saveSon[u][i].p,saveSon[u][i].d);
 
			solve(saveSon[u][i].p,D[saveSon[u][i].p]);
		}
	}
 
	return 0;
}
 
int main()
{
	int t;
 
	while(cin >> t)
    {
        while(cin >> n >> k && t--)
        {
            for(int i=0;i<=n;i++)
            {
                visit[i]=false;
                D[i]=0;
                dist[i]=0;
                saveSon[i].clear();
                circleVisit[i]=false;
                circle.clear();
            }
 
 
            for(int i=1;i<=n;i++)
            {
                int u,l;
 
                cin >> u >> l;
 
                if(u==i) continue;
 
                point tmp; tmp.p=i; tmp.d=l;
 
                saveSon[u].push_back(tmp);
                tmp.p=u;
                saveSon[i].push_back(tmp);
            }
 
            ans=0;
 
            for(int i=1;i<=n;i++)
                if(!circleVisit[i])
                {
                    tmp++;
                    findCircle(i,0);
                }
				
					 for(int i=1;i<=tmp;i++)
					 {
					 	 for(int j=0;j<circle[i].size();j++)
						 {
						  	 int a=cirlce[i][j];
							 
							 visit[a]=true;
						 }
					 }

            for(int i=1;i<=tmp;i++)
					 {
					 	 for(int j=0;j<circle[i].size();j++)
						 {
						  	 int a=cirlce[i][j];
							 
							 solve(a,)
						 }
					 }
 
            cout << ans << endl;
        }
    }
}
 