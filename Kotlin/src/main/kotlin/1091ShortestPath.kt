
// leetcode 1091

fun shortestPathBinaryMatrix(grid: Array<IntArray>): Int {
    if (grid[grid.size - 1][grid[0].size - 1] == 1 || grid[0][0] == 1) return -1
    val dirs = setOf(-1 to -1, -1 to 0, -1 to 1, 0 to -1, 0 to 1, 1 to -1, 1 to 0, 1 to 1)
    val q = ArrayDeque<Pair<Int, Int>>()
    var shortestPath = 1
    q += 0 to 0
    grid[0][0] = 1
    while (q.isNotEmpty() && grid[grid.size - 1][grid[0].size - 1] != 1) {
        for (i in 0 until q.size) {
            val (i, j) = q.removeFirst()
            for ((dx, dy) in dirs) {
                val ii = i + dx
                val jj = j + dy
                if (ii !in grid.indices || jj !in grid[0].indices || grid[ii][jj] == 1) continue

                q += ii to jj

                grid[ii][jj] = 1
            }
        }
        shortestPath++
    }
    return if (grid[grid.size - 1][grid[0].size - 1] != 1) -1 else shortestPath
}
