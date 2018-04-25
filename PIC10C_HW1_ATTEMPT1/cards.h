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
     accessor function: displays a single card
     */
    void display() const;
};

class Hand {
private:
    float value; // stores the value of the cards
    vector<Card> hand; // stores cards
public:
    /**
     Constructor: sets the value to 0 and default initializes the vector of cards
     */
    Hand();
    
    /**
     mutator function: adds a card to the hand
     @param card , card to be added
     */
    void addCard(const Card& card);
    
    /**
     accessor function: gets the total value of the hand
     @return total
     */
    float total() const;
    
    /**
     accessor function: display's the cards in the player's hand
     */
    void display() const;
};

class Player {
private:
    int money; // stores the money
    
public:
    /**
     Constructor: takes in the player's initial amount of money
     @param m , money
     */
    Player(int m);
    
    /**
     accessor function: get's the player's money
     @return money
     */
    int getMoney() const;
    
    /**
     mutator function: adds or subtracts the player's money depending on whether or not they won that round
     @param won , true if they bet the dealer, false if not
     @parma bet , add/subtract the bet
     */
    void updateMoney(bool won, int bet);
    
};

#endif
