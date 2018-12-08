#include <cmath>
#include <random>
#include "Point2D.h"

size_t Point2D::randomSeed = static_cast<long unsigned int>(time(0));

Point2D::Point2D(){
    m_coor.resize(m_dim);
    for (size_t i = 0; i < m_dim; ++i){
        m_coor[m_dim] = 0.0;
    }
}

void Point2D::setRandomInRange(float range){
    randomSeed += 1;
    std::mt19937 gen(randomSeed);
    std::uniform_real_distribution<> dis(-range, range);
    for (size_t i = 0; i < m_dim; ++i){
        m_coor[i] = dis(gen);
    }
}
float Point2D::distanceTo(Point2D other_point) const{
    float sum = 0.0;
    for (size_t i = 0; i < m_dim; ++i){
        sum += m_coor[i];
    }
    return std::sqrt(sum);
}
