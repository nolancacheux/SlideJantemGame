
var dim =12;
var valid1= true;
var valid2 = false;
var div1 = document.querySelector('#uniquecreator');
var tab1 = document.createElement('tableCrea');

var tableaucrea = Array(dim);

var ligne = dim;
var colonne = dim;

var div2 = document.querySelector('#uniquejeu');

var tab2 = document.createElement('tableJeu');
div2.appendChild(tab2);

var tableaujeu = Array(dim);

var tr1 = document.createElement('tr');
var tr2 = document.createElement('tr');

var td1 = document.createElement('td');
var td2 = document.createElement('td');

var nbrail1=0;
var nbrail2=0;
var nombrerail1 = 0;
var nombrerail2 = 0;

var cBon = 1;

var creator = document.querySelector('#creator');

var sel1 = document.querySelector('#select1')
var sel2 = document.querySelector('#select2')

input = document.getElementById('bouton');
 
input.addEventListener('click', function(){
   input.style.display = 'none';
   document.getElementById("bouton2").style.display = "";
   document.getElementById("buttonjs").style.display = "";
   document.getElementById("Auto").style.display = "";
   document.getElementById("dim").style.display = "none";
});
document.getElementById("bouton2").style.display = "none";
document.getElementById("buttonjs").style.display = "none";
document.getElementById("Auto").style.display = "none";

function updateTextInput(val) {
	  document.getElementById('textInput').value=val; 
	}

function maFonction(){
	
	var saisie = document.querySelector("#zoneDeSaisie").value;
	dim = saisie;
	console.log(dim);
	main();
}


document.querySelector("#bouton").addEventListener("click",maFonction);

function main(){
		valid1= true;

		console.log("Jeu")
		div1 = document.querySelector('#uniquecreator');

		tab1 = document.createElement('tableCrea');
		div1.appendChild(tab1);

		tableaucrea = Array(dim);

		ligne = dim;
		colonne = dim;
				
		for(let i = 0; i < ligne; i++){
			tr1 = document.createElement('tr');
			tab1.appendChild(tr1);
			tableaucrea[i] = Array(dim);
			
			for(let j = 0; j < colonne; j++){
				td1 = document.createElement('td');
				tr1.appendChild(td1);
				td1.dataset['ligne'] = i;
				td1.dataset['column'] = j;
				tableaucrea[i][j] = td1;
			}
		}

		div2 = document.querySelector('#uniquejeu');

		tab2 = document.createElement('tableJeu');
		div2.appendChild(tab2);

		tableaujeu = Array(dim);
				
		for(let i = 0; i < ligne; i++){
			tr2 = document.createElement('tr');
			tab2.appendChild(tr2);
			tableaujeu[i] = Array(dim);
			
			for(let j = 0; j < colonne; j++){
				td2 = document.createElement('td');
				tr2.appendChild(td2);
				td2.dataset['ligne'] = i;
				td2.dataset['column'] = j;
				tableaujeu[i][j] = td2;
			}
		}

		nbrail1=0;
		nbrail2=0;
		nombrerail1 = 0;
		nombrerail2 = 0;
	
		initCreator();
		
		cl = 0;

		cBon = 1;

		creator = document.querySelector('#creator');
		creator.addEventListener('click', EnregistrementCrea);

		tab1.addEventListener('click', place);

		gamew = document.querySelector('#test2');
		gameo = document.querySelector('#test');


		sel1 = document.querySelector('#select1')
		sel2 = document.querySelector('#select2')

		gamew = document.querySelector('#test2');
		gameo = document.querySelector('#test');

}
//Verifie si le niveau est possible
//Fonction Fini//



//Convertie la grille de décors en numéro
//Fonction Fini
function convertNumberCrea(){

        var tabN = Array(dim);

        for (let i = 0; i < ligne; i++){

            tabN[i] = Array(dim);

            for (let j = 0; j < colonne; j++){

                var test = tableaucrea[i][j];

                if (test.classList.contains('block')){
                    tabN[i][j] = 1;
                }
                else if (test.classList.contains('teleporter')){
                    tabN[i][j] = 2;
                }
                else if (test.classList.contains('perso1')){
                    tabN[i][j] = 3;
                }
                else{
						tabN[i][j] = 0;
					}
            }
			//console.log(tabN[i]);
        }
		console.log(tabN);
        return tabN;
		
}

//fonction pour récup les données du php
var reeq = new XMLHttpRequest();
reeq.onload = function() {
    var truc = this.responseText;
}
reeq.open("GET", "php/countfilesauto.php", false);

reeq.send(null);

var nbFichiers = reeq.responseText-1;

//Convertie le tableau en créa
//Fonction Fini

function numberToCREATION(){

		//fonction pour récup les données dans le map.json
		var request = new XMLHttpRequest();
		request.open("GET", "php/map.txt", false);
		request.send(null)
		var file = request.responseText
        //console.log(file)

		// Scrap des données du TXT
		// Division des résultats en SixeX SizeY et map
		const arrayfile = Array.from(String(file), Number);


		const SizeX = arrayfile.splice(0, 2);
		const SizeY = arrayfile.splice(0, 2);

		var arr = arrayfile 
		interval = dim
		map = [];
		while (arr.length >= interval) {
		   map.unshift(arr.splice(-interval, interval));
		}
		map.unshift(arr);
		map.shift();
        console.log("MAP : ",map)

        var tabN = map;

        for (let i = 0; i < ligne; i++){

            for (let j = 0; j < colonne; j++){

                var test = tableaucrea[i][j];

                if (tabN[i][j]==1){
                    tabN[i][j] = 1;
					setJeu(j,i,1);
					tableaucrea[i][j].className = 'block';
                }
                else if (tabN[i][j]==2){
                    tabN[i][j] = 2;
					setJeu(j,i,2);
					tableaucrea[i][j].className = 'teleporter';
                }
                else if (tabN[i][j]==3){
                    tabN[i][j] = 3;
					setJeu(j,i,3);
					tableaucrea[i][j].className = 'perso1';
                }
                else{
					tabN[i][j] = 0;
					setJeu(j,i,0);
					tableaucrea[i][j].className = '';
				}
            }
			//console.log(tabN[i]);
        }
        console.log("TabN :");
		console.log(tabN);
        return tabN;
		
}
function randomtab(e){
    
        initCreator();

        var nbvides = 0;
		
        var tabN = Array(dim);

        for (let x = 0; x < ligne; x++){
            tabN[x] = Array(dim);
        }

        for (let i = 0; i < ligne; i++){

            for (let j = 0; j < colonne; j++){
                tabN[i][j] = 1;
            }
        }
        //Math.floor(Math.random() * (max - min + 1)) + min;
        var i = Math.floor( Math.random() * (dim-2)) + 1;
        var j = Math.floor( Math.random() * (dim-2)) + 1;

        console.log(i,j);
        tabN[i][j] = 3;
        setJeu(j,i,3);
        tableaucrea[i][j].className = 'perso1';
        console.log(tabN);

        while (nbvides != dim*6){
            
            var direction = Math.floor ( Math.random() * 4 );
            // 0 = Nord , 1 = Ouest , 2 = Sud , 3 = Est
            var enregistrement = 4;
            if (direction==0){
                if (enregistrement!=2 && i-1!=0){
                    i--;
                    enregistrement = 0;
                    nbvides++;
                }
            }
            if (direction==1){
                if (enregistrement!=3 && j-1!=0){
                    j--;
                    enregistrement = 1;
                    //nbvides++;
                }
            }
            if (direction==2){
                if (enregistrement!=0 && i+1!=ligne-1){
                    i++;
                    enregistrement = 2;
                    //nbvides++;
                }
            }
            if (direction==3 ){
                if (enregistrement!=1 && j+1!=colonne-1){
                    j++;
                    enregistrement = 3;
                    nbvides++;
                }
            }
            tabN[i][j] = 0;
            setJeu(j,i,0);
            tableaucrea[i][j].className = '';
            //console.log(tabN);
        }
		var perso = 0;
        var randomperso= Math.floor ( Math.random() * 10 );
        var compteur = 0;
        for (let i = 0; i < ligne; i++){
            for (let j = 0; j < colonne; j++){

                if ((tabN[i][j] == 0)&&(tabN[i-1][j-1] == 0)&&(tabN[i][j-1] == 0)
                &&(tabN[i+1][j-1] == 0)&&(tabN[i-1][j] == 0)&&(tabN[i+1][j] == 0)
                &&(tabN[i+1][j] == 0)&&(tabN[i-1][j+1] == 0)&&(tabN[i][j+1] == 0)){

                    tabN[i][j] = 1;
                    setJeu(j,i,1);
                    tableaucrea[i][j].className = 'block';
                    tabN[i][j+1] = 1;
                    setJeu(j+1,i,1);
                    tableaucrea[i][j+1].className = 'block';
                }
                if(tabN[i][j] == 0){
                    if((i==0)||(j==0)||(j==colonne-1)||(i==ligne-1)){
                        tableaucrea[i][j].className = 'block';
                        tabN[i][j] = 1;
                    }
                    else{
                        compteur++;
                        var randomtel = Math.floor ( Math.random() *10);

                        if((perso ==0)&&(randomperso== compteur)){
                            tableaucrea[i][j].className = 'perso1';
                            tabN[i][j] = 3;
                            perso++;
                        }
                    }
                }
                else{
                    tableaucrea[i][j].className = 'block';
                    tabN[i][j] = 1;
                }
            }
        }
        var tel = 0;
        for (let i = 0; i < ligne; i++){
            for (let j = 0; j < colonne; j++){

                var randomtel = Math.floor ( Math.random() * nbvides/4 );
                

                if(tabN[i][j] == 0){

                    if (randomtel == 1 && tel<2){
                        tableaucrea[i][j].className = 'teleporter';
                        tabN[i][j] = 2;
                        tel++;
                    }
                }
            }
        }

            
        return tabN;
}
//Sert a reset
//Fonction Fini//

function initCreator (e){
    console.log('Fonction initCreator faite');
    for (let i = 0; i < ligne; i++){
        for (let j = 0; j < colonne; j++){
			if((i==0)||(j==0)||(j==colonne-1)||(i==ligne-1)){
				tableaucrea[i][j].className = 'block';
			}
			else{
				tableaucrea[i][j].className = '';
			}
        }
    }
}


function resetcrea (e){
    valid2 = false;
    autoo = 0;
    initCreator();
    console.log('Fonction reset faite');
    nbrail1=0;
    nbrail1=0;

    if (gameo.classList.contains('over')){
    
        gameo.removeChild(texte);
        gameo.className='';
        
    }
    else if (gamew.classList.contains('win')){

        gamew.removeChild(texte);
        gamew.className='';
    }
}

function Try(){
    console.log("Fonction Try");
    if (cBon == 1){
        gamew.className = 'win';
    
        texte = document.createElement('h2');
        gamew.appendChild(texte);

        texte.innerHTML = 'You must Verify before'

    gamew.addEventListener('click', reset);
    }
    else if (cBon == 0){
    var modecrea = document.querySelector('.modecrea');
    modecrea.classList.add('invisible');
    var modejeu = document.querySelector('.modejeu');
    modejeu.classList.remove('invisible');
    if (gamew.classList.contains('win')){

        gamew.removeChild(texte);
        gamew.className='';
    }
    document.getElementById("nbrail1").innerHTML=nbrail1 + "x";
    document.getElementById("nbrail2").innerHTML=nbrail2 + "x";

    nombrerail1 = nbrail1;
    nombrerail2 = nbrail2;

    initJeu();
    }
}
function Save(){
    autoo =0;
    if (valid2){
	gameo.className = 'over';

    texte = document.createElement('h2');
    gameo.appendChild(texte);

    texte.innerHTML = 'Saved successfully'
    }
	convertNumberCrea();
    nbFichiers+=1;
    initJeu();
	//randomtab()
    
}
var autoo = 1;
function auto(e){

    if (valid2 && autoo !=1){

        gameo.removeChild(texte);
	    gameo.className='';
    }
    valid2 = true;
    autoo = 1;

    do{
        console.log('Fonction auto faite');

        var request = new XMLHttpRequest();
        
        request.open("GET", "php/auto.php?dim="+dim+"&nbFichiers="+nbFichiers, false);
        request.send(null)

        var request = new XMLHttpRequest();
        request.open("GET", "php/verifauto.php", false);
        request.send(null)
        var file = request.responseText

        file = file.split(" ")
        var result = file[0]
        var count = file[1]

        var tab = numberToCREATION();
        
        request.open("GET", "php/autoapres.php?array="+tab.join('|')+"&nbFichiers="+nbFichiers, false);
		request.send(null)


        var perso = 0;
        var tele = 0;
        var vide = 0;
        var falses = true;
    

     for (let i = 0; i < ligne; i++){
        for (let j = 0; j < colonne; j++){
            if(tab[i][j] == 3){
                perso++;
            }
            if(tab[i][j] == 0){
                vide++;
            }
            if(tab[i][j] == 2){
                tele++;
                if(tab[i-1][j]+tab[i+1][j]+tab[i][j-1]+tab[i][j+1]>=4){
                    falses = false;
                }
                else if ((tab[i-1][j-1] == 2)||(tab[i][j-1] == 2)
                    ||(tab[i+1][j-1] == 2)||(tab[i-1][j] == 2)||(tab[i+1][j] == 2)
                    ||(tab[i+1][j] == 2)||(tab[i-1][j+1] == 2)||(tab[i][j+1] == 2)){
                    falses = false;
                }
            }
        }
    }
    if (tele == 1){falses = false;}

    }while (perso==0 ||falses == false)
}
function randomtab2(e){
    
    initCreator();

    var nbvides = 0;
    
    var tabN = Array(dim);

    for (let x = 0; x < ligne; x++){
        tabN[x] = Array(dim);
    }

    //Math.floor(Math.random() * (max - min + 1)) + min;
    var i = Math.floor( Math.random() * (dim-2)) + 1;
    var j = Math.floor( Math.random() * (dim-2)) + 1;

    console.log(i,j);
    tabN[i][j] = 3;
    setJeu(j,i,3);
    tableaucrea[i][j].className = 'perso1';
    console.log(tabN);
    
    var nbtel = 0;
    var addtel = Math.floor ( Math.random() * 4 );
    while (nbvides != dim*6){
        
        var direction = Math.floor ( Math.random() * 4 );
        // 0 = Nord , 1 = Ouest , 2 = Sud , 3 = Est
        var enregistrement = 4;
        var compare = 4;
        if (direction==0){
            if (enregistrement!=2 && i-1!=0){
                i--;
                enregistrement = 0;
                nbvides++;
            }
        }
        if (direction==1){
            if (enregistrement!=3 && j-1!=0){
                j--;
                enregistrement = 1;
                //nbvides++;
            }
        }
        if (direction==2){
            if (enregistrement!=0 && i+1!=ligne-1){
                i++;
                enregistrement = 2;
                //nbvides++;
            }
        }
        if (direction==3 ){
            if (enregistrement!=1 && j+1!=colonne-1){
                j++;
                enregistrement = 3;
                nbvides++;
            }
        }

        if (addtel == 1 && nbtel!=2){
            addtel=0;
            nbtel+=2;
            tabN[i][j] = 2;
            setJeu(j,i,2);
            tableaucrea[i][j].className = 'teleporter';

            do{
                i = Math.floor( Math.random() * (dim-2)) + 1;
                j = Math.floor( Math.random() * (dim-2)) + 1;
            } while(tabN[i][j]==0 && tabN[i][j]==1)

            tabN[i][j] = 2;
            setJeu(j,i,2);
            tableaucrea[i][j].className = 'teleporter';
        }
        else{
            if (tabN[i][j] !=2 || tabN[i][j] !=1){
                tabN[i][j] = 0;
                setJeu(j,i,0);
                tableaucrea[i][j].className = '';
                // 0 = Nord , 1 = Ouest , 2 = Sud , 3 = Est
                if(compare!=enregistrement){
                    if(compare ==0){
                        tabN[i-1][j] = 1;
                        setJeu(j,i,1);
                        tableaucrea[i][j].className = 'block';
                    }
                    else if(compare ==1){
                        tabN[i][j-1] = 1;
                        setJeu(j,i,1);
                        tableaucrea[i][j].className = 'block';
                    }
                    else if(compare ==2){
                        tabN[i+1][j] = 1;
                        setJeu(j,i,1);
                        tableaucrea[i][j].className = 'block';
                    }
                    else if(compare ==3){
                        tabN[i][j+1] = 1;
                        setJeu(j,i,1);
                        tableaucrea[i][j].className = 'block';
                    }

                }
            }
            compare = enregistrement;
            addtel = Math.floor ( Math.random() * 4 );
        }
    }
    var perso = 0;
    var randomperso= Math.floor ( Math.random() * 10 );
    var compteur = 0;
    for (let i = 0; i < ligne; i++){
        for (let j = 0; j < colonne; j++){

            if ((tabN[i][j] == 0)&&(tabN[i-1][j-1] == 0)&&(tabN[i][j-1] == 0)
            &&(tabN[i+1][j-1] == 0)&&(tabN[i-1][j] == 0)&&(tabN[i+1][j] == 0)
            &&(tabN[i+1][j] == 0)&&(tabN[i-1][j+1] == 0)&&(tabN[i][j+1] == 0)){

                tabN[i][j] = 1;
                setJeu(j,i,1);
                tableaucrea[i][j].className = 'block';
                tabN[i][j+1] = 1;
                setJeu(j+1,i,1);
                tableaucrea[i][j+1].className = 'block';
            }

            if(tabN[i][j] == 0){
                if((i==0)||(j==0)||(j==colonne-1)||(i==ligne-1)){
                    tableaucrea[i][j].className = 'block';
                    tabN[i][j] = 1;
                }
                else{
                    compteur++;

                    if((perso ==0)&&(randomperso== compteur)){
                        tableaucrea[i][j].className = 'perso1';
                        tabN[i][j] = 3;
                        perso++;
                    }
                }
            }
            else{
                if(tabN[i][j] != 2){
                tableaucrea[i][j].className = 'block';
                tabN[i][j] = 1;
                }
            }
        }
    }

        
    return tabN;
}
//JEu
//Fonction fini
function initJeu (e){
            console.log("Fonction initJeu");
            for (let i = 0; i < ligne; i++){
				for (let j = 0; j < colonne; j++){
					if((i==0)||(j==0)||(j==colonne-1)||(i==ligne-1)){
						tableaucrea[i][j].className = 'block';
					}
					else{
						tableaucrea[i][j].className = '';
					}
				}
			}	
            for (let i = 0; i < ligne; i++){
    
                for (let j = 0; j < colonne; j++){
    
                    var test = tableaucrea[j][i];
    
                    if (test.classList.contains('block')){
                        setJeu(j,i,1);
                    }
                    else if (test.classList.contains('teleporter')){
                        setJeu(j,i,2);
                    }
                    else if (test.classList.contains('perso1')){
                        setJeu(j,i,3);
                    }
					else{
						 setJeu(j,i,0);
					}
                }
            }
    
        
}



//Convertie la grille de décors en numéro
//Fonction fini//
function convertNumberJeu(){

            var tabN = Array(dim);

            for (let i = 0; i < ligne; i++){

                tabN[i] = Array(dim);

                for (let j = 0; j < colonne; j++){

                    var test = tableaujeu[i][j];
					
					if (test.classList.contains('block')){
                        tabN[i][j] = 1;
                    }
                    else if (test.classList.contains('teleporter')){
                        tabN[i][j] = 2;
                    }
                    else if (test.classList.contains('perso1')){
                        tabN[i][j] = 3;
                    }
					else{
						tabN[i][j] = 0;
					}
                    
                }
				console.log(tabN[i]);
				
            }

            return tabN;
}
        
function resetJeu (e){
    console.log("Fonction ResetJeu");
    nbrail1 = nombrerail1;
    nbrail2 = nombrerail2;
            
    if (gameo.classList.contains('youlost')){
                
        gameo.removeChild(texte);
        gameo.className='';
    }
    else if (gamew.classList.contains('youwin')){

        gamew.removeChild(texte);
        gamew.className='';
    }
    
    document.getElementById("nbrail1").innerHTML=nbrail1 + "x";
    document.getElementById("nbrail2").innerHTML=nbrail2 + "x";

    initJeu();
}


//Fonction Fini
function obstacle(laCible){

            if (laCible.classList.contains('block')){
                return true;
            } 
}


    
//Fonction Fini
function setJeu(row, column, decor){
    var elt = tableaujeu[row][column];
    
    if (decor == 1){
        elt.className = 'block'
    }
    else if (decor == 2){
        elt.className = 'teleporter'
    }
    else if (decor == 3){
        elt.className = 'perso1';
    }
}



function over(e){
    
    gameo.className = 'over';
    
    texte = document.createElement('h2');
    gameo.appendChild(texte);
	if (valid1){
		texte.innerHTML = "GOOD"
	}
	else{
        texte.innerHTML = "DOESN'T WORK"
        resetJeu();

	}
    gameo.addEventListener('click', reset);
	

}

function gameready(e){
    
    gameo.className = 'good';
    
    texte = document.createElement('h2');
    gameo.appendChild(texte);

    texte.innerHTML = "Good"

    gameo.addEventListener('click', reset);
	
	return;

}

function youlost(e){
    
    gameo.className = 'youlost';
    
    texte = document.createElement('h2');
    gameo.appendChild(texte);

    texte.innerHTML = 'GAME OVER'

    gameo.addEventListener('click', reset);

}

function youwin(e){

    
    cBon = 0;
    console.log('cBon:',cBon);
    gamew.className = 'youwin';
    
    texte = document.createElement('h2');
    gamew.appendChild(texte);

    texte.innerHTML = 'You Win'

    gamew.addEventListener('click', reset);
}

function win(e){

    
    cBon = 0;
    console.log('cBon:',cBon);
    gamew.className = 'win';
    
    texte = document.createElement('h2');
    gamew.appendChild(texte);

    texte.innerHTML = 'Work'

    gamew.addEventListener('click', reset);
}

function GoCrea(){
    var modejeu = document.querySelector('.modejeu');
    modejeu.classList.add('invisible');
    var modecrea = document.querySelector('.modecrea');
    modecrea.classList.remove('invisible');
    nombrerail1 = 0;
    nombrerail2 = 0;
}


//Fonction Fini//
function place(e) {
    
    var laCible = event.target;
    var col = laCible.dataset.column;
    var li = laCible.dataset.ligne;
    cBon =0;
    setcrea(li, col, cl);       
}

//Fonction Fini//
//SETCREA//
function setcrea(row, column, decor){
	
	console.log("setcrea");
    var elt = tableaucrea[row][column];
    
    if (decor == 1){
        elt.className = 'block'
    }
    else if (decor == 2){
        elt.className = 'teleporter'
    }
    else if (decor == 3){
        elt.className = 'perso1';
    }
}

//Fonction Fini//
function EnregistrementCrea(e){

    var laCible = event.target

    if (laCible.classList.contains('block')){
        cl = 1;
        var currentCrea = document.querySelector('#currentCrea');
        currentCrea.className = 'block';
    }
    else if (laCible.classList.contains('teleporter')){
        cl = 2;
        var currentCrea = document.querySelector('#currentCrea');
        currentCrea.className = 'teleporter';
    }
	else if (laCible.classList.contains('perso1')){
        cl = 3;
        var currentCrea = document.querySelector('#currentCrea');
        currentCrea.className = 'perso1';
        
    }
else {
        return false;
    }
}
