#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

typedef unsigned long long ULL;

#define THREADS 8

ULL N;

void extend(ULL product, ULL sum, ULL index, ULL *sequence) {
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

        extend(new_product, new_sum, index+1, sequence);
    }
}

void *make_thread(void *arg) {
    ULL thread_num = (ULL) arg;
    ULL max_length = ceil(log2(N)) + 1;
    ULL *sequence = malloc(sizeof(ULL) * max_length);

    for (ULL n = thread_num+2; n <= N; n += THREADS) {
	sequence[0] = n;
	extend(n, n, 1, sequence);
    }

    free(sequence);
    return NULL;
}

int main() {
    scanf("%llu", &N);
    printf("N = %llu\n", N);

    pthread_t thread_ids[THREADS];
    for (ULL i = 0; i < THREADS; i++) {
	int res = pthread_create(&(thread_ids[i]), NULL, make_thread, (void *) i);
	// printf("res = %d\n", res);
	// make_thread((void *) thread_num);
    }

    for (ULL i = 0; i < THREADS; i++)
	pthread_join(thread_ids[i], NULL);

    return 0;
}
