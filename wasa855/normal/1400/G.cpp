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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1100005
int fac[N],inv[N],pinv[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
int l[N],r[N],a[N],b[N],n,m;
int t[N],cnt[N];
int sum[45][N];
signed main()
{
	init();
	cin>>n>>m;
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read(),t[l[i]]++,t[r[i]+1]--;
	for(int i=1;i<=m;i++) a[i]=read(),b[i]=read();
	for(int i=1;i<=n;i++) cnt[i]=cnt[i-1]+t[i];
	int ans=0;
	for(int i=0;i<(1<<m);i++)
	{
		int L=1,R=n,cnt=0;
		set<int> s;
		for(int j=1;j<=m;j++)
		{
			if(i&(1<<(j-1)))
			{
				cnt++; s.insert(a[j]),s.insert(b[j]);
				L=max(L,l[a[j]]),R=min(R,r[a[j]]);
				L=max(L,l[b[j]]),R=min(R,r[b[j]]);
			}
		}
		int t=s.size();
		// printf("%d %d %d\n",L,R,t);
		if(L>R) continue;
		if(cnt&1) sum[t][L]--,sum[t][R+1]++;
		else sum[t][L]++,sum[t][R+1]--;
	}
	for(int i=0;i<=2*m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i][j-1];
			int R=mul(sum[i][j],C(cnt[j]-i,j-i));
			if(R<0) ans=sub(ans,-R);
			else ans=add(ans,R);
		}
	}
	cout<<ans<<endl;
	return 0;
}