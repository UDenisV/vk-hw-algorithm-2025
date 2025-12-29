#include "ArcGraph.h"

ArcGraph::ArcGraph(int verticesCount)
    : verticesCount_(verticesCount) {
}
ArcGraph::ArcGraph(const IGraph& other)
    : verticesCount_(other.VerticesCount()) {
    for (int v = 0; v < other.VerticesCount(); ++v) {
        for (int to : other.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}
void ArcGraph::AddEdge(int from, int to) {
    edges_.emplace_back(from, to);
}
int ArcGraph::VerticesCount() const {
    return verticesCount_;
}
std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& edge : edges_) {
        if (edge.first == vertex) {
            result.push_back(edge.second);
        }
    }
    return result;
}
std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (const auto& edge : edges_) {
        if (edge.second == vertex) {
            result.push_back(edge.first);
        }
    }
    return result;
}