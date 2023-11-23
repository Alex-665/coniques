#include <iostream>
#include <vector>
#include <cstdlib>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"

int main()
{
    // the viewer will open a file whose path is writen in hard (bad!!). 
    // So you should either launch your program from the fine directory or change the path to this file.
    Viewer_conic viewer;

    // viewer options
    viewer.set_background_color(250, 250, 255);
    viewer.show_axis(true);
    viewer.show_grid(false);
    viewer.show_value(false);
    viewer.show_label(true);

    //input utilisateur
    std::cout << "Que voulez-vous tracer ? Si vous voulez tracer une simple conique à partir de points, tapez 1, si vous voulez tracer une conique à partir de tangentes, tapez 2, si vous voulez tracer un faisceau de coniques tapez 3."  << std::endl;
    int x;
    std::cin >> x;
    switch (x) 
    {
        case 1 :
            try {
                std::cout << "Entrez le nombre de points souhaités (au moins 5)." << std::endl;
                int n;
                std::cin >> n;
                if (n<5) throw std::string("vous ne m'avez pas écouté...il faut mettre au moins 5 points.");
                Eigen::MatrixXd points(n,3);
                Conic c = Conic::random_conic(n, points);
                viewer.push_points(points);
                viewer.push_conic(c.get_all(), 0,200,0);
            }
            catch(const std::string &s) {
                std::cerr << "erreur : " << s << std::endl;
            }
            break;
        case 2 :
            try {
                std::cout << "Entrez le nombre de tangentes souhaitées (au moins 5)." << std::endl;
                int n;
                std::cin >> n;
                if (n<5) throw std::string("vous ne m'avez pas écouté...il faut mettre au moins 5 tangentes.");
                Eigen::MatrixXd tans(n,3);
                Conic c = Conic::random_tan_conic(n, tans);
                //on affiche également les tangentes
                viewer.push_tans(tans);
                viewer.push_conic(c.get_all(), 0,200,0);
            }
            catch(const std::string &s) {
                std::cerr << "erreur : " << s << std::endl;
            }
            break;
        case 3 :
            try {
                std::cout << "Entrez le nombre de coniques que vous voulez dans votre faisceau de coniques (au moins 1 (les coniques seront tracées à partir de 5 points (visuellement on ne s'y retrouve pas vraiment sinon)))." << std::endl;
                int n;
                std::cin >> n;
                if (n<=0) throw std::string("vous ne m'avez pas écouté...il faut mettre au moins 1 conique.");
                std::vector<Conic> f = Conic::faisceaux_coniques(Conic::random_conic(5), Conic::random_conic(5), n);
                viewer.push_conics(f);
            }
            catch(const std::string &s) {
                std::cerr << "erreur : " << s << std::endl;
            }
            break;
    }

    // render
    viewer.display(); // on terminal
    viewer.render("output.html");  // generate the output file (to open with your web browser)

    return 0;
}

