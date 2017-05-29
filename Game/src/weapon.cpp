#include <iostream>
#include "image.h"
#include "keyboardevent.h"
#include "environment.h"

#include "weapon.h"

Weapon::Weapon(Object *parent, ObjectID id, const string& path, 
	int resistance,	double damage, int attack_speed)
    :Image(parent, id, path)
    {
    	m_damage = damage;
    	m_attack_speed = attack_speed;
    	m_resistance = resistance;
    }
