#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,mod;
ll ans=1,a[maxn];

int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(mod);
	for (int i=1;i<=n;i++) read(a[i]);
	if (n<=mod) {
		for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++) ans=ans*abs(a[i]-a[j])%mod;
	} else ans=0;
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/