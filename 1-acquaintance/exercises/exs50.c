#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct timespec time_diff(struct timespec t1, struct timespec t2) {
    struct timespec diff;
    long nano = 1000000000L;
    long t1_nsec = t1.tv_sec * nano + t1.tv_nsec;
    long t2_nsec = t2.tv_sec * nano + t2.tv_nsec;

    long diff_nsec = labs(t1_nsec - t2_nsec);

    diff.tv_sec = diff_nsec / nano;
    diff.tv_nsec = diff_nsec % nano;
    
    return diff;
}

int main(void) {
    // sec should be >= 0
    // nsec should be [0, 999999999]
    struct timespec t1 = {
        .tv_sec = 3,
        .tv_nsec = 912837,
    };

    struct timespec t2 = {
        .tv_sec = 4,
        .tv_nsec = 10283,
    };

    struct timespec diff = time_diff(t1, t2);
    printf("t1 is %lu seconds and %lu nanoseconds\n", t1.tv_sec, t1.tv_nsec);
    printf("t2 is %lu seconds and %lu nanoseconds\n", t2.tv_sec, t2.tv_nsec);

    printf("The difference between them is %lu seconds and %lu nanoseconds\n", diff.tv_sec, diff.tv_nsec);
}