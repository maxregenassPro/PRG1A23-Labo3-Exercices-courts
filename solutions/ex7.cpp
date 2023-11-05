#include <iostream>

using namespace std;

// ecrire la fonction en_base(n,b) qui retourne sous forme
// de std::string la représentation en base b de l'entier n.
// Cette fonction doit fonctionner pour n positif ou nul et
// pour b entre 2 et 36. Les chiffres de 10 à 35 utilisent
// les lettres majuscules de A à Z.

string en_base(int n, int b) {
   string r{};
   while(n) {
      int d = n % b;
      char c = d + ( d >= 10 ? 'A'-10 : '0');
      r = c + r;
      n /= b;
   }
   if(r.empty())
      r+= '0';
   return r;
}

int main() {

  for(int b = 2; b <= 36; ++b)
  {
     cout << 42 << " en base " << b << " = " << en_base(42,b) << endl;
  }
   cout << 0 << " en base " << 7 << " = " << en_base(0,7) << endl;

}