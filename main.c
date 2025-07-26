#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long ULL;

ULL N;
ULL *sequence;

void extend(ULL product, ULL sum, ULL index) {
    ULL max = index > 0 ? sequence[index-1] : N;

    for (ULL a = 2; a <= max; a++) {
        sequence[index] = a;
        ULL new_product = product * a;
        ULL new_sum = sum + a;

        if (new_product > new_sum + N - index - 1) {
            return;
        } if (new_product == new_sum + N - index - 1) {
            for (ULL i = 0; i <= index; i++) printf("%llu ", sequence[i]);
            printf("\n");
            return;
        }

        extend(new_product, new_sum, index+1);
    }
}

int main() {
    scanf("%llu", &N);
    printf("N = %llu\n", N);
    int max_length = ceil(log2(N));
    sequence = malloc(sizeof(ULL) * max_length);

    extend(1, 0, 0);
    return 0;
}
