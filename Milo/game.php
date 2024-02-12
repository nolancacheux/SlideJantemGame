<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <title>Slide Jantem</title>
    <link rel="stylesheet" href="css/style.css">

    <?php
    session_start();
    if(isset($_SESSION["ID"])){
      $id = $_SESSION["ID"];
      require("../bdd/getskin.php");
      getSkin($id);
      echo '<script>var playerdesign = '.json_encode($_SESSION['player']).';</script>';
      echo '<script>var traildesign = '.json_encode($_SESSION['trail']).';</script>';
    }
    else{
      echo '<script>var playerdesign = 1;</script>';
      echo '<script>var traildesign = 1;</script>';
    }
    session_abort();
    ?>
    
    <script src="js/game.js"></script>
    <script src="js/script.js"></script>
  </head>
  <?php 
        include "nuage.php";
        if(isset($_GET["w"])){
          $w = $_GET["w"];
        }
        else{
          $w = 1;
        }
        echo '<body style="background: url(\'img/map/'.$w.'.gif\')no-repeat center center fixed; background-size: cover;">';
  ?>
    <!-- <div class="button">   -->
    <div class="game">
      <div class="push_button restart" onClick="reset();"> Restart </div>
      <div class="push_button cancel" onClick="lastplay();"> Cancel</div>
      <!-- </div> -->
      <div class="move">Move</div>
      <div class="score"></div>
      <div class="frame">
        <div class="header">
            <!-- <div class="help">Key: ← → ↑ ↓</div> -->
        </div>
        <div class="board"></div>
        <div class="footer">
            <div class="info"></div>
        </div>
      </div>
      <div class="loadbar">
          <strong class="bar" style='height:0%;'></strong>
      </div>

      <div id="finish" class="">
        <!-- <img class="img" src="img/sprite-22-1.png" alt="LevelComplete"> -->
        <div class="lvl">Level Completed !</div>
        <div class="menu home" onClick="menu();">Home</div>

        <?php
        if(isset($_GET["w"])){
          if (($_GET["w"] == 4) && ($_GET["map"] == 5)){?>
              <div class="menu next" onClick="end();">END !</div>
          <?php
          }
          ?>
          <div class="menu next" onClick="nextlevel();">Next</div>
        <?php
        }
        else{?>
          <div class="menu next" onClick="returnlevels();">Levels</div>
        <?php
        }
        ?>
        
        
      </div>
    </div>
    <div class="top">
      <?php include "icone.php";?>
    </div>

  <!-- <div class="help">https://codepen.io/ludmila-tretyakova/pen/yrNPMQ</div> -->
</body>
</html>