#include <stdio.h>
#include <stddef.h>

/* 
Challenge 4 (Union-Find) . The Union-Find problem deals with the representation of par-
titions over a base set. We will identify the elements of the base set using the numbers 0, 1, ...
and will represent partitions with a forest data structure where each element knows a “parent”
that is another element inside the same partition. Each set in such a partition is identified by a
designated element called the root of the set
*/

void print_parent(size_t parent[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (parent[i] == __SIZE_MAX__) {
            printf("%zu: root\n", i);
        } else {
            printf("%zu: %zu\n", i, parent[i]);
        }
    }
    printf("\n");
}

size_t find(size_t parent[], size_t index) {
    if (parent[index] == __SIZE_MAX__) {
        return index;
    }
    return find(parent, parent[index]);
}

size_t find_replace(size_t parent[], size_t index, size_t value) {
    if (parent[index] == __SIZE_MAX__) {
        parent[index] = value;
        return index;
    }
    size_t next = parent[index];
    parent[index] = value;

    return find_replace(parent, next, value);
}

// [SIZE_MAX, 0, 0, 1]
size_t find_compress(size_t parent[], size_t index) {
    if (parent[index] == __SIZE_MAX__) {
        return index;
    }

    size_t root = find_compress(parent, parent[index]);
    parent[index] = root;
    return root;
}

// [SIZE_MAX, 0, 0, 1, SIZE_MAX, 4] -> [SIZE_MAX, 0, 0, 0, 0, 4]
void parent_union(size_t parent[], size_t a, size_t b) {
    size_t root_a = find_compress(parent, a);
    find_replace(parent, b, root_a);
}

int main(void) {
    size_t size = 10;
    size_t parent[10];

    for (size_t i = 0; i < size; ++i) {
        parent[i] = __SIZE_MAX__;
    }

    print_parent(parent, size);

    size_t test0 = 4;
    printf("root of %zu is %zu\n", test0, find(parent, test0));

    parent_union(parent, 0, 1);
    print_parent(parent, size);

    parent_union(parent, 1, 3);
    print_parent(parent, size);

    parent_union(parent, 8, 9);
    print_parent(parent, size);

    parent_union(parent, 0, 2);
    print_parent(parent, size);

    parent_union(parent, 5, 6);
    print_parent(parent, size);

    parent_union(parent, 0, 5);
    print_parent(parent, size);

    parent_union(parent, 0, 8);
    print_parent(parent, size);
}