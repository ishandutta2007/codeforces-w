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
typedef pair<ull,int> pi;

const int N=1000005,P=1e9+7;

int S[N],n,fail[N],e[N][26],len[N],ec,last,anc[N],diff[N],m,dp[N],val[N];
char s[N];

inline int newnode(int l){len[++ec]=l;return ec;}
inline void init(){
	last=1;while(n)S[n--]=0;S[0]=-1;
	while(~ec)len[ec]=fail[ec]=0,mms(e[ec],26),ec--;
	newnode(0);newnode(-1);fail[0]=1;
}
inline int match(int p){
	while(S[n]!=S[n-len[p]-1])p=fail[p];
	return p;
}
inline void extend(int c){
	S[++n]=c;
	int cur=match(last);
	if(!e[cur][c]){
		int p=newnode(len[cur]+2);
		fail[p]=e[match(fail[cur])][c];e[cur][c]=p;
		diff[p]=len[p]-len[fail[p]];
		anc[p]=diff[p]==diff[fail[p]]?anc[fail[p]]:fail[p];
	}
	last=e[cur][c];
}

int main(){
	scanf("%s",s+1);m=strlen(s+1);
	fo(i,1,m>>1)S[(i<<1)-1]=s[i]-'a';
	fo(i,1,m>>1)S[i<<1]=s[m-i+1]-'a';
	init();dp[0]=1;
//	fo(i,1,m)putchar(S[i]+'a');puts("");
	fo(i,1,m){
		extend(S[i]);
		for(int x=last;x;x=anc[x]){
			if(anc[x]!=fail[x])val[x]=val[fail[x]];else val[x]=0;
			int p=i-len[anc[x]]-diff[x];
			val[x]=(val[x]+dp[p])%P;
			if((~i&1))dp[i]=(dp[i]+val[x])%P;
		}
	}
//	fo(i,1,m)printf("%d ",dp[i]);puts("");
	printf("%d\n",dp[m]);
	return 0;
}