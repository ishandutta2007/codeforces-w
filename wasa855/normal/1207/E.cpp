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
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int ans=0;
	printf("? ");
	for(int i=1;i<=100;i++) printf("%d ",i);
	cout<<"\n";
	fflush(stdout);
	int x=read();
	for(int i=7;i<=13;i++)
	{
		if(x&(1<<i)) ans|=(1<<i);
	}
	printf("? ");
	for(int i=1;i<=100;i++) printf("%d ",i*128);
	cout<<"\n";
	fflush(stdout);
	x=read();
	for(int i=0;i<=6;i++)
	{
		if(x&(1<<i)) ans|=(1<<i);
	}
	fflush(stdout);
	printf("! %d\n",ans);
	fflush(stdout);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}