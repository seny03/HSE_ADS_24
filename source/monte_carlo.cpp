#define _USE_MATH_DEFINES
#include "math.h"
#include <bits/stdc++.h>
#include <random>
using namespace std;

const double L = 0, R = 3.5;
const int POINTS_NUMBER = 1e8;
const double REAL_SQUARE = 0.25 * M_PI + 1.25 * asin(0.8) - 1;

struct Point {
  double x, y;

  double Distance2(const Point &other) {
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y);
  }
};

double genProb() { return (double)rand() / RAND_MAX; }

double generateNum(double min, double max) {
  return min + genProb() * (max - min);
}

Point generatePoint(double min, double max) {
  return Point{generateNum(min, max), generateNum(min, max)};
}

void MonteCarlo() {
  Point c[3] = {Point{1, 1}, Point{1.5, 2}, Point{2, 1.5}};
  double r[3] = {1, sqrt(5) / 2, sqrt(5) / 2};

  int internal_points = 0;
  for (int i = 0; i < POINTS_NUMBER; i++) {
    Point p = generatePoint(L, R);
    bool is_internal = true;
    for (int j = 0; j < 3; j++) {
      if (c[j].Distance2(p) > r[j] * r[j]) {
        is_internal = false;
        break;
      }
    }
    internal_points += is_internal;
  }

  double found_square =
      (double)internal_points / POINTS_NUMBER * (R - L) * (R - L);
  cout << "Found square: " << found_square << '\n';
  cout << "Real square: " << REAL_SQUARE << '\n';
  cout << "Error: " << abs(REAL_SQUARE - found_square) << '\n';
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  srand(42);

  MonteCarlo();

  return 0;
}
