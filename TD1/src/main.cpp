#include <iostream>
#include "fraction.hpp"
#include "utils.hpp"

int main()
{
    std::cout << std::endl << "EXERCICE 2 : AFFICHAGE" << std::endl;
    std::cout << "Transformer la fonction display en surcharge de l'operateur :<<" << std::endl;

    Fraction f1 { 1, 2 };
    Fraction f2 { 3, 4 };
    Fraction f3 { 2, 4 };

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;
    std::cout << "f3 = " << f3 << std::endl;

    std::cout << std::endl << "EXERCICE 3 : EGALITE" << std::endl;
    std::cout << "1. Ajouter l'operateur == pour comparer deux fractions :" << std::endl;

    if(f1 == f3){
        std::cout << "f1 = f3" << std::endl;
    } else {
        std::cout << "f1 != f3" << std::endl;
    }

    std::cout << "2. Ajouter l'operateur != en se basant sur l'operateur ==" << std::endl;

    if(f1 == f2){
        std::cout << "f1 = f2" << std::endl;
    } else {
        std::cout << "f1 != f2" << std::endl;
    }

    std::cout << std::endl << "EXERCICE 4 : COMPARAISON" << std::endl;
    std::cout << "1. Ajouter l'operateur < pour comparer deux fractions :" << std::endl;

    if(f1 < f2){
        std::cout << "f1 < f2" << std::endl;
    } else {
        std::cout << "f2 < f1" << std::endl;
    }

    std::cout << std::endl << "2. Ajouter les operateurs <=, > et >=" << std::endl;

    if(f1 <= f2){
        std::cout << "f1 <= f2" << std::endl;
    } else {
        std::cout << "f1 > f2" << std::endl;
    }

    if(f1 <= f3){
        std::cout << "f1 <= f3" << std::endl;
    } else {
        std::cout << "f1 > f3" << std::endl;
    }

    if(f2 > f1){
        std::cout << "f2 > f1" << std::endl;
    } else {
        std::cout << "f1 <= f3" << std::endl;
    }

    if(f2 >= f1){
        std::cout << "f2 >= f1" << std::endl;
    } else {
        std::cout << "f2 < f1" << std::endl;
    }

    if(f1 >= f3){
        std::cout << "f1 >= f3" << std::endl;
    } else {
        std::cout << "f1 < f3" << std::endl;
    }

    std::cout << std::endl << "EXERCICE 5 : OPERATIONS D'AFFECTION" << std::endl;
    std::cout << "Transformer les methodes en surcharge des +=, -=, *= et /=" << std::endl;

    std::cout << std::endl << "f1 + f2 = " << f1 + f2 << std::endl;

    std::cout << "f2 - f1 = " << f2 - f1 << std::endl;

    std::cout << "f1 * f2 = " << f1 * f2 << std::endl;

    std::cout << "f1 / f2 = " << f1 / f2 << std::endl;

    std::cout << std::endl << "EXERCICE 6 : CONVERSION" << std::endl;
    std::cout << "1. Definir et implementer une methode to_float :" << std::endl;

    std::cout << "f1 = " << f1.to_float() << std::endl;

    std::cout << std::endl << "2. Ajouter l'operateur de conversion float :" << std::endl;

    std::cout << "float d1 {static_cast<float>(f1)}" << std::endl;

    float d1 {static_cast<float>(f1)};

    std::cout << "d1 = " << d1 ;

    return 0;
}