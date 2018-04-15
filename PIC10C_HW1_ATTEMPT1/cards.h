#ifndef __CARDS_H__
#define __CARDS_H__

#include <vector>
#include <string>
#include <fstream>

using namespace std;

// possible suits
enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

// possible ranks
// sota, caballo, and rey are valued at frac(1/2)
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11};


class Card{
private:
    suit_t suit; // card's suit
    rank_t rank; // card's rank
public:
    /**
     Constructor: randomly creats a card by picking a suit and a rank. *note* multpiles are allowed since there can be more than one "deck"
     */
    Card();
    /**
     accessor function: gets the card's suit (in Spanish)
     @return Spanish suit
     */
    string getSpanishSuit() const;
    
    /**
     accessor function: gets the card's rank (in Spanish)
     @return Spanish rank
     */
    string getSpanishRank() const;
    
    /**
     accessor function: gets the card's suit (in English)
     @return English suit
     */
    string getEnglishSuit() const;
    
    /**
     accessor function: gets the card's rank (in English)
     @return English rank
     */
    string getEnglishRank() const;
    
    /**
     accessor function: gets the numeric value of the rank
     @return numeric rank
     */
    int getRank() const;
    
    /**
     accessor function: allows for cards to compared by rank
     @return true if card2 is greater, false if card2 is less
     */
    bool operator < (const Card& card2) const;
};

class Hand {
private:
    float value; // stores the value of the cards
    vector<Card> hand; // stores cards
public:
    
    Hand();
    
    void addCard(const Card& card);
    
    float handTotal() const;
};

class Player {
private:
    int money;
    
public:
    Player(int m);
    
};

#endif
