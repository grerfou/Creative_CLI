import { loadTextFile } from "./import"

export function addElementToSidebar(text) {
  const sidebarList = document.getElementById("sidebarList");
  var length_title = loadTextFile.length;
    

  var liSidebar = document.createElement("li");
  var aSidebar = document.createElement("a");
  var backline = document.createElement("br");

  var i = 0;

  for (i = 0; i <= length_title; i++)
  {
    //aSidebar.href = "#";
    aSidebar.id = `test${i}`;
    //console.log("Valeur de i =", i);

    aSidebar.textContent = text;
    liSidebar.appendChild(aSidebar);
    sidebarList.appendChild(backline);
    sidebarList.appendChild(liSidebar);
  }
}
