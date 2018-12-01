#include <stdio.h>
#include "pi2nth.h"

int main(){
    PiCalculator pc;
    mpf_t res;
    mpf_init(res);
    pc.calculateUpTo(10, res);
    gmp_printf("%.*Ff \n", 10, res);
    pc.calculateUpTo(20, res);
    gmp_printf("%.*Ff \n", 20, res);
    pc.calculateUpTo(100, res);
    gmp_printf("%.*Ff \n", 100, res);
}
