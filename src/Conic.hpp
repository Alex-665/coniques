#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <cmath>
#include <Eigen/Dense>

#include "functions.hpp"

constexpr double PI = 3.1415926535897932;

class Conic {
    private :
        Eigen::VectorXd m_data;
    public :
        //constructor
        Conic() : m_data(6) {};
        //copy constructor
        Conic(const Conic &c) = default;
        //destructor
        ~Conic() = default;

        //getter and setter
        inline double get(const size_t i) const {return m_data(i);};
        inline void set(const size_t i, const double d) {m_data(i) = d;};
        inline const Eigen::VectorXd get_all() const {return m_data;};
        inline void set_all(const Eigen::VectorXd v) {m_data = v;};
        inline void set_all(const Conic c) {m_data = c.m_data;};

        //bon c'est un peu nul de faire ça, c'est juste pour tracer des jolis trucs, mais y a pas vraiment moyen de mettre des conditions sur les points de manière simple
        static Conic random_conic(const size_t &n);
        static const std::vector<Conic> random_conics(const size_t &n, const size_t &nb_pt);//n coniques à partir de nb_pt points
        //à voir si cela n'est pas mieux de faire une fonction void qui va directement normer la conique
        inline void conique_normee() {this->m_data/std::sqrt(std::inner_product(this->m_data.begin(), this->m_data.end(), this->m_data.begin(), 0));};
        static std::vector<Conic> faisceaux_coniques(Conic ca, Conic cb, const size_t &n);
        static Conic random_tan_conic(const size_t &n);
        static const std::vector<Conic> random_tan_conics(const size_t &n, const size_t &nb_tan);
};
