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
    int N, K;
    cin >> N >> K;
    vector<int> c(N);

    rep(i, N){
        cin >> c[i];
    }
    map<int, int> mp;
    int max_ = 0;
    rep(i, K){
        mp[c[i]]++;
    }
    max_ = mp.size();
    int cnt = max_;
    rep2(i, K, N){
        mp[c[i]]++;
        if (mp[c[i]] == 1){
            cnt += 1;
        }
        mp[c[i - K]]--;

        if (mp[c[i - K]] == 0){
            cnt -= 1;
        }

        if (cnt > max_){
            max_ = cnt;
        }
    }

    cout << max_;

    cout << std::fixed << setprecision(15);

    return EXIT_SUCCESS;
}