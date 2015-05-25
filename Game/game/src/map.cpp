#include "map.h"

#include <vector>
#include <utility>
#include <ijengine/core/environment.h>
#include <ijengine/core/rect.h>
#include <map>
#include "item.h"
#include "player.h"


using namespace std;

Map::Map() : current_room(nullptr)
{	
	GenerateMap(50);

}
// Room Criation
void Map::CreateRoom(Room *room, int *id,int x, int y, int qnt)
{
	int randomVar;
	
	randomVar = rand() % 4+1;

	string sala = "sala ";
	int num = *id;
	char numero1, numero2;

	numero1 = num/10 + 48;

	numero2 = num % 10 + 48;


	

	switch(randomVar)
	{	
		case LEFT:
			if(room->r_left != nullptr)
				CreateRoom(room->r_left, id, x-1, y, qnt);
			else if(x-1 >= 0 && matriz[x-1][y] == false)
            {
            	room->Room::r_left = new Room(this, sala + numero1 + numero2);
            	room->r_left->r_right = room;
				//rooms->left = InsertRoom(*id, NULL, NULL, rooms, NULL);
                matriz[x-1][y] = true;
                //add_child(room->r_left);
                //*id+=1;
            }	
            else
            {
                *id-=1;
                return;
            }
			break;
			
		case RIGHT:
			if(room->r_right != nullptr)
				CreateRoom(room->r_right, id, x+1, y, qnt);
			else if(x+1 < qnt && matriz[x+1][y] == false)
            {
            	room->r_right = new Room(this, sala + numero1 + numero2);
            	room->r_right->r_left = room;
				//rooms->right = InsertRoom(*id, rooms, NULL, NULL, NULL);
                matriz[x+1][y] = true;
                //add_child(room->r_right);
                //*id+=1;
            }
            else
            {   
                *id-=1;
                return;
            }
			break;
		
		case TOP:
			if(room->r_top != nullptr)
				CreateRoom(room->r_top, id, x, y-1, qnt);
			else if(y-1 >= 0 && matriz[x][y-1] == false)
            {
				room->r_top = new Room(this, sala + numero1 + numero2);
				room->r_top->r_botton = room;
                matriz[x][y-1] = true;
                //add_child(room->r_top);
                //*id+=1;
            }
            else
            {   
                *id-=1;
                return;
            }
			break;
		
		case BOTTOM:
			if(room->r_botton != nullptr)
				CreateRoom(room->r_botton, id, x, y+1, qnt);
			else if(y+1 < qnt && matriz[x][y+1] == false)
            {
				room->r_botton = new Room(this, sala + numero1 + numero2);
				room->r_botton->r_top = room;
                matriz[x][y+1] = true;
                //add_child(room->r_botton);
                //*id+=1;
            }
            else
            {
                *id-=1;
                return;
            }
			break;
	}
}


// Generate all the map
void Map::GenerateMap(int quantidade_salas)
{
	int id = 0;

	
    int x = rand() % quantidade_salas/2 + 1;
    int y = x;
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matriz[i][j] = false;
        }
    }
    printf("Gerou a matriz\n");
	Room *room = new Room(this,"sala 00");
	matriz[x][y] = true;
    id+=1;
	for(id = 1;id < quantidade_salas; id++)
	{	
		CreateRoom(room, &id, x, y, quantidade_salas);
	}
    current_room = room;
    add_child(current_room);
    printf("saindo da generate\n");
}

Room *
Map::room()
{
	return current_room;
}

void
Map::enter_room(Room * anterior, Room * nova)
{
	remove_child(anterior);
	add_child(nova);
	current_room = nova;
}

void Map::draw_self()
{
}