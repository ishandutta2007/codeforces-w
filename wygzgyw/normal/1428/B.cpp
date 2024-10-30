#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int T,n;
char s[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1); int ans=0,f1=1,f2=1;
		for (int i=1;i<=n;i++) f1&=(s[i]!='<'),f2&=(s[i]!='>');
		for (int i=1;i<=n;i++) {
			if (s[i]=='-'||s[i%n+1]=='-') ans++;
			else ans+=(f1|f2);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/