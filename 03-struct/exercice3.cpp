/*
  Exercice 3 - Nuage de points

  Q1 - Implémentez une structure représentant un point 3D pondéré par un réel.

  Q2 - Implémentez les opérateurs nécessaires pour extraire et insérer une
  instance de cette structure dans un flux.

  Q3 - Renseignez vous sur la fonction std::getline.
    Utilisez la pour lire un fichier texte contenant une quantité
    arbitraire de points pondérés. Cette fonction prendra en paramètre le nom du
    fichier à lire et renverra un std::vector de point 3D pondéré.

  Q4 - Implémentez une fonction calculant la distance entre deux points pondérés

  Q5 - Implémentez une fonction renvoyant le point le plus éloigné d'un point
    donné parmi tous les points stockés dans un std::vector de points pondérés.

  Q6 - Implémentez une fonction renvoyant le point le plus proche d'un point
    donné parmi tous les points stockés dans un std::vector de points pondérés.

  Q7 - Implémentez une fonction calculant le barycentre d'un ensemble de point
    stocké dans un std::vector. Q8 - Implémentez une fonction calculant la
    distance entre le point le plus proche et le plus éloigné du barycentre d'un
    ensemble de points.

  Chaque fonction devra être testée en isolation afin de s'assurer de son
  fonctionnement correct.
*/

#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>

struct Point3D
{
    // Q1
    int x;
    int y;
    int z;
    double w;
};

// Q2
std::ostream &operator<<(std::ostream &os, Point3D pt)
{
    return os << "(" << pt.x << ", " << pt.y << ", " << pt.z << "; " << pt.w << ")";
}

// Q3
// Fonction convertissant un fichier de points 3D en une liste d'objets Point3D
std::vector<Point3D> file_to_points(std::string filename) 
{
    // Vector de Points3D à renvoyer
    std::vector<Point3D> vec_to_return;

    // Ouverture du fichier
    std::ifstream file(filename);

    // Conteneur de la ligne lue
    std::string current_line;

    // Vérification de la bonne ouverture du fichier
    if (file.is_open()) {

        // Lecture des lignes tant que possible
        while (std::getline(file, current_line)) {
            
          // Passage de la ligne dans une istringstream
          std::istringstream stream(current_line);

          // Déclaration des coordonnées 
          int line_x, line_y, line_z;
          double line_w;

          // Extraction des coordonnées de la ligne
          stream >> line_x >> line_y >> line_z >> line_w;

          // Création d'un Point3D
          vec_to_return.push_back({line_x, line_y, line_z, line_w});
        }
    }

    // En cas d'erreur d'ouverture
    else {
        std::cerr << "(X) ERREUR | Échec de l'ouverture du ficher " << filename << "\n";
    }

    return vec_to_return;
}

// Q4 
// Fonction de calcul de la distance entre deux points pondérés
double distance(Point3D const& p1, Point3D const& p2)
{
  // Calcul des différences entre chaque coordonnées
  double diff_x = p2.x - p1.x;
  double diff_y = p2.y - p1.y;
  double diff_z = p2.z - p1.z;

  std::cout << "(i) DEBUG | diff_x = " << diff_x << "\n";
  std::cout << "(i) DEBUG | diff_y = " << diff_y << "\n";
  std::cout << "(i) DEBUG | diff_z = " << diff_z << "\n";

  // Calcul de la distance sans la pondération
  double dist = sqrt(((diff_x*diff_x) + (diff_y*diff_y) + (diff_z*diff_z)));

  std::cout << "(i) DEBUG | dist = " << dist << "\n";

  // Calcul de la pondération moyenne
  double avg_pond = (p2.z + p1.z) / 2.0f;

  std::cout << "(i) DEBUG | avg_pond = " << avg_pond << "\n";

  return dist * avg_pond;
}

int main(int, char **)
{

    Point3D pt1 = {1, 0, 3, 2.8};

    std::cout << "\n----- Test de l'affichage d'un point 3D -----\n";
    std::cout << pt1 << "\n";

    std::cout << "\n----- Test de l'affichage de plusieurs points 3D, à partir d'un fichier -----\n";
    std::vector<Point3D> points_from_file = file_to_points("points.tplt");

    for (int i = 0; i < (int)points_from_file.size(); i++) {
      std::cout << points_from_file[i] << "\n";
    }

    std::cout << "\n----- Test de la distance entre deux points 3D du fichier -----\n";
    std::cout << distance(points_from_file[1], points_from_file[2]) << "\n";


    return 0;
}
