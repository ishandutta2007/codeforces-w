#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 105
int a[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	bool ok=1;
	for(int i=1;i<n;i++)
	{
		if(a[i+1]-a[i]==1) ok=0;
	}
	printf("%d\n",ok?1:2);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}