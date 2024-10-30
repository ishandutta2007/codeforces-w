#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=205;
int _,n,k,cnt[50];
char s[N];

void solve() {
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	rep(i,0,26) cnt[i]=0;
	rep(i,0,n) cnt[s[i]-'a']++;
	rep(i,0,k) {
		int cc=0;
		while (cc<n/k&&cnt[cc]>0) cnt[cc]--,cc++;
		printf("%c",(char)(cc+'a'));
	}
	puts("");
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}