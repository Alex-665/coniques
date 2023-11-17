#include <iostream>
#include <vector>
#include <cstdlib>
#include <Eigen/Dense>

#include "functions.hpp"

//un point random
Eigen::VectorXd random_point() {
    Eigen::VectorXd pt(3);
    pt(0) = float(rand() % 100 / 50);
    pt(1) = float(rand() % 100 / 50);
    pt(2) = 1.0;
    return pt;
}

//un point random à l'infini
Eigen::VectorXd random_infinite_point() {
    Eigen::VectorXd pt(3);
    pt(0) = float(rand() % 100 / 50);
    pt(1) = float(rand() % 100 / 50);
    pt(2) = 0.0;
    return pt;
}

//fonction qui donne une matrice de n points random
Eigen::MatrixXd random_points_matrix(const size_t &n) {
    Eigen::MatrixXd pts(n,3);
    for (size_t i=0;i<n;i++) {
        pts(i,Eigen::all) = random_point();
    }
    return pts;
}

//on va prendre w=1 de base
Eigen::VectorXd pt_controle(const Eigen::VectorXd &v) {
    Eigen::VectorXd res(6);
    res << v(0)*v(0), v(0)*v(1), v(1)*v(1), v(0)*v(2), v(1)*v(2), v(2)*v(2);
    return res;
}

Eigen::MatrixXd matrice_systeme(const Eigen::MatrixXd &m) {
    Eigen::MatrixXd a(m.rows(),6);
    for (size_t i = 0; i<m.rows(); i++) {
        a(i,Eigen::all) = pt_controle(m(i,Eigen::all));
    }
    return a;
}

//fonction qui résout le système à n équations et renvoie la conique
Eigen::VectorXd resolve_conic(const Eigen::MatrixXd &m) {
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(m, Eigen::ComputeThinU|Eigen::ComputeFullV);
    Eigen::VectorXd conic = svd.matrixV().rightCols(1);
    return conic;
}
