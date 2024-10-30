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
const int maxn=(2e5)+10;
int T,n,m;
struct edge { int x,y,z; } E[maxn];
int fa[maxn],ban[maxn];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
int main() {
	read(T); while (T--) {
		read(n),read(m);
		for (int i=1;i<=m;i++) read(E[i].x),read(E[i].y),read(E[i].z),ban[i]=0;
		int ans=0;
		for (int i=30;i>=0;i--) {
			for (int j=1;j<=n;j++) fa[j]=j; int cnt=n;
			for (int j=1;j<=m;j++) if (!ban[j]) {
				if (E[j].z>>i&1) continue;
				int x=find(E[j].x),y=find(E[j].y);
				if (x!=y) cnt--,fa[x]=y;
			}
			if (cnt>1) ans+=(1<<i);
			else {
				for (int j=1;j<=m;j++) if (E[j].z>>i&1) ban[j]=1;
			}
		} printf("%d\n",ans);
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