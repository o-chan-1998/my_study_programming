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

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n=3;
	const int M = 200005;
	vector<int> d(M);
	vi a{6,2,3};	// 与式数列
	
	// 数列の出現カウンタ
	rep(i,n) {
		d[a[i]]++;
	}
	
	ll ans = 0;
	
	// 問題の結論となる組み合わせを総当り
	for (int a = 1; a < M; a++) {
		// cの値がM以下なので、aと掛けるbはM/a以下
		for (int b = 1; b <= (M-1)/a; b++) {
			int c = a*b;
			ans += (ll)d[a]*d[b]*d[c];
		}
	}
	cout << ans << endl;

    return EXIT_SUCCESS;
}


