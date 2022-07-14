//
// Created by ryanz on 5/21/2022.
//
#ifndef PHYSICSFORMULA_STATICEQUILIBRIUM_H
#define PHYSICSFORMULA_STATICEQUILIBRIUM_H

#include "Constants.h"

using namespace std;

class StaticEquilibrium {
public:
    /**
     * A l -m-long log of irregular cross section lies horizontally, supported
     * by a wall at one end and a cable attached d -m from the other end.
     * The log weighs w -N, and the tension in the cable is t -N. Find the log's
     * center of gravity.
     * @param l is the length of the log
     * @param d is the distance from the end of the log to the cable
     * @param w is the weight of the log
     * @param t is the tension in the cable
     * @param print is a boolean that determines whether or not to print the result
     * @returns the center of gravity of the log
     */
    static ld log_cg(ld l, ld d, ld w, ld t, bool print = false);

    /**
     * A uniform board of mass m -kg is d -m long and is supported by a pivot
     * r -m from the left end and by a scale at the right end. How far from the
     * left end should a child of mass m_c -kg sit for the scale to read N?
     * @param m is the mass of the board
     * @param m_c is the mass of the child
     * @param d is the length of the board
     * @param r is the distance from the left end of the board to the pivot
     * @param N is the weight of the scale
     * @param print is a boolean that determines whether or not to print the result
     * @returns the distance from the left end of the board to the child
     */
    static ld child_on_board(ld m, ld m_c, ld d, ld r, ld N, bool print = false);

    /**
     * A d -m-long beam is supported by a cable at its center.
     * A steelworker of mass m -kg stands at one end of the beam. Where should
     * a bucket of concrete with mass m_c -kg be suspended for the beam to be
     * in static equilibrium?
     * @param d is the length of the beam
     * @param m is the mass of the steelworker
     * @param m_c is the mass of the concrete
     * @param print is a boolean that determines whether or not to print the result
     * @returns the distance from the left end of the beam to the concrete
     */
    static ld concrete_on_beam(ld d, ld m, ld m_c, bool print = false);


};

ld StaticEquilibrium::log_cg(const ld l,
                       const ld d,
                       const ld w,
                       const ld t,
                       const bool print) {
    auto cg = (t*(l - d))/w;
    if (print) {
        cout << "The center of gravity of the log is " << cg << " meters." << endl;
    }
    return cg;
}

ld StaticEquilibrium::child_on_board(const ld m,
                               const ld m_c,
                               const ld d,
                               const ld r,
                               const ld N,
                               const bool print) {
    auto ga = constants::Ga;
    auto cgl = d / 2.0;
    auto pivot_to_cg = cgl - r;
    auto pivot_to_scale = d - r;
    auto x = (m * pivot_to_cg * ga - N * pivot_to_scale) / (ga * m_c);
    // if x is negative then add the absolute value of x to the pivot
    if (x < 0) {
        x = -x;
        x += r;
    }
    if (print) {
        cout << "The child should be " << x << " meters from the left end of "
                                               "the board." << endl;
    }
    return x;
}

ld StaticEquilibrium::concrete_on_beam(ld d, ld m, ld m_c, bool print) {
    auto ga = constants::Ga;
    auto cgl = d / 2.0;
    auto x = (m * ga * cgl) / (ga * m_c);
    if (print) {
        cout << "The concrete should be " << x << " meters from the left end of "
                                               "the beam." << endl;
    }
    return x;
}

#endif //PHYSICSFORMULA_STATICEQUILIBRIUM_H
