#include "Conic.hpp"

Conic Conic::random_conic(const size_t &n) {
    Conic c;
    c.m_data = resolve_conic(matrice_systeme(random_points_matrix(n)));
    return c;
}

const std::vector<Conic> Conic::random_conics(const size_t &n, const size_t &nb_pt) {
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

