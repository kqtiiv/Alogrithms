package dynamic

class Solution {
    fun canPartition(nums: IntArray): Boolean {
        val total: Int = nums.sum()
        if (total and 1 == 1) return false

        val target: Int = total / 2

        val dp: BooleanArray = BooleanArray(target + 1) { false }
        dp[0] = true
        for (num in nums) {
            for (total in target downTo 1) {
                if (total - num >= 0) dp[total] = dp[total] or dp[total - num]
                if (dp[target]) return true
            }
        }
        return dp[target]
    }
}
