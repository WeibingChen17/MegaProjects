# Find the pair of points with the least distance

This is a general engine of finding the pair of *points* with the least *distance*.  The point is a class with a member function of dist(other), which returns a float value, i.e., the distance to other point. 

**For 2D points only now** 

## Algorithm
Use divide-and-conquer algorithm for 2D points.

## Todo
* __add time statistics__
* improve the divideAndConquer to avoid copy. Use iterator and return a tuple
* support higher dimension
