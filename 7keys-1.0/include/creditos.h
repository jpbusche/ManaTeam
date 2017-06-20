#ifndef CREDITOS_H
#define CREDITOS_H

#include "level.h"

class Image;

class Creditos : public Level
{
public:
    Creditos();
    virtual ~Creditos();

    bool on_message(Object *sender, MessageID id, Parameters parameters);

private:
    void draw_self();
};

#endif