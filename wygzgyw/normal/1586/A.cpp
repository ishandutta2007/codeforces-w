// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(1e5)+10;
int T,n,a[maxn],sum;
int check(int x) {
	for (int i=2;i*i<=x;i++) if (x%i==0) return 1;
	return 0;
}
int main() {
	read(T);
	while (T--) {
		read(n); sum=0;
		for (int i=1;i<=n;i++) read(a[i]),sum+=a[i];
		if (check(sum)) { printf("%d\n",n); for (int i=1;i<=n;i++) printf("%d ",i); puts(""); }
		else {
			int fd=-1;
			for (int i=1;i<=n;i++) if (check(sum-a[i])) {
				fd=i; break;
			}
			printf("%d\n",n-1);
			for (int i=1;i<=n;i++) if (i!=fd) printf("%d ",i); puts("");
		}
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/