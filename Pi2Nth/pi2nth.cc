#include "pi2nth.h"

void print_mpf_t(int n, mpf_t x){
    gmp_printf("%.*Ff \n", n, x);
}

PiCalculator::PiCalculator(){
}

PiCalculator::~PiCalculator(){
}

void PiCalculator::calculateUpTo(unsigned int m, mpf_t res){
    int n = 2 * int(m * 3.32) ; // 2 * m * log_2(10), which is very enough
    mpf_init2(res, n);
    mpf_init2(m_pi, n);
    mpf_init2(m_y, n);
    mpf_init2(m_a, n);
    mpf_init2(one, n);
    mpf_init2(two, n);
    mpf_init2(four, n);
    mpf_init2(six, n);

    mpf_set_d(one, 1.0);
    mpf_set_d(two, 2.0);
    mpf_set_d(four, 4.0);
    mpf_set_d(six, 6.0);

    mpf_t sqrt2, m4sqrt2; 
    mpf_init2(sqrt2, n);
    mpf_sqrt(sqrt2, two);
    mpf_sub(m_y, sqrt2, one);

    mpf_init2(m4sqrt2, n);
    mpf_mul(m4sqrt2, four, sqrt2);
    mpf_sub(m_a, six, m4sqrt2);

    mpf_set_d(m_pi, 3.0);
    mpf_clear(sqrt2);
    mpf_clear(m4sqrt2);

    m_k = 0;

    mpf_t y2, y4, m1my4, m1my4_4, m1my4_4_n1, uf, df;
    mpf_t m1py, m1py4, m1pypyy, pow2ip3, am1py4, pow2y, pow2yy, yy;
    mpf_init2(y2, n);
    mpf_init2(y4, n);
    mpf_init2(m1my4, n);
    mpf_init2(m1my4_4, n);
    mpf_init2(m1my4_4_n1, n);
    mpf_init2(uf, n);
    mpf_init2(df, n);
    mpf_init2(m1py, n);
    mpf_init2(m1py4, n);
    mpf_init2(pow2ip3, n);
    mpf_init2(am1py4, n);
    mpf_init2(m1pypyy, n);
    mpf_init2(pow2y, n);
    mpf_init2(pow2yy, n);
    mpf_init2(yy, n);

    while (true){
        mpf_pow_ui(y2, m_y, 2);
        mpf_pow_ui(y4, y2, 2);
        mpf_sub(m1my4, one, y4);
        mpf_sqrt(m1my4_4, m1my4);
        mpf_sqrt(m1my4_4_n1, m1my4_4);
        mpf_sub(uf, one, m1my4_4_n1);
        mpf_add(df, one, m1my4_4_n1);
        mpf_div(m_y, uf, df);

        mpf_pow_ui(y2, m_y, 2);
        mpf_add(m1py, one, m_y);
        mpf_pow_ui(m1py4, m1py, 4);
        mpf_mul(am1py4, m_a, m1py4);
        mpf_pow_ui(pow2ip3, two, 2*m_k+3);
        mpf_mul(pow2y, pow2ip3, m_y);
        mpf_add(yy, m1py, y2);
        mpf_mul(pow2yy, pow2y, yy);
        mpf_sub(m_a, am1py4, pow2yy);

        mpf_t new_pi;
        mpf_init2(new_pi, n);
        mpf_div(new_pi, one, m_a);
        if (mpf_eq(new_pi, m_pi, m)){
            mpf_set(m_pi, new_pi);
            mpf_clear(new_pi);
            m_k += 1;
            break;
        }
        mpf_set(m_pi, new_pi);
        mpf_clear(new_pi);

        m_k += 1;
    }

    mpf_clear(y2);
    mpf_clear(y4);
    mpf_clear(m1my4);
    mpf_clear(m1my4_4);
    mpf_clear(m1my4_4_n1);
    mpf_clear(uf);
    mpf_clear(df);
    mpf_clear(m1py);
    mpf_clear(m1py4);
    mpf_clear(pow2ip3);
    mpf_clear(am1py4);
    mpf_clear(m1pypyy);
    mpf_clear(pow2y);
    mpf_clear(pow2yy);
    mpf_clear(yy);

    mpf_set(res, m_pi);

    mpf_clear(m_y);
    mpf_clear(m_a);
    mpf_clear(m_pi);
    mpf_clear(one);
    mpf_clear(two);
    mpf_clear(four);
    mpf_clear(six);
}
