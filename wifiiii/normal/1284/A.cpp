#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

string a[22],b[22];
int main()
{
    int n,m;
    cin>>n>>m;
    ii cin>>a[i];
    ij cin>>b[i];
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        cout<<a[(x-1)%n+1]<<b[(x-1)%m+1]<<endl;
    }
}