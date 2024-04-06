#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "ScopedTimer.hpp"

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

// Création de tableaux aléatoires

std::vector<float> generate_random_vector(size_t const size, int const max = 100)
{
    std::vector<float> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]()
                  { return std::rand() % max; });
    return vec;
}

// EXERCICE 1 : TRI ITERATIF
// Ecrire une fonction qui trie un tableau par ordre croissant.

void selection_sort(std::vector<float> &vec)
{
    for (std::size_t i{0}; i < vec.size(); i++)
    {
        std::size_t min{i};
        for (std::size_t j{i + 1}; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            std::swap(vec[min], vec[i]);
        }
    }
}

// EXERCICE 2 : TRI RECURSIF
// Utiliser un algorithme de tri récursif.

void merge_sort_merge(std::vector<float> &vec, size_t const left, size_t const middle, size_t const right)
{
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size{middle - left + 1};
    size_t const right_size{right - middle};
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index{0};
    size_t right_index{0};

    size_t index{left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size)
    {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence

        if (left_vec[left_index] <= right_vec[right_index])
        {
            vec[index] = left_vec[left_index];
            left_index++;
        }
        else
        {
            vec[index] = right_vec[right_index];
            right_index++;
        }
        index++;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original

    while (left_index >= left_size && right_index < right_size)
    {
        vec[index] = right_vec[right_index];
        right_index++;
        index++;
    }

    while (right_index >= right_size && left_index < left_size)
    {
        vec[index] = left_vec[left_index];
        left_index++;
        index++;
    }
}

void merge_sort(std::vector<float> &vec, size_t const left, size_t const right)
{
    if (left >= right)
    {
        return;
    }

    // 1. Choix de l'index au milieu de la partition
    size_t const middle{(left + right) / 2};

    // 2. Appels récursifs sur les deux sous-parties
    merge_sort(vec, left, middle);
    merge_sort(vec, middle + 1, right);

    // 3. Fusion des deux sous-parties
    merge_sort_merge(vec, left, middle, right);
}

// Même mécanisme que pour le tri rapide
void merge_sort(std::vector<float> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
}

// EXERCICE 4 : DICHOTOMIE
// 1. Écrire une fonction search.

size_t search(std::vector<float> vec, float value)
{
    size_t left{0};
    size_t right{vec.size() - 1};
    while (right >= left)
    {
        size_t middle{(left + right) / 2};
        if (vec[middle] < value)
        {
            left = middle + 1;
        }
        else if (vec[middle] > value)
        {
            right = middle - 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

void search_result(std::vector<float> vec, float value)
{
    std::cout << std::endl;
    std::cout << vec << std::endl;
    size_t index{search(vec, value)};
    if (index != -1)
    {
        std::cout << "Valeur  " << value << " --> Indice " << search(vec, value) << std::endl;
    }
    else
    {
        std::cout << value << " n'est pas present dans le tableau." << std::endl;
    }
}

int main()
{
    std::vector<float> arrayA{6, 2, 8, 1, 5, 3, 9};
    std::cout << std::endl;
    std::cout << "Tableau original : " << arrayA << std::endl;
    std::cout << std::endl;

    // EXERCICE 1 : TRI ITERATIF
    // Ecrire une fonction qui trie un tableau par ordre croissant.

    std::cout << "EXERCICE 1 : TRI ITERATIF" << std::endl;
    selection_sort(arrayA);
    std::cout << "Tri par selection : " << arrayA << std::endl;

    if (is_sorted(arrayA))
    {
        std::cout << "Le tableau est bien trie." << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas bien trie." << std::endl;
    }
    std::cout << std::endl;

    // EXERCICE 2 : TRI RECURSIF
    // Utiliser un algorithme de tri récursif.

    std::cout << "EXERCICE 2 : TRI RECURSIF" << std::endl;
    std::vector<float> arrayB{6, 2, 8, 1, 5, 3, 9};
    merge_sort(arrayB);
    std::cout << "Tri fusion : " << arrayA << std::endl;

    if (is_sorted(arrayB))
    {
        std::cout << "Le tableau est bien trie." << std::endl;
    }
    else
    {
        std::cout << "Le tableau n'est pas bien trie." << std::endl
                  << std::endl;
    }
    std::cout << std::endl;

    // EXERCICE 3 : COMPARAISON
    // Comparer en terme de complexité temporelle.

    std::cout << "EXERCICE 3 : COMPARAISON" << std::endl;

    std::srand(std::time(nullptr));

    size_t iteration{500};

    size_t const size{10000};
    int const max{1000};

    // Generate a vector of random vectors (to compare the sorting algorithms on the same data set)
    std::vector<std::vector<float>> vecs{};
    // Optimization: reserve the memory for the vector of vectors as we know the size
    vecs.reserve(iteration);

    for (size_t i{0}; i < iteration; i++)
    {
        vecs.push_back(generate_random_vector(size, max));
    }

    auto display_average = [&iteration](std::string const &name, double const duration_us)
    {
        double const average_ms{(duration_us * 0.001) / static_cast<double>(iteration)};
        std::cout << name << " : average of " << average_ms << " ms for " << iteration << " iterations" << std::endl;
    };

    std::cout << "Sorting algorithms comparison" << std::endl;

    // reduce the number of iterations for the iterative algorithms
    iteration = 10;

    {
        ScopedTimer scopedTimer("Selection sort", display_average);

        for (size_t i{0}; i < iteration; i++)
        {
            std::vector<float> vec_copy{vecs[i]};
            selection_sort(vec_copy);
            if (!is_sorted(vec_copy))
            {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }

    {
        ScopedTimer scopedTimer("Merge sort", display_average);

        for (size_t i{0}; i < iteration; i++)
        {
            std::vector<float> vec_copy{vecs[i]};
            merge_sort(vec_copy);
            if (!is_sorted(vec_copy))
            {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }

    {
        ScopedTimer scopedTimer("std sort", display_average);

        for (size_t i{0}; i < iteration; i++)
        {
            std::vector<float> vec_copy{vecs[i]};
            std::sort(vec_copy.begin(), vec_copy.end());
            if (!is_sorted(vec_copy))
            {
                std::cerr << "Sort failed" << std::endl;
                break;
            }
        }
    }

    // restore the number of iterations
    iteration = 500;

    //...

    // Que constatez-vous ?
    // Le std sort est plus rapide que mon tri récursif, lui-même plus rapide que mon tri itératif.

    // Que pouvez-vous en dire ?
    // Le std sort est l'algorithme de tri le plus efficace parmi ces trois-là. Je suppose qu'il s'agit d'un tri récursif plus performant.

    // EXERCICE 4 : DICHOTOMIE
    // 2. Tester la fonction search.
    std::cout << std::endl;
    std::cout << "EXERCICE 4 : DICHOTOMIE" << std::endl;

    std::vector<float> array1{1, 2, 2, 3, 4, 8, 12};
    search_result(array1, 8);

    std::vector<float> array2{1, 2, 3, 3, 6, 14, 12, 15};
    search_result(array2, 15);

    std::vector<float> array3{2, 2, 3, 4, 5, 8, 12, 15, 16};
    search_result(array3, 16);

    std::vector<float> array4{5, 6, 7, 8, 9, 10, 11, 12, 13};
    search_result(array4, 6);

    std::vector<float> array5{1, 2, 3, 4, 5, 6, 7, 8, 9};
    search_result(array5, 10);

    std::cout << std::endl;

    return 0;
}