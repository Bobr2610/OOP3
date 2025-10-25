#include "polygon_utils.h"
#include <cmath>
#include <stdexcept>

double polygonArea(const std::vector<Point>& pts) {
    if (pts.size() < 3) return 0.0;
    long double sum = 0.0L;
    for (size_t i = 0; i < pts.size(); ++i) {
        const Point& a = pts[i];
        const Point& b = pts[(i + 1) % pts.size()];
        sum += static_cast<long double>(a.x) * b.y - static_cast<long double>(b.x) * a.y;
    }
    if (sum < 0.0L) sum = -sum;
    return static_cast<double>(sum * 0.5L);
}

Point polygonCentroid(const std::vector<Point>& pts) {
    if (pts.size() < 3) return {0.0, 0.0};
    long double A2 = 0.0L; // 2A signed
    long double cx = 0.0L;
    long double cy = 0.0L;
    for (size_t i = 0; i < pts.size(); ++i) {
        const Point& a = pts[i];
        const Point& b = pts[(i + 1) % pts.size()];
        long double cross = static_cast<long double>(a.x) * b.y - static_cast<long double>(b.x) * a.y;
        A2 += cross;
        cx += (static_cast<long double>(a.x) + b.x) * cross;
        cy += (static_cast<long double>(a.y) + b.y) * cross;
    }
    if (A2 == 0.0L) return {0.0, 0.0};
    long double inv = 1.0L / (3.0L * A2);
    return {static_cast<double>(cx * inv), static_cast<double>(cy * inv)};
}


