/* 
 * File:   main.cpp
 * Author: ericw
 *
 * Created on February 7, 2019, 1:45 PM
 */

#include "card.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <algorithm> 


/*
 * 
 */
int main(int argc, char** argv) 
{
    Deck a {
		PlayingCard{Ace,  Club},
		PlayingCard{Two,  Club},
		PlayingCard{Three,Club},
		PlayingCard{Four, Club},
		PlayingCard{Five, Club},
		PlayingCard{Six,  Club},
		PlayingCard{Seven,Club},
		PlayingCard{Eight,Club},
		PlayingCard{Nine, Club},
		PlayingCard{Ten,  Club},
		PlayingCard{Jack, Club},
		PlayingCard{Queen,Club},
		PlayingCard{King, Club},

		PlayingCard{Ace,  Diamond},
		PlayingCard{Two,  Diamond},
		PlayingCard{Three,Diamond},
		PlayingCard{Four, Diamond},
		PlayingCard{Five, Diamond},
		PlayingCard{Six,  Diamond},
		PlayingCard{Seven,Diamond},
		PlayingCard{Eight,Diamond},
		PlayingCard{Nine, Diamond},
		PlayingCard{Ten,  Diamond},
		PlayingCard{Jack, Diamond},
		PlayingCard{Queen,Diamond},
		PlayingCard{King, Diamond}, 

		PlayingCard{Ace,  Heart},
		PlayingCard{Two,  Heart},
		PlayingCard{Three,Heart},
		PlayingCard{Four, Heart},
		PlayingCard{Five, Heart},
		PlayingCard{Six,  Heart},
		PlayingCard{Seven,Heart},
		PlayingCard{Eight,Heart},
		PlayingCard{Nine, Heart},
		PlayingCard{Ten,  Heart},
		PlayingCard{Jack, Heart},
		PlayingCard{Queen,Heart},
		PlayingCard{King, Heart}, 

		PlayingCard{Ace,  Spade},
		PlayingCard{Two,  Spade},
		PlayingCard{Three,Spade},
		PlayingCard{Four, Spade},
		PlayingCard{Five, Spade},
		PlayingCard{Six,  Spade},
		PlayingCard{Seven,Spade},
		PlayingCard{Eight,Spade},
		PlayingCard{Nine, Spade},
		PlayingCard{Ten,  Spade},
		PlayingCard{Jack, Spade},
		PlayingCard{Queen,Spade},
		PlayingCard{King, Spade}, 

		PlayingCard{Black},
		PlayingCard{Red}, 
        
    };
    std::cout << a << std::endl;
    
    std::random_device r;
    std::minstd_rand prng(r());
    std::shuffle(a.begin(),a.end(),prng);
    
    std::cout << a << std::endl;
	
    return 0;
}

