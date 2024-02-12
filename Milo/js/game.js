const urlp = new URLSearchParams(window.location.search);
const custom = decodeURIComponent(urlp.get('mapc'));


const playerd = playerdesign;
const traild = traildesign;
// console.log(playerd, traild);

let root = document.documentElement;
root.style.setProperty('--block-player', "url(\"../img/perso/"+playerd+".gif\") no-repeat");
root.style.setProperty('--fond', "var(--fond"+traild+"");


var request = new XMLHttpRequest();
if(custom == "null"){
   var nbmap = decodeURIComponent(urlp.get('map'));
   var word = decodeURIComponent(urlp.get('w'));  

   root.style.setProperty('--block-wall', "url(\"../img/block/"+word+".jpg\")");

   var finalmap = parseInt(nbmap)+(5*(parseInt(word)-1));
   request.open("GET", "map/map"+finalmap+".txt", false);
}
else{  
   const manu = decodeURIComponent(urlp.get('manu'));
   root.style.setProperty('--block-wall', "url(\"../img/block/1.jpg\")");
   
   if(manu == 1){
      request.open("GET", "../Nolan/php/manualmaps/map"+custom+".txt", false);
   }
   else{
      request.open("GET", "../Nolan/php/automaps/map"+custom+".txt", false);
   }
}
request.send(null)
var file = request.responseText

// console.log (word, nbmap);

// variable globales:
let bag = 0
const EMPTY = 0
const WALL = 1
const PLAYER = 3
const TELEPORT = 2
const PASSED = 4
// const EXIT = 8
// const EXIT_READY = 9

const DOWN = 40
const UP = 38
const LEFT = 37
const RIGHT = 39

const timesleep = 200
let ready = 0
let tp = 0
var nbtp = 0;
var dim = 0;
var coups = 0;
var nbcase = 0;
var TPpos1 = [-1,-1];
var TPpos2 = [-1,-1];


const arrayfile = Array.from(String(file), Number);
const SizeX = arrayfile.splice(0, 2);
const SizeY = arrayfile.splice(0, 2);
for (i = 0; i < SizeX.length; i++) {
   dim *= 10;
   dim += SizeX[i];
}
// console.log(dim)

var arr = arrayfile
interval = dim
map = [];
while (arr.length >= interval) {
   map.unshift(arr.splice(-interval, interval));
}
map.unshift(arr);
map.shift();
// console.log(map);


// chargement de la map
const ROWS = dim
const COLS = dim
maze = [];
for (var i = 0; i < map.length; i++)
   maze[i] = map[i].slice();

previousmaze = [];
for (var i = 0; i < map.length; i++)
   previousmaze[i] = map[i].slice();
// console.log(maze)


// modif css pour la taille du jeu
document.documentElement.style.setProperty('--map-size', ROWS);

// placement du joueur et téléporteur dans la map
for (let row = 0; row < ROWS; row++) {
   for (let col = 0; col < COLS; col++) {
      if (maze[row][col] == PLAYER) {
         player = [row, col]
         oldplayer = [row, col]
         resetplayer = [row, col]
      }
      if (maze[row][col] == TELEPORT) {
         if (nbtp === 0) {
            TPpos1 = [row, col];
            nbtp++;
         }
         else {
            TPpos2 = [row, col];
         }
      }
   }
}

window.onload = () => {
   // generateDiamond()
   createBoard()
   renderMaze()
}

// function generateDiamond(){
//    let count = 0

//    do {
//       let row = Math.floor(Math.random() * ROWS)
//       let col = Math.floor(Math.random() * COLS)
//       if (maze[row][col] === EMPTY &&
//          row !== 0 && col !== 0 &&
//          row !== ROWS - 1 && col !== COLS - 1) {
//          maze[row][col] = DIAMOND
//          count++
//       }

//    } while (count !== DIAMOND_COUNT)
// }


function lastplay() {
   if(LP != 1 && coups != 0){
      // console.log(previousmaze)
      for (var i = 0; i < maze.length; i++)
         maze[i] = previousmaze[i].slice();
      player[0] = oldplayer[0];
      player[1] = oldplayer[1];
      coups -= 1;
      LP = 1;
   }
   return renderMaze();
}
function reset() {
   // console.log(map)
   for (var i = 0; i < maze.length; i++)
      maze[i] = map[i].slice();
   player[0] = resetplayer[0];
   player[1] = resetplayer[1];
   coups = 0;
   pourcent = 0;
   direction = 0;
   return renderMaze();
}
function menu() {
   window.location.href="accueil.php"; 
}
function nextlevel() {
   next = parseInt(nbmap) + 1;
   if (next < 6){
      window.location.href="game.php?map="+(next)+"&w="+word+"";
   }
   else{
      window.location.href="words.php";
   }
}

function returnlevels() {
   window.location.href="../Nolan/php/levels.php";
}
function end() {
   window.location.href="end.php";
}

function createBoard() {
   for (let row = 0; row < ROWS; row++) {
      for (let col = 0; col < COLS; col++) {
         const block = document.createElement('div')
         block.id = `id-${col}-${row}`
         document.querySelector(".board").appendChild(block);
      }
   }
}

function renderMaze() {
   var remainder = 0
   tp = 0
   for (let row = 0; row < ROWS; row++) {
      for (let col = 0; col < COLS; col++) {
         let itemClass = ''
         if ((row === TPpos1[0] && col === TPpos1[1]) || (row === TPpos2[0] && col === TPpos2[1])) {
            maze[row][col] = TELEPORT
         }
         switch (maze[row][col]) {
            case PLAYER:
               itemClass = 'player passed'; break
            case WALL:
               itemClass = 'wall'; break
            case PASSED:
               itemClass = 'passed'; break
            case TELEPORT:
               itemClass = 'teleport'; break
            // case EXIT:
            //    itemClass = 'exit'; break
            // case EXIT_READY:
            //    itemClass = 'end'; break
            default:
               itemClass = 'empty';
               remainder += 1;
         }

         const id = `#id-${col}-${row}`
         obj = document.getElementById("id-" + col + "-" + row + "")
         // console.log(obj)
         obj.removeAttribute('style')

         if (itemClass != "player") {
            document.querySelector(id).className = `block ${itemClass}`
         }
      }
   }
   // console.log(remainder)

   if(nbcase === 0){
      nbcase = remainder;
   }

   pourcent = 100 - parseInt(remainder*100 / nbcase)
   // console.log(pourcent)
   document.querySelector('.bar').style.height = pourcent+'%';
   document.querySelector('.bar').textContent = "";
   if (pourcent != 0){
      document.querySelector('.bar').textContent = pourcent+'%';
   }
   


   const id = `#id-${player[1]}-${player[0]}`
   if (remainder > 0) {
      document.querySelector(id).className = 'player'
      // document.querySelector('.score').textContent = coups + ` move(s). Remaining ` + remainder + ' cell(s) !'
      document.querySelector('.info').textContent = 'Passez sur toutes les cases !'
   } else {
      // Fin du jeu
      // document.querySelector('.score').textContent = `Well done ! Finish in ` + coups + ' moves !'
      document.querySelector('.info').textContent = "Bravo ! Niveau suivant"
      obj = document.getElementById("finish");
      obj.classList.add("finished");
      obj.style.visibility = "visible";
      obj.style.opacity = 1;



      scoremap = ((100 - coups) * 4);

      var score = new XMLHttpRequest();
      score.onload = function(){};
      url = "../bdd/score.php?score="+scoremap+"&map="+finalmap;
      score.open("GET", url, false);
      score.send();
      // score = score.responseText;



   }
   document.querySelector('.score').textContent = coups;


   // if (!(bag === DIAMOND_COUNT && player[1] === COLS - 1 && player[0] === ROWS - 1)) {
   //    document.querySelector(id).className = 'block player'
   // }

   // if (remainder === 0 && !(player[1] === COLS - 1 && player[0] === ROWS - 1)){
   //    document.querySelector(id).className = 'player'
   //    document.querySelector('.score').textContent = 'Vous avez toutes les cases !';
   // }

   // else if (!(remainder === 0 && player[1] === COLS - 1 && player[0] === ROWS - 1)) {
   //    document.querySelector(id).className = 'player'
   //    document.querySelector('.score').textContent = `Encore `+remainder+' case(s) !'
   // }

   // else {
   //    document.querySelector('.score').textContent = 'Félicitation !';
   //    document.querySelector(id).className = 'player bye'
   //    document.querySelector('.info').textContent = 'bye!'
   // }
   ready = 1;
}


window.onkeydown = (event) => {
   switch (event.keyCode) {
      case DOWN:
         direction = DOWN; break
      case UP:
         direction = UP; break
      case LEFT:
         direction = LEFT; break
      case RIGHT:
         direction = RIGHT; break
      default:
         direction = 0
   }

   if (direction !== 0 && ready === 1) {
      coups += 1;
      
      for (var i = 0; i < maze.length; i++)
         previousmaze[i] = maze[i].slice();
      oldplayer[0] = player[0]
      oldplayer[1] = player[1]
      LP = 0;
      changePlayerPos(player[1], player[0], player[1], player[0], direction)

      // changePlayerPos(direction)
   }
}


//Version anime qui marche TROP BIEN
function changePlayerPos(oldX, oldY, x, y, direction) {
   ready = 0
   let dy = 0
   let dx = 0
   // Gestion des changements de background SAUF exit, exitready et teleporteur
   // if ((maze[y][x] !== EXIT ) && (maze[y][x] !== EXIT_READY) && (maze[y][x] !== TELEPORT)) {
   //    maze[y][x] = PASSED
   // }   
   if ((maze[y][x] !== TELEPORT)) {
      maze[y][x] = PASSED
   }

   // console.log(x, y, dx, dy, direction)
   switch (direction) {
      case UP:
         dy -= 1;
         break;
      case RIGHT:
         dx += 1;
         break;
      case LEFT:
         dx -= 1;
         break;
      case DOWN:
         dy += 1;
         break;
      default:
         return state
   }
   x = x + dx
   y = y + dy
   player[y, x]
   // console.log(maze[y][x]);

   // console.log(x, y, direction)
   if (x >= 0 && x < COLS && y >= 0 && y < ROWS && maze[y][x] !== WALL && maze[y][x] !== TELEPORT) {
      changePlayerPos(oldX, oldY, x, y, direction);
   }

   else {
      if (x >= 0 && x < COLS && y >= 0 && y < ROWS && maze[y][x] === TELEPORT) {
         switch (direction) {
            case UP:
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateY(-" + (35 * (oldY - y)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case RIGHT:
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateX(" + (-35 * (oldX - x)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case LEFT:
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateX(-" + (35 * (oldX - x)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case DOWN:
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateY(" + (-35 * (oldY - y)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
         }
         // console.log(x,y)

         if (y === TPpos1[0] && x === TPpos1[1] && tp !== 1) {
            y = TPpos2[0];
            x = TPpos2[1];
            player = [TPpos2[0], TPpos2[1]];
            tp = 1;
            setTimeout(function () { renderMaze(); }, timesleep);
            setTimeout(function () { changePlayerPos(x, y, x, y, direction) }, 1.1 * timesleep);
         }
         if (y === TPpos2[0] && x === TPpos2[1] && tp !== 1) {
            y = TPpos1[0];
            x = TPpos1[1];
            player = [TPpos1[0], TPpos1[1]];
            tp = 1;
            setTimeout(function () { renderMaze(); }, timesleep);
            setTimeout(function () { changePlayerPos(x, y, x, y, direction) }, 1.1 * timesleep);
         }
         // else{
         //    player = [y, x]
         //    console.log("OUI")
         //    setTimeout(function() {renderMaze();}, timesleep);
         // }
      }
      else {
         switch (direction) {
            case UP:
               y = y + 1
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateY(-" + (35 * (oldY - y)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case RIGHT:
               x = x - 1
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateX(" + (-35 * (oldX - x)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case LEFT:
               x = x + 1
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateX(-" + (35 * (oldX - x)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
            case DOWN:
               y = y - 1
               obj = document.getElementsByClassName("player")[0]
               // console.log(obj)
               obj.style.transform = "translateY(" + (-35 * (oldY - y)) + "px)";
               obj.style.transition = "" + timesleep + "ms ease-in-out";
               break;
         }
         // console.log(x,y)
         player = [y, x]
         setTimeout(function () { renderMaze(); }, timesleep);
      }
   }
}