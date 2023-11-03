#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction caractere_le_plus_frequent(string const& filename)
// qui retourne une structure ou une paire (voir chapitre 7) qui
// contient le caractère (hors espace ' ') le plus fréquent dans ce fichier,
// ainsi que le nombre de fois qu'il apparait. Ce nombre est négatif
// si le fichier est illisible.

struct Caractere {
    char c;
    int nb;
};

int nb_char_in_file(string ligne, char c){
    int nb = 0;

    for (char c_ligne : ligne){
        if (c == c_ligne){
            ++nb;
        }
    }

    return nb;
}

Caractere caractere_le_plus_frequent(string const& filename){
    ifstream file(filename);

    if (!file) return Caractere{' ',-1};

    while (file) {
        string une_ligne;
        getline(file, une_ligne);

        for (char c_ligne : une_ligne){

        }
    }
}

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename;
   cin >> filename;

   auto [c, n] = caractere_le_plus_frequent(filename);
   if (n >= 0)
      cout << "Le caractère " << c
           << " est le plus fréquent et apparait " << n
           << " fois dans le fichier " << filename << endl;
   else
      cout << "Le fichier est illisible";
}