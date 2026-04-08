#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define X SIZE_MAX

void shortest_path(size_t N, size_t distance_matrix[N][N], size_t start, size_t end, size_t previous[N]) {
    bool visited[N];
    size_t distance[N]; // shortest distance
    
    
    for (size_t i = 0; i < N; i++) {
        visited[i] = 0;
        previous[i] = X;
        distance[i] = X; 
    }
    // iniitialize the distance from current to current to be zero and set current
    distance[start] = 0;
    size_t current = start;

    while (true) {
        size_t min_dist = SIZE_MAX;

        // find the minimum distance to each node overall and set that node to the current
        for (size_t i = 0; i < N; i++) {
            if (!visited[i] && distance[i] < min_dist) {
                min_dist = distance[i];
                current = i;
            }
        }

        // if there are no unvisited nodes with a distance less than SIZE_MAM
        if (min_dist == SIZE_MAX) {
            return;
        }

        // mark current node as visited
        visited[current] = 1;

        // if the current node is at the end goal
        if (current == end ) {
            return;
        }

        // for each node connected to the current node, if the distance to the current node + that new node is 
        // less than the known distance, set that distance to node i to be the found one
        for (size_t i = 0; i < N; i++) {
            if (distance_matrix[current][i] == SIZE_MAX) {
                continue;
            }

            size_t new_dist = distance[current] + distance_matrix[current][i];
            if (!visited[i] && new_dist < distance[i]) {
                distance[i] = new_dist;
                previous[i] = current;
            }
        }
    }
}

void print_array(size_t array[], size_t length) {
    printf("[ ");
    for (size_t i = 0; i < length; i++) {
        printf("%zu ", array[i]);
    }
    printf("]\n");
}

void print_path(size_t previous[], size_t start, size_t end) {
    size_t path[100];
    size_t length = 0;

    size_t current = end;

    // start at the end of previous and use the previous array to find where we came from
    while (current != SIZE_MAX) {
        path[length++] = current;
        if (current == start) break;
        current = previous[current];
    }

    // if we never reached the start, there is no path
    if (path[length - 1] != start) {
        printf("No Path\n");
        return;
    }

    // print the path in reverse
    printf("Path: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%zu ", path[i]);
    }
    printf("\n");
}

int main(void) {
    #define N_NODES 6

    size_t distance_matrix[N_NODES][N_NODES] = {
        {X, 3, X, 8, X, X},
        {3, X, 2, X, 11, 10},
        {X, 2, X, 4, X, X},
        {8, X, 4, X, X, 1},
        {X, 11, X, X, X, 1},
        {X, 10, X, 1, 1, X},
    };

    size_t start = 0;
    size_t end = 5;
    size_t previous[N_NODES];
    shortest_path(N_NODES, distance_matrix, start, end, previous);
    print_array(previous, N_NODES);
    print_path(previous, start, end);

}