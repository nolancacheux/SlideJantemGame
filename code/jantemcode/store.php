<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Store</title>
    <link rel="stylesheet" href="styleStore.css">
    <script src="script.js"></script>
</head>

<div class="content_title">
    <div class="content__container">
        
            <ul class="content__container__list">
                <li class="content__container__list__item">Select  </li>
                <li class="content__container__list__item">Buy  </li>
                <li class="content__container__list__item">Select  </li>
                <li class="content__container__list__item">Buy  </li>
            </ul>
            <p class="content__container__text"> your skin and your paint colour </p>
    </div>
  </div>

<body class="backstore">

    <?php 
        // include "nuage.php";
        include "icone.php";
    ?>
    

    <div class = "back">

        <input type="radio" name="position" checked />
        <input type="radio" name="position" />
        <input type="radio" name="position" />
        <input type="radio" name="position" />
        <input type="radio" name="position" />

        <main class="carousel">
            <div class="item">
                <img src="image/peintre.png">
                <br>
                <button class = "buttonS"> Select </button>
            </div>
            <div class="item">
                <img src="image/peintre.png">
                <br>
                <button  class = "buttonB"> Buy </button>
            </div>
            <div class="item">
                <img src="image/peintre.png">
                <button  class = "buttonB" > Buy </button>
            </div>
            <div class="item">
                <img src="image/peintre.png">
                <br>
                <button  class = "buttonSe"> Selected </button>
            </div>
            <div class="item">
                <img src="image/peintre.png">
                <br>
                <button class = "buttonS"> Select </button>
            </div>
        </main>

    </div> 

    <div class = "back2">

        <input class="input2" type="radio" name="position" checked />
        <input class="input2" type="radio" name="position" />
        <input class="input2" type="radio" name="position" />
        <input class="input2" type="radio" name="position" />
        <input class="input2" type="radio" name="position" />
        <input class="input2" type="radio" name="position" />
        <input class="input2" type="radio" name="position" />
        

        <main class="carousel2">
            <div class="item2">
                <img class = "peinture" src="image/blue.png">
                <br>
                <button class = "buttonB"> Buy </button>
            </div>
            <div class="item2">
                <img class = "peinture" src="image/purple.png">
                <br>
                <button  class = "buttonSe"> Selected </button>
            </div>
            <div class="item2">
                <img class = "peinture" src="image/pink.png">
                <button  class = "buttonS"> Select </button>
            </div>
            <div class="item2">
                <img class = "peinture" src="image/red.png">
                <br>
                <button  class = "buttonB"> Buy </button>
                
            </div>
            <div class="item2">
                <img class = "peinture" src="image/orange.png">
                <br>
                <button class = "buttonB" > Buy </button>
            </div>
            <div class="item2">
                <img class = "peinture" src="image/yellow.png">
                <br>
                <button class = "buttonS" > Select </button>
            </div>
            <div class="item2">
                <img class = "peinture" src="image/green.png">
                <br>
                <button class = "buttonS" > Select </button>
            </div>
        </main>
        
    </div>
   
</body>
<script src="script.js"></script>
</html>