#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

auto const is_space = [](char letter)
{ return letter == ' '; };

// 1. Écrire une fonction retournant le nombre de lettres du premier mot de la phrase.

int char_number(std::string const &sentence)
{
    auto first_space{std::find(sentence.begin(), sentence.end(), ' ')};
    return std::distance(sentence.begin(), first_space);
}

// 2. Écrire une fonction qui permet de découper la phrase en mots.

std::vector<std::string> split_string(std::string const &str)
{

    std::vector<std::string> vec;

    auto begin{str.begin()};

    while (begin != str.end())
    {

        auto end{std::find(begin, str.end(), ' ')};
        std::string word{begin, end};
        vec.push_back(word);
        begin = std::find_if_not(end, str.end(), is_space);
    }

    return vec;
}

int main()
{

    // 1. Écrire une fonction retournant le nombre de lettres du premier mot de la phrase.

    std::string sentence;

    std::cout << "Redigez une phrase : ";

    std::getline(std::cin, sentence);

    std::cout << "Le premier mot de la phrase est compose de " << char_number(sentence) << " lettres." << std::endl;

    // 2. Écrire une fonction qui permet de découper la phrase en mots.

    for (std::string word : split_string(sentence))
    {
        std::cout << word << " " << std::endl;
    }

    return 0;
}