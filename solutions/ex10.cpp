#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction caractere_le_plus_frequent(string const& filename)
// qui retourne une structure ou une paire (voir chapitre 7) qui
// contient le caractère (hors ' ') le plus fréquent dans ce fichier,
// ainsi que le nombre de fois qu'il apparait. Ce nombre est négatif
// si le fichier est illisible.

int nb_char_in_file(string const& filename, char c) {
   ifstream file(filename);
   int cnt{};
   char d;
   while(file.get(d))
      if(c == d)
         ++cnt;
   return cnt;
}

pair<char,int> caractere_le_plus_frequent(string const& filename) {
   ifstream file(filename);
   if(!file) return { 0, -1 }; // illisible

   int r = -1;
   int r_cnt = 0;
   for(int c = 0; c < 256; ++c) { // pas en char, sinon boucle infinie
      if(c == 32) continue;
      int c_cnt = nb_char_in_file(filename,c);
      if(c_cnt > r_cnt) {
         r_cnt = c_cnt;
         r = c;
      }
   }
   return {r, r_cnt};
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