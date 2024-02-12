<!DOCTYPE html>
<html lang="en">

  <div class="nav">
      <a class="Bmaison" onclick="out('../Milo/accueil.php')"></a>
      <a class="Bprofil" href="#profil"></a>
      <a class="Bsetting" href="#popup1"></a>
    </div>
    <div id="popup1" class="overlay">
        <div class="popup">
            <h2>SETTINGS</h2>
            <a class="close" href="#">&times;</a>
            <div class="content">
                <audio id="track">
                    <source src="../Milo/clash.mp3" type="audio/mpeg">
                </audio> 
                <div id="player-container">
                    <div id="play-pause" class="play">Play</div>
                </div>
            </div>
        </div>
    </div>    

    <div id="profil" class="overlay">
        <div class="popup">
            <h2>Profil</h2>
            <a class="close" href="#">&times;</a>
            <?php
            session_start();
            if(!isset($_SESSION["ID"])){
              echo "<h3>You are not connected</h3>";
              ?>
              <div class="content"> 
                  <div class="button">
                      <a onclick="out('../Milo/accueil.php')" class="supprimer">Login</a>
                  </div>
              </div>
            <?php
            }   
            else{
              require("../bdd/main.php");
              $scoreG = scoreG($_SESSION["ID"]);
              echo "<h3>Score : ".$scoreG."</h3>";
              ?>
              <div class="content"> 
                  <div class="button">
                      <a onclick="out('../Milo/supprimer.php')" class="supprimer">Logout</a>
                  </div>
              </div>
              <?php
            } 
            ?>
        </div>
    </div>  
    
<script src="../Milo/js/script.js"></script>

<style>

.nav{
  z-index: 10;
  position: relative;
  grid-column: 2;
  margin-bottom: 8%;
}
/* icones en haut */
.Bmaison{
  cursor: url('../Milo/image/B2.ico'), pointer;
  display:inline-block;
  background: url(../Milo/image/maisonH.png) no-repeat;
  width: 59px;
  height: 66px;
  margin-left: 64%;
 }

 .Bprofil{
  cursor: url('../Milo/image/B2.ico'), pointer;
  display: inline-block;
  background-image:url(../Milo/image/profil.png); 
  background-size: 100% auto;
  width : 10.2vh;;
  height : 10.2vh;;
  margin-left: 2.55vh;
  margin-top : 0.85vh;
}

 .Bsetting{
  cursor: url('../Milo/image/B2.ico'), pointer;
  display: inline-block;
  background-image:url(../Milo/image/p2.png); 
  background-size: 100% auto;
  width : 10.2vh;
  height : 10.2vh;
  margin-left: 2.55vh;
  margin-right : 0.85vh;
  margin-top : 0.85vh;
 }


.popup {
  margin: 8.5vh auto;
  padding: 3.4vh;
  width: 40%;
  background-size: 100%;
  position: relative;
  transition: all 400ms ease-in-out;
  border-radius:0.85vh;
  background-color: rgb(245, 229, 139);
  border: 2.04vh solid #8a6840;
  text-align:center;
  
}

.popup h2 {
  margin-top: 0;
  color: #333;
  font-family: Tahoma, Arial, sans-serif;
  font-size : 4vh;
}
.popup h3 {
  margin-top: 0;
  color: #333;
  font-family: Tahoma, Arial, sans-serif;
  font-size : 2.5vh;
}
.popup .close {
  position: absolute;
  top: 0.85vh;
  right: 1.7vh;
  transition: all 200ms;
  font-size: 6.8vh;
  font-weight: bold;
  text-decoration: none;
  color: #333;
  padding : 3.4vh;

}
.popup .close:hover {
  color: #06D85F;
  font-size : 8.5vh;
}
.popup .content {
  max-height: 90%;
  overflow: auto;
}

@media screen and (max-width: 119vh){
  .popup{
    width: 80%;
  }
}
.overlay {
  position: fixed;
  top: 0;
  bottom: 0;
  left: 0;
  right: 0;
  background: rgba(0, 0, 0, 0.7);
  transition: opacity 1.4s;
  visibility: hidden;
  opacity: 0;
  z-index : 19;
}
.overlay:target {
  visibility: visible;
  opacity: 1;
}

#player-container #play-pause {
  cursor: url('../Milo/image/B2.ico'), pointer;
  text-indent: -170000vh;
  height:6.8vh;
  width: 6.8vh;
  padding: 2.04vh 3.06vh;
  background-image: url(../Milo/image/logoff.png);
  background-repeat: no-repeat!important;
  background-position: center;

}

.play {
  background-image: url(../Milo/image/logoff.png);
  background-size: 75% auto;

}
.pause {
   background-image: url(../Milo/image/logon.png)!important;
  background-size: 75% auto;
}



  /*boutton supprimer compte et donnees*/

  .button{
    font-family: 'Montserrat', sans-serif
  }
  
  
  .supprimer{
    cursor: url('../Milo/image/B2.ico'), pointer;
    position:relative;
    width:60%;
    color:#FFF;
    display:inline-block;
    text-decoration:none;
    margin:0 auto;
    border-radius:0vh;
    font-family:'Rubik One', sans-serif;
    border:solid 0.17vh #b48c5d;
    background:#b48c5d;
    text-align:center;
    padding:1.36vh 0vh;
    font-size: 2.72vh;
    -webkit-transition: all 0.1s;
    -moz-transition: all 0.1s;
    transition: all 0.1s;
    -webkit-box-shadow: 0vh 1.53vh 0vh #8a6840;
    -moz-box-shadow: 0vh 1.53vh 0vh #8a6840;
    box-shadow: 1.53vh 1.53vh 0vh #8a6840;
    margin: 1.7vh;
  }
  
  .supprimer:hover{  
  -webkit-box-shadow: 0vh 0.34vh 0vh #8a6840;
  -moz-box-shadow: 0vh 0.34vh 0vh #8a6840;
  box-shadow: 0.34vh 0.34vh 0vh #8a6840;
  position:relative;
  top:1.19vh;
  }
  
  
  </style>