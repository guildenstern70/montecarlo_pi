/*
 *
 * MonteCarlo Computing of PI
 * Copyright 2025 Alessio Saltarin <alessiosaltarin@gmail.com>
 * This software is licensed with BSD License (see LICENSE file)
 *
 */

#include <random>
#include <chrono>
#include <bits/stdc++.h>

#define INTERVAL 10000
#define M_PI     3.14159265358979323846

using namespace std;

double get_difference(const double computedPi) {
    return (computedPi / M_PI) * 100;
}

int main() {
    double rand_x{0.0}, rand_y{0.0}, origin_dist{0}, pi{0};
    int circle_points{0}, square_points{0};

    const chrono::steady_clock::time_point begin = chrono::steady_clock::now();

    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0.0, INTERVAL + 1);

    cout << endl << "MONTECARLO PI COMPUTER v.0.1 " << endl << endl;

    for (int i = 0; i < (INTERVAL * INTERVAL); i++) {
        rand_x = static_cast<double>(dist(mt)) / INTERVAL;
        rand_y = static_cast<double>(dist(mt)) / INTERVAL;
        origin_dist = rand_x * rand_x + rand_y * rand_y;
        if (origin_dist <= 1)
            circle_points++;
        square_points++;
        pi = static_cast<double>(4 * circle_points) / square_points;

        // Progress
        if (i % 10000000 == 0) {
            const double percentage = get_difference(pi);
            cout << " - " << setprecision(15) << pi << " [" << percentage << "%]" << endl;
        }
    }

    const chrono::steady_clock::time_point end = chrono::steady_clock::now();

    // Final Estimated Value
    cout << endl << "Final Estimation of Pi = " << setprecision(15) << pi << endl;
    cout << "Real Value of Pi = " << setprecision(15) << M_PI << endl << endl;

    cout << "Elapsed = " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " sec." << endl << endl;

    return 0;
}
