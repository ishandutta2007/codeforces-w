#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define R(X) cin>>(X)
#define RII(X, Y) cin>>(X)>>(Y)
#define RIII(X, Y, Z)  cin>>(X)>>(Y)>>(Z)
#define DRI(X) int (X); cin>>(X)
#define DRII(X, Y) int X, Y; cin>>(X)>>(Y)
#define DRIII(X, Y, Z) int X, Y, Z; cin>>(X)>>(Y)>>(Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I]) 
#define DRVL(N, X) VL X(N); for (int ___I=0; ___I<N; ___I++) cin>>(X[___I])
#define RS(X) cin>>X
#define DRS(X) string X; cin>>X
#define CASET int ___T, case_n = 1; cin>>___T; while (___T-- > 0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define PB push_back
#define F first
#define S second

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod=1000000007;
    CASET{
        DRI(n);
        VL fact(n+1,1);
        REPP(i,1,n+1){
            fact[i]=(fact[i-1]*i)%mod;
        }
        DRVI(n,a);
        int themin=1000000000;
        map<int,int> mc;
        REP(i,n){
            mc[a[i]]++;
            themin=min(themin, a[i]);
        }
        LL res=0;
        bool isok=true;
        
        for (auto i: mc){
            if ((themin&i.F)!=themin) isok=false;
            //cout<<themin<<" "<<i.F<<" "<<isok<<endl;
        }
        if (isok){
            if (mc[themin]>1){
                res=(((fact[n-2]*mc[themin])%mod)*(mc[themin]-1))%mod;
            }
        }/*
        for (auto i: mc){
            if (i.S>1){
                    res+=(((fact[n-2]*i.S)%mod)*(i.S-1))%mod;
                    res%=mod;
                }
        }*/
        cout<<res<<"\n";
    }
}