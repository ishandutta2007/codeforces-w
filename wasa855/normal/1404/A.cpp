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
#define N 300005
char s[N];
vector<pair<char,int>> v[N];
void work()
{
	int n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) v[i%k].eb(s[i],i);
	for(int i=0;i<k;i++)
	{
		char ch=0;
		for(auto [j,k]:v[i])
		{
			if(j!='?')
			{
				if(ch==j) continue;
				if(!ch) ch=j;
				else {cout<<"NO\n"; for(int i=0;i<k;i++) v[i].clear(); return ;}
			}
		}
		if(ch)
		{
			for(auto [j,k]:v[i])
			{
				if(j=='?') s[k]=ch;
			}
		}
	}
	int sum=0,cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(s[i]=='?') cnt++;
		else sum+=s[i]-'0';
	}
	if(sum>k/2) cout<<"NO\n";
	else
	{
		int ned=abs(k/2-sum);
		printf("%s\n",ned<=cnt?"YES":"NO");
	}
	for(int i=0;i<k;i++) v[i].clear();
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}