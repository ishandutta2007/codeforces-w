#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,x;
int sum;
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(x);
		for (int k=1;;k++) {
			sum=k*(k+1)/2;
			if (x<=sum&&x!=sum-1) { printf("%d\n",k); break; }
		}
	}
	return 0;
}