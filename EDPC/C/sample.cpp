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

ll n;
ll happy[110000][3];
ll dp[110000][3];

int main()
{
	// IO高速化のおまじない
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n;

    rep1(i,n){
        cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
    }

    rep1(i,n){
        rep(place,3){
            rep(placeY,3){
                if(place==placeY){
                    continue;
                }
                ll check01 = dp[i][place];
                ll check02 = dp[i-1][placeY]+happy[i][place];
                if(check01>=check02){
                    dp[i][place] = check01;
                }else{
                    dp[i][place] = check02;
                }
            }
        }
    }

    ll ans = 0;
    rep(place,3){
        ans = max(ans, dp[n][place]);
    }

    cout << ans << endl;

    return EXIT_SUCCESS;
}