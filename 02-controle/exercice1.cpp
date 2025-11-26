/*
  Exercice 1 - Avis de recherche

  Q1 - Obtenez un entier aléatoire entre 0 et RAND_MAX.
  Pour ce faire, consultez la documentation de std::rand.

  Q2 - Convertissez le en réel compris dans l'intervalle [1, 20]

  Q3 - De la même façon, remplissez le tableau data de valeurs réelles
  aléatoires comprises entre 1 et 20.

  Q4 - Affichez le contenu du tableau ainsi rempli

  Q5 - Ecrivez le code nécessaire pour
  parcourir le tableau data et insérer dans un tableau resultats les index des
  valeurs supérieurs à 15

  Q6 - Affichez le tableau ainsi rempli et vérifiez vos résultats

*/

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

int generate_random_int() {
  return std::rand() % 20 +1;
}

int main(int, char **) {
  std::srand(std::time(nullptr));

  std::vector<float> data(20);

  // Q1
  int random_int = std::rand();
  std::cout << "Random value on [0, RAND_MAX]: " << random_int << ";\n";

  // Q2
  // Conversion en un réel dans l'intervalle [1 - 20]
  random_int = random_int % 20 + 1;
  std::cout << "Random value on [0, 20]: " << random_int << ";\n";

  // Q3
  // Génération de 20 réels aléatoires entre 1 et 20
  for (int i = 0; i < 20; i++) {
    data[i] = generate_random_int();
  }

  std::cout << "(i) DEBUG : data size = " << (int)data.size() << "\n";

  // Q4
  // Affichage de la data
  std::cout << "Vector of random values on [0, 20]: \n [";
  for (int j = 0; j < (int)data.size(); j++) {

    std::cout << data[j];

    if (j < (int)data.size() - 1) {
      std::cout << "; ";
    }

  }
  std::cout << "]; \n";

  // Q5
  // Récupération des index de val > 15
  // et insertion dans resultats

  std::vector<int> results; 

  for (int j = 0; j < (int)data.size(); j++) {
    if (data[j] > 15) {
      results.push_back(j);
    }
  }

  // Q6
  // Affichage de results
  std::cout << "Index of numbers > 15: \n [";
  for (int j = 0; j < (int)results.size(); j++) {

    std::cout << results[j];

    if (j < (int)results.size() - 1) {
      std::cout << "; ";
    }

  }
  std::cout << "]; \n";


  return 0;
}
