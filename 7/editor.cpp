#include "editor.h"

void editor::prt_doc() {
    if (doc == nullptr) {
        std::cout << "no doc\n";
        return;
    }
    doc->prt();
}
void editor::crt_doc(std::string& name) {
    doc = std::make_shared<document>(name);
}
bool editor::doc_ext() {
    return doc != nullptr;
}
void editor::add_doc(std::shared_ptr<figure> &newFigure) {
    if (doc == nullptr) {
        std::cout << "no doc\n";
        return;
    }
    std::shared_ptr<command> tmp_cmd = std::shared_ptr<command>(new add_cmd(doc));
    doc->insert(newFigure);
    history.push(tmp_cmd);
}
void editor::delete_doc(int ind) {
    if (doc == nullptr) {
        std::cout << "no doc\n";
        return;
    }
    if (ind >= doc->get_size()) {
        std::cout << "out of bounds\n";
        return;
    }
    std::shared_ptr<figure> tmp = doc->get_fig(ind);
    std::shared_ptr<command> tmp_cmd = std::shared_ptr<command>(new del_cmd(tmp,ind,doc));
    doc->remove(ind);
    history.push(tmp_cmd);
}
void editor::save_doc() {
    if (doc == nullptr) {
        std::cout << "no doc\n";
        return;
    }
    std::string saved = doc->get_name();
    doc->save(saved);
}
void editor::load_doc(std::string &name) {
    try {
        doc = std::make_shared<document>(name);
        doc->load(name);
        while (!history.empty()) {
            history.pop();
        }
    } catch (std::logic_error &e) {
        std::cout << e.what();
    }
}
void editor::undo() {
    if (history.empty()) {
        throw std::logic_error("empty history\n");
    }
    std::shared_ptr<command> prev_cmd = history.top();
    prev_cmd->undo_exec();
    history.pop();
}