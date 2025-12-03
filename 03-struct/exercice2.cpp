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

};

// Q3
  std::ostream& operator<<(std::ostream& os, Tableau2D const& tab) {
    
    std::string str_to_return = "";

    // Pour chaque ligne
    for (int current_i = 0; current_i < tab.hauteur; current_i++) {

      // Pour chaque colonne, ou case de la ligne
      for (int current_j = 0; current_j < tab.largeur; current_j++) {

        // Si la case dépasse la borne maximale du tableau, on renvoie '?'
        if ((current_i * tab.largeur + current_j) >= tab.tableau.size()) {
          str_to_return += "?";
        }
        else {
          str_to_return += tab(current_i, current_j);
        }

        str_to_return += ";";
      };

      str_to_return += "\n";
    }

    return os << str_to_return;
  }

int main(int, char **) {
  
  Tableau2D tab1 = {{2, 8, 6, 1, 1, 7, 5, 14, 9}, 3, 3};

  std::cout << tab1;

  return 0;
}
