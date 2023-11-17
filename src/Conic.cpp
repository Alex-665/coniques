#include "Conic.hpp"

const Conic Conic::random_conic(const size_t &n) {
    Conic c;
    c.m_data = resolve_conic(matrice_systeme(random_points_matrix(n)));
    return c;
}

//pour les autres ça devrait marcher de la même manière sauf qu'il y a des conditions à respecter (je vais en faire un histoire de voir si ça marche et après on fera ensemble demain)
const Conic Conic::ellipse(const size_t &n) {
    Conic c;
    return c;
}

const Conic Conic::cercle(const size_t &n) {
    Conic c;
    return c;
}

const Conic Conic::parabole(const size_t &n) {
    Conic c;
    return c;
}

const Conic Conic::hyperbole(const size_t &n) {
    Conic c;
    return c;
}

const std::vector<Conic> random_conics(const size_t &n) {
    std::vector<Conic> vc(n);
    for (size_t i = 0; i<n; i++) {
        vc[i] = Conic::random_conic(5);
    }
    return vc;
}
