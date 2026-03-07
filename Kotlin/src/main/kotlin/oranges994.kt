
// leetcode 994

fun orangesRotting(grid: Array<IntArray>): Int {
    val m = grid.size
    val n = grid[0].size
    val q = ArrayDeque<Pair<Int, Int>>()

    var fresh = 0
    var time = 0
    val dirs = setOf(0 to 1, 1 to 0, 0 to -1, -1 to 0)
    for (i in 0 until m) {
        for (j in 0 until n) {
            when (grid[i][j]) {
                1 -> fresh++
                2 -> q += i to j
            }
        }
    }

    while (q.isNotEmpty() && fresh > 0) {
        for (i in 0 until q.size) {
            val (i, j) = q.removeFirst()
            for ((dr, dc) in dirs) {
                val ii = dr + i
                val jj = dc + j
                if (ii !in 0 until m || jj !in 0 until n || grid[ii][jj] != 1) continue
                fresh--
                grid[ii][jj] = 2
                q += ii to jj
            }
        }
        time++
    }
    return if (fresh == 0) {
        time
    } else {
        -1
    }
}
