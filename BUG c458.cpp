
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int l,k;

	string str1,str2;
	
	cin >> str1 >> str2;
	cin >> l >> k;
	
	bool flag=true;
	
	for(int i=0;i<min(str1.size(),str2.size());i++)
	{
		if(str1[i]!=str2[i])
		{
			flag=false;
			break;
		}
	}
	
	if(abs(str1.size()-str2.size())<=l*k && l!=0)
	{
		if((str1.size()-str2.size())%l==0)
			cout << (str1.size()-str2.size())/l;
		else
			cout << (str1.size()-str2.size())/l+1;
	}
	else if(flag && str1.size()==str2.size())
		cout << 0;
	else
		cout << "Impossible";
		
		cout << endl;
	
	
	return 0;
}