/*
  Exercice 2 - Tableau 2D

  On désire implémenter un tableau dynamique à deux dimensions. Pour ce faire,
  on considérera qu'un tableau 2D se stocke dans un tableau dynamique standard
  et que, lorsque sa largeur et sa hauteur sont disponibles, on peut calculer la
  position linéaire n d'un élément de coordonnées (i,j) par la formule :

    n = i*largeur + j

  Q1 - Proposez une structure tableau2D qui suit cette spécification.

  Q2 - Surchargez l'opérateur () pour accéder à l'élément (i,j) du tableau.

  Q3 - Surchargez l'opérateur d'insertion de flux afin d'affichez vos tableaux

  Q4 - Fournissez sous forme de fonction un moyen d'obtenir la somme des
  éléments du tableau

  Q5 - Implémentez les fonctions membres begin() et end()
  permettant d'utiliser votre structure dans une boucle for par interval
*/

#include <iostream>
#include <vector>

// Q1 
struct Tableau2D {
  std::vector<int> tableau;
  int hauteur;
  int largeur;

  Tableau2D(std::vector<int> tableau, int largeur, int hauteur) {
    this->tableau = tableau;
    this->largeur = largeur;
    this->hauteur = hauteur;
  }

  // Q2
  int operator()(int i, int j) {
    return tableau[i * this->largeur + j];
  };

  // Q3
  std::ostream& operator<<(std::ostream& os) {
    std::string string_to_return = "";

    for 
  }
};

int main(int, char **) {
  
  return 0;
}
