/* 
 * File:   card.cpp
 * Author: ericw
 *
 * Created on February 7, 2019, 2:40 PM
 */

#include "card.h"
#include <iostream>
//#include <bits/random.h>


/*
 * 
 
bool operator==(Card a, Card b)
{
    return (a.get_rank() == b.get_rank() && a.get_suit() == b.get_suit());
}

bool operator!=(Card a, Card b)
{
    return !(a==b);
}

bool operator<(Card a, Card b)
{
    if (a.get_suit() < b.get_suit())
    {
        return true;
    }
    if (a.get_suit() > b.get_suit())
    {
        return false;
    }
    return (a.get_rank() < b.get_rank());
}

bool operator>(Card a, Card b)
{
    return (b < a);
}

bool operator>=(Card a, Card b)
{
    return !(a < b);
}

bool operator<=(Card a, Card b)
{
    return !(b < a);
}
*/



std::ostream&operator<<(std::ostream&os, Suit s)
{
    switch(s)
    {
        case Club : return os << 'C';
        case Diamond : return os << 'D';
        case Spade : return os << 'H';
        case Heart : return os << 'S';
    }
}

std::ostream&operator<<(std::ostream& os, Rank r)
{
    switch(r)
    {
        case Ace : return os << 'A';
        case Two : return os << '2';
        case Three : return os << '3';
        case Four : return os << '4';
        case Five : return os << '5';
        case Six : return os << '6';
        case Seven : return os << '7';
        case Eight : return os << '8';
        case Nine : return os << '9';
        case Ten : return os << 'T';
        case Jack : return os << 'J';
        case Queen : return os << 'Q';
        case King : return os << 'K';
    }
}

std::ostream&operator<<(std::ostream& os, StandardCard c)
{
    return os << c.get_rank() << c.get_suit();
}

std::ostream&operator<<(std::ostream& os,Color c)
{
	if(c==Black){return os << "B";}
	else {return os << "R";}
	
    return os << c.get_rank() << c.get_suit();
}

std::ostream&operator<<(std::ostream& os,JokerCard c)
{
	
    return os << c.get_color();
}

std::ostream&operator<<(std::ostream& os,Color c)
{
	if(c==Black){return os << "B";}
	else {return os << "R";}
	
}

std::ostream&operator<<(std::ostream& os,PlayingCard c)
{
	if(c.is_standard()){return os << c.get_standard();}
	else {return os << c.get_joker();}
	
}


std::ostream&operator<<(std::ostream& os, Deck const& d)
{
    int i = 0;
    for (PlayingCard c : d)
    {
        os << c << ' ';
        if (i==12) { os << std::endl; i=0;}
        else{i++;}
    }
    return os;
}





