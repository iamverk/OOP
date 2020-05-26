#ifndef OOP7_DOCUMENT_H
#define OOP7_DOCUMENT_H

#include <fstream>
#include <cstdint>
#include <memory>
#include <string>
#include <algorithm>
#include "figure.h"
#include <vector>
#include "factory.h"

struct document {
public:
    void prt() const;
    document(std::string& new_name): name_(new_name), factory_(), buf(0) {};
    void insert(std::shared_ptr<figure>& ptr);
    void rename(const std::string& new_name);
    void save (const std::string& filename) const;
    void load(const std::string& filename);
    std::shared_ptr<figure> get_fig(int index);
    void remove(int index);
    std::string get_name();
    size_t get_size();
private:
    friend class add_cmd;
    friend class rmv_cmd;
    factory factory_;
    std::string name_;
    std::vector<std::shared_ptr<figure>> buf;
    void pop_top();
public:
    void add_ind(std::shared_ptr<figure>& newFigure, int index);
};


#endif //OOP7_DOCUMENT_H