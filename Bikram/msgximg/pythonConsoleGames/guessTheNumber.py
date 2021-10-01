#Guess the number Game

def Game():
    from random import randint
    def randomNumber(x):
        return (randint(0, x))

    guessCounter=0
    while (True):
        if (guessCounter==0):
            x=int(input("Choose the upperbound of the numbers :"))
            number= randomNumber(x)
        guess=int(input("Enter your guess: "))
        if (guess>number):
            print("sorry, too high!")
        elif (guess<number):
            print("sorry, too low!")
        elif (guess==number):
            print("Hurray! you guessed it right :)")
            restart=input("Play again?(yes/no)").lower()
            guessCounter=0
            if (restart=="no" or restart=="n"):
                break
            else:
                continue
        else:
            print("Please enter correct input")
        guessCounter+=1