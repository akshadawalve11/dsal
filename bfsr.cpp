#include <iostream>
using namespace std;

int graph[10][10], visited[10], queue[10], front = 0, rear = 0, n;

void bfs() {
    if (front == rear) return;
    int node = queue[front++];
    cout << node << " ";
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }
    bfs(); // recursive call
}

int main() {
    int edges, u, v;
    cout << "Enter nodes and edges: ";
    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1; // undirected graph
    }
    queue[rear++] = 0;
    visited[0] = 1;
    cout << "BFS traversal: ";
    bfs();
    return 0;
}


