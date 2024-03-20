#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    // EXERCICE 5 : OPERATIONS D'AFFECTATION
    // Transformer les méthodes add, sub, mul et div en surcharge des opérateurs d'affectation +=, -=, *= et /=

    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    // EXERCICE 6 : CONVERSION

    // Définir et implémenter une méthode to_float qui retourne la valeur sous forme de float.
    float to_float() const;

    // Ajouter l'opérateur de conversion float pour pouvoir convertir une fraction en float.
    operator float() const;

};

// EXERCICE 1 : OPERATIONS
// Transformer les méthodes add, sub, mul et div en surcharge des opérateurs +, -, * et /

Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);

// EXERCICE 2 : AFFICHAGE
// Transformer la fonction display en surcharge de l'opérateur <<

std::ostream& operator<<(std::ostream& os, Fraction const& f);

// EXERCICE 3 : EGALITE

// Ajouter l'opérateur == pour comparer deux fractions.
bool operator==(Fraction const& f1, Fraction const& f2);

// Ajouter l'opérateur != en se basant sur l'opérateur ==.
bool operator!=(Fraction const& f1, Fraction const& f2);

// EXERCICE 4 : COMPARAISON

// Ajouter l'opérateur < pour comparer deux fractions.
bool operator<(Fraction const& f1, Fraction const& f2);

// Ajouter les opérateurs <=, > et >= en se basant sur l'opérateur <.
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);