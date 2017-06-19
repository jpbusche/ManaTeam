#include "creditos.h"
#include "button.h"
#include "font.h"
#include "environment.h"

#include <iostream>
using namespace std;

Creditos::Creditos()
    : Level("creditos")
{
    Environment *env = Environment::get_instance();

    double w = env->canvas->w();
    double h = env->canvas->h();

    set_dimensions(w, h);
    
    Button *back = new Button(this, "back", "res/interface/menuCreditos/voltar.png",
        "res/interface/menuCreditos/Svoltar.png");
    back->align_to(this, Object::RIGHT, Object::RIGHT);
    back->set_y(520);

    back->add_observer(this);
    add_child(back);

}
Creditos::~Creditos()
{
}

void
Creditos::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);

    shared_ptr<Texture> image = env->resources_manager->get_texture("res/interface/menuCreditos/telaCreditos.png");
    env->canvas->draw(image.get(), 1, 0);
}

bool
Creditos::on_message(Object *object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }

    Button *button = dynamic_cast <Button *>(object);

    if (not button)
    {
        return false;
    }
    if (button->id() == "back")
    {
        set_next("title");
    }

    finish();

    return true;
}
