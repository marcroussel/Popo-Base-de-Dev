/*
  Exercice 2 - Manipulation de chaines de caractères

  Q1 - Construisez une variable de type chaine contenant 10 symboles '#'

  Q2 - Construisez une variable de type chaine contenant deux symboles '#'
  séparés par 8 espaces

  Q3 - En vous aidant des variables ci-dessus, affichez le motif suivant :

  ##########
  #        #
  #        #
  #        #
  ##########

  Q4 - En vous aidant du code précédent, construisez une variable de type chaine
  de caractère contenant ce motif et affichez-la.
*/

#include <iostream>
#include <string>

int main(int, char **) {
  // Q1
  std::string trait_horizontal = "##########";
  
  // Q2
  std::string trait_vertical = "#        #";

  // Q3
  std::cout << trait_horizontal << "\n";

  for (int i=0; i<3; i++) {
    std::cout << trait_vertical << "\n";
  }

  std::cout << trait_horizontal << "\n";

  // Q4
  std::string motif = trait_horizontal + "\n";
  for (int i=0; i<3; i++) {
    motif += trait_vertical + "\n";
  }
  motif += trait_horizontal + "\n";

  std::cout << motif;

  /// CORRECTION 
  auto end = std::string(10, '#') + '\n';
  auto mid = "#" + std::string(8, ' ') + "#\n";

  auto motif_correct = end + mid + mid + mid + end;
  std::cout << motif;

  return 0;
}
