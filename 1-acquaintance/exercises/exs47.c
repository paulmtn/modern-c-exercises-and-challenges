#include <stdio.h>
#include <string.h>

int safe_strcmp(char* s1, size_t s1_size, char* s2, size_t s2_size) {
    char* end1 = memchr(s1, '\0', s1_size);
    char* end2 = memchr(s2, '\0', s2_size);
    
    if (end1 && end2) {
        size_t diff1 = end1 - s1;
        size_t diff2 = end2 - s2;

        size_t min_diff = (diff1 > diff2) ? diff2 : diff1;

        int result = memcmp(s1, s2, min_diff);
        if (result) {
            return result;
        }
        return (int) diff1 - diff2;

    }
    return -1;
}

int main(void) {
    char* s1 = "orianna";
    size_t s1_size = strlen(s1) + 1;
    char* s2 = "oriannaaaa";
    size_t s2_size = strlen(s2) + 1;

    printf("%s compared with %s: %d\n", s1, s2, safe_strcmp(s1, s1_size, s2, s2_size));
}
