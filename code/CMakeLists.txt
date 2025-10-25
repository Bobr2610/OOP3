add_library(figures_lib
    figure.h
    point.h
    polygon_utils.h
    trapezoid.h
    rhombus.h
    pentagon.h
    array.h
    figure.cpp
    polygon_utils.cpp
    trapezoid.cpp
    rhombus.cpp
    pentagon.cpp
    array.cpp
)
set_property(TARGET figures_lib PROPERTY CXX_STANDARD 17)

add_executable(OOP_LAB_3 main.cpp)
target_link_libraries(OOP_LAB_3 figures_lib)
set_property(TARGET OOP_LAB_3 PROPERTY CXX_STANDARD 17)
