#include <iostream>

//1. Écrire une fonction de hachage faisant la somme des valeurs ASCII.

size_t folding_string_hash(std::string const &s, size_t max){
    size_t sum{0};
    for (char letter : s){
        sum += letter;
    }
    return sum % max;
}

// 2. Écrire une nouvelle fonction avec l'ordre des caractères.

size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t sum{0};
    for (int i{0}; i <= s.length(); i++){
        sum += (i+1)*s[i];
    }
    return sum % max;
}

// 3. Écrire une fonction utilisant le rolling hash.

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t sum{static_cast<size_t>(s[0])};
    size_t power {p};
    for (int i{1}; i <= s.length(); i++){
        sum += power*s[i];
        power *= power;
    }
    return sum % m;
}

int main()
{
    std::string word;
    std::cout << "Saisissez un mot : ";
    std::cin >> word;

    size_t max;
    std::cout << "Choisissez un maximum : ";
    std::cin >> max;

    size_t p;
    std::cout << "Entier pour le rolling hash : ";
    std::cin >> p;

    std::cout << "Somme des valeurs ASCII : " << folding_string_hash(word, max) << std::endl;
    std::cout << "Prise en compte de l'ordre : " << folding_string_ordered_hash(word, max) << std::endl;
    std::cout << "Polynomial rolling hash : " << polynomial_rolling_hash(word, p, max);

    return 0;
}