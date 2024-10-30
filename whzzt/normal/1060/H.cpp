#pragma GCC diagnostic error "-std=c++11"
#pragma optimize("unroll-loops,no-stack-protector")
#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define ALL(a) a.begin(),a.end()
#define lowbit(x) ((x)&-(x))
#define dec dec_xx
using namespace std;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<int,int>pii;
typedef vector<int>VI;
typedef long long ll;
typedef double ld;
namespace io{
	struct eof{eof(){}};
	const int L=(1<<21)|5;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,qu[55];int f,qr;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout),oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>inline void gi(I&x){
		for(f=1,c=gc();(c<'0'||c>'9')&&(c!=EOF);c=gc())if(c=='-')f=-1;
 		if(c==EOF)throw eof();
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)qu[++qr]=x%10+'0',x/=10;while(qr)putc(qu[qr--]);
	}
	struct StringReader{
		function<bool(char)>chk;
		StringReader(){chk=[&](char c){return c<='z'&&c>='a';};}
		StringReader(function<bool(char)>func){chk=func;}
		inline char read(){for(c=gc();!chk(c);c=gc());return c;}
		inline void gs(char*s){for(c=gc();!chk(c);c=gc());for(;chk(c);c=gc())*s++=c;*s=0;}
	};
	inline void ps(const char*s){int l=strlen(s),x;for(x=0;x<l;x++)putc(s[x]);}
	struct IOC{~IOC(){flush();}}ioc;
	inline double readld(){
		double x=0,y=1;
		for(c=gc();c<'0'||c>'9';c=gc())if(c=='-')y=-1;assert(c!='.');
		for(;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=y;assert(c!='e');
		if(c=='.')for(c=gc();c<='9'&&c>='0';c=gc())y*=0.1,x+=y*(c&15);
		return x;
	}
	inline void printld(double x,int y){
		if(x<0)putc('-'),x=-x;x+=.5*pow(.1,y);print((u64)x),putc('.');
		for(x-=(u64)x;y;--y)x*=10,putc((int)x+'0'),x-=(int)x;
	}
}using io::gi;using io::print;using io::putc;
template<class T>int ctz(T a){return sizeof(T)>2?__builtin_ctzll(a):__builtin_ctz(a);}
template<class T>inline T gcd(T a,T b){
	int shift=ctz(a|b);
	for(b>>=ctz(b),a>>=ctz(a);a;a-=b,a>>=ctz(a))if(a<b)swap(a,b);
	return b<<shift;
}
template<class T>void exgcd(T a,T b,T&x,T&y){
	if(!b)return (void)(x=1,y=0);
	exgcd(b,a%b,y,x),y-=a/b*x;
}
template<class T>T Inv(T a,T p){T x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
inline int fpow(int a,int t,int p){static int r;for(r=1;t;a=(ll)a*a%p,t>>=1)if(t&1)r=(ll)r*a%p;return r;}
string to_string(string s){return '"'+s+'"';};
string to_string(const char*s){return to_string(string(s));}
string to_string(bool f){return f?"true":"false";}
template<class A,class B>string to_string(pair<A,B>p){return "("+to_string(p.fi)+", "+to_string(p.se)+")";}
template<class T>string to_string(T v){string s="{",e="";for(auto&x:v)s+=e+to_string(x),e=", ";s+="}";return s;}
void debug_out(){cerr<<endl;}template<class A,class...B>void debug_out(A x,B...y){cerr<<" "<<to_string(x),debug_out(y...);}
void scan(){}template<class A,class...B>void scan(A&a,B&...b){gi(a),scan(b...);}
template<class T>inline bool chkmin(T&a,T b){return b<a?a=b,true:false;}
template<class T>inline bool chkmax(T&a,T b){return a<b?a=b,true:false;}
template<class T>inline T abs(T x){return x<0?-x:x;}

int vec[5005];

#ifdef whzzt
bool local=true;
#else
bool local=false;
#endif

const int N=15,M=35;
int n,c[N][N],P,A[N][N],B[N];
void add(int x,int y,int z){
	printf("+ %d %d %d\n",x,y,z);
	if(local)vec[z]=(vec[x]+vec[y])%P;
} 
void mul(int x,int c){
	static int pos[M];int b;
	c=(c+P-1)%P; 
	pos[0]=x;
	for(b=1;b<=30;b++)add(pos[b-1],pos[b-1],pos[b]=1000+b);
	for(b=0;b<=30;b++)if(c>>b&1)add(x,pos[b],x);
}
void dec(int x,int y,int z){mul(y,P-1),add(x,y,z);}
void up(int x,int y){
	int b;
	mul(2000,0),add(x,2000,2000);
	for(b=1;b<=n;b++)add(2000+b-1,5000,2000+b);
	mul(y,0);
	for(b=0;b<=n;b++){
		printf("^ %d %d\n",2000+b,2000+b);
		if(local)vec[2000+b]=fpow(vec[2000+b],n,P);
		mul(2000+b,B[b]);
		add(y,2000+b,y);
	}
}
int main(){
#ifdef whzzt
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int i,j,k,l,v;
	scan(n,P);
	if(local){
		srand(time(0)^size_t(new char));
		for(i=1;i<=5000;i++)vec[i]=1;
		vec[1]=rand()%P,vec[2]=rand()%P;
	}
	for(i=0;i<=n;i++)for(j=*c[i]=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)A[j][i]=(u64)fpow(i,n-j,P)*c[n][j]%P;
	B[2]=1;
	for(i=0;i<=n;i++){
		for(l=i;l<=n;l++)if(A[l][i])break;
		if(l!=i){
			for(j=0;j<=n;j++)swap(A[i][j],A[l][j]);
			swap(B[i],B[l]);
		}
		v=fpow(A[i][i],P-2,P);
		for(j=0;j<=n;j++)A[i][j]=(u64)A[i][j]*v%P;
		B[i]=(u64)B[i]*v%P;
		for(j=0;j<=n;j++)if(j!=i&&A[j][i]){
			v=A[j][i];
			for(k=0;k<=n;k++)A[j][k]=(A[j][k]-(ll)A[i][k]*v%P+P)%P;
			B[j]=(B[j]-(ll)B[i]*v%P+P)%P;
		}
	}
	add(1,2,3);
	up(1,4),up(2,5),up(3,6);
	add(4,5,7),dec(6,7,8);
	mul(8,(P+1)/2);
	puts("f 8");
	if(local){
		assert((ll)vec[1]*vec[2]%P==vec[8]);
	}
}