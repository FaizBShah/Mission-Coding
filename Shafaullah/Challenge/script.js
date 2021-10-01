let searchVal = ''

window.onload = function () {
  let search = document.getElementById('search-color')
  search.addEventListener('input', function (e) {
    searchVal = e.target.value
    if (searchVal == '') showAllColors()
    else displaySearhColor(searchVal)
  })
}

function showAllColors() {
  document.querySelectorAll('.box').forEach(function (el) {
    el.style.display = 'block'
  })
}

const colors = [
  'red',
  'blue',
  'purple',
  'lightblue',
  'green',
  'brown',
  'yellow',
  'cyan',
]

function displaySearhColor(val) {
  document.querySelectorAll('.box').forEach(function (el) {
    el.style.display = 'none'
  })
  val = val.toLowerCase()
  colors.filter(function (color) {
    if (color.includes(val)) {
      return document.querySelectorAll('.box').forEach(function (el) {
        if (el.getAttribute('id') == color) el.style.display = 'block'
      })
    }
  })
}
