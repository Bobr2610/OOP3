#include <gtest/gtest.h>
#include <array>
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"

TEST(Geometry, TrapezoidBasics) {
    Trapezoid t({Point{0,0}, Point{4,0}, Point{3,2}, Point{1,2}});
    double area = static_cast<double>(t);
    EXPECT_DOUBLE_EQ(area, 8.0);
    auto c = t.center();
    // Centroid check approximate
    EXPECT_NEAR(c.y, 1.0, 1e-6);
}

TEST(Geometry, RhombusBasics) {
    Rhombus r({Point{-1,0}, Point{0,2}, Point{1,0}, Point{0,-2}});
    double area = static_cast<double>(r);
    EXPECT_DOUBLE_EQ(area, 4.0);
    auto c = r.center();
    EXPECT_NEAR(c.x, 0.0, 1e-6);
    EXPECT_NEAR(c.y, 0.0, 1e-6);
}

TEST(Geometry, PentagonBasics) {
    Pentagon p({Point{0,1}, Point{1,1}, Point{1.5,0}, Point{0.5,-1}, Point{-0.5,0}});
    double area = static_cast<double>(p);
    EXPECT_GT(area, 0.0);
}

TEST(Geometry, EqualityAndClone) {
    Trapezoid a({Point{0,0}, Point{4,0}, Point{3,2}, Point{1,2}});
    auto b = a.clone();
    EXPECT_TRUE(a == *b);
}

TEST(Geometry, ArrayTotalAreaAndRemove) {
    FigureArray arr;
    arr.add(std::make_unique<Trapezoid>(std::array<Point,4>{Point{0,0}, Point{4,0}, Point{3,2}, Point{1,2}})); // 8
    arr.add(std::make_unique<Rhombus>(std::array<Point,4>{Point{-1,0}, Point{0,2}, Point{1,0}, Point{0,-2}})); // 4
    EXPECT_DOUBLE_EQ(arr.totalArea(), 12.0);
    EXPECT_TRUE(arr.removeAt(0));
    EXPECT_DOUBLE_EQ(arr.totalArea(), 4.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
