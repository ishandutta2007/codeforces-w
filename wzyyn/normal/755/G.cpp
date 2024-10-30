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
const int mo=998244353;
const int FFTN=1<<16;
const int N=FFTN+5;
int W[N],w[N],R[N];
int A[N],B[N],C[N],D[N],E[N];
int n,k,f[3][N];
ull p[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void FFTinit(){
	W[0]=1;
	W[1]=power(3,(mo-1)/FFTN);
	For(i,2,N-1) W[i]=1ll*W[i-1]*W[1]%mo;
}
int FFTinit(int n){
	int L=1;
	for (;L<=n;L<<=1);
	For(i,0,L-1) R[i]=(R[i>>1]>>1)|((i&1)?(L>>1):0);
	return L;
}
void DFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=0;i<d;i++,j+=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	For(i,0,n-1) a[i]=p[i]%mo;
}
void IDFT(int *a,int n){
	For(i,0,n-1) p[R[i]]=a[i];
	for (int d=1;d<n;d<<=1){
		int len=FFTN/(d<<1);
		for (int i=0,j=FFTN;i<d;i++,j-=len) w[i]=W[j];
		for (int i=0;i<n;i+=(d<<1))
			for (int j=0;j<d;j++){
				int y=p[i+j+d]*w[j]%mo;
				p[i+j+d]=p[i+j]+mo-y;
				p[i+j]+=y;
			}
	}
	int val=power(n,mo-2);
	For(i,0,n-1) a[i]=p[i]*val%mo;
}
void UPD1(){
	memcpy(f[0],f[1],sizeof(f[1]));
	memcpy(f[1],f[2],sizeof(f[2]));
	For(i,1,k) f[2][i]=(f[2][i]+1ll*f[1][i-1]+f[0][i-1])%mo;
}
void UPD2(){
	int L=FFTinit(2*k);
	For(i,0,L-1) A[i]=B[i]=C[i]=D[i]=E[i]=0;
	For(i,0,k) A[i]=f[0][i],B[i]=f[1][i],C[i]=f[2][i];
	DFT(A,L); DFT(B,L); DFT(C,L);
	For(i,0,L-1){
		D[i]=1ll*A[i]*B[i]%mo;
		E[i]=1ll*B[i]*C[i]%mo;
		A[i]=1ll*A[i]*A[i]%mo;
		B[i]=1ll*B[i]*B[i]%mo;
		C[i]=1ll*C[i]*C[i]%mo;
	}
	IDFT(A,L); IDFT(B,L); IDFT(C,L);
	IDFT(D,L); IDFT(E,L);
	memcpy(f[2],C,sizeof(f[0]));
	memcpy(f[1],E,sizeof(f[1]));
	memcpy(f[0],B,sizeof(f[2]));
	For(i,1,k){
		f[2][i]=(f[2][i]+B[i-1])%mo;
		f[1][i]=(f[1][i]+D[i-1])%mo;
		f[0][i]=(f[0][i]+A[i-1])%mo;
	}
}
/*
f(2x  )=f(x)^2    +xf(x-1)^2
f(2x-1)=f(x)f(x-1)+xf(x-1)f(x-2)
f(2x-2)=f(x-1)^2  +xf(x-2)^2
*/
void solve(int n){
	if (n==2) return;
	if (n&1){
		solve(n-1);
		UPD1();
	}
	else{
		solve(n/2);
		UPD2();
	}
}
int main(){
	FFTinit();
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	f[1][0]=f[1][1]=1;
	f[2][0]=f[2][2]=1; f[2][1]=3;
	if (n<=2){
		For(i,1,k) printf("%d ",f[n][i]);
		return 0;
	}
	solve(n);
	For(i,1,k) printf("%d ",f[2][i]);
}