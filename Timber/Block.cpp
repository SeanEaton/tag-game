#include "stdafx.h"
#include "Block.h"

using namespace sf;

Block::Block(std::string symbol) {
	collide_type = symbol;
}

std::string Block::getCollideType() {
	return collide_type;
}