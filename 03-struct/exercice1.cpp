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
  auto nv_num = frac_gauche.num + ent_droite * frac_gauche.denom;
  
  return {nv_num, frac_gauche.denom};
}



/// ---------- SOUSTRACTION ---------- ///
// soustraction fraction/fraction
fraction operator-(fraction const& frac_gauche, fraction const& frac_droite)
{
  auto nv_num = frac_gauche.num * frac_droite.denom - frac_droite.num * frac_gauche.denom;
  auto nv_denom = frac_gauche.denom * frac_droite.denom;

  return {nv_num, nv_denom};
}

// soustraction entier/fraction
fraction operator-(int ent_gauche, fraction const& frac_droite)
{
  auto nv_num = ent_gauche * frac_droite.denom - frac_droite.num;
  
  return {nv_num, frac_droite.denom};
}

// soustraction fraction/entier
fraction operator-(fraction const& frac_gauche, int ent_droite)
{
  auto nv_num = frac_gauche.num - ent_droite * frac_gauche.denom;
  
  return {nv_num, frac_gauche.denom};
}



/// ---------- MULTIPLICATION ---------- ///
// multiplication fraction/fraction
fraction operator*(fraction const& frac_gauche, fraction const& frac_droite)
{
  return {frac_gauche.num * frac_droite.num, frac_gauche.denom * frac_droite.denom};
}

// multiplication entier/fraction
fraction operator*(int ent_gauche, fraction const& frac_droite)
{
  return {ent_gauche * frac_droite.num, frac_droite.denom};
}

// multiplication fraction/entier
fraction operator*(fraction const& frac_gauche, int ent_droite)
{
  return {frac_gauche.num * ent_droite, frac_gauche.denom};
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
  std::cout << "\n// ----- Tests des additions ----- //\n";
  fraction f1{4, 3};
  fraction f2{1, 2};
  fraction f3 = f1 + f2;

  std::cout << "f1 + f2 = " << f3 << "\n";
  std::cout << "f1 + 3 = " << (f1 + 3) << "\n";
  std::cout << "1 + f2 = " << (1 + f2) << "\n";

  std::cout << "// ----- Tests des soustractions ----- //\n";
  fraction f4{8, 6};
  fraction f5{2, 3};
  fraction f6 = f4 - f5;

  std::cout << "f4 - f5 = " << f6 << "\n";
  std::cout << "f4 - 2 = " << (f4 - 2) << "\n";
  std::cout << "1 - f5 = " << (1 - f5) << "\n";

  std::cout << "// ----- Tests des multiplications ----- //\n";
  
  std::cout << "f1 * f5 = " << (f1 * f5) << "\n";
  std::cout << "f4 * 2 = " << (f4 * 2) << "\n";
  std::cout << "-1 * f5 = " << ((-1) * f5) << "\n";

  return 0;
}
