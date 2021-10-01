#importing the game python files
import guessTheNumber
import RockPaperScissors
import hangman



# this is the main game menu linking to the code of each game
def game(gameNumber):
    print(gameNumber)

while (True):
    print("""choose which game you want to play: 
1. Guess the number
2. Rock Paper Scissors
3. Hangman
4. tic-tac-toe
5. Minesweeper""")
    gamenumber=input("Enter choice(1/2/3/4/5/exit): ")
    if (gamenumber=="1"):
        guessTheNumber.Game()
    if (gamenumber=="2"):
        RockPaperScissors.Game()
    if (gamenumber=="3"):
        hangman.Game()
    if (gamenumber=="4"):
        game(4)
    if (gamenumber=="5"):
        game(5)
    if (gamenumber=="exit"):
        break