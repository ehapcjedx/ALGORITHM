//LeetCode 62
//二维dp

#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[110][110];
        for(int i=0; i<110; i++)
        {
            dp[1][i] = 1;
            dp[i][1] = 1;
        }

        for(int i=2; i<=m; i++)
            for(int j=2; j<=n; j++)
                dp[i][j] = dp[i][j-1] + dp[i-1][j];

        return dp[m][n];

    }
};


int main()
{
    Solution ss;
    int res = ss.uniquePaths(7,3);
    cout<<res;
    return 0;
}