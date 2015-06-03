
#include <string>
#include <iostream>
#include <core/font.h>
#include <core/environment.h>
#include <core/rect.h>

#include "item.h"
#include "room.h"

Room::Room(Object *parent, ObjectID id, string type)
: Object(parent, id), r_left(nullptr), r_right(nullptr), r_top(nullptr), r_botton(nullptr), type(type)
{
	Item *piso = new Item(this,"piso",0,0,true);
	piso->change_sprite("res/tile_sheets/piso1.png");
	piso->set_w(1280);
	piso->set_h(720);
	add_child(piso);

	Item *paredes = new Item(this,"parede",0,0,true);
	paredes->change_sprite("res/tile_sheets/paredes.png");
	paredes->set_w(1280);
	paredes->set_h(720);
	add_child(paredes);
	// Item *piso;
	// for(int i = 0; i < 22; i++)
	// {
	// 	for(int j = 0; j < 12; j++)
	// 	{
	// 		piso = new Item(this,"piso",i*60,j*60,true);
	// 		piso->change_sprite("res/tile_sheets/tile1.png");
	 		
	// 	}
	// }

	// /*Adicionando cantos*/
	// Item *canto = new Item(this,"canto", 0, 0,false);
	// canto->change_sprite("res/tile_sheets/canto1.png");
	// canto->set_w(80);
	// canto->set_h(80);
	// add_child(canto);

	// canto = new Item(this,"canto", 1200, 0,false);
	// canto->change_sprite("res/tile_sheets/canto2.png");
	// canto->set_w(80);
	// canto->set_h(80);
	// add_child(canto);

	// canto = new Item(this,"canto", 0, 640,false);
	// canto->change_sprite("res/tile_sheets/canto4.png");
	// canto->set_w(80);
	// canto->set_h(80);
	// add_child(canto);

	// canto = new Item(this,"canto", 1200, 640,false);
	// canto->change_sprite("res/tile_sheets/canto3.png");
	// canto->set_w(80);
	// canto->set_h(80);
	// add_child(canto);

	// /*Adicionando paredes */
	// Item *parede;
	// for(int x = 1; x < 15; x++)
	// {
	// 	parede = new Item(this, "parede", x*80, 0, false);
	// 	parede->change_sprite("res/tile_sheets/parede2.png");
	// 	parede->set_w(80);
	// 	parede->set_h(80);
	// 	add_child(parede);

	// 	parede = new Item(this, "parede", x*80, 640, false);
	// 	parede->change_sprite("res/tile_sheets/parede4.png");
	// 	parede->set_w(80);
	// 	parede->set_h(80);
	// 	add_child(parede);
	// }
	// for(int y = 1; y < 8; y++ )
	// {
	// 	parede = new Item(this, "parede", 0, y*80, false);
	// 	parede->change_sprite("res/tile_sheets/parede1.png");
	// 	parede->set_w(80);
	// 	parede->set_h(80);
	// 	add_child(parede);

	// 	parede = new Item(this, "parede", 1200, y*80, false);
	// 	parede->change_sprite("res/tile_sheets/parede3.png");
	// 	parede->set_w(80);
	// 	parede->set_h(80);
	// 	add_child(parede);
	// }

	/*Gerando os itens aleatóriamente na sala*/
	draw_itens(this);
}

string Room::room_type()
{
	if (this->type == "CelaH" || this->type == "CelaV")
		return "Cela";

	return this->type;
}

void Room::draw_itens(Room* room)
{
	//srand(time(NULL));
	int random_number = rand()%10+1;

	if(this->room_type() == "None")
	{

	}
	if(this->room_type() != "Cela")
	{
		//Desenhando uma bancada
		Item* stand_table = new Item(this, "bancada", 520, 240, false);
		if(random_number == 1)
		{
			stand_table->change_sprite("res/tile_sheets/Bancadaa1.png");

			stand_table->set_w(240);
			stand_table->set_h(240);
			add_child(stand_table);
		}
			
		else if(random_number == 2)
		{
			stand_table->change_sprite("res/tile_sheets/Bancadaa2.png");

			stand_table->set_w(240);
			stand_table->set_h(240);
			add_child(stand_table);
		}

		random_number = rand()%10+1;
		//Desenhando uma cadeira
		Item *chair = new Item(this, "cadeira", rand() % 1098 + 80, rand() % 520 + 80, false);
		if(random_number == 1)
		{
			chair->change_sprite("res/tile_sheets/Cadeira1.png");
			chair->set_w(22);
			chair->set_h(40);
			add_child(chair);
		}

		chair = new Item(this, "cadeira", rand() % 1098 + 80, rand() % 520 + 80, false);
		random_number = rand()%10+1;
		if(random_number == 2)
		{
			chair->change_sprite("res/tile_sheets/Cadeira2.png");
			chair->set_w(22);
			chair->set_h(40);
			add_child(chair);
		}

		//Desenhando cadeira e mesa
		random_number = rand()%10+1;
		Item *chair_n_table = new Item(this, "cadeira e mesa", rand() % 1060 + 80, rand() % 480 + 80, false);
		if(random_number == 1)
		{
			chair_n_table->change_sprite("res/tile_sheets/CadeiraseMesa1.png");
			chair_n_table->set_w(80);
			chair_n_table->set_h(80);
			add_child(chair_n_table);
		}

		random_number = rand()%10+1;
		chair_n_table = new Item(this, "cadeira e mesa", rand() % 1060 + 80, rand() % 480 + 80, false);
		if(random_number == 2)
		{
			chair_n_table->change_sprite("res/tile_sheets/CadeiraseMesa2.png");
			chair_n_table->set_w(64);
			chair_n_table->set_h(38);
			add_child(chair_n_table);
		}

		random_number = rand()%10+1;
		chair_n_table = new Item(this, "cadeira e mesa", rand() % 1060 + 80, rand() % 480 + 80, false);
		if(random_number == 3)
		{
			chair_n_table->change_sprite("res/tile_sheets/CadeiraseMesa3.png");
			chair_n_table->set_w(80);
			chair_n_table->set_h(80);
			add_child(chair_n_table);
		}
	}
	if(this->room_type() == "Cela")
	{
		if(room->type == "CelaH")
		{
			Item *cell_room = new Item(this, "celas", 0, 0, true);
			cell_room->change_sprite("res/tile_sheets/ConjuntodeCelas.png");
			cell_room->set_w(1280);
			cell_room->set_h(720);
			add_child(cell_room);
		}

	}
	if(this->room_type() == "Final")
	{

	}
	if(this->room_type() == "KeyRoom")
	{
		Item *key = new Item(this, "key", rand() % 900 + 80, rand() % 500 + 80, true, "key");
		key->change_sprite("res/itens/key.png");
		key->set_w(32);
		key->set_h(32);
		add_child(key);
		add_vector(key);
	}	

}

void
Room::add_vector(Item * item)
{
	this->items.push_back(item);
}

vector <Item*>
Room::get_vector()
{
	return this->items;
}


void Room::check_entry()
{
	Environment *env = Environment::get_instance();
	if(this->r_left)
	{
		Rect l_door {0, 340, 80, 80};
		env->canvas->draw(l_door, Color::WHITE);

	}
	if(this->r_top)
	{
		Rect t_door {600, 0, 80, 80};
		env->canvas->draw(t_door, Color::WHITE);

	}
	if(this->r_right)
	{
		Rect r_door {1200, 340, 80, 80};
		env->canvas->draw(r_door, Color::WHITE);

	}
	if(this->r_botton)
	{
		Rect b_door {600, 640, 80, 80};
		env->canvas->draw(b_door, Color::WHITE);

	}
}

void
Room::draw_id(Room * anterior, Room * sala, int x, int y)
{

	Environment *env = Environment::get_instance();
	shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
	env->canvas->set_font(font);
	env->canvas->draw(sala->id(),x,y,Color::RED);

	if(sala->r_left && sala->r_left != anterior)
	{
		env->canvas->draw("-", x - 20, y,Color::RED);
		draw_id(sala, sala->r_left, x - 100, y);
	}
	if(sala->r_top && sala->r_top != anterior)
	{
		env->canvas->draw("|", x + 20, y - 30,Color::RED);
		draw_id(sala, sala->r_top, x, y - 60);
	}
	if(sala->r_right && sala->r_right != anterior)
	{
		env->canvas->draw("-", x + 80, y,Color::RED);
		draw_id(sala, sala->r_right, x + 100, y);
	}
	if(sala->r_botton && sala->r_botton != anterior)
	{
		env->canvas->draw("|", x + 20, y + 25,Color::RED);
		draw_id(sala, sala->r_botton, x, y + 60);
	}
}

void Room::draw_self()
{
	Environment *env = Environment::get_instance();
	draw_id(NULL, this, 640, 360);
	Rect square {635, 355, 80, 40};
	env->canvas->draw(square, Color::RED);

	Item *porta;

	if(this->r_left)
	{
		Rect l_door {0, 320, 80, 80};
		env->canvas->draw(l_door, Color::WHITE);

		/*Adicionando portas */
		porta = new Item(this,"porta", 0, 320, true);
		porta->change_sprite("res/tile_sheets/porta1.png");
		porta->set_w(80);
		porta->set_h(80);
		add_child(porta);

	}
	if(this->r_top)
	{
		Rect t_door {600, 0, 80, 80};
		env->canvas->draw(t_door, Color::WHITE);

		porta = new Item(this,"porta", 600, 0, true);
		porta->change_sprite("res/tile_sheets/porta2.png");
		porta->set_w(80);
		porta->set_h(80);
		add_child(porta);

	}
	if(this->r_right)
	{
		Rect r_door {1200, 320, 80, 80};
		env->canvas->draw(r_door, Color::WHITE);

		porta = new Item(this,"porta", 1200, 320, true);
		porta->change_sprite("res/tile_sheets/porta3.png");
		porta->set_w(80);
		porta->set_h(80);
		add_child(porta);

	}
	if(this->r_botton)
	{
		Rect b_door {600, 640, 80, 80};
		env->canvas->draw(b_door, Color::WHITE);
		porta = new Item(this,"porta", 600, 640, true);
		porta->change_sprite("res/tile_sheets/porta4.png");
		porta->set_w(80);
		porta->set_h(80);
		add_child(porta);

	}

	if(this->type == "Final")
	{
		if(this->r_right)
		{
			/*Adicionando portas */
			porta = new Item(this,"finaldoor", 0, 320, true, "finaldoor");
			porta->change_sprite("res/door/porta1.png");
			porta->set_w(80);
			porta->set_h(80);
			add_child(porta);
			add_vector(porta);
		}
		if(this->r_botton)
		{
			porta = new Item(this,"finaldoor", 600, 0, true, "finaldoor");
			porta->change_sprite("res/door/porta2.png");
			porta->set_w(80);
			porta->set_h(80);
			add_child(porta);
			add_vector(porta);

		}
		if(this->r_left)
		{
			porta = new Item(this,"finaldoor", 1200, 320, true, "finaldoor");
			porta->change_sprite("res/door/porta3.png");
			porta->set_w(80);
			porta->set_h(80);
			add_child(porta);
			add_vector(porta);

		}
		if(this->r_top)
		{
			porta = new Item(this,"finaldoor", 600, 640, true, "finaldoor");
			porta->change_sprite("res/door/porta4.png");
			porta->set_w(80);
			porta->set_h(80);
			add_child(porta);
			add_vector(porta);
		}
	}
	env->canvas->draw(this->type, 1100, 320,Color::WHITE);



}