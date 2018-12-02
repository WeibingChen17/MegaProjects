#include <stdio.h>
#include <stdlib.h>
#include "pi2nth.h"

int main(int argc, char *argv[]){
    if (argc == 1) return 1;
    PiCalculator pc;
    mpf_t res;
    mpf_init(res);
    int m = atoi(argv[1]);
    size_t k = pc.calculateUpTo(m, res);
    gmp_printf("%.*Ff \n", m, res);
    printf("It takes %d steps.\n", int(k));
    return 0;
}
