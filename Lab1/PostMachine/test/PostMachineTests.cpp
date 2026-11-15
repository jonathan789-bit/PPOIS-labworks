#include <gtest/gtest.h>
#include "command.h"
#include <vector>

// Test 1: The machine should halt immediately if the program is empty or just halts
TEST(PostMachineTest, HaltImmediately) {
    std::vector<PostInstruction> program = { { PostOp::Halt } };
    PostMachine machine(program);
    auto result = machine.run(100);
    
    EXPECT_TRUE(result.halted);
    EXPECT_EQ(result.steps, 1); // 1 step to execute Halt
}

// Test 2: The machine should execute a simple write and halt
TEST(PostMachineTest, WriteAndHalt) {
    std::vector<PostInstruction> program = { 
        { PostOp::Write1 }, 
        { PostOp::Halt } 
    };
    PostMachine machine(program);
    auto result = machine.run(100);
    
    EXPECT_TRUE(result.halted);
    EXPECT_EQ(result.steps, 2);
}

// Test 3: The machine should move right and write
TEST(PostMachineTest, MoveRightAndWrite) {
    std::vector<PostInstruction> program = { 
        { PostOp::MoveRight }, 
        { PostOp::Write1 },
        { PostOp::Halt } 
    };
    PostMachine machine(program);
    auto result = machine.run(100);
    
    EXPECT_TRUE(result.halted);
    EXPECT_EQ(result.steps, 3);
}

// Test 4: The machine should halt when it runs out of instructions
TEST(PostMachineTest, HaltsWhenOutOfInstructions) {
    std::vector<PostInstruction> program = { 
        { PostOp::MoveRight } 
    };
    PostMachine machine(program);
    auto result = machine.run(10); // Limit to 10 steps
    
    // It should halt because the program has no more instructions to execute
    EXPECT_TRUE(result.halted); 
    EXPECT_EQ(result.steps, 1); // It only needed 1 step to finish the program
}