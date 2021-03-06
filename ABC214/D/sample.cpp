#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <bitset>
#include <numeric> // iota関数
#include <fstream>

using namespace std;

#define rep(i, H) for (int i = 0; i < H; i++)
#define rep1(i, H) for (int i = 1; i <= H; i++)
#define drep(i, H) for (int i = H - 1; i >= 0; i--)
#define drep1(i, H) for (int i = H; i >= 1; i--)
#define srep(i, S, T) for (int i = S; i < T; i++)
#define rng(a) a.begin(), a.end()

template <typename T>
using vc = vector<T>;
template <typename T>
using vv = vc<vc<T>>;
template <typename T>
using vvv = vv<vc<T>>;
using vi = vc<int>;
using vvi = vv<int>;
using vvvi = vvv<int>;
using vl = vc<long>;
using vvl = vv<long>;
using ll = long long;
using vll = vc<ll>;
using vvll = vv<ll>;

struct UnionFind {
	vi d;
	UnionFind(int n=0): d(n,-1) {}
	int find(int x) {
		if (d[x] < 0){
			return x;
		}
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y) {
		x = find(x); 
		y = find(y);
		if (x == y){
			return false;
		}
		if (d[x] > d[y]){
			swap(x,y);
		} 
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { 
		return find(x) == find(y);
	}
	int size(int x) { 
		return -d[find(x)];
	}
};

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, pair<int,int>>> es;

	rep(i,n-1){
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		es.emplace_back(w, pair<int,int>(u,v));
	}

	// 重みの昇順に整列
	sort(es.begin(), es.end());

	UnionFind d(n);

	ll ans = 0;
	
	// 重みの小さい順にUnionFindしていく
	for(auto p: es){
		// 重み✕端末1のサイズ✕端末2のサイズ
		ans += (ll)(p.first)*d.size(p.second.first)*d.size(p.second.second);
		d.unite(p.second.first, p.second.second);
	}

	cout << ans << endl;

    return EXIT_SUCCESS;
}