#include "Conic.hpp"

Conic Conic::random_conic(const size_t &n)
{
    Conic c;
    c.m_data = resolve_conic(matrice_systeme(random_points_matrix(n)));
    return c;
}
Conic Conic::random_conic(const size_t &n, Eigen::MatrixXd &m)
{
    Conic c;
    c.m_data = resolve_conic(matrice_systeme(random_points_matrix(n, m)));
    return c;
}

std::vector<Conic> Conic::faisceaux_coniques(Conic ca, Conic cb, const size_t &n)
{
    std::vector<Conic> faisceau(n);
    for (size_t i = 0; i<n; i++) {
        ca.conique_normee();
        cb.conique_normee();
        faisceau[i].m_data = std::cos(i*PI/n)*ca.m_data + std::sin(i*PI/n)*cb.m_data;
    }
    return faisceau;
}

Conic Conic::random_tan_conic(const size_t &n)
{
    Conic c;
    Eigen::VectorXd v = resolve_conic(matrice_systeme(random_tan_matrix(n)));
    Eigen::MatrixXd C_inverse(3,3);
    C_inverse << v(0), v(1)/2, v(3)/2,
                 v(1)/2, v(2), v(4)/2,
                 v(3)/2, v(4)/2, v(5);
    Eigen::MatrixXd C = C_inverse.inverse();
    c.m_data << C(0,0), 2*C(0,1), C(1,1), 2*C(0,2), 2*C(1,2), C(2,2);
    return c;
}
Conic Conic::random_tan_conic(const size_t &n, Eigen::MatrixXd &m)
{
    Conic c;
    Eigen::VectorXd v = resolve_conic(matrice_systeme(random_tan_matrix(n, m)));
    Eigen::MatrixXd C_inverse(3,3);
    C_inverse << v(0), v(1)/2, v(3)/2,
                 v(1)/2, v(2), v(4)/2,
                 v(3)/2, v(4)/2, v(5);
    Eigen::MatrixXd C = C_inverse.inverse();
    c.m_data << C(0,0), 2*C(0,1), C(1,1), 2*C(0,2), 2*C(1,2), C(2,2);
    return c;
}
