// leetcode 802

fun eventualSafeNodes(graph: Array<IntArray>): List<Int> {
    val safeNodes = mutableListOf<Int>()
    val entered = IntArray(graph.size) { 0 }
    val exited = IntArray(graph.size) { 0 }

    fun dfsts(x: Int): Boolean {
        entered[x] = 1
        for (y in graph[x]) {
            if (entered[y] == 1) {
                if (exited[y] == 0) {
                    return false
                }
            } else if (!dfsts(y)) {
                return false
            }
        }
        safeNodes += x
        exited[x] = 1
        return true
    }

    for (x in graph.indices) {
        if (entered[x] == 0) dfsts(x)
    }
    safeNodes.sort()
    return safeNodes
}
