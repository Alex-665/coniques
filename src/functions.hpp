#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

Eigen::VectorXd random_point();
Eigen::VectorXd random_tangente();
Eigen::VectorXd random_infinite_point();
Eigen::MatrixXd random_points_matrix(const size_t &n);
Eigen::VectorXd pt_controle(const Eigen::VectorXd &v);
Eigen::MatrixXd matrice_systeme(const Eigen::MatrixXd &m, const size_t &n);
Eigen::VectorXd resolve_conic(const Eigen::MatrixXd &m);

#endif
// test bug commit