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
const int N=300005;
char s[N];
int tag[N],n,k;
int main(){
  int T=read();
  while(T--){
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=0;i<k;i++)tag[i]=-1; 
    int wa=0;
    for(int i=1;i<=n;i++){
      if(s[i]!='?'){
        s[i]^='0';
        if(~tag[i%k]&&tag[i%k]!=s[i]){
          wa=1;break;
        }
        tag[i%k]=s[i];
      }
    }
    if(wa){
      puts("NO");continue;
    }
    int one=0,no=0;
    for(int i=0;i<k;i++){
      if(~tag[i]){
        if(tag[i]==1)one++;
        else one--;
      }else{
        no++;
      }
    }
    if(one>=0&&one-no>0)puts("NO");
    else if(one<0&&one+no<0)puts("NO");
    else if((one+no)&1)puts("NO");
    else puts("YES");
  }
  return 0;
}