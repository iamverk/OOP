#include <iostream>
#include "factory.h"
#include "editor.h"

void crt(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    edit.crt_doc(tmp);
}

void load(editor& edit) {
    std::string tmp;
    std::cin >> tmp;
    try {
        edit.load_doc(tmp);
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void save(editor& edit) {
    std::string tmp;
    try {
        edit.save_doc();
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    }
}

void add(editor& edit) {
    factory fac;
    try {
        std::shared_ptr<figure> newElem = fac.new_figure(std::cin);
        edit.add_doc(newElem);
    } catch (std::logic_error& e) {
        std::cout << e.what() << '\n';
    }
}

void rmv(editor& edit) {
    int index;
    std::cin >> index;
    try {
        edit.delete_doc(index);
    } catch (std::logic_error& err) {
        std::cout << err.what() << "\n";
    }
}

int main() {
    editor edit;
    std::string command;
    while (true) {
        std::cin >> command;
        if (command == "crt") {
            crt(edit);
        } else if (command == "load") {
            load(edit);
        } else if (command == "save") {
            save(edit);
        } else if (command == "ext") {
            break;
        } else if (command == "add") {
            add(edit);
        } else if (command == "rmv") {
            rmv(edit);
        } else if (command == "prt") {
            edit.prt_doc();
        } else if (command == "undo") {
            try {
                edit.undo();
            } catch (std::logic_error& e) {
                std::cout << e.what();
            }
        } else {
            std::cout << "no such a command\n";
        }
    }
    return 0;
}