#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=0,r=0;
    for(char c:s) if(c=='(') l++;else r++;
    if(l != r) return cout << -1 << endl, 0;
    int p = 0, last = 0, ans = 0;
    int f = 0;
    for(char c:s)
    {
        if(c=='(') ++p;
        else --p;
        if(p < 0) f = 1;
        if(f) ++ans;
        if(p >= 0) f = 0;
    }
    cout << ans << endl;
}