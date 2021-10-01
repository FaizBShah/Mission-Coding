
def Game():
    while(True):
        # game code here
        again=input("want to play again?(y/n) ").lower()
        print(again=="n")
        if ((again=="n")or(again=="no")):
            break