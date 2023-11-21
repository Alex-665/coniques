#include <iostream>
#include <vector>
#include <cstdlib>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Conic.hpp"


//fonction qui donne 5 points random

void display_matrix(Eigen::MatrixXd &m) 
{
    for (size_t i = 0; i<m.rows(); i++) {
        for (size_t j = 0; j<m.cols(); j++) {
            std::cout << m(i,j) << "  " ;
        }
        std::cout << "" << std::endl;
    }
}

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

    // draw points
    Eigen::VectorXd pt1(2), pt2(2), pt3(2);
    pt1 <<  1.5,  2.0;
    pt2 <<  3.0,  1.0;
    pt3 << -2.0, -1.0;

    //viewer.push_point(pt1, "p1", 200,0,0);
    //viewer.push_point(pt2, "p2", 200,0,0);
    //viewer.push_point(pt3, 200,0,0);

    // draw line
    //viewer.push_line(pt1, pt2-pt1,  200,200,0);

    // draw conic
    //std::vector<Conic> vc = Conic::random_conics(5,5);
    //for (size_t i = 0; i<5; i++) {
    //    viewer.push_conic(vc[i].get_all(), rand() % 255, rand() % 255, rand() % 255);
    //}
    
    std::vector<Conic> f = Conic::faisceaux_coniques(Conic::random_conic(5), Conic::random_conic(5), 10);
    
    for (size_t i = 0; i<10; i++) {
        viewer.push_conic(f[i].get_all(),255 - 3*i, 0,55 + 3*i);
    }

    // render
    viewer.display(); // on terminal
    viewer.render("output.html");  // generate the output file (to open with your web browser)

    return 0;
}

