#Rock Paper Scissors game
import random
def Game():
    while(True):
        usr=input("Enter ur choice[rock(r)/paper(p)/scissors(s)] : ").lower()
        if usr not in ["r","s","p"]:
            print("please enter correct choice.")
        else:
            pc= random.choice(["r","p","s"])
            pcChoices={"r":"rock","p":"paper","s":"scissors"}
            print("the pc chose ",pcChoices[pc])
            if (usr==pc):
                print("It's a tie.")
            elif isWin(usr,pc):
                print("Hurray! you won.")
            else:
                print("Alas! You lost this one.")
            again=input("Do u want to play again?(y/n) ")
            if (again=="n"):
                break
def isWin(player,opponent):
    if (((player=="s")&(opponent=="p"))|((player=="p")&(opponent=="r"))|((player=="r")&(opponent=="s"))):
        return True