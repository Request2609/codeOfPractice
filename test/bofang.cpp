#include <iostream>
#include <cmath>
/*考虑 dp[i][j]。最后一首歌，我们可以播放没有播放过的歌也
 * 可以是播放过的。如果未播放过的，那么就是 dp[i-1][j-1] * 
 * (N-j) 种选择方法
 * 。如果不是，那么就是选择之前的一首歌，
 * dp[i-1][j] * max(j-K, 0)（j 首歌，
 * 最近的 K 首不可以播放）。
 *
 * */
class Solution {
public :
    int numMusicPlaylists(int N, int L, int K) {
        int MOD = 1000000007;

        long dp[L+1][N+1];
        dp[0][0] = 1;
        for (int i = 1; i <= L; ++i)
            for (int j = 1; j <= N; ++j) {
                dp[i][j] += dp[i-1][j-1] * (N-j+1);
                dp[i][j] += dp[i-1][j] *((j-K>0)?(j-K):0);
                dp[i][j] %= MOD;
            }
        return (int) dp[L][N];
    }
} ;

int main(){
    return 0;
}

