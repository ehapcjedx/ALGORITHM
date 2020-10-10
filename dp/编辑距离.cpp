//LeetCode 72
//luogu p2758

#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int len1 = word1.size(), len2 = word2.size();
//         int dp[len1+5][len2+5];

//         for(int i=0; i<=len2; i++)
//             dp[0][i] = i;

//         for(int i=1; i<=len1; i++)
//             dp[i][0] = i;

//         for(int i=1; i<=len1; i++)
//             for(int j=1; j<=len2; j++)
//                 {
//                     dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
//                     dp[i][j] = min(dp[i][j], dp[i-1][j-1]) + 1;
//                     if(word1[i-1] == word2[j-1])
//                         dp[i][j] = dp[i-1][j-1];
//                 }     
       
//         return dp[len1][len2];

//     }
// };


int main()
{
    string word1, word2;
    cin>>word1>>word2;
    int len1 = word1.size(), len2 = word2.size();
    int dp[len1+5][len2+5];

    for(int i=0; i<=len2; i++)
        dp[0][i] = i;

    for(int i=1; i<=len1; i++)
        dp[i][0] = i;

    for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]) + 1;
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
            }     
    
    cout<<dp[len1][len2];

    return 0;
}