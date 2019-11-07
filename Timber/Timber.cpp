#include <iomanip>
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Block.h"
#include "Timber.h"

using namespace sf;

int main(){
	//Create a video mode object, high and low res
	VideoMode vm(1920, 1080);
	//VideoMode vm(1280, 720);


	//Create and open a window for the game
	RenderWindow window(vm, "Tag", Style::Fullscreen);
	window.setMouseCursorVisible(false);
	//RenderWindow window(vm, "Tag");
	//View view(FloatRect(0, 0, 1280, 720));
	//window.setView(view);



	//Get some timers
	Clock it_clock;
	Clock move_clock;
	Clock countdown_clock;
	//Get text
	Font font;
	font.loadFromFile("fonts/MajorMonoDisplay-Regular.ttf");
	Text countdown;
	countdown.setFont(font);
	countdown.setCharacterSize(200);
	countdown.setPosition(886, 414);
	countdown.setFillColor(Color::White);
	Text time_since_tag;
	time_since_tag.setFont(font);
	time_since_tag.setCharacterSize(50);
	time_since_tag.setPosition(982, -1);
	time_since_tag.setFillColor(Color::White);
	Text time_aggregate_p1;
	time_aggregate_p1.setFont(font);
	time_aggregate_p1.setCharacterSize(58);
	time_aggregate_p1.setPosition(1570, -6);
	time_aggregate_p1.setFillColor(Color::White);
	Text time_aggregate_p2;
	time_aggregate_p2.setFont(font);
	time_aggregate_p2.setCharacterSize(58);
	time_aggregate_p2.setPosition(6, -6);
	time_aggregate_p2.setFillColor(Color::White);
	Text it_p1;
	it_p1.setFont(font);
	it_p1.setString("it");
	it_p1.setCharacterSize(50);
	it_p1.setPosition(1844, -1);
	it_p1.setFillColor(Color(227, 44, 44));
	Texture it_background_texture;
	it_background_texture.loadFromFile("graphics/barcover.png");
	Sprite it_background_p1;
	it_background_p1.setTexture(it_background_texture);
	it_background_p1.setPosition(1842, 8);
	Text it_p2;
	it_p2.setFont(font);
	it_p2.setString("it");
	it_p2.setCharacterSize(50);
	it_p2.setPosition(0, -1);
	it_p2.setFillColor(Color(227, 44, 44));
	Texture it_background_cover_p2;
	it_background_cover_p2.loadFromFile("graphics/barcover.png");
	Sprite it_background_p2;
	it_background_p2.setTexture(it_background_cover_p2);
	it_background_p2.setPosition(-2, 8);
	Text loser;
	loser.setFont(font);
	loser.setString("loser");
	loser.setCharacterSize(50);
	loser.setPosition(-500, -500);
	loser.setFillColor(Color(227, 44, 44));
	


	/*
	Create sprites
	*/

	//Create cursor
	Mouse mouse;
	Texture texture_cursor;
	texture_cursor.loadFromFile("graphics/cursor.png");
	Sprite cursor;
	cursor.setTexture(texture_cursor);

	//Create background
	Texture texture_background;
	texture_background.loadFromFile("graphics/background.png");
	Sprite sprite_background;
	sprite_background.setTexture(texture_background);
	sprite_background.setPosition(0, 0);

	//Create Players
	Texture texture_p1;
	Texture it_texture_p1;
	Texture texture_p2;
	Texture it_texture_p2;
	Player player1(1);
	Player player2(2);
	texture_p1.loadFromFile("graphics/player1.png");
	it_texture_p1.loadFromFile("graphics/player1it.png");
	texture_p2.loadFromFile("graphics/player2.png");
	it_texture_p2.loadFromFile("graphics/player2it.png");
	player1.setTexture(it_texture_p1);
	player2.setTexture(texture_p2);
	player1.setPosition(1728, 960);
	player2.setPosition(128, 960);
	player1.setIt(true);
	player2.setIt(false);
	std::vector<Player> players;
	players.push_back(player1);
	players.push_back(player2);

	//Create fillbar textures and sprites
    //Player1 fillbar
	Texture texture_fillbaroutline_p1;
	texture_fillbaroutline_p1.loadFromFile("graphics/fillbaroutline.png");
	Sprite fillbaroutline_p1;
	fillbaroutline_p1.setTexture(texture_fillbaroutline_p1);
	fillbaroutline_p1.setPosition(1038, 8);
	Texture texture_fillbar_p1;
	texture_fillbar_p1.loadFromFile("graphics/fillbar.png");
	Sprite fillbar_p1;
	fillbar_p1.setTexture(texture_fillbar_p1);
	fillbar_p1.setPosition(1840, 8);
	//Player2 fillbar
	Texture texture_fillbaroutline_p2;
	texture_fillbaroutline_p2.loadFromFile("graphics/fillbaroutline.png");
	Sprite fillbaroutline_p2;
	fillbaroutline_p2.setTexture(texture_fillbaroutline_p2);
	fillbaroutline_p2.setPosition(78, 8);
	Texture texture_fillbar_p2;
	texture_fillbar_p2.loadFromFile("graphics/fillbar.png");
	Sprite fillbar_p2;
	fillbar_p2.setTexture(texture_fillbar_p2);
	fillbar_p2.setPosition(-720, 8);

	//create pause menu graphics
	Texture texture_pause_overlay;
	texture_pause_overlay.loadFromFile("graphics/pauseoverlay.png");
	Sprite pause_overlay;
	pause_overlay.setTexture(texture_pause_overlay);
	pause_overlay.setPosition(0, 0);
	Text resume;
	resume.setFont(font);
	resume.setString("resume");
	resume.setCharacterSize(100);
	resume.setPosition(738, 300);
	Text newgame;
	newgame.setFont(font);
	newgame.setString("new game");
	newgame.setCharacterSize(100);
	newgame.setPosition(670, 600);
	Text to_menu;
	to_menu.setFont(font);
	to_menu.setString("main menu");
	to_menu.setCharacterSize(100);
	to_menu.setPosition(630, 800);

	//create main menu graphics
	Texture texture_menu_background;
	texture_menu_background.loadFromFile("graphics/menubackground.png");
	Sprite menu_background;
	menu_background.setTexture(texture_menu_background);
	menu_background.setPosition(0, 0);
	Text start;
	start.setFont(font);
	start.setString("start");
	start.setCharacterSize(100);
	start.setPosition(738, 300);
	Text exit;
	exit.setFont(font);
	exit.setString("exit");
	exit.setCharacterSize(100);
	exit.setPosition(670, 600);

	//Create platformblocks
	Texture texture_platformblock;
	texture_platformblock.loadFromFile("graphics/platformblock.png");
	Texture texture_sceneblock;
	texture_sceneblock.loadFromFile("graphics/sceneblock.png");
	Texture texture_launchblock;
	texture_launchblock.loadFromFile("graphics/launchblock.png");
	//Level Layout - each "B" (block) or "-" (nothing) is 64 pixels.
	std::string platform_layout =
		"AYYYYYYYYYYYYYYYYYYYYYYYYYYYYA"
		"X----..-------..-------..----X"
		"X----..-------..-------..----X"
		"X----TR-------..-------TR----X"
		"X-------------..-------------X"
		"X-------------..-------------X" 
		"X------------TYYR------------X"
		"X-------------..-------------X"
		"X--LYYR-------..-------TYYM--X"
		"X..X----------..----------X..X"
		"X..X---------TYYR---------X..X"
		"X..X----------..----------X..X"
		"X..X----------..----------X..X"
		"X--OYR--------..--------TYN--X"
		"X----------TYYYYYYR----------X"
		"X----------------------------X"
		"AJYYYYYYYYYYYYYYYYYYYYYYYYYYJA";
	float pixel_position_x = 0;
	float pixel_position_y = 0;
	std::vector<Block> blocks;
	for (std::size_t i = 0; i < platform_layout.length(); i++) {
		//collision blocks
		if (platform_layout.at(i) == 'A') {
			Block platform_block("A");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'X') {
			Block platform_block("X");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'Y') {
			Block platform_block("Y");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'L') {
			Block platform_block("L");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'M') {
			Block platform_block("M");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'N') {
			Block platform_block("N");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'O') {
			Block platform_block("O");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'Q') {
			Block platform_block("Q");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'R') {
			Block platform_block("R");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'S') {
			Block platform_block("S");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		if (platform_layout.at(i) == 'T') {
			Block platform_block("T");
			platform_block.setTexture(texture_platformblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		//dynamic blocks
		if (platform_layout.at(i) == 'J') {
			Block platform_block("J");
			platform_block.setTexture(texture_launchblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		//decorative blocks
		if (platform_layout.at(i) == '.') {
			Block platform_block(".");
			platform_block.setTexture(texture_sceneblock);
			platform_block.setPosition(pixel_position_x, pixel_position_y);
			blocks.push_back(platform_block);
		}
		pixel_position_x += 64;
		if ((i+1) % 30 == 0) {
			pixel_position_y += 64;
			pixel_position_x = 0;
		}
	}



	//state variables
	int total_tags = 0;
	int round = 1;
	bool paused = false;
	bool game_start = false;
	bool main_menu = true;

	//Execute game
	while (window.isOpen()) {
		/*
		Handle input
		*/
		//Non-movement
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		//Main menu functions
		if (cursor.getGlobalBounds().intersects(start.getGlobalBounds()) && (mouse.isButtonPressed(Mouse::Left)) && (main_menu == true)) {
			main_menu = false;
			game_start = true;
		}
		if (cursor.getGlobalBounds().intersects(exit.getGlobalBounds()) && (mouse.isButtonPressed(Mouse::Left)) && (main_menu == true)) {
			window.close();
		}

		//pause
		if (Keyboard::isKeyPressed(Keyboard::P)) {
			paused = true;
			game_start = false;
		}
		
		//Pause menu functions
		if (cursor.getGlobalBounds().intersects(resume.getGlobalBounds()) && (mouse.isButtonPressed(Mouse::Left)) && (paused == true)) {
			paused = false;
			game_start = true;
		}
		if (cursor.getGlobalBounds().intersects(newgame.getGlobalBounds()) && (mouse.isButtonPressed(Mouse::Left)) && (paused == true)) {
			for (Player& player : players) {
				if (player.getPlayerNumber() == 1) {
					player.setPosition(1728, 960);
					player.setScore(0);
					player.resetSpeeds();
					player.setIt(true);
					player.setTexture(it_texture_p1);
				}
				if (player.getPlayerNumber() == 2) {
					player.setPosition(128, 960);
					player.setScore(0);
					player.resetSpeeds();
					player.setIt(false);
					player.setTexture(texture_p2);
				}
				fillbar_p1.setPosition(1840, 8);
				fillbar_p2.setPosition(-720, 8);
			}
			paused = false;
			game_start = true;
		}
		if (cursor.getGlobalBounds().intersects(to_menu.getGlobalBounds()) && (mouse.isButtonPressed(Mouse::Left)) && (paused == true)) {
			paused = false;
			game_start = false;
			main_menu = true;
		}

		
		//countdown 
		if (game_start == true) {
			if (countdown_clock.getElapsedTime().asSeconds() <= 1) {
				countdown.setString("3");
			}
			else if (countdown_clock.getElapsedTime().asSeconds() <= 2) {
				countdown.setString("2");
			}
			else if (countdown_clock.getElapsedTime().asSeconds() <= 3) {
				countdown.setString("1");
			}
			else if (countdown_clock.getElapsedTime().asSeconds() <= 4) {
				game_start = false;
			}
		}

		//no time should pass as game is paused
		if (paused == true) {
			it_clock.restart();
			move_clock.restart();
			countdown_clock.restart();
		}
		if (main_menu == true) {
			it_clock.restart();
			move_clock.restart();
			countdown_clock.restart();
		}
		if (game_start == true) {
			it_clock.restart();
			move_clock.restart();
		}

		//check if game is paused, not starting, and not in main_menu
		if (paused == false && game_start == false && main_menu == false) {

			//Time passed
			int time_as_it = it_clock.restart().asMilliseconds();

			//add score as time as it increases/check for losers
			for (Player& player : players) {
				if ((player.getPlayerNumber() == 1) && (player.getScore() >= 60000)) {
					loser.setPosition(player.getPosition().x - 62, player.getPosition().y - 64);
					player.Freeze();
				}
				if ((player.getPlayerNumber() == 2) && (player.getScore() >= 60000)) {
					loser.setPosition(player.getPosition().x - 62, player.getPosition().y - 64);
					player.Freeze();
				}
			}
			for (Player& player : players) {
				if ((player.getPlayerNumber() == 1) && (player.getIt() == true)) { 
					player.addScore(time_as_it);
				}
				if ((player.getPlayerNumber() == 2) && (player.getIt() == true)) {
					player.addScore(time_as_it);
				}
			}

			//Movement
			//How long since last movement
			float delta = move_clock.restart().asSeconds();

			//Player movement
			for (Player& player : players) {
				//Player 1
				if (player.getPlayerNumber() == 1) {
					if (Keyboard::isKeyPressed(Keyboard::Right) && (player.getStoppedRight() == false)) {
						if (Keyboard::isKeyPressed(Keyboard::Left)) {
							//continually do nothing if both directions are pressed (avoid tiny movements via the movement function called last)
							player.Slide(delta);
							continue;
						}
						player.accelerateRight(delta);
						player.setMoving(true);
					}
					if (Keyboard::isKeyPressed(Keyboard::Left) && (player.getStoppedLeft() == false)) {
						if (Keyboard::isKeyPressed(Keyboard::Right)) {
							//continually do nothing if both directions are pressed (avoid tiny movements via the movement function called last)
							player.Slide(delta);
							continue;
						}
						player.accelerateLeft(delta);
						player.setMoving(true);
					}
					if ((Keyboard::isKeyPressed(Keyboard::Up)) && (player.getStoppedDown() == true)) {
						player.Jump(delta);
					}
					//call slide functions
					player.Slide(delta);
				}
				//Player 2
				if (player.getPlayerNumber() == 2) {
					if (Keyboard::isKeyPressed(Keyboard::D) && (player.getStoppedRight() == false)) {
						if (Keyboard::isKeyPressed(Keyboard::A)) {
							//continually do nothing if both directions are pressed (avoid tiny movements via the movement function called last)
							player.Slide(delta);
							continue;
						}
						player.accelerateRight(delta);
						player.setMoving(true);
					}
					if (Keyboard::isKeyPressed(Keyboard::A) && (player.getStoppedLeft() == false)) {
						if (Keyboard::isKeyPressed(Keyboard::D)) {
							//continually do nothing if both directions are pressed (avoid tiny movements via the movement function called last)
							player.Slide(delta);
							continue;
						}
						player.accelerateLeft(delta);
						player.setMoving(true);
					}
					if ((Keyboard::isKeyPressed(Keyboard::W)) && (player.getStoppedDown() == true)) {
						player.Jump(delta);
					}
					//call slide functions
					player.Slide(delta);
				}
			}
			//apply physics, clear collisions
			for (Player& player : players) {
				player.applyGravity(delta);
				player.clearCollisions();
				player.setMoving(false);
			}

			/*
			Check for collisions
			*/
			for (Player& player : players) {
				for (Block platform : blocks) {
					if (player.getGlobalBounds().intersects(platform.getGlobalBounds())) {
						//jumppad block
						if (platform.getCollideType().compare("J") == 0) {
							player.Launch(delta);
						}
						//blocks with all faces revealed
						if (platform.getCollideType().compare("A") == 0) {
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
						}
						//blocks with only a left or right face revealed
						if (platform.getCollideType().compare("X") == 0) {
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
						}
						//block with only a top or bottom face revealed
						if (platform.getCollideType().compare("Y") == 0) {
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
						}

						//block with left and top faces revealed
						if (platform.getCollideType().compare("L") == 0) {
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
						}
						//block with top and right faces revealed
						if (platform.getCollideType().compare("M") == 0) {
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
						}
						//block with right and bottom faces revealed
						if (platform.getCollideType().compare("N") == 0) {
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
						}
						//block with bottom and left faces revealed
						if (platform.getCollideType().compare("O") == 0) {
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
						}

						//block with left, top, and right faces revealed
						if (platform.getCollideType().compare("Q") == 0) {
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
						}
						//block with top, right, and bottom faces revealed
						if (platform.getCollideType().compare("R") == 0) {
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
						}
						//block with right, bottom, and left faces revealed
						if (platform.getCollideType().compare("S") == 0) {
							//collision on left of player block
							if ((((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && (((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left) >= ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top))) {
								//set new position to just outside the block's right side
								player.setPosition(platform.getPosition().x + platform.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedLeft(true);
							}
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
						}
						//block with bottom, left, and top faces revealed
						if (platform.getCollideType().compare("T") == 0) {
							//collision on top of player block
							if ((((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top) >= ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((player.getGlobalBounds().top + player.getGlobalBounds().width) - platform.getGlobalBounds().top) >= ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's bottom side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top + platform.getGlobalBounds().height);
								player.setStoppedUp(true);
							}
							//collision on right of player block
							if ((((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top)) && ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left) > ((player.getGlobalBounds().top + player.getGlobalBounds().height) - platform.getGlobalBounds().top)) {
								//set new position to just outside the block's left side
								player.setPosition(platform.getPosition().x - player.getGlobalBounds().width, player.getPosition().y);
								player.setStoppedRight(true);
							}
							//collision on bottom of player block
							if ((((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((player.getGlobalBounds().left + player.getGlobalBounds().width) - platform.getGlobalBounds().left)) && (((platform.getGlobalBounds().top + platform.getGlobalBounds().height) - player.getGlobalBounds().top) > ((platform.getGlobalBounds().left + platform.getGlobalBounds().width) - player.getGlobalBounds().left))) {
								//set new position to just outside block's top side
								player.setPosition(player.getPosition().x, platform.getGlobalBounds().top - player.getGlobalBounds().height);
								player.setStoppedDown(true);
							}
						}
					}
				}
				//collision with other player, swap its and skins
				for (Player& other_player : players) {
					if (other_player.getPlayerNumber() != player.getPlayerNumber()) {
						if ((player.getGlobalBounds().intersects(other_player.getGlobalBounds())) && (player.getScore() < 60000) && (other_player.getScore() < 60000)) {
							if (player.getIt() == true) {
								player.setIt(false);
								other_player.setIt(true);
								if (player.getPlayerNumber() == 1) {
									player.setTexture(texture_p1);
									other_player.setTexture(it_texture_p2);
								}
								else {
									player.setTexture(texture_p2);
									other_player.setTexture(it_texture_p1);
								}
							}
							else {
								player.setIt(true);
								other_player.setIt(false);
								if (player.getPlayerNumber() == 1) {
									player.setTexture(it_texture_p1);
									other_player.setTexture(texture_p2);
								}
								else {
									player.setTexture(it_texture_p2);
									other_player.setTexture(texture_p1);
								}
							}
							if (player.getPlayerNumber() == 1) {
								player.setPosition(1728, 960);
							}
							other_player.setPosition(128, 960);
							player.resetSpeeds();
							other_player.resetSpeeds();
							countdown_clock.restart();
							game_start = true;
						}
					}
				}
			}

		}
		/*
		Draw the scene
		*/
		//Clear last frame
		window.clear();

		//Draw this frame
		if (main_menu == false) {
			window.draw(sprite_background);
			for (Block& block : blocks) {
				if (block.getCollideType().compare(".") == 0) {
					window.draw(block);
				}
			}
			for (Player& player : players) {
				window.draw(player);
			}
			for (Block& block : blocks) {
				if (block.getCollideType().compare(".") != 0) {
					window.draw(block);
				}
			}
			for (Player& player : players) {
				if ((player.getPlayerNumber() == 1) && (player.getIt() == true) && (fillbar_p1.getPosition().x >= 1041)) {
					fillbar_p1.setPosition(1840 - player.getScore() / 75, 8);
				}
				if ((player.getPlayerNumber() == 2) && (player.getIt() == true) && (fillbar_p2.getPosition().x <= 79)) {
					fillbar_p2.setPosition(-720 + player.getScore() / 75, 8);
				}
			}
			window.draw(fillbar_p1);
			window.draw(fillbar_p2);
			window.draw(fillbaroutline_p1);
			window.draw(fillbaroutline_p2);
			window.draw(it_background_p1);
			window.draw(it_background_p2);
			window.draw(loser);
			for (Player& player : players) {
				if (player.getPlayerNumber() == 1) {
					if (player.getIt() == true) {
						window.draw(it_p1);
					}
				}
				if (player.getPlayerNumber() == 2) {
					if (player.getIt() == true) {
						window.draw(it_p2);
					}
				}
			}

			//draw pause overlay
			if (paused == true) {
				window.draw(pause_overlay);
				cursor.setPosition(mouse.getPosition().x, mouse.getPosition().y);
				window.draw(cursor);
				window.draw(newgame);
				window.draw(resume);
				window.draw(to_menu);
			}
			if (game_start == true) {
				window.draw(pause_overlay);
				window.draw(countdown);
			}
		}
		if (main_menu == true) {
			window.draw(menu_background);
			cursor.setPosition(mouse.getPosition().x, mouse.getPosition().y);
			window.draw(cursor);
			window.draw(start);
			window.draw(exit);
		}

		//Show everything we just drew
		window.display();
	}
	return 0;
}