#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{

    // 1. Remplir un std::vector avec des nombres entiers aléatoires compris entre 0 et 100.

    std::srand(std::time(nullptr));

    std::vector<int> tab{};
    for (int i{0}; i < 5; i++)
    {
        tab.push_back(std::rand() % 100);
    }

    std::cout << "Affichage du tableau :" << std::endl;

    for (int value : tab)
    {
        std::cout << value << std::endl;
    }

    // 2. Utiliser les itérateurs et les méthodes begin et end pour afficher les valeurs du vecteur.

    std::vector<int>::iterator end_iterator{tab.end()};

    std::cout << "Affichage avec iterateur :" << std::endl;

    for (std::vector<int>::iterator it{tab.begin()}; it != end_iterator; ++it)
    {
        std::cout << *it << std::endl;
    }

    // 3. Chercher si un nombre saisi par l'utilisateur est présent dans le vecteur.

    int value{0};
    std::cout << "Cherchez un nombre : ";
    std::cin >> value;

    auto it{std::find(tab.begin(), tab.end(), value)};

    if (it != tab.end())
    {
        std::cout << *it << " est bien present dans le tableau !" << std::endl;
    }
    else
    {
        std::cout << value << " n'est pas present dans le tableau." << std::endl;
    }

    // 4. Compter le nombre d'occurrences d'un autre nombre entier dans le vecteur.

    const int num_items = std::count(tab.cbegin(), tab.cend(), value);
    std::cout << value << " apparait " << num_items << " fois dans le tableau." << std::endl;

    // 5. Utiliser la fonction std::sort pour trier le vecteur.

    std::sort(tab.begin(), tab.end());

    std::cout << "Tableau trie : " << std::endl;

    for (int element : tab)
    {
        std::cout << element << std::endl;
    }

    // 6. Calculer la somme des éléments du tableau.

    int sum{std::accumulate(tab.begin(), tab.end(), 0, [](int acc, int current_element)
                            { return acc + current_element; })};
    std::cout << "Somme des elements du tableau : " << sum << std::endl;

    return 0;
}