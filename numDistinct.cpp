class Solution {
public:
    int numDistinct(string S, string T) {
        int dp[T.length() + 1][S.length()+1] ;
        int i = 0, j = 0;
        for (i = 0; i < S.length() + 1; i++){
            dp[0][i] = 1;
        }
        for(i = 1; i < T.length() + 1; i++){
            dp[i][0] = 0 ;
        }
        for (i = 1; i < T.length() + 1; i++){
            for(j = 1; j < S.length() + 1; j++){
                if(S.at(j - 1) == T.at(i - 1)){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j - 1];
                }else{
                    dp[i][j] = dp[i][j - 1] ;
                }
            }
        }
        return dp[T.length()][S.length()] ;
    }
};