// GAME VARS
let min = 1,
  max = 10,
  winningNum = getRandomNum(min, max),
  guessLeft = 3;

// UI VARS
const game = document.querySelector("#game"),
  guessInput = document.querySelector("#guess-input"),
  message = document.querySelector(".message"),
  guessBtn = document.querySelector("#guess-btn"),
  minNum = document.querySelector(".min-num"),
  maxNum = document.querySelector(".max-num");

game.addEventListener("mousedown", function (e) {
  if (e.target.className == "play-again") {
    window.location.reload();
  }
});

// Assign max and min to UI
// minNum.appendChild(document.createTextNode(min));
minNum.textContent = min;
maxNum.textContent = max;

guessBtn.addEventListener("click", function () {
  let guess = parseInt(guessInput.value);
  if (isNaN(guess) || guess < min || guess > max) {
    setmessage(`Please enter a number between ${min} and ${max}`, "red");
  }
  if (guess == winningNum) {
    gameOver(true, `${winningNum} is correct, YOU WIN !`);
  } else {
    guessLeft -= 1;
    if (guessLeft == 0) {
      // game Over;
      gameOver(false, `GAME OVER. YOU LOST ! correct number was ${winningNum}`);
    } else {
      guessInput.value = "";
      setmessage(
        `${guess} is not correct,You have ${guessLeft} guess left.`,
        "red"
      );
    }
  }
});
function setmessage(msg, color) {
  message.textContent = msg;
  message.style.color = color;
}

// gameOver Function
function gameOver(won, msg) {
  // Color depends on won or not
  let color;
  won == true ? (color = "green") : (color = "red");

  // Disabling the input
  guessInput.disabled = true;
  // changing border color
  guessInput.style.borderColor = color;
  setmessage(msg, color);
  guessBtn.value = "PLAY AGAIN";
  guessBtn.className += "play-again";
}

function getRandomNum() {
  return Math.floor(Math.random() * (max - min + 1) + min);
}
