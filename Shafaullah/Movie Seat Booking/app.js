const container = document.querySelector(".container");
const seats = document.querySelectorAll(".row .seat:not(.occupied)");
const count = document.querySelector("#count");
const total = document.querySelector("#total");
let movieSelect = document.querySelector("#movie");
let ticketPrice = +movieSelect.value;

populateUI();

// Event listener for seats
container.addEventListener("click", (e) => {
  if (
    e.target.classList.contains("seat") &&
    !e.target.classList.contains("occupied")
  ) {
    e.target.classList.toggle("selected");
    updateSelectedCount();
  }
  e.preventDefault();
});

// Set Movie data
function setMovieData(selectedMovieIndex, selectedMoviePrice) {
  // Set local Storage with selected movie and its price
  localStorage.setItem("SelectedMovieIndex", selectedMovieIndex);
  localStorage.setItem("SelectedMoviePrice", selectedMoviePrice);
}

// Update count and ticket Price
function updateSelectedCount() {
  const selectedSeat = document.querySelectorAll(".row .seat.selected");
  // copying nodeList into into an array
  const selectedSeatIndex = [...selectedSeat].map((seat) =>
    [...seats].indexOf(seat)
  );
  // Set Local storage with SelectedSeats
  localStorage.setItem("SelectedSeats", JSON.stringify(selectedSeatIndex));

  const selectedSeatCount = selectedSeat.length;

  count.innerText = selectedSeatCount;
  total.textContent = selectedSeatCount * ticketPrice;
}

function populateUI() {
  const selectedSeatIndex = JSON.parse(localStorage.getItem("SelectedSeats"));
  if (selectedSeatIndex !== null && selectedSeatIndex.length > 0) {
    seats.forEach((seat, index) => {
      if (selectedSeatIndex.indexOf(index) != -1) {
        seat.classList.add("selected");
      }
    });
  }
  const selectedMovieIndex = JSON.parse(
    localStorage.getItem("SelectedMovieIndex")
  );
  if (selectedMovieIndex !== null) {
    movieSelect.selectedIndex = selectedMovieIndex;
  }
}

// Change Movie
movieSelect.addEventListener("change", (e) => {
  setMovieData(e.target.selectedIndex, e.target.value);
  ticketPrice = e.target.value;
  updateSelectedCount();
});

// Update count and total on reload
updateSelectedCount();
