#include <string>
#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

template<typename T>
class Cluster {
    public:
        Cluster(size_t n): m_numberOfPoints(n){ 
            for (size_t i = 0; i < m_numberOfPoints; ++i){
                T point;
                m_points.push_back(point);
            }
        }

        Cluster(const std::vector<T>& pts){
            m_numberOfPoints = pts.size();
            m_points = pts;
        }

        Cluster<T> & operator=(const Cluster<T>& Other_cluster){
            m_numberOfPoints = Other_cluster.m_points.size();
            m_points = Other_cluster.m_points;
            return (*this);
        }

        ~Cluster() {};

        size_t getNumberOfPoints() { return m_numberOfPoints; }

        void randomInit(float range){
            for (auto & a_point : m_points){
                a_point.setRandomInRange(range);
            }
        }

        Cluster<T> getClosestPairBF() const{
            //brute force
            float minDis = std::numeric_limits<float>::max();
            size_t mini = 0, minj = 0;
            for (size_t i = 0; i < m_numberOfPoints; ++i){
                for (size_t j = i + 1; j < m_numberOfPoints; ++j){
                    float d = m_points[i].distanceTo(m_points[j]);
                    if (d < minDis){
                        mini = i; 
                        minj = j;
                        minDis = d;
                    }
                }
            }
            std::vector<T> pts;
            pts.push_back(m_points[mini]);
            pts.push_back(m_points[minj]);
            return Cluster<T>(pts);
        }

        std::vector<T> divideAndConquer(std::vector<T> m_points) const{
            if (m_points.size() <= 2)
                return m_points;
            std::vector<T> left(m_points.begin(), m_points.begin() + m_points.size()/2);
            std::vector<T> right(m_points.begin() + m_points.size()/2, m_points.end());
            std::vector<T> leftPair = divideAndConquer(left);
            std::vector<T> rightPair = divideAndConquer(right);
            float leftD = std::numeric_limits<float>::max();
            float rightD = std::numeric_limits<float>::max();
            if (leftPair.size() == 2)
                leftD = leftPair[0].distanceTo(leftPair[1]);
            if (rightPair.size() == 2)
                rightD = rightPair[0].distanceTo(rightPair[1]);
            float d = leftD < rightD ? leftD : rightD;
            std::vector<T> vl, vr;
            std::vector<T> crossPair;
            for (auto& p : left) {
                if (right.front()[0] - p[0] < d) vl.push_back(p);
            }
            for (auto& p : right){
                if (p[0] - left.back()[0] < d) vr.push_back(p);
            }
            for (auto& pl : vl){
                for (auto& pr : vr){
                    if (pr[1] - pl[1] < d and pl[1] - pr[1] < d and pl.distanceTo(pr) < d){
                        crossPair.clear();
                        crossPair.push_back(pl);
                        crossPair.push_back(pr);
                        d = pl.distanceTo(pr);
                    }
                }
            } 
            if (crossPair.size() > 0){
                return crossPair;
            } else if (leftD < rightD){
                return leftPair;
            } else {
                return rightPair;
            }
        }

        Cluster<T> getClosestPairDC() const{
            //divide and conquer
            std::vector<T> dup(m_points);
            std::sort(dup.begin(), dup.end(), [](T p1, T p2){return p1[0] < p2[0];});
            std::vector<T> res = divideAndConquer(dup);
            return Cluster<T>(res);
        }

        Cluster<T> getClosestPair(std::string str="") const{
            if (str == "" or str == "dc")
                return getClosestPairDC();
            else if (str == "bf")
                return getClosestPairBF();
            else
                throw("Wrong options");
        }
        
        friend std::ostream& operator<<(std::ostream& outstream, const Cluster<T>& C){
            for (auto& a_point : C.m_points){
                outstream << a_point << std::endl;
            }
            return outstream;
        }
    private:
        size_t m_numberOfPoints;
        std::vector<T> m_points;
};
