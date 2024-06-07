function ciao() {
    alert("Ciao");
}

let nome = 10.0;

console.log(nome === 10);

nome = `Alessandro`;
let testo = `<h1>Ciao ${nome}, come va?</h1>`;

//document.body.innerHTML = testo; //cancella il resto della roba in html

let data = ['Milano', 'Napoli', 'Palermo'];

for(i=0; i<data.length; i++) console.log(data[i]);

let citta = 'Milano,Napoli,Palermo';

console.log(citta.split(",")); //prende un elemento in comune e separa gli elementi estranei e li mette in un array 
console.log(data.join("-")); //prende gli elementi di un array e li unisce in una stringa separati da qualcosa

data.push("Firenze"); //Aggiunge un elemento alla fine dell'array
console.log(data);

data.pop("Firenze"); //Elimina un elemento alla fine dell'array
console.log(data);

data.unshift("Firenze"); //Aggiunge un elemento all'inizio dell'array
console.log(data);

data.shift(); //Elimina un elemento all'inizio dell'array
console.log(data);


const myButton = document.querySelector('button');

myButton.onclick = function(){ //Funzione anonima (non ha nome);
    alert("Hello");
}

nome = 'Ale'; //Variabile fuori funzione è globale, dentro funzione utilizzabile solo nella funzione

function hello() {
    let cognome = 'popa';
    console.log("Ciao " + nome);
    saluta(cognome);
}

function saluta(nome) {
    console.log("Ciao " + nome);
}

hello();
saluta(nome);