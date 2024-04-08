#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>

// EXERCICE 2 : STRUCTURE ET ENUMERATIONS

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    OPEN_PAREN,
    CLOSE_PAREN
};

enum class TokenType
{
    OPERATOR,
    OPERAND
};

struct Token
{
    TokenType type;
    float value;
    Operator op;
};

// 1. Créer 2 fonctions permettant de construire la structure.

Token make_token(float value)
{
    Token token{TokenType::OPERAND, value};
    return token;
}
Token make_token(Operator op)
{
    Token token{TokenType::OPERATOR, 0, op};
    return token;
}

// 2. Créer une fonction tokenize retournant un vecteur.

bool is_floating(std::string const &s)
{
    for (char value : s)
    {
        if (!std::isdigit(value))
        {
            return 0;
        }
    }
    return 1;
}

std::vector<Token> tokenize(std::vector<std::string> stringVec)
{
    std::vector<Token> tokenVec;
    for (std::string string : stringVec)
    {
        if (is_floating(string))
        {
            tokenVec.push_back(make_token(std::stof(string)));
        }
        else if (string == "+")
        {
            tokenVec.push_back(make_token(Operator::ADD));
        }
        else if (string == "-")
        {
            tokenVec.push_back(make_token(Operator::SUB));
        }
        else if (string == "*")
        {
            tokenVec.push_back(make_token(Operator::MUL));
        }
        else if (string == "/")
        {
            tokenVec.push_back(make_token(Operator::DIV));
        }
        else
        {
            std::cout << "Erreur de saisie" << std::endl;
        }
    }
    return tokenVec;
}

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

// 3. Créer une nouvelle npi_evaluate.

float npi_evaluate(std::vector<Token> const &tokens)
{
    std::stack<float> stack;
    for (Token token : tokens)
    {
        if (token.type == TokenType::OPERAND){
            stack.push(token.value);
        } else {
            float rightOperand{stack.top()};
            stack.pop();

            float leftOperand{stack.top()};
            stack.pop();

            float result{0};

            switch (token.op) {
                case Operator::ADD : 
                result = leftOperand + rightOperand;
                break;
                case Operator::SUB :
                result = leftOperand - rightOperand;
                break;
                case Operator::MUL :
                result = leftOperand * rightOperand;
                break;
                case Operator::DIV :
                result = leftOperand / rightOperand;
                break;
            }
            stack.push(result);
        }
    }
    return stack.top();
}

void test(std::string string)
{
    std::cout << string << " = " << npi_evaluate(tokenize(split_string(string))) << std::endl;
}

int main()
{

    std::cout << "Expression en NPI : ";
    std::string string;
    std::getline(std::cin, string);

    std::cout << "Resultat : " << npi_evaluate(tokenize(split_string(string))) << std::endl;
    std::cout << "Autres tests :" << std::endl;

    test("3 4 +");
    test("2 12 + 5 +");
    test("3 4 11 5 + / +");
    test("4 5 2 * +");

    return 0;
}