#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 105
int t[N];
void work()
{
	int n=read(),m=read();
	int l=m,r=m;
	int ok=1;
	for(int i=1;i<=n;i++)
	{
		t[i]=read();
		int L=read(),R=read();
		l=l-(t[i]-t[i-1]);
		r=r+(t[i]-t[i-1]);
		l=max(l,L),r=min(r,R);
		if(l>r) ok=0;
	}
	if(ok) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}