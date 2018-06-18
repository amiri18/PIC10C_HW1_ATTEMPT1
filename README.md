# Homework Assignment 1B: "Siete y Medio" Card Game
## Game details:
This is a card game that is very similar to the game "Twenty One", execpt in this version it is called *Seven and Half*. There are regular cards, ace through seven, that are their numeric value (ace is one), and there are face cards that are all the value of a half (or 0.5). There are four suits: bastos (clubs), oros (golden coins), copas (cups), and espadas (swords) and three face cards: sota (jack), the caballo (knight), and rey (king). The goal of the game, similar to Twenty One, is to get a total of seven and half, and is played against the dealer.

In the game that I programmed, the user starts out with $100. In order to beat "the casino", the user must win $1000. If the user loses all their money, they lose the game. For each round the user starts out by placing their bet and drawing a card. There are three outcomes which could happen during a round:
- The user wins (either having a higher hand value than the dealer or the dealer busts).
- The user loses (either having a lower hand value than the dealer or the user busts).
- The user and dealer die (both have the same hand value).

While the user plays the game, the program keeps track of each round. Once the game is finished, the program produces a `gamelog.txt` file which has recorded the bet, cards, and hand values of each round. 

More details of the assignment described here: http://pic.ucla.edu/%7Ersalazar/pic10c/assignments/hw1/index.html
## Programming Details:
I didn't have too many difficulties with this project. I did have a few merge conflicts, however using mergetool to resolve them helped a lot.
### `siete-y-medio.cpp`
This file contains the main loop of the game, alternating between the user and the dealer. It also inputs the game information to `gamelog.txt`. To make the dealer "smarter", I coded that it will take "ricks" sometimes by drawing another card once it already has a hand value of 5. I like to believe that this made it harder for the user to win. 
### `cards.h` and `cards.cpp`
`cards.h` is the header file for which contains the declarations of the Card, Hand, and Player class, and `cards.cpp` contains all their definitions.
### `gamelog.txt`
This file currently holds the log of the last game that was played, keeping track of the bet, cards dealt, and hand values of both the player and dealer.
# Homework Assignment 1A: Template Vector Class
## Class Details:
This program is a templated vector class coded from "scratch." It has the typical vector functions like `push_back`, `pop_back`, etc. And it can store different data types such as strings, doubles and ints. 
## Programming Details: 
I had done a similar project in pic10b, so this assignment was relatively simple, but fun nonetheless.
### `vector_main.cpp`
This file holds simple code that tests the functions of the program to see that it runs successfully.
### `VectorTemplatedClass.h`
This file contains the vector class constructors, operators, and its functions.

More details of the assignment described here: https://bitbucket.org/rikis-salazar/10b-hw-pic10b-vector
