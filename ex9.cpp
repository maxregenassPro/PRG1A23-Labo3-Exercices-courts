#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction nb_char_in_file(filename, c) qui compte le nombre
// de fois que la caractère c apparait dans le fichier. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier

int nb_char_in_file(string filename, char c){
    ifstream file_in(filename);
    int nb = 0;

    if (!file_in) return -1;

    while (file_in) {
        string une_ligne;
        getline(file_in, une_ligne);

        for (char c_ligne : une_ligne){
            if (c == c_ligne){
                ++nb;
            }
        }
    }

    return nb;
}

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename; cin >> filename;
   cout << "Entrez le caractère : " << flush;
   char c; cin >> c;

   auto n = nb_char_in_file(filename,c);
   if(n >= 0)
      cout << "Le fichier contient " << n << " fois le caractère " << c << endl;
   else
      cout << "Le fichier est illisible";
}