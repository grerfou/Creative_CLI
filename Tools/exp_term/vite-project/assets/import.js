
export function loadTextFile(filePath, callback) {
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

export function extractTitlesFromMarkdown(content) {
  var lines = content.split('\n');
  var titles = [];

  for (var i = 0; i < lines.length; i++) {
    var line = lines[i];

    // Vérifier si la ligne correspond à un titre (de ## à ######)
    var titleMatch = line.match(/^(#{1,6})\s(.*)$/);
    if (titleMatch) {
      // Ajouter le titre à la liste des titres
      titles.push(titleMatch[2]);
    }
  }
  return titles;
}

