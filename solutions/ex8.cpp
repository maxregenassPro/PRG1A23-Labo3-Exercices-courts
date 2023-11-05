#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction qui compte le nombre lignes d'un fichier
// dont le nom est passé en paramètre. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier

int nb_lignes(string const& filename) {
   ifstream file(filename);
   if(!file) return -1;
   int cnt = 0;
   string s;
   while(getline(file,s)) ++cnt;
   return cnt;
}

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename; cin >> filename;
   auto n = nb_lignes(filename);
   if(n >= 0)
      cout << "Le fichier contient " << n << " lignes" << endl;
   else
      cout << "Le fichier est illisible";
}