
var dim =12;
var valid1= true;

var text = false;

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

var cBon = 0;

var creator = document.querySelector('#creator2');

var sel1 = document.querySelector('#select1')
var sel2 = document.querySelector('#select2')

input = document.getElementById('bouton');
 
input.addEventListener('click', function(){
   input.style.display = 'none';
   document.getElementById("bouton2").style.display = "";
   document.getElementById("buttonjs").style.display = "";
   document.getElementById("creator2").style.display = "";
   document.getElementById("dim").style.display = "none";
});
document.getElementById("bouton2").style.display = "none";
document.getElementById("buttonjs").style.display = "none";
document.getElementById("creator2").style.display = "none";
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
		initCreator();
		
		nbrail1=0;
		nbrail2=0;
		nombrerail1 = 0;
		nombrerail2 = 0;

		cl = 0;

		cBon = 0;

		creator = document.querySelector('#creator');
		creator.addEventListener('click', EnregistrementCrea);

		tab1.addEventListener('click', place);

		gamew = document.querySelector('#test2');
		gameo = document.querySelector('#test');


		sel1 = document.querySelector('#select1')
		sel2 = document.querySelector('#select2')

		gamew = document.querySelector('#test2');
		gameo = document.querySelector('#test');

        texte = document.createElement('h2');
        gamew.appendChild(texte);

        texte.innerHTML = ''

}
//Verifie si le niveau est possible
//Fonction Fini//


function verifCreator (e){

    text = true;
	console.log("Verif fonction")
    convertNumberCrea();
    var request = new XMLHttpRequest();
    request.open("GET", "php/verif.php", false);
    request.send(null)
    var file = request.responseText

    file = file.split(" ")
    console.log(file)
    var result = file[0]
    console.log(result)
    var count = file[1]

    if (result==0){
        valid1= false;
        cBon =0;
    }
    else{
        valid1=true;
        cBon =1;
    }
		
    if (gameo.classList.contains('over')){
    
        gameo.removeChild(texte);
        gameo.className='';
    }
    over();

}  

//fonction pour récup les données du php
var reeq = new XMLHttpRequest();
reeq.onload = function() {
    var truc = this.responseText;
}
reeq.open("GET", "php/countfiles.php", false);

reeq.send(null);

var nbFichiers = reeq.responseText-1;

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
				else if (test.classList.contains('vide')){
                    tabN[i][j] = 0;
                }
                else{
					tabN[i][j] = 0;
				}
            }
        }

		var request = new XMLHttpRequest();
        
		//console.log("php/manual.php?array="+tabN.join('|')+"&nbFichiers="+nbFichiers);
		//window.location.assign("php/manual.php?array="+tabN.join('|')+"&nbFichiers="+nbFichiers);
		request.open("GET", "php/manual.php?array="+tabN.join('|')+"&nbFichiers="+nbFichiers, false);
		request.send(null)
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

    initCreator();
    console.log('Fonction reset faite');
    nbrail1=0;
    nbrail1=0;

    
    if (text){
        gameo.removeChild(texte);
        gameo.className='';
        text = false;
    }
    else{
        if (gameo.classList.contains('over')){
        
            gameo.removeChild(texte);
            gameo.className='';
            text = false;
            
        }
        else if (gamew.classList.contains('win')){

            gamew.removeChild(texte);
            gamew.className='';

            text = false;
        }
    }
}

function Try(){
    console.log("Fonction Try");
    if (cBon == 0){
        gamew.className = 'win';
    
        texte = document.createElement('h2');
        gamew.appendChild(texte);

        texte.innerHTML = 'You must Verify before'

    gamew.addEventListener('click', reset);
    }
    else if (cBon == 1){
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
	
    
    if (text){
        gameo.removeChild(texte);
        gameo.className='';
        text = false;
    }
	
    if (cBon == 0){
        gameo.className = 'over';
    
        texte = document.createElement('h2');
        gameo.appendChild(texte);

        texte.innerHTML = 'You must Verify before'

		gameo.addEventListener('click', reset);
        text = true;

        
    }
    else if (cBon == 1){

    gameo.className = 'over';

    texte = document.createElement('h2');
    gameo.appendChild(texte);

    texte.innerHTML = 'Saved successfully'
    text = true;

    gameo.addEventListener('click', reset);
    gameo.removeChild(texte);
	gameo.className='';

    
    convertNumberCrea();
    initJeu();
	nbFichiers+=1;
	
	//randomtab()
	
	
    }
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
					else if (test.classList.contains('vide')){
                        setJeu(j,i,0);
                    }
					else{
						 setJeu(j,i,0);
					}
                }
            }
    
        
}



//Verifie si le niveau est possible
//Fonction fini
function verif(e){
      
	if (gameo.classList.contains('youlost')){
	
		gameo.removeChild(texte);
		gameo.className='';
        text = false;
	}
	youlost();
        
}

//Convertie la grille de décors en numéro
//Fonction fini//
function convertNumberJeu(){
			
			 console.log("Fonction convertNumberJeu");
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
					else if (test.classList.contains('vide')){
                        tabN[i][j] = 0;
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
        
    if (text){
    gameo.removeChild(texte);
    gameo.className='';

    text = false;
    }

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
	
  

	console.log("Fonction setJeu");
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
	else if (decor == 0){
        elt.className = 'vide';
    }
}



function over(e){
    
	console.log("Fonction over");
    gameo.className = 'over';
    
    texte = document.createElement('h2');
    gameo.appendChild(texte);
	if (valid1){
		texte.innerHTML = "GOOD"
	}
	else{
    texte.innerHTML = "DOESN'T WORK"
	}
    gameo.addEventListener('click', reset);
	

}

function gameready(e){
    
	console.log("Fonction gameready");
    gameo.className = 'good';
    
    texte = document.createElement('h2');
    gameo.appendChild(texte);

    texte.innerHTML = "Good"

    gameo.addEventListener('click', reset);
	
	return;

}

function youlost(e){
    
	console.log("Fonction youlost");
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
    
	console.log("Fonction place");
    var laCible = event.target;
    var col = laCible.dataset.column;
    var li = laCible.dataset.ligne;
    cBon =0;
    setcrea(li, col, cl);       
}

//Fonction Fini//
//SETCREA//
function setcrea(row, column, decor){
    var elt = tableaucrea[row][column];
    
    console.log("Fonction setcrea");
	
	if((row==0)||(column==0)||(row==dim-1)||(column==dim-1)){
	
		elt.className = 'block'
	}
	else{
		if (decor == 1){
			elt.className = 'block'
		}
		else if (decor == 2){
			elt.className = 'teleporter'
		}
		else if (decor == 3){
			elt.className = 'perso1';
		}
		else if (decor == 0){
			elt.className = 'vide';
		}
	}
}

//Fonction Fini//
function EnregistrementCrea(e){


    if (text){
        gameo.removeChild(texte);
        gameo.className='';
        text = false;
        console.log("Il y a un texte");
    }
    
	console.log("Fonction enregistrementcrea");
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
    else if (laCible.classList.contains('vide')){
        cl = 0;
        var currentCrea = document.querySelector('#currentCrea');
        currentCrea.className = 'vide';
        
    }
else {
        return false;
    }
}
