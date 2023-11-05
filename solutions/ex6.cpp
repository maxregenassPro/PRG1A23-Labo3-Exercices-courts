#include <iostream>

using namespace std;

// écrire la fonction multiplier qui permette au programme
// ci dessous de fonction comme dans l'exemple d'utilisation
// suivant. Vous ne pouvez pas utiliser d'autre type numérique
// que le type "unsigned int"
//
//2 3
//2 * 3 = 6
//543 876
//543 * 876 = 475668
//1234567 8765432
//Le produit de 1234567 et 8765432 depasse la limite du type unsigned

bool multiplier(unsigned a, unsigned b, unsigned& c) {
   if( numeric_limits<unsigned>::max() / a < b )
      return false;
   c = a * b;
   return true;
}

int main() {

   unsigned a, b, r;
   do {
      cin >> a >> b;
   } while (multiplier(a, b, r) and
            cout << a << " * " << b << " = " << r << endl);

   cout << "Le produit de " << a << " et " << b << " depasse la limite du type unsigned";
}