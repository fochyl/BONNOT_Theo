#include "node.cpp"

int main()
{
    // 1. Créer un arbre avec 5, 3, 7, 2, 4, 6, 8, 1, 9, 0

    Node *tree{create_node(5)};

    tree->insert(3);
    tree->insert(7);
    tree->insert(2);
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    tree->insert(1);
    tree->insert(9);
    tree->insert(0);

    // 2. Afficher l'arbre

    tree->display_infixe();

    // 4. Afficher la somme des valeurs de l'arbre

    int sum{0};
    for (Node const *node : tree->prefixe())
    {
        sum += node->value;
    }
    std::cout << " = " << sum << std::endl;

    // 5. Afficher la hauteur de l'arbre

    std::cout << tree->height() << std::endl;

    return 0;
}