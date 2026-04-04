#include <stdio.h>
#include <stdbool.h>
#include <search.h>

#define N_NODES 5

typedef struct {
    size_t from;
    size_t to;
} Edge;
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
        
        // add nodes that are not already visited
        for (size_t i = 0; i < N; ++i) {
            if (adjacency_matrix[current_node][i] && !visited[i]){
                visited[i] = 1;
                queue[right++] = i;
            }
        }
        // print_array(queue, right);
    }
}

// Connected components always have a path to eachother, doesn't have to be direct.
void find_connected_components(size_t N, bool adjacency_matrix[N][N],  bool visited[N]) {
    size_t component_count = 1;
    for (size_t i = 0; i < N; i++) {
        if (!visited[i]) {
            printf("Component %zu\n", component_count++);
            breadth_first_search(N, adjacency_matrix, i, visited);
        }
    }
}

void bfs_spanning_tree(size_t N, bool adjacency_matrix[N][N], size_t root, bool visited[N], Edge tree_edges[N-1], size_t *edge_count) {
    size_t queue[N];
    size_t left = 0;
    size_t right = 0;

    visited[root] = 1;
    queue[right++] = root;

    printf("Root: %zu\n", root);

    while (left < right) {
        size_t current_node = queue[left++];
        
        // add nodes that are not already visited
        for (size_t i = 0; i < N; ++i) {
            if (adjacency_matrix[current_node][i] && !visited[i]){
                visited[i] = 1;
                queue[right++] = i;

                tree_edges[*edge_count].from = current_node;
                tree_edges[*edge_count].to = i;
                (*edge_count)++;
            }
        }
        // print_array(queue, right);
    }
}

void find_spanning_trees(size_t N, bool adjacency_matrix[N][N]) {
    bool visited[N];
    for (size_t i = 0; i < N; i++) visited[i] = 0;

    Edge tree_edges[N-1];
    size_t edge_count;

    for (size_t i = 0; i < N; i++) {
        if (!visited[i]) {
            edge_count = 0;
            // We pass edge_count as a pointer so because otherwise, it'd be a copy. This way we can modify the value and then use it in this function
            bfs_spanning_tree(N, adjacency_matrix, i, visited, tree_edges, &edge_count);

            printf("Spanning tree for component starting at node %zu:\n", i);
            for (size_t j = 0; j < edge_count; j++) {
                printf("%zu -> %zu\n", tree_edges[j].from, tree_edges[j].to);
            }
        }
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
    
    printf("\n");
    bool adjacency_matrix1[N_NODES][N_NODES] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1},
    };
    bool visited1[N_NODES] = {};
    find_connected_components(N_NODES, adjacency_matrix1, visited1);

    printf("\n");
    find_spanning_trees(N_NODES, adjacency_matrix1);
}
