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
#define N 200005
int a[N];
int cnt[3];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	if(cnt[2]&&cnt[1])
	{
		cout<<"2 1 ";
		cnt[2]--,cnt[1]--;
		while(cnt[2]--) printf("%d ",2);
		while(cnt[1]--) printf("%d ",1);
	}
	else if(cnt[1]>=3)
	{
		cout<<"1 1 1 ";
		cnt[1]-=3;
		while(cnt[2]--) printf("%d ",2);
		while(cnt[1]--) printf("%d ",1);
	}
	else if(cnt[1])
	{
		cout<<"1 "; cnt[1]--;
		while(cnt[2]--) printf("%d ",2);
		while(cnt[1]--) printf("%d ",1);
	}
	else
	{
		while(cnt[2]--) printf("%d ",2);
		while(cnt[1]--) printf("%d ",1);
	}
	return 0;
}