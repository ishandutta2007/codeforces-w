#include <bits/stdc++.h>
typedef long long LL;
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define RALL(X) (X).rbegin(), (X).rend()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRVI(N, X) VI X(N); for (int ___I=0; ___I<N; ___I++) scanf("%d", &(X[___I]))  
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second

using namespace std;

int main(){
    CASET{
        LL k;
        scanf("%I64d",&k);
        if (k&1) {printf("-1\n"); continue;}
        VI r(0);
        REP(i,60){
            if ((1LL<<(i+1))&k){
                //cout<<"isin "<<i<<endl;
                r.PB(1);
                if (i) r.PB(i);
            }
        }
        //printf("%d\n", SZ(r));
        int ncp=0;
        int ir=0;
        VI rr(0);
        int ar=0;
        for (auto ir:r){
            //cout<<"ir "<<ir<<endl;
            REP(i,ir-1) {rr.PB(0);}
            rr.PB(1);
            //printf("%d%c", )
        }
        printf("%d\n", SZ(rr));
        REP(i,SZ(rr)){
            printf("%d%c", rr[i], (i==SZ(rr)-1)?'\n':' ');
        }
    }
}