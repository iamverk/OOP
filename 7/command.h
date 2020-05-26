#ifndef OOP7_COMMAND_H
#define OOP7_COMMAND_H
#include "document.h"

class command {
public:
    virtual ~command() = default;
    virtual void undo_exec() = 0;


protected:
    std::shared_ptr<document> doc_;
};

class add_cmd : public command {
public:
    void undo_exec() override;

    add_cmd(std::shared_ptr<document>& doc);


};

class del_cmd : public command {
public:
    del_cmd(std::shared_ptr<figure>& newFigure, int new_ind,std::shared_ptr<document>& doc);
    void undo_exec() override;

private:
    std::shared_ptr<figure> fig;
    int ind;
};
#endif