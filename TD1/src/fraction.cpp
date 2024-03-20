#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// EXERCICE 1 : OPERATIONS
// Transformer les méthodes add, sub, mul et div en surcharge des opérateurs +, -, * et /

// Fraction operator+(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator-(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator*(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.numerator,
//         f1.denominator * f2.denominator
//     });
// }

// Fraction operator/(Fraction const& f1, Fraction const& f2) {
//     return simplify({
//         f1.numerator * f2.denominator,
//         f1.denominator * f2.numerator
//     });
// }

// EXERCICE 2 : AFFICHAGE
// Transformer la fonction display en surcharge de l'opérateur <<

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

// EXERCICE 3 : EGALITE

// Ajouter l'opérateur == pour comparer deux fractions.

bool operator==(Fraction const& f1, Fraction const& f2) {
    return simplify(f1).numerator == simplify(f2).numerator && simplify(f1).denominator == simplify(f2).denominator;
}

// Ajouter l'opérateur != en se basant sur l'opérateur ==.

bool operator!=(Fraction const& f1, Fraction const& f2) {
    return !(f1 == f2);
}

// EXERCICE 4 : COMPARAISON

// Ajouter l'opérateur < pour comparer deux fractions.

bool operator<(Fraction const& f1, Fraction const& f2) {
    return f1.numerator < f2.numerator || (f1.numerator == f2.numerator && f1.denominator < f2.denominator);
}

// Ajouter les opérateurs <=, > et >= en se basant sur l'opérateur <.

bool operator>(Fraction const& f1, Fraction const& f2) {
    return f2 < f1;
}

bool operator<=(Fraction const& f1, Fraction const& f2) {
    return f1 < f2 || (f1 == f2);
}

bool operator>=(Fraction const& f1, Fraction const& f2) {
    return f1 > f2 || (f1 == f2);
}

// EXERCICE 5 : OPERATIONS D'AFFECTATION

// Transformer les méthodes add, sub, mul et div en surcharge des opérateurs d'affectation +=, -=, *= et /=


Fraction& Fraction::operator+=(Fraction const& f){
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
};

Fraction& Fraction::operator-=(Fraction const& f){
    numerator = numerator * f.denominator - f.numerator * denominator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
};

Fraction& Fraction::operator*=(Fraction const& f){
    numerator *= f.numerator;
    denominator *= f.denominator;
    *this = simplify(*this);
    return *this;
};

Fraction& Fraction::operator/=(Fraction const& f){
    numerator *= f.denominator;
    denominator *= f.numerator;
    *this = simplify(*this);
    return *this;
};

// Réécrire les opérateurs +, -, * et / en utilisant les opérateurs affectation.

Fraction operator+(Fraction f1, Fraction const& f2) {
    f1 += f2;
    return simplify(f1);
}

Fraction operator-(Fraction f1, Fraction const& f2) {
    f1 -= f2;
    return simplify(f1);
}

Fraction operator*(Fraction f1, Fraction const& f2) {
    f1 *= f2;
    return simplify(f1);
}

Fraction operator/(Fraction f1, Fraction const& f2) {
    f1 /= f2;
    return simplify(f1);
}

// EXERCICE 6 : CONVERSION

// Définir et implémenter une méthode to_float qui retourne la valeur sous forme de float.

float Fraction::to_float() const{
    return static_cast<float>(numerator)/static_cast<float>(denominator);
}

// Ajouter l'opérateur de conversion float pour pouvoir convertir une fraction en float.

Fraction::operator float() const{
    return to_float();
}