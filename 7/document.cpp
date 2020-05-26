#include "document.h"

void document::prt() const {
    if (buf.empty()) {
        std::cout << "Buffer is empty\n";
    }
    for (auto elem : buf) {
        elem->print(std::cout);
    }
}
void document::insert(std::shared_ptr<figure> &ptr) {
    buf.push_back(ptr);
}

void document::rename(const std::string &newName) {
    name_ = newName;
}

void document::save(const std::string &filename) const {
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    fout << buf.size() << '\n';
    for (auto elem : buf) {
        elem->print_file(fout);
    }
}

void document::load(const std::string &filename) {
    std::ifstream fin;
    fin.open(filename);
    if (!fin.is_open()) {
        throw std::runtime_error("File is not opened\n");
    }
    size_t size;
    fin >> size;
    buf.clear();
    for (int i = 0; i < size; i++) {
        buf.push_back(factory_.new_figure(fin));
    }
    name_ = filename;
}

std::shared_ptr<figure> document::get_fig(int ind) {
    return buf[ind];
}

void document::remove(int ind) {
    if ( ind >= buf.size()) {
        throw std::logic_error("Out of bounds\n");
    }
    buf[ind] = nullptr;
    while (ind < buf.size() - 1) {
        buf[ind] = buf[ind + 1];
        ind++;
    }
    buf.pop_back();
}

std::string document::get_name() {
    return this->name_;
}

size_t document::get_size() {
    return buf.size();
}

void document::pop_top() {
    if (buf.empty()) {
        throw std::logic_error("Document is empty");
    }
    buf.pop_back();
}

void document::add_ind(std::shared_ptr<figure>& new_fig, int ind) {
    buf.insert(buf.begin() + ind, new_fig);
}