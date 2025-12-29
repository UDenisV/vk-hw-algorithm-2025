#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int verticesCount)
    : matrix_(verticesCount, std::vector<bool>(verticesCount, false)) {
}
MatrixGraph::MatrixGraph(const IGraph& other)
    : MatrixGraph(other.VerticesCount()) {
    for (int v = 0; v < other.VerticesCount(); ++v) {
        for (int to : other.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}
void MatrixGraph::AddEdge(int from, int to) {
    matrix_[from][to] = true;
}
int MatrixGraph::VerticesCount() const {
    return static_cast<int>(matrix_.size());
}
std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int to = 0; to < VerticesCount(); ++to) {
        if (matrix_[vertex][to]) {
            result.push_back(to);
        }
    }
    return result;
}
std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < VerticesCount(); ++from) {
        if (matrix_[from][vertex]) {
            result.push_back(from);
        }
    }
    return result;
}