#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=200005;
int n,a[N],b[N],c[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) c[i]=a[i]-b[i];
	sort(c+1,c+n+1);
	int p=n;
	ll ans=0;
	For(i,1,n){
		p=max(p,i);
		for (;p>i&&c[p]+c[i]>0;--p);
		ans+=n-p;
	}
	printf("%lld\n",ans);
}
int main(){
	solve();
}