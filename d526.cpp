#include <SandboxLibraries> //do not modify this line
 
using namespace std;

struct node
{
  int v;
  node *parent;
  node *l;
  node *r;
};

node p[1000];

void find(node now,int x,int i)
{
  if(x>now.v)
  {
    if(now.r!=NULL)
      find(*now.r,x,i);
    else
    {
      p[i].parent=&now;
      now.r=&p[i];
    }
  }
  else
  {
    if(now.l!=NULL)
      find(*now.l,x,i);
    else
    {
	   p[i].parent=&now;
      now.l=&p[i];
    }
  }  
}

void output(node now)
{
	cout << now.v << " ";

	if(now.l!=NULL)
		output(*now.l);

	if(now.r!=NULL)
		output(*now.r);
}

int main()
{
   int n,a=0;
   
   //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   
   while(cin >> n)
   { 
     for(int i=0;i<n;i++)
	  {
       p[i].l=NULL;
       p[i].r=NULL;
     }
         
     for(int i=0;i<n;i++)
     {
       int tmp;
       
       cin >> tmp;
       
       p[i].v=tmp;
       
       if(i-1>=0)
       {
         find(p[0],tmp,i);
       }
     }

	  output(p[0]);
   }
      
	return 0;
}
