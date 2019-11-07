#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block : public Sprite{
	std::string collide_type;
	Texture block_texture;
	Sprite block_sprite;

public:
	Block(std::string collision_type);
	std::string getCollideType();
};