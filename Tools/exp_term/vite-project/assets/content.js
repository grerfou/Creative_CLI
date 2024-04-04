
function addElementToContent(title, text, date, file_modif, modif) {
  const content = document.getElementById("content");

  const divContent = document.createElement("div");
  divContent.classList.add('conte');
  divContent.innerHTML = ` 
    <h1 class="title">
      ${title}
    </h1>
    <h3 class="date">${date}</h3>
    <p class="text">${text}</p>
    <p class="file-modif"> <br> File Modified: <br> ${file_modif} <br></p>
    <p class="modif"><br>Modifications: <br> ${modif}<br></p>
  `;

  content.appendChild(divContent);
}

export async function getCommits(owner, repo, pat) {
  try {
    const accessToken = pat; // Remplacez VOTRE_CLE_API_GITHUB par votre propre clé API GitHub

    const response = await fetch(`https://api.github.com/repos/${owner}/${repo}/commits`, {
      headers: {
        Authorization: `token ${accessToken}`
      }
    });
    const data = await response.json();
    
    if (response.ok) {
      for (const commit of data) {
        // Obtention des détails du commit
        const commitDetailsResponse = await fetch(commit.url, {
          headers: {
            Authorization: `token ${accessToken}`
          }
        });
        const commitDetails = await commitDetailsResponse.json();

        // Récupération des informations sur les fichiers modifiés et les modifications
        const filesModified = commitDetails.files.map(file => file.filename).join(', ');
        const modifications = commitDetails.files.map(file => file.changes).join(', ');

        addElementToContent(
          commitDetails.commit.author.name, 
          commitDetails.commit.message, 
          commitDetails.commit.author.date, 
          filesModified, 
          modifications
        );
      }
    } else {
      console.error(`Failed to fetch commits: ${data.message}`);
    }
  } catch (error) {
    console.error(`Error fetching commits: ${error}`);
  }
}
