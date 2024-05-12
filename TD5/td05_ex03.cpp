#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstdlib>

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;

    // 1. Surchargez l'opérateur ==

    bool operator==(Card const &b) const
    {
        return kind == b.kind && value == b.value;
    }

    // 2. & 3. Écrire une méthode hash parfaite

    int hash() const
    {
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }
};

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards{};
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}

// 4. Compter le nombre de fois que chaque carte apparaît

std::unordered_map<Card, int> get_map(std::vector<Card> cards)
{
    std::unordered_map<Card, int> map;
    for (int i{0}; i < 52; i++)
    {
        int sum{0};
        Card found_card;
        for (Card card : cards)
        {
            if (card.hash() == i)
            {
                sum++;
                found_card = card;
            }
        }

        if (sum > 0)
        {
            std::pair<Card, int> new_sum{found_card, sum};
            map.insert(new_sum);
        }
    }
    return map;
}

// 4. Afficher le résultat

void display_map(std::vector<Card> cards)
{
    for (std::pair<Card, int> sum : get_map(cards))
    {
        std::cout << card_name(sum.first) << " : " << sum.second << std::endl;
    }
}

int main()
{
    // 4. Générer une liste de 100 cartes aléatoires

    display_map(get_cards(100));

    return 0;
}