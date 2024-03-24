#include <iostream>
#include <vector>
#include <algorithm>

// Affichage des tableaux dans la console

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> array)
{
    os << "[ ";
    for (size_t i = 0; i < array.size() - 1; i++)
    {
        os << array[i] << ", ";
    }
    os << array[array.size() - 1] << "]";
    return os;
}

// Vérification du tri

bool is_sorted(std::vector<float> const &vec) { return std::is_sorted(vec.begin(), vec.end()); }

// EXERCICE 1 : TRI ITERATIF

// Ecrire une fonction qui prend en paramètre un tableau d'entiers et le trie par ordre croissant.

void selection_sort(std::vector<float> &vec)
{
    for (std::size_t i{0}; i < vec.size(); i++)
        for (std::size_t j{i + 1}; j < vec.size(); j++)
        {
            if (vec[j] <= vec[i])
            {
                std::swap(vec[j], vec[i]);
            }
        }
}

// EXERCICE 2 : TRI RECURSIF
// Utiliser un algorithme de tri récursif.

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    std::vector<float> to_sort(vec.begin(), vec.end());
    vec.clear();
    size_t i{left};
    size_t j{middle};

    // Création du tableau final

    while (i < middle && j <= right)
    {

        if (to_sort[i] < to_sort[j])
        {
            vec.push_back(to_sort[i]);
            i++;
        }
        else if (to_sort[i] > to_sort[j])
        {
            vec.push_back(to_sort[j]);
            j++;
        }
        else
        {
            vec.push_back(to_sort[i]);
            vec.push_back(to_sort[j]);
            i++;
            j++;
        }
    }

    // Gestion des dépassements

    if (i < middle && j > right)
    {
        vec.push_back(to_sort[i]);
    }
    else if (i >= middle && j <= right)
    {
        vec.push_back(to_sort[j]);
    }
};

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    // Création des sous-tableaux
    std::vector<float> vec1(vec.begin(), vec.begin() + right / 2 + 1);
    std::vector<float> vec2(vec.end() - right / 2, vec.end());


    // Tri des sous-tableaux
    selection_sort(vec1);
    selection_sort(vec2);

    // Fusion des sous-tableaux

    std::vector<float> vec3(vec.size());
    std::copy(vec1.begin(), vec1.end(), vec3.begin());
    std::copy(vec2.begin(), vec2.end(), vec3.begin() + vec1.size());
    vec.assign(vec3.begin(), vec3.end());
    merge_sort_merge(vec, left, right / 2 + 1, right);
};

void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
};

int main()
{

    std::vector<float> array{6, 2, 8, 1, 5, 3, 9};
    std::cout << "Tableau original : " << array << std::endl;
    // selection_sort(array);
    merge_sort(array);

    std::cout << "Tableau trie : " << std::endl << array << std::endl;

    if (is_sorted(array))
    {
        std::cout << "Le tableau est trie" << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}