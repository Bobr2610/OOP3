#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <array>
#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"

static void printHelp() {
    std::cout << "Commands:\n"
              << " add trapezoid x1 y1 x2 y2 x3 y3 x4 y4\n"
              << " add rhombus x1 y1 x2 y2 x3 y3 x4 y4\n"
              << " add pentagon x1 y1 x2 y2 x3 y3 x4 y4 x5 y5\n"
              << " print\n" 
              << " centers\n"
              << " areas\n"
              << " total\n"
              << " remove index\n"
              << " help\n"
              << " quit\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(6);

    FigureArray arr;
    std::string cmd;
    printHelp();
    while (std::cin >> cmd) {
        if (cmd == "add") {
            std::string type;
            if (!(std::cin >> type)) break;
            if (type == "trapezoid") {
                auto fig = std::make_unique<Trapezoid>();
                std::cin >> *fig;
                arr.add(std::move(fig));
            } else if (type == "rhombus") {
                auto fig = std::make_unique<Rhombus>();
                std::cin >> *fig;
                arr.add(std::move(fig));
            } else if (type == "pentagon") {
                auto fig = std::make_unique<Pentagon>();
                std::cin >> *fig;
                arr.add(std::move(fig));
            } else {
                std::cout << "Unknown figure type\n";
            }
        } else if (cmd == "print") {
            arr.forEach([](const Figure& f){ std::cout << f << "\n"; });
        } else if (cmd == "centers") {
            size_t i = 0; 
            arr.forEach([&](const Figure& f){ auto c = f.center(); std::cout << i++ << ": (" << c.x << ", " << c.y << ")\n"; });
        } else if (cmd == "areas") {
            size_t i = 0; 
            arr.forEach([&](const Figure& f){ std::cout << i++ << ": " << static_cast<double>(f) << "\n"; });
        } else if (cmd == "total") {
            std::cout << arr.totalArea() << "\n";
        } else if (cmd == "remove") {
            size_t idx; if (std::cin >> idx) {
                if (!arr.removeAt(idx)) std::cout << "Index out of range\n";
            }
        } else if (cmd == "help") {
            printHelp();
        } else if (cmd == "quit" || cmd == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Type 'help'.\n";
        }
    }
    return 0;
}
