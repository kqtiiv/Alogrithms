package dynamic

class Solution {
    fun minDistance(
        word1: String,
        word2: String,
    ): Int {
        val n: Int = word1.length
        val m: Int = word2.length

        val dp: Array<IntArray> = Array(n + 1) { IntArray(m + 1) }

        for (i in 0..n) {
            dp[i][0] = i
        }

        for (j in 0..m) {
            dp[0][j] = j
        }

        for (i in 1..n) {
            for (j in 1..m) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]
                } else {
                    dp[i][j] = minOf(1 + dp[i][j - 1], 1 + dp[i - 1][j], 1 + dp[i - 1][j - 1])
                }
            }
        }

        return dp[n][m]
    }
}
