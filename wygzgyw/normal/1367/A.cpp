#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; int f=1; char ch=getchar();
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int T,n;
char s[maxn];
int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		printf("%c",s[1]);
		for (int i=2;i<n;i+=2) printf("%c",s[i]);
		printf("%c\n",s[n]);
	}
	return 0;
}