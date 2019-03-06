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

enum Color
{
	Black,
	Red,
}

enum PlayingCardKind
{
	Standard,
	Joker,
}



class StandardCard
{
public:	
	StandardCard(Rank r, Suit s)
	:rank(r), suit(s)
	{}

	Rank get_rank() const {return rank;}
	Suit get_suit() const {return suit;}
    
    
    
private:
    Suit suit;
    Rank rank;
    
};

struct JokerCard
{
	JokerCard(Color c)
	:color(c)
	{}
	
	Color get_color() const
	{
		return color;
	}

private:
	Color color;
};

union PlayingCardData
{
	PlayingCardData(Rank r, Suit s)
	:sc(r,s)
	{}
	
	PlayingCardData(Color c)
	:jc(c)
	{}
	
	StandardCard sc;
	JokerCard jc;
};

struct PlayingCard
{
private:
	PlayingCardKind tag;
	PlayingCardData data;

public:
	PlayingCard(Rank r, Suit s) 
	:tag(Standard), data(r,s)
	{}
	
	PlayingCard(Color c) 
	:tag(Joker), data(c)
	{}
	
	bool is_standard() const
	{
		return (tag==Standard);
	}
	
	bool is_joker() const
	{
		return (tag==Joker);
	}
	
	Rank get_rank() const
	{
		return data.sc.get_rank();
	}
	
	Suit get_suit() const
	{
		return data.sc.get_suit();
	}
	
	Color get_color() const
	{
		return data.jc.get_color();
	}
	
	StandardCard get_standard() const 
	{
		return data.sc;
	}
	
	JokerCard get_joker() const
	{
		return data.jc;
	}
};

struct PlayingCard : std::variant<StandardCard,JokerCard>
{};

struct Deck : std::deque<PlayingCard>
{
    using std::deque<PlayingCard>::deque;
};


bool operator==(Card a, Card b);
bool operator!=(Card a, Card b);

bool operator<(Card a, Card b);
bool operator>(Card a, Card b);
bool operator<=(Card a, Card b);
bool operator>=(Card a, Card b);





std::ostream& operator<<(std::ostream& os, Suit s);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Color c);
std::ostream& operator<<(std::ostream& os, PlayingCard c);
std::ostream& operator<<(std::ostream& os, JokerCard c);
std::ostream& operator<<(std::ostream& os, StandardCard c);
std::ostream& operator<<(std::ostream& os, Deck const& d);

#endif	/* CARD_H */

