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
const int N=400005;
int n,ans;
int a[N],b[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	for (int B=1;B<=2e7;B<<=1){
		For(i,1,n) b[i]=a[i]%B;
		int sum=0;
		For(i,1,n) if (a[i]&B) ++sum;
		if ((sum&1)&&!(n&1)) ans^=B;
		sort(b+1,b+n+1);
		sum=0;
		int p=n;
		For(i,1,n){
			p=max(p,i);
			for (;p>i&&b[i]+b[p]>=B;--p);
			sum^=n-p;
		}
		if (sum&1) ans^=B; 
	}
	printf("%d\n",ans);
}