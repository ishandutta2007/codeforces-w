#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int a[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) a[i]=read();
	int del=0,ans=0,cur=1;
	while(del<m)
	{
//		cout<<"Passed\n";
//		while(a[del+1]-del>(cur-1)*k) cur++;
		cur=max(cur,(a[del+1]-del-1)/k+1);
		ans++;
		int tmp=del;
		for(int i=tmp+1;i<=m;i++)
		{
			if(a[i]-tmp<=(cur)*k) del++;
			else break;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}