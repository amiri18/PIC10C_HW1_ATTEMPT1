# Homework Assignment 1B: "Siete y Medio" Card Game
## Game details:
This is a card game that is very similar to the game "Twenty One", execpt in this version it is called *Seven and Half*. There are regular cards, ace through seven, that are their numeric value (ace is one), and there are face cards that are all the value half (or 0.5). There are four suits, bastos (clubs), oros (golden coins), copas (cups), and espadas (swords) and the face cards are sota (jack), the caballo (knight), and the rey (king). The goal of the game, similar to Twenty One, is to get a total of seven and half, and is played against the dealer.

In the game that I programmed, the user starts out with $100. In order to beat "the casino", the user needs to gain $1000. If the user loses all their money, they lose the game. For each round the user starts out by placing their bid and drawing a card. There are three outcomes which could happen during a round:
- The user wins (either having a higher hand value than the dealer or the dealer busts).
- The user loses (either having a lower hand value than the dealer or the user busts).
- The user and dealer die (both have the same hand value).

While the user plays the game, the program keeps track of each round. Once the game is finished, the program produces a `gamelog.txt` file which has recorded the bets, cards, and scores of each round. 
## Programming Details:
