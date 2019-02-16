/* 
 * File:   card.h
 * Author: Eric Warner
 
 * Created on February 16, 2019, 4:29 PM
 */

#ifndef CARD_H
#define	CARD_H

#include <iostream>
#include <queue>
#include <list>
#include <iosfwd>

char club = 'C';
char spade = 'S';
char heart = 'H';
char diamond = 'D';

enum Suit
{
    Club,
    Spade,
    Heart,
    Diamond,
};

enum Rank
{
    Ace,
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
};

class Card
{
public:
    Card(Rank r, Suit s)
    :rank(r), suit(s)
    {}
    
    Rank get_rank() const {return rank;}
    Suit get_suit() const {return suit;}
    
    
    
private:
    Suit suit;
    Rank rank;
    
};

bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);

class Deck : Card
{
    std::list<Card> cards;
};

std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Deck const& d);

#endif	/* CARD_H */

