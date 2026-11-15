#include <gtest/gtest.h>
#include "Vector3D.h"
#include <stdexcept>

// --- Constructor and Getters ---
TEST(VectorTest, ConstructorAndGetters) {
    Vector3D v(1.5, 2.5, 3.5);
    EXPECT_DOUBLE_EQ(v.x(), 1.5);
    EXPECT_DOUBLE_EQ(v.y(), 2.5);
    EXPECT_DOUBLE_EQ(v.z(), 3.5);
}

// --- Length ---
TEST(VectorTest, LengthCalculation) {
    Vector3D v(3.0, 4.0, 0.0);
    EXPECT_DOUBLE_EQ(v.length(), 5.0);
}

// --- Cosine ---
TEST(VectorTest, CosineCalculation) {
    Vector3D v1(1.0, 0.0, 0.0);
    Vector3D v2(0.0, 1.0, 0.0);
    // The cosine between perpendicular vectors is 0
    EXPECT_DOUBLE_EQ(v1.cosine(v2), 0.0);
}

TEST(VectorTest, CosineThrowsOnZeroLength) {
    Vector3D v1(0.0, 0.0, 0.0);
    Vector3D v2(1.0, 1.0, 1.0);
    // Check if it throws the correct exception
    EXPECT_THROW(v1.cosine(v2), std::domain_error);
}

// --- Arithmetic Operators ---
TEST(VectorTest, Addition) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    Vector3D result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.x(), 5.0);
    EXPECT_DOUBLE_EQ(result.y(), 7.0);
    EXPECT_DOUBLE_EQ(result.z(), 9.0);
}

TEST(VectorTest, AdditionAssignment) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    v1 += v2;
    EXPECT_DOUBLE_EQ(v1.x(), 5.0);
    EXPECT_DOUBLE_EQ(v1.y(), 7.0);
    EXPECT_DOUBLE_EQ(v1.z(), 9.0);
}

TEST(VectorTest, Subtraction) {
    Vector3D v1(4.0, 5.0, 6.0);
    Vector3D v2(1.0, 2.0, 3.0);
    Vector3D result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.x(), 3.0);
    EXPECT_DOUBLE_EQ(result.y(), 3.0);
    EXPECT_DOUBLE_EQ(result.z(), 3.0);
}

TEST(VectorTest, SubtractionAssignment) {
    Vector3D v1(4.0, 5.0, 6.0);
    Vector3D v2(1.0, 2.0, 3.0);
    v1 -= v2;
    EXPECT_DOUBLE_EQ(v1.x(), 3.0);
    EXPECT_DOUBLE_EQ(v1.y(), 3.0);
    EXPECT_DOUBLE_EQ(v1.z(), 3.0);
}

TEST(VectorTest, ScalarMultiplication) {
    Vector3D v(1.0, 2.0, 3.0);
    Vector3D result = v * 2.0;
    EXPECT_DOUBLE_EQ(result.x(), 2.0);
    EXPECT_DOUBLE_EQ(result.y(), 4.0);
    EXPECT_DOUBLE_EQ(result.z(), 6.0);
}

TEST(VectorTest, ScalarMultiplicationAssignment) {
    Vector3D v(1.0, 2.0, 3.0);
    v *= 2.0;
    EXPECT_DOUBLE_EQ(v.x(), 2.0);
    EXPECT_DOUBLE_EQ(v.y(), 4.0);
    EXPECT_DOUBLE_EQ(v.z(), 6.0);
}

TEST(VectorTest, CrossProduct) {
    Vector3D v1(1.0, 0.0, 0.0);
    Vector3D v2(0.0, 1.0, 0.0);
    Vector3D result = v1 * v2;
    // Cross product of X and Y is Z
    EXPECT_DOUBLE_EQ(result.x(), 0.0);
    EXPECT_DOUBLE_EQ(result.y(), 0.0);
    EXPECT_DOUBLE_EQ(result.z(), 1.0);
}

TEST(VectorTest, Division) {
    Vector3D v(2.0, 4.0, 6.0);
    Vector3D result = v / 2.0;
    EXPECT_DOUBLE_EQ(result.x(), 1.0);
    EXPECT_DOUBLE_EQ(result.y(), 2.0);
    EXPECT_DOUBLE_EQ(result.z(), 3.0);
}

TEST(VectorTest, DivisionThrowsOnZero) {
    Vector3D v(1.0, 1.0, 1.0);
    EXPECT_THROW(v / 0.0, std::domain_error);
}

// --- Comparison Operators ---
TEST(VectorTest, Equality) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(1.0, 2.0, 3.0);
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, Inequality) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    EXPECT_TRUE(v1 != v2);
}