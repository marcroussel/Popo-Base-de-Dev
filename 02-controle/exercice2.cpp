/*
  Exercice 2 - Morpion

  Nous allons écrire un jeu simpliste de morpion. Le morpion est un jeu à deux
  joueurs qui consiste, à tour de rôle, de poser une croix (X) ou un rond (O)
  dans une grille 3x3. Un joueur gagne s'il aligne 3 symboles identiques en
  ligne, colonne ou diagonale.

  Q1 - Définissez un type 'grille' à base de std::array pour représenter la
  grille de jeu

  Q2 - Créez une valeur booléenne 'fin' valant false. Utilisez-la dans une
  boucle while dont la condition d'arrêt est le fait que cette variable vaille
  true. Vérifiez que le programme ne s'arrête pas.

  Q3 - Créez à l'endroit adéquat une variable 'symbole' de type char. Cette
  variable vaut 'X' au démarrage. Faites en sorte que, à chaque tour de boucle
  while, sa valeur alterne entre 'X' et 'O'.

  Q4 - Modifiez la boucle afin d'afficher un texte invitant le symbole courant à
  entrer sa position de jeu. Lisez ensuite une paire d'entiers entre 0 et 2.
  Cette paire d'entiers représente la coordonnée (x,y) dans la grille où le
  symbole courant doit être placé.

  Q5 - Construisez à l'endroit adéquat une variable de type 'grille' et mettez à
  jour sa valeur et affichez la à chaque itération.

  Q6 - Implémentez une série de tests qui vérifie après chaque coup si le joueur
  courant a gagné. Si c'est le cas, annoncez sa victoire et mettez la variable
  fin à true pour arrêter le jeu.

  QBONUS - Ajoutez tous les tests nécessaires à la capture des erreurs dues à
  l'entrée des positions des joueurs : case hors grille, case déjà utilisée, etc
  ...
*/

#include <array>
#include <iostream>

int main(int, char **) { return 0; }
