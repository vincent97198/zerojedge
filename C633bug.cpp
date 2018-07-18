#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory.h>

#define Max0 1000000

using namespace std;

struct Str
{
	string str;
	int n,sum;
};

Str num[Max0];

bool cmp(Str a,Str b)
{
	if(a.sum!=b.sum)
		return a.sum>b.sum;
	else
	{
		int i=0,j=0;	
		while(i<a.str.size() && j<b.str.size())
		{
			if(a.str[i]!=b.str[j])
			{
				if(a.str[i]>='0' && a.str[i]<='9')
					i++;
				else if(b.str[j]>='0' && b.str[j]<='9')
					j++;
				else return a.str[i]<b.str[j];
			}
			else
			{
				i++; j++;
			}
		}
				
		return a.n>b.n;
	}
}

int main()
{
	int t=0;
	
	bool prime[Max0/2];
	vector<int> Prime; Prime.clear();
	
	memset(prime,0,sizeof(prime));
	
	Prime.push_back(2);
	
	for(int i=1;i<Max0/2;i++)
	{
		if(!prime[i])
		{
			for(int j=3*(2*i+1);(j-1)/2<Max0/2;j+=2*(2*i+1))
				prime[(j-1)/2]=true;
				
			Prime.push_back(2*i+1);
		}
	}
		
	while(cin >> num[t].str)
	{
		int tmp=0;

		//cout<<"num[t].str.size()"<< num[t].str.size();		
		for(int i=0;i<num[t].str.size();i++)
		{
			if(num[t].str[i]<='9' && num[t].str[i]>='0')
				tmp=tmp*10+num[t].str[i]-'0';
				
				//cout << "t" << t << "tmp" << tmp << "tmpStr" << tmpStr << endl;
		}
		
		num[t].n=tmp;
		
		int sum0=0;
		
		for(int i=0;i<Prime.size();i++)
		{
			//cout << Prime[i] << endl;
		
			if(tmp%Prime[i]==0)
				sum0+=Prime[i];
				
			if(tmp<Prime[i])
				break;
		}
		
		num[t].sum=sum0;
		t++;
	}
	
	/*
	for(int i=0;i<t;i++)
		cout << num[i].str <<" " << "sum" << num[i].sum << "n" << num[i].n << "str2" << num[i].str2 <<endl;
		
	*/		
	sort(num,num+t,cmp);
	
	for(int i=0;i<t;i++)
		cout << num[i].str << endl;
	
	return 0;
}