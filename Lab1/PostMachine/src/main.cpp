#include "command.h"
#include <iostream>
#include <vector>

int main()
{
    // Define a simple program
    std::vector<PostInstruction> program =
    {
        { PostOp::Write1 },
        { PostOp::MoveRight },
        { PostOp::Write1 },
        { PostOp::MoveRight },
        { PostOp::Write1 },
        { PostOp::Halt }
    };

    PostMachine machine(program);

    // Run the machine (limit to 100 steps)
    auto result = machine.run(100); 

    std::cout << "Program finished\n";
    std::cout << "Steps executed: " << result.steps << '\n';
    std::cout << "Halted: " << std::boolalpha << result.halted << '\n';

    // Pause so the window doesn't close immediately
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    return 0;
}