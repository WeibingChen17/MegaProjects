#include <gmp.h>
class PiCalculator{
    public:
        PiCalculator();
        ~PiCalculator();
        size_t calculateUpTo(unsigned int, mpf_t);
    private:
        mpf_t m_y, m_a;
        mpf_t one, two, four, six;
        mpf_t m_pi;
        size_t m_k;
};
