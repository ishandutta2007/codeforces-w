#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
//random_device rng;
//mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int ok=0;
        ii cin>>a[i];
        ii if(a[i]==x) ok=1;
        if(ok)
        {
            cout<<1<<endl;
            continue;
        }
        sort(alll(a));
        int mx=a[n];
        int ans=max(2,(x+mx-1)/mx);
        cout<<ans<<endl;
    }
}