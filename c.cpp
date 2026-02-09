#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    std::ofstream file("input_large.txt");
    if (!file) {
        std::cerr << "Erreur lors de l'ouverture du fichier\n";
        return 1;
    }

    // Header
    file << "date | value\n";

    std::srand(std::time(nullptr));

    const int n_lines = 1000000; // 1 million de lignes, tu peux augmenter

    for (int i = 0; i < n_lines; ++i) {
        // Générer une date aléatoire
        int year = 2000 + std::rand() % 25;       // 2000-2024
        int month = 1 + std::rand() % 12;         // 1-12
        int day = 1 + std::rand() % 28;           // 1-28 pour simplifier

        // Générer une valeur aléatoire entre 0 et 999
        int value = std::rand() % 1000;

        file << std::setw(4) << std::setfill('0') << year << "-"
             << std::setw(2) << std::setfill('0') << month << "-"
             << std::setw(2) << std::setfill('0') << day
             << " | " << value << "\n";
    }

    file.close();
    std::cout << "Fichier généré avec succès !\n";
    return 0;
}
