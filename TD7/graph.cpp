#include "graph.hpp"

namespace Graph
{
    bool WeightedGraphEdge::operator==(WeightedGraphEdge const &other) const
    {
        return to == other.to && weight == other.weight;
    }

    bool WeightedGraphEdge::operator!=(WeightedGraphEdge const &other) const
    {
        return !(*this == other);
    }

    // EX1 : CONSTRUIRE UN GRAPHE

    // 1. Implémenter add_vertex

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
                if (weight != 0)
                {
                    graph.add_directed_edge(from, to, weight);
                }
            }
        }
        return graph;
    }

    // EX2 : TRAVERSER UN GRAPHE

    // 1. Implémenter print_DFS

    void WeightedGraph::print_DFS(int const start) const
    {
        std::vector<int> vec{};
        std::stack<int> stack;
        stack.push(start);

        while (!stack.empty())
        {
            auto it{std::find(vec.begin(), vec.end(), stack.top())};

            if (it == vec.end())
            {
                vec.push_back(stack.top());
            }

            int from{stack.top()};
            stack.pop();

            for (WeightedGraphEdge adjacent_edge : adjacency_list.at(from))
            {
                stack.push(adjacent_edge.to);
            }
        }
        for (int edge : vec)
        {
            std::cout << edge << " ";
        }
        std::cout << std::endl;
    }

    // 2. Implémenter print_BFS

    void WeightedGraph::print_BFS(int const start) const
    {
        std::vector<int> vec{};
        std::queue<int> queue;
        queue.push(start);

        while (!queue.empty())
        {
            auto it{std::find(vec.begin(), vec.end(), queue.front())};

            if (it == vec.end())
            {
                vec.push_back(queue.front());
            }

            int from{queue.front()};
            queue.pop();

            for (WeightedGraphEdge adjacent_edge : adjacency_list.at(from))
            {
                queue.push(adjacent_edge.to);
            }
        }
        for (int edge : vec)
        {
            std::cout << edge << " ";
        }
        std::cout << std::endl;
    }
}

// EX3 : DIJKSTRA

// 1 . Trouver le plus court chemin entre A et E

// AJOUT DE A(0)
// On ajoute le sommet A à la liste des sommets à visiter :
// - Distances : -
// - A visiter : A(0)

// RECUPERATION DE A(0)
// Il reste des éléments dans la liste à visiter.
// On récupère le sommet qui a la plus petite distance (A).
// On le retire de la liste à visiter.
// On parcours la liste des voisins de A (B, C et D).
// Les 3 ne sont pas déjà visités.
// On les ajoute à la liste à visiter et au tableau associatif :
// - Distances : B(1, A), C(5, A), D(2, A)
// - A visiter : B(1), C(5), D(2)

// RECUPERATION DE B(1)
// Je récupère maintenant B qui est le sommet prioritaire dans la liste à visiter.
// Je parcours la liste des voisins de B (C et D).
// C et D sont déjà présents dans le tableau associatif.
// Cela indique qu'ils ont déjà été visités ou marqués à visiter.
// Pour C, le poids actuellement dans le tableau des distances est égale au poids en passant par B (1 + 4).
// Pour D, le coût en passant par B est plus fort (1 + 5 > 2).
// Donc on ne fait rien :
// - Distances : B(1, A), C(5, A), D(2, A)
// - A visiter : C(5), D(2)

// RECUPERATION DE D(2)
// Je recommence de nouveau avec D qui est le sommet prioritaire dans la liste à visiter.
// Pour C, le coût en passant par D est plus faible (2 + 2 < 5).
// Je mets donc à jour la distance.
// Je rajoute de nouveau C dans la liste à visiter.
// Pour E, on ajoute comme précédemment ce qui donne :
// - Distances : B(1, A), C(4, D), D(2, A), E(7, D)
// - A visiter : C(5), C(4), E(7)

// RECUPERATION DE C(4)
// Je continue avec C :
// - Distances : B(1, A), C(4, D), D(2, A), E(7, D), F(8)
// - A visiter : C(5), E(7), F(8)

// RECUPERATION DE C(5)
// De nouveau avec C mais cela ne va avoir aucun effet :
// - Distances : B(1, A), C(4, D), D(2, A), E(7, D), F(8)
// - A visiter : E(7), F(8)

// RECUPERATION DE E(7)
// Enfin on récupère E.
// C'est le sommet de destination.
// On peut s'arrêter et retourner le tableau associatif.
// On peut retrouver la succession des arrêtes à parcours grâce au tableau associatif :
// A -> D -> E