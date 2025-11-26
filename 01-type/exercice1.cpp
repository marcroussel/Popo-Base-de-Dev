/*
  Exercice 1 - Type de bases

  Le programme suivant calcule la moyenne de 10 valeurs numériques.
  Le résultat est ensuite affiché.

  Q1 - Le résultat est il correct ?
  Non, le résultat devrait être 6,9.

  Q2 - Quelle est la source de l'erreur ?
  La source d'erreur est que la variable "moyenne" est un int (nombre entier), 
  et devrait être un float (nombre flottant).

  Q3 - Corrigez le code afin d'obtenir le bon résultat.
  Oui chef.
*/

#include <iostream>

int main(int, char **) {
  float moyenne = 0;

  moyenne = moyenne + 3;
  moyenne = moyenne + 5;
  moyenne = moyenne + 1;
  moyenne = moyenne + 9;
  moyenne = moyenne + 4;
  moyenne = moyenne + 2;
  moyenne = moyenne + 8;
  moyenne = moyenne + 17;
  moyenne = moyenne + 9;
  moyenne = moyenne + 11;

  std::cout << "La somme est: " << moyenne << "\n";

  moyenne = moyenne / 10.0f; // On force 10 à être float

  std::cout << "La moyenne est: " << moyenne << "\n";

  return 0;
}
