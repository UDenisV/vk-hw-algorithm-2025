#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include <iostream>

int main() {
    ListGraph graph(4);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 2);
    graph.AddEdge(1, 3);
    MatrixGraph matrixGraph(graph);
    SetGraph setGraph(matrixGraph);
    ArcGraph arcGraph(setGraph);
    for (int v : arcGraph.GetNextVertices(0)) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    return 0;
}