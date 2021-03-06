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

ll n,k;
ll a[110];
// 山がdp[i]個の状態のときに、先手が勝つか？
ll dp[110000];

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> k;
    rep(i,n){
        // xxx
        cin >> a[i];
    }

    rep(i,k+1){
        // 先手が負けるとして初期化
        dp[i]=false;
        rep(j,n){
            if(i-a[j]>=0){
                // 先手が勝っているか、a[j]前に負けていない。
                // ここは理解が足りていない。
                dp[i] = dp[i] | !dp[i-a[j]];
            }
        }
    }

    if(dp[k]){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }

    return EXIT_SUCCESS;
}