#ifndef OOP7_EDITOR_H
#define OOP7_EDITOR_H
#include "figure.h"
#include "document.h"
#include <stack>
#include "command.h"

class editor {
public:
    ~editor() = default;
    void prt_doc();
    void crt_doc(std::string& newName);
    bool doc_ext();
    editor() : doc(nullptr), history(){}
    void add_doc(std::shared_ptr<figure>& newFigure);
    void delete_doc(int ind);
    void save_doc();
    void load_doc(std::string& name);
    void undo();
private:
    std::shared_ptr<document> doc;
    std::stack<std::shared_ptr<command>> history;
};

#endif //OOP7_EDITOR_H