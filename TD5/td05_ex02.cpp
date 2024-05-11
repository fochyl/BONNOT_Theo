#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

std::string random_name(size_t size)
{
    std::string name{""};
    // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
    // https://cplusplus.com/reference/string/string/reserve/
    name.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        name.push_back('A' + std::rand() % 26);
    }
    return name;
}

std::vector<std::pair<std::string, float>> get_robots_fix(size_t size)
{
    std::vector<std::pair<std::string, float>> robots_fix{};
    // Meme optimisation que dans random_name()
    // https://cplusplus.com/reference/vector/vector/reserve/
    robots_fix.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        // random name
        std::string robotName{random_name(2)};
        // random cost
        float cost{static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
        robots_fix.push_back(std::make_pair(robotName, cost));
    }
    return robots_fix;
}

// 1. Ecrire une fonction retournant une table associative

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(std::vector<std::pair<std::string, float>> const &robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> map;
    for (std::pair<std::string, float> robot_fix : robots_fixes)
    {
        map[robot_fix.first].push_back(robot_fix.second);
    }
    return map;
}

// 2. Écrire une fonction retournant la somme des éléments d'un vecteur

float vector_sum(std::vector<float> vec)
{
    float sum{0};
    for (float value : vec)
    {
        sum += value;
    }
    return sum;
}

// 3. Afficher la somme des réparations effectuées pour chaque robot

void display_sums(std::vector<std::pair<std::string, float>> robots_fixes)
{
    std::unordered_map<std::string, std::vector<float>> map{robots_fixes_map(robots_fixes)};
    for (std::pair<std::string, std::vector<float>> key_value : map)
    {
        std::cout << "name : " << key_value.first << ", sum : " << vector_sum(key_value.second) << std::endl;
    }
}

int main()
{

    size_t size;
    std::cout << "Choisissez un nombre de robots : " ;
    std::cin >> size;

    display_sums(get_robots_fix(size));
    

    return 0;
}