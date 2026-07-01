package dynamic

import kotlin.math.min

class Solution {
    fun coinChange(
        coins: IntArray,
        amount: Int,
    ): Int {
        val numCoins: IntArray = IntArray(amount + 1) { amount + 1 }
        numCoins[0] = 0
        for (i in 1..amount) {
            for (coin in coins) {
                if (i - coin >= 0) numCoins[i] = min(numCoins[i], numCoins[i - coin] + 1)
            }
        }
        if (numCoins[amount] > amount) return -1
        return numCoins[amount]
    }
}
