add_library(figures_lib
        include/figure.h
        include/point.h
        include/trapezoid.h
        include/rhomb.h
        include/pentagon.h
        src/figure.cpp
        src/point.cpp
        src/trapezoid.cpp
        src/rhomb.cpp
        src/pentagon.cpp
)
set_property(TARGET figures_lib PROPERTY CXX_STANDARD 17)
target_include_directories(figures_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
