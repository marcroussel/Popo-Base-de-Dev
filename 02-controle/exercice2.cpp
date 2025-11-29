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

void afficher_grille(std::array<std::array<char, 3>, 3> grille)
{
    std::cout << "___0___1___2_\n";

    // Parcours des lignes de la grille
    for (int i = 0; i < (int)grille.size(); i++)
    {
        std::cout << i << "|";

        // Parcours des cases de la ligne
        for (int j = 0; j < (int)grille[i].size(); j++)
        {
            std::cout << " " << grille[i][j] << " |";
        }

        std::cout << "\n_____________\n";
    }
}

int main(int, char **)
{

    // Q1
    // Définition de la grille
    std::array<std::array<char, 3>, 3> grille = {{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    }};

    // Q2
    // Variable définissant la fin
    bool fin = false;

    // Q3
    // Variable définissant le symbole à utiliser
    char symbole = 'X';

    // Variables définissant les coordonnées du prochain coup
    int col;
    int row;

    while (!fin)
    {

        // Q4
        // Affichage de la grille
        afficher_grille(grille);

        // Entrée utilisateur
        std::cout << "\n"
                  << symbole << ", à vous de jouer ! Sélectionnez les coordonnées de la case à jouer (colonne puis ligne) \n";

        std::cout << "Colonne : ";
        std::cin >> col;

        std::cout << "Ligne : ";
        std::cin >> row;

        // Boucle de redemande si présence d'erreur
        bool redemander = true;
        while (redemander)
        {

            // Vérification de la bonne saisie des coordonnées
            if (col <= 2 && col >= 0 && row <= 2 && row >= 0)
            {
                // Vérification que la case est bien vide
                if (grille[row][col] == ' ')
                {
                    redemander = false;
                    continue;
                }
            }

            if (redemander)
            {
                // Redemande à l'utilisateur
                std::cout << "Désolé, votre saisie est incorrecte. Sélectionnez les coordonnées de la case à jouer (colonne puis ligne) \n";

                std::cout << "Colonne : ";
                std::cin >> col;

                std::cout << "Ligne : ";
                std::cin >> row;
            }
        }
        
        // Changement de la valeur de la case
        grille[row][col] = symbole;

        // Déclaration du gagnant
        char gagnant = ' ';

        /// Vérifications de gain 
        // Par ligne
        for (int i = 0; i < (int)grille.size(); i++)
        {
            bool est_gagnant = true;
            char caractere_a_verif = grille[i][0];

            std::cout << "(i) DEBUG | caractere_a_verif = " << caractere_a_verif << "\n";

            for (int j = 1; j < (int)grille[i].size(); j++)
            {
                if (grille[i][j] != caractere_a_verif || caractere_a_verif == ' ') {
                    est_gagnant = false;
                }
            }

            std::cout << "(i) DEBUG | est_gagnant = " << est_gagnant << "\n";

            if (est_gagnant) {
                fin = true;
                gagnant = caractere_a_verif;
            }
        }

        // Par colonne
        for (int i = 0; i < (int)grille[i].size(); i++)
        {
            bool est_gagnant = true;
            char caractere_a_verif = grille[0][i];

            for (int j = 1; j < (int)grille.size(); j++)
            {
                if (grille[j][i] != caractere_a_verif || caractere_a_verif == ' ') {
                    est_gagnant = false;
                }
            }

            if (est_gagnant) {
                fin = true;
                gagnant = caractere_a_verif;
            }
        }

        // Par diagonale (haut-gauche | bas-droit)
        
        bool est_gagnant = true;
        char caractere_a_verif = grille[0][0];

        for (int i = 1; i < (int)grille.size(); i++)
        {
            if (grille[i][i] != caractere_a_verif || caractere_a_verif == ' ') {
                est_gagnant = false;
            }
        }

        if (est_gagnant) {
            fin = true;
            gagnant = caractere_a_verif;
        }

        est_gagnant = true;
        caractere_a_verif = grille[2][2];

        for (int i = 1; i  >= 0; i--)
        {
            if (grille[i][i] != caractere_a_verif || caractere_a_verif == ' ') {
                est_gagnant = false;
            }
        }

        if (est_gagnant) {
            fin = true;
            gagnant = caractere_a_verif;
        }

        // Vérification d'égalité (seulement si la fin n'est pas déclarée)
        if (!fin) {
            fin = true;
            for (int i = 0; i < (int)grille.size(); i++)
            {
                for (int j = 0; j < (int)grille[i].size(); j++)
                {
                    if (grille[i][j] == ' ') {
                        std::cout << "(i) DEBUG | (grille[i][j] == ' ') = " << (grille[i][j] == ' ') << "\n";
                        fin = false;
                        break;
                    }
                }
            }
        }

        // Vérification de fin
        if (fin) {
            afficher_grille(grille);
            
            if (gagnant == ' '){
                std::cout << "Égalité \n";
            }
            else {
                std::cout << "Félicitations, " << gagnant << ", vous avez gagné ! \n";
            }
            
        }

        else {
            // Q3
            // Changement de symbole à la fin du tour
            if (symbole == 'X')
            {
                symbole = 'O';
            }
            else
            {
                symbole = 'X';
            }
        }        
    }

    return 0;
}
