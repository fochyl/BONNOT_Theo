#include "graph.cpp"

int main()
{
    // EX1 : CONSTRUIRE UN GRAPHE

    // 5. Exemple d'utilisation

    std::vector<std::vector<float>> const adjacency_matrix{
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    // Avec la fonction

    Graph::WeightedGraph graph1 {Graph::build_from_adjacency_matrix(adjacency_matrix)};

    // Avec les méthodes

    Graph::WeightedGraph graph2 {};

    for (int from {0}; from < 5; from++){
        graph2.add_vertex(from);
    }

    graph2.add_undirected_edge(0, 1, 1);
    graph2.add_undirected_edge(0, 4, 1);
    graph2.add_undirected_edge(1, 2, 1);
    graph2.add_undirected_edge(1, 3, 1);
    graph2.add_undirected_edge(2, 3, 1);
    graph2.add_undirected_edge(3, 4, 1);

    // Vérification

    std::cout << (graph1 == graph2) << std::endl;

    return 0;
}