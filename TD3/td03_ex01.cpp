#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>

// EXERCICE 1 : EVALUATION NPI

// 2. Séparer les éléments de l'expression.

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

// 3. Écrire une fonction disant si une chaîne représente un flottant.

bool is_floating(std::string const &s)
{
    for (char value : s)
    {
        if (!std::isdigit(value) || value != '.')
        {
            return 0;
        }
    }
    return 1;
}

// 4. Écrire une fonction qui retourne le résultat de l'expression.

float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack;
    for (std::string token : tokens)
    {
        if (is_floating(token))
        {
            stack.push(std::stof(token));
        }
        else
        {
            // Je récupère l'élément en haut de la pile
            float rightOperand{stack.top()};
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();

            float leftOperand{stack.top()};
            stack.pop();
            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            float result{0};
            if (token == "+")
            {
                result = leftOperand + rightOperand;
            }
            else if (token == "-")
            {
                result = leftOperand - rightOperand;
            }
            else if (token == "*")
            {
                result = leftOperand * rightOperand;
            }
            else if (token == "/")
            {
                result = leftOperand / rightOperand;
            }
            else
            {
                std::cout << "Erreur de saisie" << std::endl;
            }
            stack.push(result);
        }
    }
    return stack.top();
}

// 5. Afficher le résultat d'une expression en NPI.

void test(std::string string){
    std::cout << string << " = " << npi_evaluate(split_string(string)) << std::endl;
}

int main()
{

    // 1. Écrire un programme saisissant une expression.

    std::cout << "Expression en NPI : ";
    std::string string;
    std::getline(std::cin, string);

    // 5. Afficher le résultat d'une expression en NPI.

    std::cout << "Resultat : " << npi_evaluate(split_string(string)) << std::endl;
    std::cout << "Autres tests :" << std::endl;

    test("3 4 +");
    test("2 12 + 5 +");
    test("3 4 11 5 + / +");
    test("4 5 2 * +");

    return 0;
}