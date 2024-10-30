#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define set0(x) memset(x,0,sizeof(x))
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}

int T,n;
string ch;

int dp[200020];
int calc(string ch){
    for(int i=0;i<n+10;i++)dp[i] = 1e9;
    dp[0] = 0;
    for(int i=0;i<n+10;i++){
        if(i+2<=n){
            dp[i+2]= min(dp[i+2],dp[i]+(ch[i]!='R')+(ch[i+1]!='L'));
        }
        if(i+3<=n){
            dp[i+3]= min(dp[i+3],dp[i]+(ch[i]!='R')+(ch[i+1]!='R')+(ch[i+2]!='L'));
            dp[i+3]= min(dp[i+3],dp[i]+(ch[i]!='R')+(ch[i+1]!='L')+(ch[i+2]!='L'));
        }
        if(i+4<=n){
            dp[i+4]= min(dp[i+4],dp[i]+(ch[i]!='R')+(ch[i+1]!='R')+(ch[i+2]!='L')+(ch[i+3]!='L'));
        }
    }
    return dp[n];
}

int main() {
    read(T);
    while(T--){
        read(n);
        cin>>ch;
        int ans = 1e9;
        for(int i=0;i<4;i++){
            string nxt = "";
            for(int j=0;j<n;j++)nxt+=ch[(i+j)%n];
            ans = min(ans,calc(nxt));
        }
        cout<<ans<<"\n";
    }
    return 0;
}