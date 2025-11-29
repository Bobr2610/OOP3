#include <gtest/gtest.h>
#include <sstream>
#include "include/trapezoid.h"
#include "include/rhomb.h"
#include "include/pentagon.h"

TEST(Geometry, Basics) {
    Trapezoid t;
    std::istringstream iss1("0 0 4 0 3 2 1 2");
    iss1 >> t;
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 6.0);
    
    Rhomb r;
    std::istringstream iss2("-1 0 0 2 1 0 0 -2");
    iss2 >> r;
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 4.0);
    
    Pentagon p;
    std::istringstream iss3("0 1 1 1 1.5 0 0.5 -1 -0.5 0");
    iss3 >> p;
    EXPECT_GT(static_cast<double>(p), 0.0);
}

TEST(Geometry, Operators) {
    Trapezoid t1;
    std::istringstream iss1("0 0 4 0 3 2 1 2");
    iss1 >> t1;
    
    Trapezoid t2 = t1;
    EXPECT_TRUE(t1 == t2);
    
    t2 = std::move(Trapezoid(t1));
    EXPECT_TRUE(t1 == t2);
}

TEST(Geometry, IO) {
    Trapezoid t;
    std::istringstream iss("0 0 4 0 3 2 1 2");
    iss >> t;
    
    std::ostringstream oss;
    oss << t;
    EXPECT_FALSE(oss.str().empty());
    
    Trapezoid t2;
    std::istringstream iss2("0 0 4 0 3 2 1 2");
    iss2 >> t2;
    EXPECT_TRUE(t == t2);
}

