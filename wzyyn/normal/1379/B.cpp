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
#define all(v) v.begin(),v.end()
using namespace std;

void solve(){
	ll l,r,m;
	cin>>l>>r>>m;
	For(i,l,r)
		if (m%i<=r-l&&m>=i){
			cout<<i<<' '<<l+m%i<<' '<<l<<endl;
			return;
		}
		else if (m%i+r-l>=i){
			cout<<i<<' '<<r-(i-m%i)<<' '<<r<<endl;
			return;
		}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}