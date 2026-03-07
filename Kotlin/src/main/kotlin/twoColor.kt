// leetcode 886

fun possibleBipartition(
    n: Int,
    dislikes: Array<IntArray>,
): Boolean {
    val vis = IntArray(n) { 0 }
    val colors = IntArray(n) { -1 }
    val adj = Array<MutableList<Int>>(n) { mutableListOf() }
    for (pair in dislikes) {
        val u = pair[0] - 1
        val v = pair[1] - 1
        adj[u].add(v)
        adj[v].add(u)
    }

    fun dfs(
        x: Int,
        col: Int,
    ): Boolean {
        vis[x] = 1
        colors[x] = col
        for (i in adj[x]) {
            if (vis[i] == 0) {
                if (!dfs(i, 1 - col)) return false
            } else if (colors[i] == col) {
                return false
            }
        }
        return true
    }
    for (i in 0..<n) {
        if (vis[i] == 0) {
            if (!dfs(i, 0)) return false
        }
    }
    return true
}
