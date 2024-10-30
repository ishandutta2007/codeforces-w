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
int T,n;
char s[maxn];
int sum,mx;
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		sum=0;
		for (int i=1;i<=n;i++) sum+=s[i]-'a'+1;
		if (n%2==0) {
			printf("Alice %d\n",sum);
			continue;
		}
		mx=max(sum-2*(s[1]-'a'+1),sum-2*(s[n]-'a'+1));
		if (mx>0) printf("Alice %d\n",mx);
		else printf("Bob %d\n",-mx);
		
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