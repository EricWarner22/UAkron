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


/*
 * 
 */
int main(int argc, char** argv) 
{
    Deck a {
       Card{Ace,  Club},
       Card{Two,  Club},
       Card{Three,Club},
       Card{Four, Club},
       Card{Five, Club},
       Card{Six,  Club},
       Card{Seven,Club},
       Card{Eight,Club},
       Card{Nine, Club},
       Card{Ten,  Club},
       Card{Jack, Club},
       Card{Queen,Club},
       Card{King, Club},               

       Card{Ace,  Diamond},
       Card{Two,  Diamond},
       Card{Three,Diamond},
       Card{Four, Diamond},
       Card{Five, Diamond},
       Card{Six,  Diamond},
       Card{Seven,Diamond},
       Card{Eight,Diamond},
       Card{Nine, Diamond},
       Card{Ten,  Diamond},
       Card{Jack, Diamond},
       Card{Queen,Diamond},
       Card{King, Diamond}, 
          
       Card{Ace,  Heart},
       Card{Two,  Heart},
       Card{Three,Heart},
       Card{Four, Heart},
       Card{Five, Heart},
       Card{Six,  Heart},
       Card{Seven,Heart},
       Card{Eight,Heart},
       Card{Nine, Heart},
       Card{Ten,  Heart},
       Card{Jack, Heart},
       Card{Queen,Heart},
       Card{King, Heart}, 
         
       Card{Ace,  Spade},
       Card{Two,  Spade},
       Card{Three,Spade},
       Card{Four, Spade},
       Card{Five, Spade},
       Card{Six,  Spade},
       Card{Seven,Spade},
       Card{Eight,Spade},
       Card{Nine, Spade},
       Card{Ten,  Spade},
       Card{Jack, Spade},
       Card{Queen,Spade},
       Card{King, Spade}, 
        
    };
    std::cout << a << std::endl;
    
    std::random_device r;
    std::minstd_rand prng(r());
    std::random_shuffle(a.begin(),a.end(),prng);
    
    std::cout << a << std::endl;
	
	std::sort(a.begin(),a.end());

    return 0;
}

