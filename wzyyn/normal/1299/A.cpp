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
int n,res,p;
int S[35],a[200005];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		For(j,0,29) if (a[i]&(1<<j)) ++S[j];
	}
	For(i,1,n){
		int ans=0;
		For(j,0,29)
			if (a[i]&(1<<j))
				if (S[j]==1)
					ans|=1<<j;
		if (ans>=res) res=ans,p=i;
	}
	printf("%d",a[p]);
	For(i,1,n) if (i!=p) printf(" %d",a[i]);
}