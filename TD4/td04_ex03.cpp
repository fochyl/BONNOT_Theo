#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

bool isPalindrome(std::string const &word)
{
    return std::equal(std::begin(word), std::end(word), std::rbegin(word));
}

int main()
{
    std::string word;
    std::cout << "Saisissez un mot : ";
    std::cin >> word;

    if (isPalindrome(word))
    {
        std::cout << word << " est un palindrome !";
    }
    else
    {
        std::cout << word << " n'est PAS un palindrome." ;
    }

    return 0;
}