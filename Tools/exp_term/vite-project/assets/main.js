import { addElementToSidebar } from './sidebar.js'
import { getCommits } from './content.js'
import { loadTextFile, extractTitlesFromMarkdown} from './import.js'


var _Readme_Path = "../README.md";

const _Pat = "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";  // Personal access token
const GithubPseudo = "grerfou";     //  User Name
const GithubRepo = "Creative_CLI";  //  Repo name 



document.addEventListener("DOMContentLoaded", function() {
  
  addElementToSidebar("Commit");

  getCommits(GithubPseudo, GithubRepo, _Pat);
  addClickEventToSidebar();
});


function addClickEventToSidebar() {
  // Charger le fichier README.md et extraire les titres
  loadTextFile(_Readme_Path, function (textContent) {
    var title = extractTitlesFromMarkdown(textContent);
    
    // Ajouter les titres extraits à la barre latérale
    //title.forEach((title, index) => {
    title.forEach((title) => {
      addElementToSidebar(title); // Ajout de l'élément de titre à la barre latérale
    

      /*
      for (var i = 0; i < title.length; i ++){
        //addElementToSidebar(title); // Ajout de l'élément de titre à la barre latérale
        console.log(title.length);
      }

      */
      /*
      if (index = 0) {
        console.log("Et c'est 00000 pointer !!");
      } 
      else if (index == 1){
        console.log("Eyt c'est 11111 pointer !!");
      } else {
        console.log("Il marche pas ton machin");
      }
      */

    });

        //var el = document.getElementsByClassName("test"); 
        //console.log(el);
    
    /*

        el.addEventListener("click", function() {
          console.log("Clic sur le titre :", title);
        
          // Utilisation de l'index pour effectuer des actions différentes
          switch (index) {
            case 0:
              // Action spécifique pour le premier élément
              console.log("Premier titre");
              break;
            case 1:
              // Action spécifique pour le deuxième élément
              console.log("Deuxième titre");
              break;
            default:
              // Action par défaut pour les autres éléments
              console.log("Autre titre");
          }
        });

    */


 });
}










/*
 
telnet mapscii.me command line 


*/



/*

function displaySidebarItems(items) {
  items.forEach((item, index) => {
    console.log(`${index + 1}. ${item}`);
  });
}


*/
