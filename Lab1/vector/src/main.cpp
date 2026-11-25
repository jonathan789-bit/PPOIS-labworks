#include "Vector3D.h"
#include <iostream>
#include <limits>

int main() {
    int choice = 0;
    
    while (choice != 5) {
        std::cout << "\n=== Vector Math Menu ===\n";
        std::cout << "1. Add two vectors\n";
        std::cout << "2. Calculate length of a vector\n";
        std::cout << "3. Calculate cross product\n";
        std::cout << "4. Calculate cosine between vectors\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        
        std::cin >> choice;

        // Handle invalid input (like typing a letter)
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            double x, y, z;
            std::cout << "Enter vector 1 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v1(x, y, z);
            
            std::cout << "Enter vector 2 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v2(x, y, z);
            
            std::cout << "Result (v1 + v2): " << (v1 + v2) << "\n";
        } 
        else if (choice == 2) {
            double x, y, z;
            std::cout << "Enter vector (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v(x, y, z);
            std::cout << "Length: " << v.length() << "\n";
        }
        else if (choice == 3) {
            double x, y, z;
            std::cout << "Enter vector 1 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v1(x, y, z);
            
            std::cout << "Enter vector 2 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v2(x, y, z);
            
            std::cout << "Cross Product (v1 * v2): " << (v1 * v2) << "\n";
        }
        else if (choice == 4) {
            double x, y, z;
            std::cout << "Enter vector 1 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v1(x, y, z);
            
            std::cout << "Enter vector 2 (x y z): ";
            std::cin >> x >> y >> z;
            Vector3D v2(x, y, z);
            
            try {
                std::cout << "Cosine: " << v1.cosine(v2) << "\n";
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << "\n";
            }
        }
    }
    
    std::cout << "Exiting Vector Menu...\n";
    return 0;
}