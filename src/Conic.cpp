#include "Conic.hpp"

Conic Conic::random_conic(const size_t &n)
{
    Conic c;
    c.m_data = resolve_conic(matrice_systeme(random_points_matrix(n)));
    return c;
}

const std::vector<Conic> Conic::random_conics(const size_t &n, const size_t &nb_pt)
{
    std::vector<Conic> vc(n);
    for (size_t i = 0; i<n; i++) {
        vc[i] = random_conic(nb_pt);
    }
    return vc;
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
    c.m_data << C_inverse(0,0), 2*C_inverse(0,1), C_inverse(1,1), 2*C_inverse(0,2), 2*C_inverse(1,2), C_inverse(2,2);
    return c;
}

const std::vector<Conic> Conic::random_tan_conics(const size_t &n, const size_t &nb_tan)
{
    std::vector<Conic> vc(n);
    for (size_t i = 0; i<n; i++) {
        vc[i] = random_tan_conic(nb_tan);
    }
    return vc;
}


