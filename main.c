#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef unsigned long long ULL;

ULL N;
ULL *as;

void combinations(ULL product, ULL sum, ULL index) {
    assert(index < N);

    ULL max = index > 0 ? as[index-1] : N;

    for (ULL a = 2; a <= max; a++) {
        as[index] = a;
        ULL new_product = product * a;
        ULL new_sum = sum + a;

        if (new_product > new_sum + N - index - 1) {
            return;
        } if (new_product == new_sum + N - index - 1) {
            for (ULL i = 0; i <= index; i++) printf("%llu ", as[i]);
            printf("\n");
            return;
        }

        combinations(new_product, new_sum, index+1);
    }
}

int main() {
    scanf("%llu", &N);
    printf("N = %llu\n", N);
    int max_length = ceil(log2(N));
    printf("max_length = %d\n", max_length);
    as = malloc(sizeof(ULL) * max_length);
    printf("malloced\n");
    combinations(1, 0, 0);
    return 0;
}
