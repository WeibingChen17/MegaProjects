#include <vector>
class Point2D{
    public: 
        Point2D();
        ~Point2D() {};
        void setRandomInRange(float range);
        float distanceTo(Point2D other_point) const;
        friend std::ostream& operator<<(std::ostream& outstream, const Point2D& p){
            outstream << "(";
            for (size_t i = 0; i < p.m_dim - 1; ++i){
                outstream << p.m_coor[i] << ", ";
            }
            outstream << p.m_coor[p.m_dim - 1] << ")";
            return outstream;
        };
        static size_t randomSeed;
    private:
        const static size_t m_dim = 2;
        std::vector<float> m_coor;
};
