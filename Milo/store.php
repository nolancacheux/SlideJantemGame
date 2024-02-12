<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <title>Store</title>
    <link rel="stylesheet" href="css/styleStore.css">
    <script src="js/script.js"></script>
    <style>
        .carou {
        padding: 20px;
        perspective: 1000px;
        overflow: hidden;
        display: flex;
        flex-direction: column;
        align-items: center;
        position: absolute;
        width: 88%;
        height: 21%;
        }
        .carou > * {
        flex: 0 0 auto;
        }
        .carou figure {
        margin: 0;
        width: 300px;
        height: 100px;
        transform-style: preserve-3d;
        transition: transform 0.5s;
        transform-origin: 50% 50% -482.8427124746px;
        }
        .carou figure img {
        width: 100%;
        box-sizing: border-box;
        padding: 0 50px;
        opacity: 1;
        /* background: #0000004a; */
        height: 100%;
        }
        .carou figure img:not(:first-of-type) {
        position: absolute;
        left: 0;
        top: 0;
        transform-origin: 50% 50% -482.8427124746px;
        }
        .carou figure img:nth-child(2) {
        transform: rotateY(0.7853981634rad);
        }
        .carou figure img:nth-child(3) {
        transform: rotateY(1.5707963268rad);
        }
        .carou figure img:nth-child(4) {
        transform: rotateY(2.3561944902rad);
        }
        .carou figure img:nth-child(5) {
        transform: rotateY(3.1415926536rad);
        }
        .carou figure img:nth-child(6) {
        transform: rotateY(3.926990817rad);
        }
        .carou figure img:nth-child(7) {
        transform: rotateY(4.7123889804rad);
        }
        .carou figure img:nth-child(8) {
        transform: rotateY(5.4977871438rad);
        }
        .carou nav {
        display: flex;
        justify-content: center;
        margin: 20px 0 0;
        }
        .carou nav button {
        flex: 0 0 auto;
        margin: 0 5px;
        cursor: pointer;
        color: #333;
        background: none;
        border: 1px solid;
        letter-spacing: 1px;
        padding: 5px 10px;
        }
        .lock{
            filter: grayscale(1) blur(6px);
        }
    </style>
</head>

<body class="backstore">

    <?php 
        include "nuage.php";
        include "icone.php";

        if(isset($_SESSION["ID"])){
            $scoreG = scoreG($_SESSION["ID"]);
            echo "<h2 class=\"scoreee\">Score : ".$scoreG."</h2>";?>
            <script>
                var scoreG = <?php echo $scoreG; ?>
            </script>
        <?php
        } 
    ?>


<div class="conteent">
        <h2 class="text_shadows">jantem custom</h2>
    </div>

    <div class = "back">
        <div id="car1" class="carou">
            <figure>
                <img src="img/perso/1.gif" alt="">
                <img src="img/perso/2.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625){echo "lock";}}  ?>">
                <img src="img/perso/3.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*2){echo "lock";}}  ?>">
                <img src="img/perso/4.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*3){echo "lock";}}  ?>">
                <img src="img/perso/5.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*4){echo "lock";}}  ?>">
                <img src="img/perso/6.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*5){echo "lock";}}  ?>">
                <img src="img/perso/7.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*6){echo "lock";}}  ?>">
                <img src="img/perso/8.gif" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*7){echo "lock";}}  ?>">
            </figure>
            <nav>
                <button class="nav prev">Prev</button>
                <button class="nav next">Next</button>
            </nav>
        </div>
    </div> 

    

    <div class = "back2">
        <div id="car2" class="carou">
            <figure>
                <img src="image/blue.png" alt="">
                <img src="image/green.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625){echo "lock";}}  ?>">
                <img src="image/orange.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*2){echo "lock";}}  ?>">
                <img src="image/pink.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*3){echo "lock";}}  ?>">
                <img src="image/purple.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*4){echo "lock";}}  ?>">
                <img src="image/red.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*5){echo "lock";}}  ?>">
                <img src="image/yellow.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*6){echo "lock";}}  ?>">
                <img src="image/green2.png" alt="" class="<?php if(isset($_SESSION["ID"])){ if($scoreG < 625*7){echo "lock";}}  ?>">
            </figure>
            <nav class="navv">
                <button class="nav prev">Prev</button>
                <button class="nav next">Next</button>
            </nav>
        </div>
    </div>

    <?php
    if(isset($_SESSION["ID"])){

        echo "<button id=\"btn\" onclick=\"save()\" class = \"buttonS\"> Save </button>";
    }
    else{
        echo "<button id=\"btn\" onclick=\"document.location.href='accueil.php'\" class = \"buttonS\"> Login </button>";
    }?>
</body>

<script>
    var
    carousel = document.getElementById('car1'),
    figure = carousel.querySelector('figure'),
    nav = carousel.querySelector('nav'),
    numImages = figure.childElementCount,
    theta = 2 * Math.PI / numImages,
    currImage = 0;


    nav.addEventListener('click', onClick, true);

    function onClick(e) {
    e.stopPropagation();

    var t = e.target;
    if (t.tagName.toUpperCase() != 'BUTTON')
    return;

    if (t.classList.contains('next')) {
        currImage++;
    } else
    {
        currImage--;
    }
    figure.style.transform = `rotateY(${currImage * -theta}rad)`;
    
    verif = document.getElementById('btn');
    actu = Math.abs(currImage % 8);
    
    console.log(actu)
    if (((actu)*625) > scoreG){
        verif.style.background = "#422960a1";
        verif.setAttribute('disabled', '');
    }
    else{
        if (((actuu)*625) > scoreG){
            verif.style.background = "#422960a1";
            verif.setAttribute('disabled', '');
        }
        else{
            verif.style.background = "#b070ff";
            verif.removeAttribute('disabled');
        }
    }
    }
</script>
<script>
    var
    carousell = document.getElementById('car2'),
    figuree = carousell.querySelector('figure'),
    navv = carousell.querySelector('nav'),
    numImagess = figuree.childElementCount,
    thetaa = 2 * Math.PI / numImagess,
    currImagee = 0;


    navv.addEventListener('click', onClick, true);

    function onClick(e) {
    e.stopPropagation();

    var tt = e.target;
    if (tt.tagName.toUpperCase() != 'BUTTON')
    return;

    if (tt.classList.contains('next')) {
        currImagee++;
    } else
    {
        currImagee--;
    }

    figuree.style.transform = `rotateY(${currImagee * -thetaa}rad)`;

    verif = document.getElementById('btn');
    actuu = Math.abs(currImagee % 8);
    
    console.log(actuu)
    if (((actuu)*625) > scoreG){
        verif.style.background = "#422960a1";
        verif.setAttribute('disabled', '');
    }
    else{
        if (((actu)*625) > scoreG){
            verif.style.background = "#422960a1";
            verif.setAttribute('disabled', '');
        }
        else{
            verif.style.background = "#b070ff";
            verif.removeAttribute('disabled');
        }
    }
    }
</script>
<script>
function save(){
  document.location.href="../bdd/skin.php?player="+(currImage+1)+"&trail="+(currImagee+1)+""; 
}
</script>

</html>


<!-- TOUT LES 625 pts TU DEBLOQUES -->
