# LC problem log in c++

[2812 - Find the Safest Path in a Grid](./2812safestPath.cpp)
use BFS to calculate safeness of each square in the grid, as it is calculated via manhattan distance away from theives
(remember the bounds of the grid before pushing)
max-heap Dijkstra - use a PQ of tuples of <safeness, r, c> sorting by safeness first (a max heap) 
make sure to delete any stale queue entries, as sometimes multiple cells can be pushed with different values
the FIRST time you finalise a value in the heap, it is GUARANTEED to be the correct value for that cell, due to correctness of Dikjstra, so if you find the final cell in the pq, the corresponding safeness value is the return value.

problem asks to MAXIMIZE the MIN along a path

[3286 - Find a Safe Walk in a Grid](./3286safeWalk.cpp)
max-heap Dijkstra again - with PQ of <health, r, c>, sorting by health first
push the NEW computed value into the queue
delete stale queue entries first
ensure start health is correct before pushing
BFS must include all 4 directions
remember to return value early

problem asks to MAXIMIZE an accumulated cost with a cap (health), tracking budget
