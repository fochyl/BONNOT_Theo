#include "node.hpp"

void pretty_print_left_right(Node const &node, std::string const &prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const &node)
{
    pretty_print_left_right(node, "", true);
}

// 1. Écrire une fonction create_node

Node *create_node(int value)
{
    return new Node{value, nullptr, nullptr};
}

// 2. Écrire une méthode is_leaf

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

// 3. Écrire une méthode insert

void Node::insert(int value)
{
    if (value <= this->value)
    {
        if (left == nullptr)
        {
            left = create_node(value);
        }
        else
        {
            left->insert(value);
        }
    }
    else
    {
        if (right == nullptr)
        {
            right = create_node(value);
        }
        else
        {
            right->insert(value);
        }
    }
}

// 4. Écrire une méthode height

int Node::height() const
{
    if (this == nullptr)
    {
        return 0;
    }
    else
    {
        int leftHeight{left->height()};
        int rightHeight{right->height()};

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }
}

// 5. Écrire une fonction delete_childs

void Node::delete_childs()
{
    if (left != nullptr)
    {
        left->delete_childs();
        delete left;
        left = nullptr;
    }

    if (right != nullptr)
    {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

// 6. Écrire une méthode display_infixe

void Node::display_infixe() const
{
    if (left != nullptr)
    {
        left->display_infixe();
    }
    std::cout << value << " ";

    if (right != nullptr)
    {
        right->display_infixe();
    }
}

// 7. Écrire une méthode prefixe

std::vector<Node const *> Node::prefixe() const
{
    std::vector<Node const *> vec{this};
    if (left != nullptr)
    {
        for (Node const *value : left->prefixe())
        {
            vec.push_back(value);
        }
    }

    if (right != nullptr)
    {
        for (Node const *value : right->prefixe())
        {
            vec.push_back(value);
        }
    }
    return vec;
}

// 9. Écrire une fonction most_left

Node *&most_left(Node *&node)
{
    if (node->left != nullptr)
    {
        most_left(node->left);
    }
    else
    {
        return node;
    }
}

// 10. Écrire une fonction remove

bool remove(Node *&node, int value)
{
    // Je vérifie si la valeur correspond
    if (node->value == value)
    {
        // CAS n°1 : le noeud n'a pas de fils
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
            return true;
        }
        // CAS n°2 : le noeud a un seul fils
        else if (node->left == nullptr)
        {
            Node *right = node->right;
            delete node;
            node = right;
            return true;
        }
        else if (node->right == nullptr)
        {
            Node *left = node->left;
            delete node;
            node = left;
            return true;
        }
        else
        {
            // CAS N°3 : le noeud a deux fils
            node->value = most_left(node)->value;
            return remove(most_left(node), most_left(node)->value);
            return true;
        }
    }
    // La valeur n'a pas été trouvée
    else if (node->is_leaf())
    {
        return false;
    }
    else
    {
        // On continue de chercher la valeur
        return remove(node->left, value) || remove(node->right, value);
    }
    return false;
}

// 11. Écrire une fonction delete_tree

void delete_tree(Node *node)
{
    node->delete_childs();
    delete node;
    node = nullptr;
}