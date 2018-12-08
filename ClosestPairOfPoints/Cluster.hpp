#include <string>
#include <vector>
#include <cstdint>

template<typename T>
class Cluster {
    public:
        Cluster(size_t n): m_numberOfPoints(n){ 
            m_points.reserve(n);
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

        size_t getNumberOfPoints() {
            return m_numberOfPoints;
        }

        void randomInit(float range){
            for (size_t i = 0; i < m_numberOfPoints; i++){
                T point;
                point.setRandomInRange(range);
                m_points.push_back(point);
            }
        }

        Cluster<T> getClosestPair() const{
            //brute force
            float minDis = std::numeric_limits<float>::max();
            size_t mini = 0, minj = 0;
            for (size_t i = 0; i < m_numberOfPoints; ++i){
                for (size_t j = i + 1; j < m_numberOfPoints; ++j){
                    if (m_points[i].distanceTo(m_points[j]) < minDis){
                        mini = i; 
                        minj = j;
                    }
                }
            }
            std::vector<T> pts;
            pts.push_back(m_points[mini]);
            pts.push_back(m_points[minj]);
            return Cluster<T>(pts);
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
