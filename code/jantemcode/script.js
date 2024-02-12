

// jeu 


window.addEventListener("load", function() {
  // Class permettant de creer un labyrinthe;
  var Map = {
    init: function(grid, pos, skills) {
      this.grid = [
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
        ["in", 0, 0, 0, 0, 0, 1, 2, 0, 1],
        [1, 1, 1, 0, 1, 0, 1, 1, 0, 1],
        [1, 0, 0, 0, 1, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 1, 1, 1, 1, 1, 1],
        [1, 0, 1, 1, 1, 1, 0, 0, 4, 1],
        [1, 0, 3, 1, 0, 0, 0, 1, 1, 1],
        [1, 0, 1, 1, 0, 1, 0, 1, 1, 1],
        [1, 0, 0, 0, 0, 1, 0, 0, 0, "out"],
        [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
      ];

      this.pos = [1, 1];

      this.skills = 0;
    },

    /*
    function display : afficher le labyrinthe
        Pour chaque row de Map
            creer une row
                Pour chaque element d'une row
                    ajouter un <td> a la row en fonction du symbole
            Ajouter chaque row a Labyrinthe
    */
    display: function() {
      for (var y = 0; y < this.grid.length; y++) {
        var row = "<tr>";

        for (var x = 0; x < this.grid[y].length; x++) {
          if (this.grid[y][x] === 1) {
            row += '<td bgcolor="black"></td>';
          } else if (this.grid[y][x] === 2) {
            row +=
              '<td><img class="img-circle" src="http://www.jf-developpeur-web.fr/img/html-laby.png" alt="0 "></td>';
          } else if (this.grid[y][x] === 3) {
            row +=
              '<td><img class="img-circle" src="http://www.jf-developpeur-web.fr/img/js-laby.png" alt="1"></td>';
          } else if (this.grid[y][x] === 4) {
            row +=
              '<td><img class="img-circle" src="http://www.jf-developpeur-web.fr/img/php-laby.png" alt="2"></td>';
          } else if (x === this.pos[0] && y === this.pos[1]) {
            row +=
              '<td><img class="img-circle" src="http://www.jf-developpeur-web.fr/img/avatar-laby.jpg" alt="*"></td>';
          } else if (this.grid[y][x] === "in") {
            row +=
              '<td><i class="fa fa-minus-circle" aria-hidden="true"></i></td>';
          } else if (this.grid[y][x] === "out") {
            row +=
              '<td><i class="fa fa-long-arrow-right" aria-hidden="true"></i></td>';
          } else {
            row += "<td></td>";
          }
        }
        document
          .getElementById("labyrinthe")
          .insertAdjacentHTML("beforeEnd", row);
      }
    },

    /*
    function check: verifier le deplacement
        si on est en dehors du labyrinthe, deplacement impossible
        si this.grid[x][y] === 1 on rencontre un mur
        si this.grid[x][y] === 'out' on a gagné
    */
    check: function(x, y) {
      if (
        x < 0 ||
        y < 0 ||
        x > this.grid[0].length - 1 ||
        y > this.grid.length - 1
      ) {
        $(function() {
          $(".errors")
            .html("Déplacement impossible !")
            .fadeOut(2000, function() {
              $(this)
                .html("")
                .fadeIn();
            });
        });

        return [this.pos[0], this.pos[1]];
      } else if (this.grid[y][x] === 1) {
        $(function() {
          $(".errors")
            .html("Il y a un mur !")
            .fadeOut(2000, function() {
              $(this)
                .html("")
                .fadeIn();
            });
        });
        return [this.pos[0], this.pos[1]];
      } else if (this.grid[y][x] === "out") {
        if (this.skills === 3) {
          $(function() {
            $(".success")
              .html('<p class="alert-success">Bravo c\'est gagné !</p>')
              .fadeIn(2000);
          });
          return [-1, -1];
        } else {
          $(function() {
            $(".errors")
              .html("Il vous manque des compétences !")
              .fadeOut(2000, function() {
                $(this)
                  .html("")
                  .fadeIn();
              });
          });

          return [this.pos[0], this.pos[1]];
        }
      } else if (this.grid[y][x] === 2) {
        $(function() {
          $("#htmlLogo").prop("checked", true);
        });
        this.grid[y][x] = 0;
        this.skills += 1;
        return [x, y];
      } else if (this.grid[y][x] === 3) {
        $(function() {
          $("#jsLogo").prop("checked", true);
        });
        this.grid[y][x] = 0;
        this.skills += 1;
        return [x, y];
      } else if (this.grid[y][x] === 4) {
        $(function() {
          $("#phpLogo").prop("checked", true);
        });
        this.grid[y][x] = 0;
        this.skills += 1;
        return [x, y];
      } else {
        return [x, y];
      }
    }
  };

  /*
function listenToKeyboard: fonction appliqué a l'ecoute du clavier
    on modifie les coordonnées apres verification
    on actualise le labyrinthe
*/
  function listenToKeyboard(e) {
    var key = e.keyCode;
    var move;
    switch (key) {
      case 68:
        move = labyrinthe.check(labyrinthe.pos[0] + 1, labyrinthe.pos[1]);
        labyrinthe.pos[0] = move[0];
        labyrinthe.pos[1] = move[1];
        document.getElementById("labyrinthe").innerHTML = "";
        labyrinthe.display();
        break;
      case 81:
        move = labyrinthe.check(labyrinthe.pos[0] - 1, labyrinthe.pos[1]);
        labyrinthe.pos[0] = move[0];
        labyrinthe.pos[1] = move[1];
        document.getElementById("labyrinthe").innerHTML = "";
        labyrinthe.display();
        break;
      case 83:
        move = labyrinthe.check(labyrinthe.pos[0], labyrinthe.pos[1] + 1);
        labyrinthe.pos[0] = move[0];
        labyrinthe.pos[1] = move[1];
        document.getElementById("labyrinthe").innerHTML = "";
        labyrinthe.display();
        break;
      case 90:
        move = labyrinthe.check(labyrinthe.pos[0], labyrinthe.pos[1] - 1);
        labyrinthe.pos[0] = move[0];
        labyrinthe.pos[1] = move[1];
        document.getElementById("labyrinthe").innerHTML = "";
        labyrinthe.display();
        break;
      default:
        console.log("touche inconnue");
    }
  }

  var labyrinthe = Object.create(Map);
  labyrinthe.init();
  labyrinthe.display();

  document.addEventListener("keydown", listenToKeyboard);
});



var track = document.getElementById('track');

var controlBtn = document.getElementById('play-pause');

function playPause() {
  if (track.paused) {
    track.play();
    //controlBtn.textContent = "Pause";
    controlBtn.className = "pause";
  } 
  else { 
    track.pause();
     //controlBtn.textContent = "Play";
    controlBtn.className = "play";
}
}

controlBtn.addEventListener("click", playPause);
track.addEventListener("ended", function() {
controlBtn.className = "play";
});
