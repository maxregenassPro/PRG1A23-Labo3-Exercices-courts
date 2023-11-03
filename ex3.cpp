#include <iostream>

using namespace std;

// écrire la fonction plus_petite_lettre(str) qui retourne
// le plus petite caractère (au sens du code ASCII) de la chaine
// str. Si cette lettre apparait plusieurs fois c'est la
// dernière instance qui doit être retournée.

char& plus_petite_lettre(string& str){
    unsigned long long lettre = 0;

    for (unsigned long long i = 0; i < str.size(); ++i) {
        if (str[i] <= str[lettre]){
            lettre = i;
        }
    }

    return str[lettre];
}

int main() {

   string s{"wisigoth"};
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche wisi*oth

   s = "abraracourcix";
   plus_petite_lettre(s) = '*';
   cout << s << endl;
   // affiche abrar*courcix
}