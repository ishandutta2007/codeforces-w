#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;

const int N=1000005;
int g[N],s[N][11],Q;

int calc(int n){
	int r=1;
	while(n){
		if(n%10)r*=n%10;
		n/=10;
	}
	return r;
}

int main(){
	for(int i=1;i<=9;i++)g[i]=i;
	for(int i=10;i<=1000000;i++)g[i]=g[calc(i)];
	for(int i=1;i<=1000000;i++){
		mmp(s[i],s[i-1],11);
		s[i][g[i]]++;
	}
	scanf("%d",&Q);
	while(Q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",s[r][k]-s[l-1][k]);
	}
	return 0;
}