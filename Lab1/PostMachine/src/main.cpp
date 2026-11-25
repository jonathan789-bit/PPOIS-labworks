#include "command.h"
#include <iostream>
#include <vector>
#include <limits>

int main() {
    int choice = 0;
    
    while (choice != 2) {
        std::cout << "\n=== PostMachine Menu ===\n";
        std::cout << "1. Run the default write-move-write program\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter choice: ";
        
        std::cin >> choice;

        // Handle invalid input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            std::vector<PostInstruction> program = {
                { PostOp::Write1 },
                { PostOp::MoveRight },
                { PostOp::Write1 },
                { PostOp::MoveRight },
                { PostOp::Write1 },
                { PostOp::Halt }
            };

            PostMachine machine(program);
            auto result = machine.run(100);

            std::cout << "\n--- Execution Results ---\n";
            std::cout << "Steps executed: " << result.steps << "\n";
            std::cout << "Halted: " << std::boolalpha << result.halted << "\n";
        }
    }
    
    std::cout << "Exiting PostMachine Menu...\n";
    return 0;
}