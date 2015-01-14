A* Library
===============
A* pathfinding library written in C++11

Originally this library designed to support [weighted graphs](https://books.google.ca/books?id=1OJ8EhvuPXAC&pg=PA199&lpg=PA199) but I decided to remove the support until I implement JPS. if you want to add a support you can easily do so by holding weights in nodes and check that value when you estimate the cost from that node.

**Warning**: This is not the final product, I'm planning to make some fundamental changes to the implementation (it will still be in C++11 and will heavily use STL).

Usage
------
You can setup the library by using

    //first you'll need to crea a grid.
    Grid *grid = new Grid(cols, rows, movement, obstacles);
    //then all you have to do is to pass a pointer to grid, and call search function with start and goal nodes.
    AStar astar(grid);
    vector<Node> path = astar.search(start, goal);
    //path will contain the nodes lying on the shortest path from start to goal.

You can also take a look at the sample usage in main.cpp


TODO
------
This is purely for me to keep track of my progress, but if you want to help me with any of these, then by all means, send me a message and we'll get started :)

1. Implement JPS Optimization
2. [Euclidean Heuristic Optimization](http://webdocs.cs.ualberta.ca/~rayner/RaynerEtAl-11.pdf) looks promising, look into it.
3. Implement Multi-dimensional support
4. obsticles container(unordered_sets) currently stores Node object rather than pointers to node obj. Implement necessary comparator functions so  that it can safely store pointers to objects instead.
5. Put it inside a namesapce instead.
6. Implement a better error handling
7. Storing all the nodes in the map vs allocating the ones we need (compare performance differences)
