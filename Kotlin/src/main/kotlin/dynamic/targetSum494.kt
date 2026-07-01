package dynamic

class Solution {
    fun findTargetSumWays(
        nums: IntArray,
        target: Int,
    ): Int {
        val n: Int = nums.size
        val total = nums.sum()

        if (Math.abs(target) > total || target + total and 1 == 1) return 0

        val positiveTarget = (target + total) / 2

        val dp = IntArray(positiveTarget + 1) { 0 }
        dp[0] = 1

        for (num in nums) {
            for (j in positiveTarget downTo num) {
                dp[j] += dp[j - num]
            }
        }

        return dp[positiveTarget]
    }
}

class Solution2 {
    var cnt = 0

    fun findTargetSumWays(
        nums: IntArray,
        target: Int,
    ): Int {
        fun backtrack(
            idx: Int,
            sum: Int,
        ) {
            if (idx == nums.size) {
                if (sum == target) cnt++
                return
            }
            backtrack(idx + 1, sum + nums[idx])
            backtrack(idx + 1, sum - nums[idx])
        }
        backtrack(0, 0)
        return cnt
    }
}
