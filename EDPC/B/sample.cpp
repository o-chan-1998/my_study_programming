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
const int INF = 1 << 30;

int n, k;
int h[100010];

int dp[100010];

int main() {
    cin >> n >> k;
    rep(i,n){
        cin >> h[i];
	}

    rep(i,100010){
        dp[i] = INF;
	}

    dp[0] = 0;
    rep(i,n){
        rep1(j,k){
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
		}
	}

    cout << dp[n - 1] << endl;


    return EXIT_SUCCESS;
}