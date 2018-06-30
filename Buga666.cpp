#include <iostream>  
#include <vector>     
#include <algorithm> 
#include <cstdlib>

#define N 50000
using namespace std;

struct point
{
	int p,d;
};
 
bool cmp(int a,int b)
{
    return a<b;
}

struct point2
{
	int key,root;
};

bool cmp2(point2 a,point2 b)
{
	return a.key<b.key;
}
 
 
vector<point> saveSon[N+1];     //儲存 線
vector<point2> test;            //假裝他是BST
vector<int> dists,circle[N];   //dists就是dists,circle的值,N=>第幾個獨立塊
vector<int> distsCircle[N];       //每個節點到circleRoot節點的距離
int D[N+1],dist[N+1];   // D為子節點數 dist存距離
int minNode,min0=987654321;
int tmp=0,n,k,ans;
bool visit[N+1],circleVisit[N+1];
 

int countTreePoint(int now)     //算子樹包含幾個節點
{
    int x=0;
 
    for(int i=0;i<saveSon[now].size();i++)
    {
        if(!visit[saveSon[now][i].p])
            x+=countTreePoint(saveSon[now][i].p);
    }
 
    return x+1;
}
 
bool findCircle(int now,int father)    //找水母頭
{
    if(circleVisit[now])
    {
 
        for(int i=0;i<circle[tmp].size();i++)
        {
            if(circle[tmp][i]!=now)
                circle[tmp].erase(circle[tmp].begin()+i);
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
                circle[tmp].erase(circle[tmp].end()-1);
            else
                return true;
        }
 
        return false;
 
    }
}
 
void dSearchCircle(int now,int nowDistance,int rootNum,int father)  //find distsCricle
{
	for(int i=0;i=saveSon[now].size();i++)
	{
		if(saveSon[now][i].p==father)
			continue;
	
		distsCircle[rootNum].push_back(now+saveSon[now][i].d);
		
		dSearchCircle(saveSon[now][i].p,now+saveSon[now][i].d,rootNum,now);
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
	dists.push_back(NowDistance);
 
	for(int i=0;i<saveSon[now].size();i++)
		if(!visit[saveSon[now][i].p] && saveSon[now][i].p!=father)
            dSearch(saveSon[now][i].p,now,NowDistance+saveSon[now][i].d);
}
 
 
int cal(int root,int x) //計算符合的個數
{
   dists.clear();
 
	int ans0=0;
 
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
 
int solve(int u,int size0)  //處理中心 第orz塊連通塊(已經想不到命名了orz)
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
                circle[i].clear();
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
                    int a=circle[i][j];
 
                    visit[a]=true;
                }
            }
 
            vector<int> treepoints[tmp+1];
 
            for(int i=1;i<=tmp;i++) //我寫過最長的程式碼就是這個程式了...變數設到會忘記...也是寫最久的
                for(int j=0;j<circle[i].size();j++)
                    treepoints[i].push_back(countTreePoint(circle[i][j]));
 
            for(int i=1;i<=tmp;i++)
            {
                for(int j=0;j<circle[i].size();j++)
                {
                    int a=circle[i][j];
 
                    solve(a,treepoints[i][j]);
                }
            }
			
				for(int i=1;i<=tmp;i++)
				{
					for(int j=0;j<circle[i].size();j++)
					{
						dSearchCircle(circle[i][j],0,circle[i][j],circle[i][j]);
					}
				}
				
				for(int i=1;i<=tmp;i++)
				{
					test.clear();
				
					int m=circle[i].size();
					int s[2*m];
				
					s[0]=0;
				
					for(int j=1;j<2*m;i++)
						s[i]=s[j-1]+saveSon[circle[i][j-1]][circle[i][j]].d;
						
					for(int j=0;j<m;j++)
					{
						for(int ii=0;ii<distsCircle[circle[i][j]].size();ii++)
						{
							point2 a; a.key=distsCircle[circle[i][j]][ii]-s[j]; a.root=circle[i][j];
					
							test.push_back(a);
						}
					}
					
					sort(test.begin(),test.end(),cmp2);
					
					int l=0;
					
					for(int j=m;j<2*m;j++)
					{
						vector<point2> x;
						x.clear();
					
						while(s[i]-s[l]>s[m]/2 || (s[i]-s[l]==s[m]/2 && l>=m))
						{
							for(int ii=0;ii<test.size();ii++)
							{
								point2 a; a=test[ii];
								
								if(a.key!=circle[i][l])
								{
									x.push_back(a);
								}
							}
							
							l++;
						}
						
						for(int ii=0;ii<distsCircle[circle[i][j-m]].size();ii++)
						{
							int y=k-distsCircle[circle[i][j-m]][ii]-s[j];    //門檻
							int R=x.size(),L=0;
							
							while(L!=R)
							{
								if(x[(R+L)/2].key>y)
									R=(L+R)/2;
								else
									L=(L+R)/2;
							}
							
							ans+=L;
						}	
					}
				}
 
            cout << ans << endl;
        }
    }
}
 