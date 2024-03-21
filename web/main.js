



function loadTextFile(filePath, callback) {
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function () {
    if (xhr.readyState === XMLHttpRequest.DONE) {
      if (xhr.status === 200) {
        callback(xhr.responseText);
      } else {
        console.error("Erreur lors du chargement du fichier");
      }
    }
  };
  xhr.open("GET", filePath, true);
  xhr.send();
}


// Fonction pour insérer le contenu Markdown dans une div
function insertMarkdownContent(content, targetId) {
  document.getElementById(targetId).innerText = content;
}

function escapeHtml(text) {
    return text.replace(/&/g, "&amp;")
               .replace(/</g, "&lt;")
               .replace(/>/g, "&gt;")
               .replace(/"/g, "&quot;")
               .replace(/'/g, "&#039;")
               .replace(/[#*]/g, "");
}


function processMarkdownContent(content) {
  var lines = content.split('\n');
  var processedContent = '';

  for (var i = 0; i < lines.length; i++) {
    var line = lines[i];

    // Vérifier si la ligne correspond à un titre (de ## à ######)
    var titleMatch = line.match(/^(#{1,6})\s(.*)$/);
    if (titleMatch) 
    {
      // Insérer une balise de titre correspondant au niveau de titre détecté
      var titleLevel = titleMatch[1].length; // Détermine le niveau du titre
      processedContent += '<h' + titleLevel + '>' + escapeHtml(titleMatch[2]) + '</h' + titleLevel + '>';
    } 
    else 
    {
      // Ligne telle quelle
      processedContent += escapeHtml(line);
    }



  }
  return processedContent;
}
// Appeler la fonction de chargement pour récupérer le fichier Markdown et insérer le contenu dans la div
loadTextFile('./README.md', function (textContent) {
  var processedContent = processMarkdownContent(textContent);
  var tex = document.getElementById('markdownContentA');
  tex.innerHTML = processedContent;
});
 
