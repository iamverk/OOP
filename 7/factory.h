#ifndef _FACTORY_H
#define _FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "figure.h"
#include <string>

struct factory {
    std::shared_ptr<figure> new_figure(std::istream &is);
    std::shared_ptr<figure> new_figure_file(std::istream &is);
};

#endif