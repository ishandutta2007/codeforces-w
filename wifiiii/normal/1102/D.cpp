#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi cnt(3);
    int m = n / 3;
    for(char c : s) cnt[c-'0']++;
    // 0 -> 1
    // 0 -> 2
    // 1 -> 0
    // 1 -> 2
    // 2 -> 1
    // 2 -> 0
    for(char &c : s) {
        if(cnt[c-'0'] == m) continue;
        if(cnt[c-'0'] > m) {
            for(int i='0';i<c;++i) {
                if(cnt[i-'0'] < m) {
                    --cnt[c-'0'];
                    c = i;
                    ++cnt[c-'0'];
                }
            }
        }
    }
    reverse(all(s));
    for(char &c : s) {
        if(cnt[c-'0'] == m) continue;
        if(cnt[c-'0'] > m) {
            for(int i=c+1;i<='2';++i) {
                if(cnt[i-'0'] < m) {
                    --cnt[c-'0'];
                    c = i;
                    ++cnt[c-'0'];
                }
            }
        }
    }
    reverse(all(s));
    cout << s << endl;
}