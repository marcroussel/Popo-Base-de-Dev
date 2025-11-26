#include <array>
#include <iostream>
#include <vector>

/**
Exercice 5 - Structures de contrôle et vecteurs

  Pour chaque fonction, utilisez les éléments de l'interface des conteneurs
adéquats et les structures de contrôle adéquates pour répondre à la
problématique des fonctions.

  Pensez à tester les éventuels corner cases.
**/

std::array<int, 4> revert(std::array<int, 4> const &tab) {
  // Renvoyer un array contenant les valeurs de tab rangées dans l'ordre inverse
  std::array<int, 4> inverted_tab;
  int tab_size = tab.size();
  for(int i = 0; i < tab_size; i++) {
    inverted_tab[i] = tab[tab_size-1-i];
  }
  return inverted_tab;
}


std::vector<int> find_all(std::array<int, 4> const &tab, int value) {
  // Renvoyer un tableau contenant tous les index où la valeur de tab vaut value
  std::vector<int> tab_indexes = {};
  for (int j = 0; j < (int)tab.size(); j++) {
    if (tab[j] == value) {
      tab_indexes.push_back(j);
    }
  }
  return tab_indexes;
}


bool is_in_vector(std::vector<int> vec, int value) {
  // Renvoyer true si la valeur value est dans vec
  // Renvoyer false sinon

  for (int j = 0; j < (int)vec.size(); j++) {
    if (vec[j] == value) {
      return true;
    }
  }
  return false;
}


std::vector<int> uniques(std::array<int, 4> const &tab) {
  // Renvoyer un conteneur contenant la liste des valeurs uniques stockées dans
  // tab Ex:
  //  tab = [ 1 2 5 4 4 1 2 3 6 2 1 5 8 ]
  // renvoit
  //  [ 1 2 5 4 3 6 8 ]

  std::vector<int> tab_uniques_vals = {};
  for (int j = 0; j < (int)tab.size(); j++ ) {

    // Si la valeur de tab à l'index j n'est pas présente
    if (!is_in_vector(tab_uniques_vals, tab[j])) {
      tab_uniques_vals.push_back(tab[j]);
    }
  }

  return tab_uniques_vals;
}


int unique_sum(std::array<int, 4> const &tab) {
  // Renvoyer la somme des valeurs uniques de tab

  int sum = 0;

  // Récupération des valeurs uniques de la liste
  std::vector<int> uniques_numbers = uniques(tab);
  for (int j = 0; j < (int)uniques_numbers.size(); j++ ) {
    sum += uniques_numbers[j];
  }

  return sum;
}


void display_vector(std::vector<int> vec) {
  // Afficher sur le terminal le contenu d'un vecteur
  std::cout << "{";
  int size = vec.size();
  for (int j = 0; j < size; j++) {
    std::cout << vec[j];

    if (j != size - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}\n";
}


int main() {
  std::array<int, 4> tab = {1, 2, 2, 3};
  
  // ----- Test des Fonctions ----- //
  // Revert
  std::array<int, 4> reverted_tab = revert(tab);
  std::cout << "{";
  int size = reverted_tab.size();
  for (int j = 0; j < size; j++) {
    std::cout << reverted_tab[j];

    if (j != size - 1) {
      std::cout << ",";
    }
  }
  std::cout << "}\n";

  // Find all
  std::vector<int> find_all_result = find_all(tab, 1);
  display_vector(find_all_result); // Should display {0}

  find_all_result = find_all(tab, 2);
  display_vector(find_all_result); // Should display {1, 2}

  find_all_result = find_all(tab, 3);
  display_vector(find_all_result); // Should display {3}

  find_all_result = find_all(tab, 4);
  display_vector(find_all_result); // Should be empty
  return 0;
}