#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define fir first
#define sec second
#define mset(s,t) memset(s,t,sizeof(s))
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=1005; 
int a[N],sum[N],n;
int main(){
  n=read();
  for(int i=2;i<=n;i++){
    printf("? %d %d\n",1,i);fflush(stdout);
    scanf("%d",&sum[i]);
  }
  for(int i=3;i<=n;i++){
    a[i]=sum[i]-sum[i-1];
  }
  printf("? 2 %d\n",n);fflush(stdout);
  int x;scanf("%d",&x);
  a[2]=x;
  for(int i=3;i<=n;i++)a[2]-=a[i];
  a[1]=sum[2]-a[2];
  printf("!");
  for(int i=1;i<=n;i++)printf(" %d",a[i]);
  puts("");fflush(stdout);
}