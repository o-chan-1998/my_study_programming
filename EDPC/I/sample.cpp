#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <queue>
#include <map>
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

double dp[3300][3300];
int n;
double p[3300];

int main()
{
    // ファイル出力
    const char *fileName = "trace.txt";
    ofstream ofs(fileName);
    if (!ofs)
    {
    cout << "ファイルが開けませんでした。" << endl;
    cin.get();
    return 0;
    }

    cin >> n;

    rep1(i,n){
        cin >> p[i];
    }

    dp[0][0]=1;

    rep1(i,n){
        ofs << "---(" << i << ")---" << endl;
        rep(j,i+1){
            if(j==0){
                // 1列目
                dp[i][j]=dp[i-1][j]*(1-p[i]);
            }
            else{
                dp[i][j]=dp[i-1][j]*(1-p[i])+dp[i-1][j-1]*p[i];
            }
        }
        rep(ii,n+1){
            rep(jj,n+1){
                ofs << dp[ii][jj] << " ";
            }
            ofs << endl;
        }
        ofs << endl;
    }

    double ans=0.0;
    rep(i,n+1){
        if(i>n-i){
            ans+=dp[n][i];
        }
    }

    cout << ans << endl;

    ofs.close();

    return EXIT_SUCCESS;
}