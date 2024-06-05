#include "graph.hpp"

// EX1 : CONSTRUIRE UN GRAPHE

// 1. Implémenter add_vertex

namespace Graph
{
    void WeightedGraph::add_vertex(int const id)
    {
        auto test{adjacency_list.find(id)};
        if (test == adjacency_list.end())
        {
            adjacency_list[id];
        }
    }

    // 2. Implémenter add_directed_edge

    void WeightedGraph::add_directed_edge(int const from, int const to, float const weight)
    {
        add_vertex(to);
        adjacency_list[from].push_back({to, weight});
    }

    // 3. Implémenter add_undirected_edge

    void WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
    {
        add_directed_edge(from, to, weight);
        add_directed_edge(to, from, weight);
    }

    // 4. Implémenter adjacency_list_from_adjacency_matrix

    WeightedGraph build_from_adjacency_matrix(std::vector<std::vector<float>> const &adjacency_matrix)
    {
        WeightedGraph graph;
        for (int from{0}; from < adjacency_matrix.size(); from++)
        {
            for (int to{0}; to < adjacency_matrix.size(); to++)
            {
                float weight{adjacency_matrix[from][to]};
                if (weight !=0){
                    graph.add_directed_edge(from, to, weight);
                }
            }
        }
        return graph;
    }

}