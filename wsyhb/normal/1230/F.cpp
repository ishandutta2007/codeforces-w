#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    const int buffer_size=1e5+5;
    char buf[buffer_size],*S,*T;
    bool flag_EOF;
    inline char read_char()
    {
        if(S==T)
            T=(S=buf)+fread(buf,1,buffer_size,stdin);
        return S!=T?*(S++):EOF;
    }
    inline int read_int()
    {
        int flag=1;
        char c=read_char();
        while(c<'0'||c>'9')
        {
            if(c==EOF)
            {
                flag_EOF=true;
                return 0;
            }
            flag=(c=='-'?-1:1);
            c=read_char();
        }
        int x=0;
        while(c>='0'&&c<='9')
        {
            x=x*10+(c^48);
            c=read_char();
        }
        return x*flag;
    }
    char st[13];
    int _top;
    void Write(int x)
    {
        if(!x)
        {
            putchar('0');
            return;
        }
        if(x<0)
        {
            putchar('-');
            x=-x;
        }
        while(x)
        {
            st[++_top]=x%10+'0';
            x/=10;
        }
        while(_top>0)
            putchar(st[_top--]);
    }
}
const int P=1e9+7;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=P?P:0);
}
inline void sub(int &a,int b)
{
    a=a-b+(a-b<0?P:0);
}
inline void mul(int &a,int b)
{
    a=1ll*a*b%P;
}
inline int get_sum(int a,int b)
{
    return a+b-(a+b>=P?P:0);
}
inline int get_dif(int a,int b)
{
    return a-b+(a-b<0?P:0);
}
inline int get_pro(int a,int b)
{
    return 1ll*a*b%P;
}
inline int get_power(int a,int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)
            mul(res,a);
        mul(a,a);
        n>>=1;
    }
    return res;
}
const int max_n=1e5+5;
vector<int> bigger[max_n];
int cnt_bigger[max_n],cnt_smaller[max_n];
inline long long get_ans(int x)
{
    return 1ll*cnt_bigger[x]*cnt_smaller[x];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        bigger[a].push_back(b);
        ++cnt_bigger[a];
        ++cnt_smaller[b];
    }
    long long ans=0;
    for(int i=1;i<=n;++i)
        ans+=get_ans(i);
    printf("%lld\n",ans);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int v;
        scanf("%d",&v);
        ans-=get_ans(v);
        while(cnt_bigger[v]>0)
        {
            int x=bigger[v].back();
            bigger[v].pop_back();
            --cnt_bigger[v];
            ++cnt_smaller[v];
            ans-=get_ans(x);
            --cnt_smaller[x];
            bigger[x].push_back(v);
            ++cnt_bigger[x];
            ans+=get_ans(x);
        }
        ans+=get_ans(v);
        printf("%lld\n",ans);
    }
    return 0;
}