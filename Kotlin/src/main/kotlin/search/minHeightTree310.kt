package search // leetcode 310

fun findMinHeightTrees(
    n: Int,
    edges: Array<IntArray>,
): List<Int> {
    if (n == 1) return listOf(0)
    val adj = Array<MutableList<Int>>(n) { mutableListOf() }
    val outbound = IntArray(n) { 0 }
    for ((u, v) in edges) {
        adj[u] += v
        adj[v] += u
        outbound[u]++
        outbound[v]++
    }

    val q = ArrayDeque<Int>()
    for (i in adj.indices) {
        if (outbound[i] == 1) q += i
    }

    var processed = 0
    while (n - processed > 2) {
        processed += q.size
        repeat(q.size) {
            val x = q.removeFirst()
            for (y in adj[x]) {
                outbound[y]--
                if (outbound[y] == 1) q += y
            }
        }
    }
    return q.toList()
}
