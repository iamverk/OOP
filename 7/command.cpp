
#include "command.h"

void add_cmd::undo_exec() {
    doc_->pop_top();
}

add_cmd::add_cmd(std::shared_ptr<document>& doc) {
    doc_ = doc;
}

del_cmd::del_cmd(std::shared_ptr<figure> &newFigure, int new_ind, std::shared_ptr<document> &doc) {
    doc_ = doc;
    fig = newFigure;
    ind = new_ind;
}

void del_cmd::undo_exec() {
    doc_->add_ind(fig,ind);
}