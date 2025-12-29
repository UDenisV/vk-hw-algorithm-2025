#include "ListGraph.h"

ListGraph::ListGraph(int verticesCount)
    : adjacencyLists_(verticesCount) {
}
ListGraph::ListGraph(const IGraph& other)
    : adjacencyLists_(other.VerticesCount()) {
    for (int v = 0; v < other.VerticesCount(); ++v) {
        for (int to : other.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}
void ListGraph::AddEdge(int from, int to) {
    adjacencyLists_[from].push_back(to);
}
int ListGraph::VerticesCount() const {
    return static_cast<int>(adjacencyLists_.size());
}
std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacencyLists_[vertex];
}
std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < VerticesCount(); ++from) {
        for (int to : adjacencyLists_[from]) {
            if (to == vertex) {
                result.push_back(from);
            }
        }
    }
    return result;
}