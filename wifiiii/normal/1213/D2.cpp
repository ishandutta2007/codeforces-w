#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
#define int ll
int a[200005], cnt[200005], mp[200005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    int ans = 1e9;
    for(int i=1;i<=n;++i)
    {
        int tmp = a[i];
        int p = 0;
        do
        {
            cnt[tmp]++;
            mp[tmp]+=p;
            if(cnt[tmp] == k) ans=min(ans,mp[tmp]);
            tmp /= 2;
            ++p;
        }while(tmp);
    }
    cout<<ans<<endl;
}