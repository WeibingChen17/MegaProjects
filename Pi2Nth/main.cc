#include <stdio.h>
#include <stdlib.h>
#include "pi2nth.h"

int main(int argc, char *argv[]){
    if (argc == 1) return 1;
    PiCalculator pc;
    mpf_t res;
    mpf_init(res);
    int n = atoi(argv[1]);
    pc.calculateUpTo(n, res);
    gmp_printf("%.*Ff \n", n, res);
    return 0;
}
