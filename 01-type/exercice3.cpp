/*
  Exercice 3 - Manipulation de tableaux de taille fixe (ne pas utiliser vector)

  Q1 - Utilisez std::array pour définir un tableau de 3 éléments de type double

  Q2 - Utilisez std::array pour définir un tableau de 3 éléments de type tableau
  de 3 doubles

  Q3 - Définissez un alias de type nommé vec3 pour le type array de 3 éléments
  de type double (appelé improprement vecteur dans la suite)

  Q4 - Utilisez le type ainsi défini pour créer une variable v contenant le
  vecteur suivant:

  | 2.5 |
  | 0.6 |
  | 1.1 |

  Q5 - Définissez un alias de type nommé mat33 pour le type matrice de 3x3
  éléments de type double
  Q6 - Utilisez le type ainsi défini pour créer une variable m contenant la
  matrice suivante :

  | 1 2 1 |
  | 2 4 6 |
  | 1 2 0 |

  Q7 - Calculez le produit de la matrice m et du vecteur v ainsi défini dans un
  vecteur res

  Q8 - Vérifiez votre résultat
*/

#include <array>
#include <iostream>

int main(int, char **) {
  // Q1
  std::array<double, 3> tab_double;

  // Q2
  std::array< std::array<double, 3> , 3> matrice33_double;

  // Q3
  using vec3 = std::array<double, 3>;

  // Q4
  vec3 v = {2.5, 0.6, 1.1};

  // Q5
  using mat33 = std::array< std::array<double, 3> , 3>;

  // Q6
  mat33 m = {vec3{1, 2, 1}, vec3{2, 4, 6}, vec3{1, 2, 0}};

  // Q7
  vec3 res = {};

  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)m.size(); j++) {
      res[i] += v[i]*m[j][i];
    }
  }
  
  // Q8
  std::cout << res[0] << "\n";
  std::cout << res[1] << "\n";
  std::cout << res[2] << "\n";

  return 0;
}
