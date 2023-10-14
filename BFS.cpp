#include <bits/stdc++.h>

using namespace std;

// Función para realizar la búsqueda BFS
void bfs(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false); // Vector para mantener un seguimiento de los nodos visitados

    // Cola para el recorrido BFS
    queue<int> bfsQueue;

    // Marcar el nodo de inicio como visitado y encolarlo
    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        cout << currentVertex << " "; // Procesar el nodo actual

        // Obtener todos los nodos adyacentes al nodo actual
        vector<int> adjacentNodes = graph[currentVertex];

        // Recorrer los nodos adyacentes
        for (int i = 0; i < adjacentNodes.size(); ++i) {
            int adjacentNode = adjacentNodes[i];
            // Si el nodo adyacente no ha sido visitado, marcarlo como visitado y encolarlo
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = true;
                bfsQueue.push(adjacentNode);
            }
        }
    }
}

int main() {
    int numVertices = 7; // Número total de vértices en el grafo
    vector<vector<int>> graph(numVertices); // Grafo representado mediante listas de adyacencia

    // Agregar las aristas al grafo
    graph[0] = {1, 2};
    graph[1] = {3, 4};
    graph[2] = {5};
    graph[3] = {6};
    graph[4] = {};
    graph[5] = {};
    graph[6] = {};

    int startVertex = 0; // Nodo de inicio para la búsqueda BFS

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    bfs(graph, startVertex);

    return 0;
}






// Estructura para representar una arista
struct Edge {
    int src;
    int dest;

    Edge(int source, int destination) {
        src = source;
        dest = destination;
    }
};

// Función para realizar la búsqueda BFS
void bfs(vector<Edge>& edges, int numVertices, int startVertex) {
    vector<vector<int>> adjList(numVertices); // Lista de adyacencia
    vector<bool> visited(numVertices, false); // Vector para mantener un seguimiento de los nodos visitados

    // Construir la lista de adyacencia a partir de las aristas
    for (const auto& edge : edges) {
        adjList[edge.src].push_back(edge.dest);
    }

    // Cola para el recorrido BFS
    queue<int> bfsQueue;

    // Marcar el nodo de inicio como visitado y encolarlo
    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        cout << currentVertex << " "; // Procesar el nodo actual

        // Obtener todos los nodos adyacentes al nodo actual
        vector<int> adjacentNodes = adjList[currentVertex];

        // Recorrer los nodos adyacentes
        for (int i = 0; i < adjacentNodes.size(); ++i) {
            int adjacentNode = adjacentNodes[i];
            // Si el nodo adyacente no ha sido visitado, marcarlo como visitado y encolarlo
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = true;
                bfsQueue.push(adjacentNode);
            }
        }
    }
}

int main() {
    int numVertices = 7; // Número total de vértices en el grafo
    vector<Edge> edges; // Lista de aristas del grafo

    // Agregar las aristas al grafo
    edges.push_back(Edge(0, 1));
    edges.push_back(Edge(0, 2));
    edges.push_back(Edge(1, 3));
    edges.push_back(Edge(1, 4));
    edges.push_back(Edge(2, 5));
    edges.push_back(Edge(3, 6));

    int startVertex = 0; // Nodo de inicio para la búsqueda BFS

    cout << "BFS traversal starting from vertex " << startVertex << ": ";
    bfs(edges, numVertices, startVertex);

    return 0;
}