#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : a)
#define SZ(i) ((int)(i).size())
#define X first
#define Y second
#define PR std::pair
#define PII std::pair<int, int>
#define MP std::make_pair
#define ll long long
#define VI std::vector<int>


int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str;
	int n;
	std::cin >> n;
	std::cin >> str;
	int rem = n-1;
	FOR(i, n-1){
		if(str[i] > str[i+1]){
			rem = i;
			break;
		} 
	}
	FOR(i, n) if(i != rem) std::cout << str[i];
	return 0;
}