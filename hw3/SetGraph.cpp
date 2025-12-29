#include "SetGraph.h"

SetGraph::SetGraph(int verticesCount)
    : adjacencySets_(verticesCount) {
}
SetGraph::SetGraph(const IGraph& other)
    : adjacencySets_(other.VerticesCount()) {
    for (int v = 0; v < other.VerticesCount(); ++v) {
        for (int to : other.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}
void SetGraph::AddEdge(int from, int to) {
    adjacencySets_[from].insert(to);
}
int SetGraph::VerticesCount() const {
    return static_cast<int>(adjacencySets_.size());
}
std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(
        adjacencySets_[vertex].begin(),
        adjacencySets_[vertex].end()
    );
}
std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < VerticesCount(); ++from) {
        if (adjacencySets_[from].count(vertex) > 0) {
            result.push_back(from);
        }
    }
    return result;
}