#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	VI A(n);
	FOR(i, n) std::cin >> A[i];
	std::sort(A.begin(), A.end());
	ll left = 1;
	ll right = 2000000006;
	while(left < right){
		ll mid = (left+right)/2;
		ll need = 0;
		REP(i, n/2, n) need += std::max(0ll, mid-A[i]);
		if(need > k) right = mid;
		else left = mid+1;
	}
	std::cout << left-1;
	return 0;
}