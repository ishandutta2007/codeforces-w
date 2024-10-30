#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
inline int add(int a,int b,int c,int d){return add(a,b,add(c,d));};
inline int mul(int a,int b,int c,int d){return mul(a,b,mul(c,d));};
inline int add(int a,int b,int c,int d,int e){return add(a,b,c,add(d,e));}
inline int mul(int a,int b,int c,int d,int e){return mul(a,b,c,mul(d,e));}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 1000005
const int i2=Inv(2),i6=Inv(6);
int f[N],g[N],n;
signed main()
{
	cin>>n;
	f[0]=g[0]=1,f[1]=2,g[1]=3;
	for(int i=2;i<=n;i++)
	{
		f[i]=add(f[i-1],mul(f[i-1],g[i-2]),mul(f[i-1],f[i-1]+1,i2));
		g[i]=add(g[i-1],f[i]);
	}
	// for(int i=1;i<=n;i++) printf("%d%c",f[i]," \n"[i==n]);
	int ans=add(f[n],mul(f[n-1],g[n-2],g[n-2]+1,i2),mul(f[n-1],f[n-1]+1,g[n-2],i2),mul(f[n-1],f[n-1]+1,f[n-1]+2,i6));
	ans=add(ans,ans-1);
	for(int i=0;i<n-1;i++)
	{
		int r=mul(f[i]-1,sub(f[n-i-1],f[n-i-2]));
		ans=add(ans,r);
	}
	cout<<ans<<endl;
	return 0;
}