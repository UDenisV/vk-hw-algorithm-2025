#pragma once
#include "IGraph.h"
#include <utility>
#include <vector>

class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int verticesCount);
    ArcGraph(const IGraph& other);
    void AddEdge(int from, int to) override;
    int VerticesCount() const override;
    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;
private:
    int verticesCount_;
    std::vector<std::pair<int, int>> edges_;
};