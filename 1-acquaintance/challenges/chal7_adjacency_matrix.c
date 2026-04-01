#include <stdio.h>
#include <stdbool.h>
#include <search.h>

#define N_NODES 5


/* 
Challenge 7 (Adjacency matrix) . The adjacency matrix of a graph G is a matrix A that
holds a value true or false in element A[i][j] if there is an arc from node i to node j.
At this point, can you use an adjacency matrix to conduct a breadth-first search in a graph G?
Can you find connected components? Can you find a spanning tree?
*/

void print_array(size_t arr[], size_t size) {
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%zu", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void breadth_first_search(size_t N, bool adjacency_matrix[N][N], size_t root, bool visited[N]) {
    size_t queue[N];
    size_t left = 0;
    size_t right = 0;

    visited[root] = 1;
    queue[right++] = root;

    printf("Root: %zu\n", root);

    while (left < right) {
        size_t current_node = queue[left++];
        printf("Visited: %zu\n", current_node);
        visited[current_node] = 1;

        // add nodes that are not already visited
        for (size_t i = 0; i < N; ++i) {
            if (adjacency_matrix[current_node][i] && !visited[i]){
                queue[right] = adjacency_matrix[current_node][i];
                right++;
            }
        }
        print_array(queue, N);
    }

}

int main(void) {
    bool adjacency_matrix[N_NODES][N_NODES] = {
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 1, 0, 1},
    };

    bool visited[N_NODES] = {};

    breadth_first_search(N_NODES, adjacency_matrix, 0, visited);
}
