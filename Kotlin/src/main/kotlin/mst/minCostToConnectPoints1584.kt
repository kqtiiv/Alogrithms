package mst

fun minCostConnectPoints(points: Array<IntArray>): Int {
    val n = points.size

    val tree = BooleanArray(n) { false }
    val minWeight = IntArray(n) { Int.MAX_VALUE }

    var totalCost = 0
    var nodesAdded = 0

    var cur = 0
    minWeight[cur] = 0

    fun calcDist(
        point1: IntArray,
        point2: IntArray,
    ) = Math.abs(point2[0] - point1[0]) + Math.abs(point2[1] - point1[1])

    while (nodesAdded < n) {
        tree[cur] = true
        totalCost += minWeight[cur]
        nodesAdded++
        var nextNode = -1
        var lowestNextWeight = Int.MAX_VALUE

        for (i in 0 until n) {
            if (!tree[i]) {
                val dist = calcDist(points[i], points[cur])
                if (dist < minWeight[i]) {
                    minWeight[i] = dist
                }
                if (minWeight[i] < lowestNextWeight) {
                    lowestNextWeight = minWeight[i]
                    nextNode = i
                }
            }
        }
        cur = nextNode
    }
    return totalCost
}
