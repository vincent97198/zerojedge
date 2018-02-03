#include<bits/stdc++.h>
using namespace std;

struct K{
	int a , b , c;
}k[200001];

bool ss(K a , K b) {
	return a.c<b.c;
}

int s[100000];

int f(int a) {
	return (s[a]==a? a :s[a]=f(s[a]));
}

void p(int a , int b) {
	s[f(a)]=f(b);
}

int main(int argc, char** argv) {
    int n ,  m;
    while(~scanf("%d %d",&n,&m)) {
    	for(int i=0;i<n;i++) s[i]=i;
    	for(int i=0;i<m;i++) scanf("%d %d %d",&k[i].a,&k[i].b,&k[i].c);
    	sort(k,k+m,ss);
    	long long ans=0;
    	for(int i=1 , j=0;i<n;i++) {
    		while(f(k[j].a)==f(k[j].b)&&j<m) j++;
    		if(j>=m) {
    			ans=-1;
    			break;
			}
			ans+=k[j].c; p(k[j].a,k[j].b);
		}
    	printf("%lld\n",ans);
	}
    return 0;
}
