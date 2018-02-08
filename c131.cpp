#include <iostream>
#include <map>

using namespace std;

void output(int t,bool a)
{
    if(a)
        cout << "Case " << t << " is a tree." << endl;
    else
        cout << "Case " << t << " is not a tree." << endl;
}

int main()
{
    int n,m,t=1;

    while(cin >> n >> m && n>=0 && m>=0)
    {
        int a=n,b=m,root=a;
        bool flag=true;
        map<int,int> node;     // save father point

        while(a!=0 && b!=0)
        {
            map<int,int>::iterator iter;

            iter=node.find(b);

            if(a==b)
            {
                flag=false;
            }
            else if(iter!=node.end())
            {
                flag=false;
            }
            else
            {
                node[b]=a;

                iter=node.find(a);

                if(root==b && iter!=node.end())
                    flag=false;
                else if(root==b)
                    root=a;
            }

            cin >> a >> b;
        }

        output(t,flag);
        t++;
    }

    return 0;
}
