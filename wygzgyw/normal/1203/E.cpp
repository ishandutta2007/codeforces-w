#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=150010;
int n,a[maxn],ans,lst;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x;
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1); lst=maxn;
	for (int i=n;i>=1;i--) {
		if (a[i]+1<lst) a[i]++;
		else if (a[i]==lst) a[i]--;
		if (a[i]<lst&&a[i]) ans++,lst=a[i];
	}
	printf("%d\n",ans);
	return 0;
}