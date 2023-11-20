#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <Eigen/Dense>

#include "functions.hpp"

class Conic {
    private :
        Eigen::VectorXd m_data;
    public :
        //constructor
        Conic() : m_data(6) {};
        //copy constructor
        Conic(const Conic &c) : m_data(c.m_data) {};
        //destructor
        ~Conic() = default;

        //getter and setter
        inline const double get(const size_t i) const {return m_data(i);};
        inline void set(const size_t i, const double d) {m_data(i) = d;};
        inline const Eigen::VectorXd get_all() const {return m_data;};
        inline void set_all(const Eigen::VectorXd v) {m_data = v;};
        inline void set_all(const Conic c) {m_data = c.m_data;};


        //bon c'est un peu nul de faire ça, c'est juste pour tracer des jolis trucs, mais y a pas vraiment moyen de mettre des conditions sur les points de manière simple
        static const Conic random_conic(const size_t &n);
        //celles-ci seront surement pas utiles
        static const Conic ellipse(const size_t &n);
        static const Conic cercle(const size_t &n);
        static const Conic parabole(const size_t &n);
        static const Conic hyperbole(const size_t &n);
        //jusque là
        static const std::vector<Conic> random_conics(const size_t &n);
};

