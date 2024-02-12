<!DOCTYPE html>
<html lang="en">

    <head>
        <meta charset="utf-8">
        <style>
        .backindex{
            background: no-repeat center center fixed; 
            text-align: center;
            background-size: cover;
            /* background-image: url('../code/jantemcode/image/1.gif'); */
            z-index: 10;
        }

        .main{
            z-index: 15;
        }

        .loader {
            position: fixed;
            width: 100%;
            height: 100%;
            opacity: 1;
            animation: cloudtransparency 2s 1;
            z-index: 0;
            visibility: hidden;
        }
        .loaderr {
            position: fixed;
            width: 100%;
            height: 100%;
            opacity: 1;
            animation: cloudtransparency 1.3s 1;
            z-index: 10000;
            visibility: visible;
        }

        .left{
            position: absolute;
            z-index: 19;
            width: 100%;
            height: 100%;
            top: -1%;
            left: -1%;
            background: url("../Milo/image/left.png");
            background-size: 100%;
            animation: cloudL 2s 1;
        }
        .right{
            position: absolute;
            z-index: 19;
            width: 100%;
            height: 100%;
            top: -1%;
            background: url('../Milo/image/right.png');
            background-size: 100%;
            animation: cloudR 2s 1;
        }

        .leftt{
            position: absolute;
            z-index: 19;
            width: 100%;
            height: 100%;
            top: -1%;
            left: -1%;
            background: url("../Milo/image/left.png");
            background-size: 100%;
            animation: cloudLL 1.3s 1;
        }
        .rightt{
            position: absolute;
            z-index: 19;
            width: 100%;
            height: 100%;
            top: -1%;
            right: 0%;
            background: url('../Milo/image/right.png');
            background-size: 100%;
            animation: cloudRR 1.3s 1;
        }


        @keyframes cloudL {
            0% {
                left: -1%;
                z-index: 100000;
            }
            10% {
                left: -1%;
            }
            100% {
                left: -100%;
            }
        }
        @keyframes cloudR {
            0% {
                right: 0%;
                z-index: 100000;
            }
            10% {
                right: 0%;
            }
            100% {
                right: -100%;
            }
        }

        @keyframes cloudLL {
            0% {
                left: -100%;
                z-index: 100000;
            }
            10% {
                left: -100%;
            }
            100% {
                left: -1%;
            }
        }
        @keyframes cloudRR {
            0% {
                right: -100%;
                z-index: 100000;
            }
            10% {
                right: -100%;
            }
            100% {
                right: 0%;
            }
        }

        @keyframes cloudtransparency {
            0% {
                opacity: 1;
                z-index: 10000;
                visibility: visible;
            }
            50% {
                opacity: 1;
                z-index: 0;
            }
            99% {
                opacity: 1;
            }
            100% {
                opacity: 0;
            }
        }
        </style>
    </head>

    <body>
        <div id="loader" class="loader">
            <div id="left" class="left"></div>
            <div id="right" class="right"></div>
        </div>
    </body>
</html>