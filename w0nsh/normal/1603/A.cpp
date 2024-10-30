#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		VI A(n);
		FOR(i, n) std::cin >> A[i];

		bool wa = false;
		FOR(i, n){
			if(i > 40) continue;
			bool bad = true;
			REP(j, 2, i+3){
				if(A[i] % j != 0) bad = false;
			}
			if(bad){
				wa = true;
				break;
			}
		}
		std::cout << (wa ? "NO\n" : "YES\n");
	}


	return 0;
}