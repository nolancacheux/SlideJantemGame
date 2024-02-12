


// //Version non animé qui marche mais moyen
// const changePlayerPos = (direction) => {
//    let [dy, dx] = [0, 0];
//    let x = 0
//    let y = 0
//    switch (direction) {
//       case UP:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dy -= 1; 
//             x = player[1] + dx
//             y = player[0] + dy         
//          }
//          y = player[0] + (dy+1)
//          break;
//       case RIGHT:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dx += 1; 
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          x = player[1] + (dx-1)
//          break;
//       case LEFT:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dx -= 1; 
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          x = player[1] + (dx+1)
//          break;
//       case DOWN:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dy += 1
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          y = player[0] + (dy-1)
//          break;
//       default:
//          return state
//    }
//    player = [y, x]

//    if (maze[y][x] === DIAMOND) {
//       maze[y][x] = EMPTY
//       bag++
//    }
//    renderMaze()
// }


// // Version animé qui marche pas <3
// const changePlayerPos = (direction) => {
//    let [dy, dx] = [0, 0];
//    let x = 0
//    let y = 0

//    let px = player[1]
//    let py = player[0]
//    // console.log(px,py)

//    let obj;
//    switch (direction) {
//       case UP:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dy -= 1; 
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          y = player[0] + (dy+1)

//          obj = document.getElementById("id-"+px+"-"+py+"");
//          console.log(obj)
//          console.log(obj.className === "player" )
//          // if ("player" in obj.classList){
//             obj.style.transform = "translateY("+(35*(dy+1))+"px)";
//             obj.style.transition = "330ms ease-in-out";
//          // }
//          break;


//       case RIGHT:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dx += 1; 
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          x = player[1] + (dx-1)

//          obj = document.getElementById("id-"+px+"-"+py+"");
//          console.log(obj)
//          console.log(obj.className === "player" )
//          if ("player" in obj.classList){
//             obj.style.transform = "translateX("+(35*(dx-1))+"px)";
//             obj.style.transition = "330ms ease-in-out";
//          }
//          break;


//       case LEFT:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dx -= 1; 
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          x = player[1] + (dx+1)

//          obj = document.getElementById("id-"+px+"-"+py+"");
//          console.log(obj)
//          console.log(obj.className === "player" )
//          if ("player" in obj.classList){
//             obj.style.transform = "translateX("+(35*(dx+1))+"px)";
//             obj.style.transition = "330ms ease-in-out";
//          }
//          break;


//       case DOWN:
//          while(x >= 0 && x < COLS && y >= 0 && y < ROWS &&maze[y][x] !== WALL){
//             dy += 1
//             x = player[1] + dx
//             y = player[0] + dy
//          }
//          y = player[0] + (dy-1)

//          obj = document.getElementById("id-"+px+"-"+py+"");
//          console.log(obj)
//          console.log(obj.className === "player" )
//          if ("player" in obj.classList){
//             obj.style.transform = "translateY("+(35*(dy-1))+"px)";
//             obj.style.transition = "330ms ease-in-out";
//          // }
//          break;
//       default:
//          return state
//    }
//    player = [y, x]
//    renderMaze()
// }


// //Version mouvement 1 par 1
// const changePlayerPos = (direction) => {
//    let [dy, dx] = [0, 0];
//    switch (direction) {
//       case UP:
//          dy = -1; break;
//       case RIGHT:
//          dx = 1; break;
//       case LEFT:
//          dx = -1; break;
//       case DOWN:
//          dy = 1; break;
//       default:
//          return state
//    }
//    const x = player[1] + dx
//    const y = player[0] + dy

//    if (x >= 0 && x < COLS && y >= 0 && y < ROWS &&
//       maze[y][x] !== WALL) {
//       player = [y, x]

//       if (maze[y][x] === DIAMOND) {
//          maze[y][x] = EMPTY
//          bag++
//       }
//       renderMaze()
//    }
// }