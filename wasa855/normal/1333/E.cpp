#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 505
int ans[4][4]={
	{},
	{0,1,7,9},
	{0,3,2,5},
	{0,4,8,6}
};
int a[N][N];
signed main()
{
	int n=read();
	if(n<=2)
	{
		cout<<"-1\n";
		return 0;
	}
	if(n%2==1)
	{
		int cnt=0;
		for(int i=1;i<=n-3;i++)
		{
			if(i&1)
			{
				for(int j=1;j<=n-i+1;j++) a[i][j]=++cnt;
				for(int j=i+1;j<=n;j++) a[j][n-i+1]=++cnt;
			}
			else
			{
				for(int j=n;j>=i;j--) a[j][n-i+1]=++cnt;
				for(int j=n-i;j>=1;j--) a[i][j]=++cnt;
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++) a[n-3+i][j]=ans[i][j]+cnt;
		}
	}
	else
	{
		int cnt=0;
		for(int i=1;i<=n-3;i++)
		{
			if(i&1)
			{
				for(int j=n;j>=i;j--) a[j][n-i+1]=++cnt;
				for(int j=n-i;j>=1;j--) a[i][j]=++cnt;
			}
			else
			{
				for(int j=1;j<=n-i+1;j++) a[i][j]=++cnt;
				for(int j=i+1;j<=n;j++) a[j][n-i+1]=++cnt;
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++) a[n-3+i][j]=ans[i][j]+cnt;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) printf("%d ",a[i][j]);
		cout<<"\n";
	}
	return 0;
}