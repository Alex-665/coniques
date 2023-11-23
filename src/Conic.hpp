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
        Conic() : m_data(6) {};
        Conic(const Conic &c) = default;
        ~Conic() = default;

        //getter and setter
        inline double get(const size_t i) const {return m_data(i);};
        inline void set(const size_t i, const double d) {m_data(i) = d;};
        inline const Eigen::VectorXd get_all() const {return m_data;};
        inline void set_all(const Eigen::VectorXd v) {m_data = v;};
        inline void set_all(const Conic c) {m_data = c.m_data;};

        static Conic random_conic(const size_t &n);
        static Conic random_conic(const size_t &n, Eigen::MatrixXd &m);
        inline void conique_normee() {this->m_data/std::sqrt(std::inner_product(this->m_data.begin(), this->m_data.end(), this->m_data.begin(), 0));};
        static std::vector<Conic> faisceaux_coniques(Conic ca, Conic cb, const size_t &n);
        static Conic random_tan_conic(const size_t &n);
        static Conic random_tan_conic(const size_t &n, Eigen::MatrixXd &m);
};
