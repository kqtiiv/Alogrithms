# problem log in c++

[2812 - Find the Safest Path in a Grid](./2812safestPath.cpp)
use BFS to calculate safeness of each square in the grid, as it is calculated via manhattan distance away from theives
(remember the bounds of the grid before pushing)
max-heap Dijkstra - use a PQ of tuples of <safeness, r, c> sorting by safeness first (a max heap) 
make sure to delete any stale queue entries, as sometimes multiple cells can be pushed with different values
the FIRST time you finalise a value in the heap, it is GUARANTEED to be the correct value for that cell, due to correctness of Dikjstra, so if you find the final cell in the pq, the corresponding safeness value is the return value.
