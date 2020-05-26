#include "factory.h"

std::shared_ptr<figure> factory::FigureCreate(std::istream &is) {
    std::string name;
    is >> name;
    if ( name == "p" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "h") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "r") {
        return std::shared_ptr<figure> ( new rhombus(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}

std::shared_ptr<figure> factory::FigureCreateFile(std::ifstream &is) {
    std::string name;
    is >> name;
    if ( name == "p" ) {
        return std::shared_ptr<figure> ( new pentagon(is));
    } else if ( name == "h") {
        return std::shared_ptr<figure> ( new hexagon(is));
    } else if ( name == "r") {
        return std::shared_ptr<figure> ( new rhombus(is));
    } else {
        throw std::logic_error("There is no such figure\n");
    }
}
