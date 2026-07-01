package mst
//
// fun findRedundantConnection(edges: Array<IntArray>): IntArray {
//    val n: Int = edges.size
//
//    val cycleStart: Int = -1
//    val visited=  MutableList(n) {false}
//
//    val parent= MutableList(n) {-1}
//
//    val adjList= List<MutableList<Int>>(n) {mutableListOf()}
//
//    for (edge in edges) {
//        adjList[edge[0] - 1].add(edge[1] - 1)
//        adjList[edge[1] - 1].add(edge[0] - 1)
//    }
//
//    dfs(0)
//
//    val cycleNodes: Map<Int, Int> = mutableMapOf()
//    var node: Int = cycleStart
//
//    // Start from the cycleStart node and backtrack to get all the nodes in
//    // the cycle. Mark them all in the map.
//    do {
//        cycleNodes[node] = 1
//        node = parent[node]
//    } while (node != cycleStart)
//
//    // If both nodes of the edge were marked as cycle nodes then this edge
//    // can be removed.
//    for (i in n-1 downTo 0) {
//        if (
//            cycleNodes.containsKey(edges[i][0] - 1) &&
//            cycleNodes.containsKey(edges[i][1] - 1)
//        ) {
//            return edges[i]
//        }
//    }
//
//    fun dfs(
//        src: Int
//    ) {
//        visited[src] = true;
//
//        for (int adj : adjList[src]) {
//        if (!visited[adj]) {
//            parent[adj] = src;
//            DFS(adj, visited, adjList, parent);
//            // If the node is visited and the parent is different then the
//            // node is part of the cycle.
//        } else if (adj != parent[src] && cycleStart == -1) {
//            cycleStart = adj;
//            parent[adj] = src;
//        }
//    }
//    }
//
//
//
//        return new int[] {}; // This line should theoretically never be reached
//    }
//
//    val queue: ArrayDeque<>
// }
