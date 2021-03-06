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

	const int MX=205;
	// 素数表作成
	vector<bool> prime(MX);
	for(int i=2; i<MX; i++){
		prime[i] = true;
		for(int j=2; j<i; j++){
			if(i%j==0){
				prime[j]=false;
			}
		}
	}

	int a,b,c,d;
	cin >> a >> b >> c >> d;
	for(int i=a; i<=b;i++){
		bool win=true;
		for(int j=c; j<=d; j++){
			if(prime[i+j]){
				win = false;
			}
		}
		if(win){
			cout << "Takahashi" << endl;
			return EXIT_SUCCESS;
		}
	}

	cout << "Aoki" << endl;

    return EXIT_SUCCESS;
}