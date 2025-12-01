/*
  Exercice 1 - Fraction

  Fournissez une implémentation d'une structure fraction représentant un nombre
  fractionnaire. Vous implémenterez sous forme de fonction ou d'opérateur
  surchargés les fonctionnalités suivantes:

  - addition fraction/fraction, entier/fraction, fraction/entier
  - soustraction fraction/fraction, entier/fraction, fraction/entier
  - multiplication fraction/fraction, entier/fraction, fraction/entier
  - division fraction/fraction, entier/fraction, fraction/entier
  - négation de fraction
  - conversion de la fraction en nombre réel double précision
  - insertion et extraction depuis un flux
*/

#include <iostream>

struct fraction
{
  int num, denom;

  // La fonction 
  operator double() const { 
    return static_cast<double>(num) / static_cast<double>(denom);
  }
};

/// ---------- ADDITIONS ---------- ///
// addition fraction/fraction
fraction operator+(fraction const& frac_gauche, fraction const& frac_droite)
{
  auto nv_num = frac_gauche.num * frac_droite.denom + frac_droite.num * frac_gauche.denom;
  auto nv_denom = frac_gauche.denom * frac_droite.denom;

  return {nv_num, nv_denom};
}

// addition entier/fraction
fraction operator+(int ent_gauche, fraction const& frac_droite)
{
  auto nv_num = ent_gauche * frac_droite.denom + frac_droite.num;
  
  return {nv_num, frac_droite.denom};
}

// addition fraction/entier
fraction operator+(fraction const& frac_gauche, int ent_droite)
{
  auto nv_num = ent_droite * frac_gauche.denom + frac_gauche.num;
  
  return {nv_num, frac_gauche.denom};
}

/// ---------- OPÉRATEURS DE FLUX ---------- ///
// Flux de sortie
std::ostream& operator<<(std::ostream &os, fraction const& f) {
  return os << "(" << f.num << "/" << f.denom << ")";
}

// Flux d'entrée 
std::istream& operator>>(std::istream &is, fraction& f) {
  return is >> f.num >> f.denom;
}

int main(int, char **) 
{
  // ----- Tests des additions ----- // 
  fraction f1{4, 3};
  fraction f2{1, 2};
  fraction f3 = f1 + f2;

  std::cout << "f1 + f2 = " << f3 << "\n";
  std::cout << "f1 + 3 = " << (f1 + 3) << "\n";
  std::cout << "1 + f2 = " << (1 + f2) << "\n";

  return 0;
}
