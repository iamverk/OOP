#ifndef _FACTORY_H
#define _FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "hexagon.h"
#include "rhombus.h"
#include "pentagon.h"
#include <string>

struct factory {
    std::shared_ptr<figure> FigureCreate(std::istream& is);
    std::shared_ptr<figure> FigureCreateFile(std::ifstream& is);

};

#endif