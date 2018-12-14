#include <iostream>
#include "Point2D.h"
#include "Cluster.hpp"
#include <string>
#include <time.h>

int main(int argc, char* argv[]){
    if (argc != 3) {
        std::cout << "main number_of_points range" << std::endl;
    }
    int numP = std::stoi(argv[1]);
    float range = std::stof(argv[2]);
    Cluster<Point2D> points(numP);
    points.randomInit(range);
    clock_t t = clock();
    Cluster<Point2D> pair1 = points.getClosestPair("bf"); 
    std::cout << pair1;
    std::cout << "time in tick: " << clock() - t << std::endl;
    t = clock();
    Cluster<Point2D> pair2 = points.getClosestPair("dc"); 
    std::cout << pair2;
    std::cout << "time in tick: " << clock() - t << std::endl;
}
