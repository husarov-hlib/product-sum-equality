#include <stdio.h>
#include <assert.h>

#define N 100

int as[N];

void combinations(int product, int sum, int index) {
    assert(index < N);

    int max = index > 0 ? as[index-1] : N;

    for (int a = 2; a <= max; a++) {
        as[index] = a;
        int new_product = product * a;
        int new_sum = sum + a;

        if (new_product > new_sum + N - index - 1) {
            return;
        } if (new_product == new_sum + N - index - 1) {
            for (int i = 0; i <= index; i++) printf("%d ", as[i]);
            printf("\n");
            return;
        }

        combinations(new_product, new_sum, index+1);
    }
}

int main() {
    combinations(1, 0, 0);
    return 0;
}
