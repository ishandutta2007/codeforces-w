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
#define N 200005
int s[N][20];
void work()
{
	int ans=inf;
	int l=read(),r=read();
	for(int i=0;i<19;i++)
	{
		ans=min(ans,s[r][i]-s[l-1][i]);
	}
	printf("%d\n",ans);
}
signed main()
{
	for(int i=0;i<19;i++)
	{
		s[0][i]=1;
		for(int j=1;j<N;j++) s[j][i]=s[j-1][i]+1-(j>>i&1);
	}
	int T=read(); while(T--) work();
	return 0;
}