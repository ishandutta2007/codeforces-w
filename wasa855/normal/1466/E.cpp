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
#define mod 1000000007
#define int long long
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
#define N 500005
int a[N],n,cnt[N],pw[N];
void work()
{
	n=read(); for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=60;i++) cnt[i]=0;
	for(int i=1;i<=n;i++) for(int j=0;j<=60;j++) cnt[j]+=a[i]>>j&1;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int s1=0,s2=0;
		for(int j=0;j<=60;j++)
		{
			if(a[i]>>j&1) s1=add(s1,mul(pw[j],cnt[j]));
		}
		for(int j=0;j<=60;j++)
		{
			if(a[i]>>j&1) s2=add(s2,mul(n,pw[j]));
			else s2=add(s2,mul(cnt[j],pw[j]));
		}
		ans=add(ans,mul(s1,s2));
	}
	printf("%lld\n",ans);
}
signed main()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
	int T=read(); while(T--) work();
	return 0;
}