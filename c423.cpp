#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <set>
#include <sstream>

using namespace std;


int main(void)
{
    int n,r;

    while(cin >> n >> r)
    {
       set<string> ans;
       string str,tmp;

       cin >> str;

       for(int x=0;x<10;x++)
       {
          int num=x;

          for(int i=0;i<str.size();i++)
             num+=str[i]-'0';

          while(num>10)
          {
              int save=0;

              while(num>0)
              {
                  save+=num%10;
                  num/=10;
              }

              num=save;
          }

          if(r==num)
          {
              int a=0;

              for(int i=0;i<str.size();i++)
              {
                 a*=10;
                 a+=str[i]-'0';
              }

              long long int ii=1;

              for(int i=0;i<=str.size();i++)
              {
                  string tmpSTR=str;

                  stringstream ss;

                  string o;

                  ss << x;
                  ss >> o;

                  tmpSTR.insert(i,o);
				
                  ans.insert(tmpSTR);
              }

          }

       }

       int test=false;
       set<string>::iterator iter=ans.begin();
	   
	    if(ans.size()==1)
		  {
			for(int i=0;i<n;i++)
				cout << 0;
					
			cout << endl;
			}

       while(ans.size()>1)
       {
           iter=ans.begin();

           if(test)
               cout << *iter << endl;


           ans.erase(*iter);
           test=true;

       }
	   

    }

	return 0;
}