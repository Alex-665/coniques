#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

//peut-être qu'il faudra mettre des const par ci par là car certaines de ces fonctions ne sont utilisées que pour lire des vecteurs et pas les modifier
Eigen::VectorXd random_point();
Eigen::VectorXd random_tangente();
Eigen::VectorXd random_infinite_point();
Eigen::MatrixXd random_points_matrix(const size_t &n);
Eigen::MatrixXd random_tan_matrix(const size_t &n);
//pt_controle, matrice_systeme et resolve_conic vont marcher pour les points et les tangentes
Eigen::VectorXd pt_controle(const Eigen::VectorXd &v);
Eigen::MatrixXd matrice_systeme(const Eigen::MatrixXd &m);
Eigen::VectorXd resolve_conic(const Eigen::MatrixXd &m);

#endif
