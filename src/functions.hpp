#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

Eigen::VectorXd random_point();
Eigen::VectorXd random_tangente();
Eigen::MatrixXd random_points_matrix(const size_t &n);
Eigen::MatrixXd random_points_matrix(const size_t &n, Eigen::MatrixXd &m);
Eigen::MatrixXd random_tan_matrix(const size_t &n);
Eigen::MatrixXd random_tan_matrix(const size_t &n, Eigen::MatrixXd &m);
//pt_controle, matrice_systeme et resolve_conic vont marcher pour les points et les tangentes
Eigen::VectorXd pt_controle(const Eigen::VectorXd &v);
Eigen::MatrixXd matrice_systeme(const Eigen::MatrixXd &m);
Eigen::VectorXd resolve_conic(const Eigen::MatrixXd &m);

#endif
