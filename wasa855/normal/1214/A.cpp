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
	int n,d,e;
	cin>>n>>d>>e;
	int ans=n;
	for(int i=0;i<=n;i+=5)
	{
		if(e*i>n) break;
		int rest=n-i*e;
		rest=rest%d;
		if(rest<ans) ans=rest;
	}
	cout<<ans<<endl;
	return 0;
}