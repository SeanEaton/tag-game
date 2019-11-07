#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public Sprite{
	int player_number;
	
	const float INIT_HSPEED = 0.f;
	const float MAX_HSPEED = 900.f;
	const float MIN_HSPEED = -900.f;
	const float INIT_VSPEED = 0.f;
	const float INIT_GRAV = 1190.f;
	const float INIT_ACCL = 6.f;
	const float INIT_FRIC = 8.f;
	const float INIT_SCORE = 0.f;

	float hspeed_p;
	float vspeed_p;
	float maxhspeed_p;
	float minhspeed_p;
	float grav_p;
	float accl_p;
	float fric_p;

	int score;

	bool moving;
	bool stopped_left;
	bool stopped_right;
	bool stopped_up;
	bool stopped_down;
	bool it;

public:

	Player(int number);

	int getPlayerNumber();

	float getHSpeed();
	float getVSpeed();
	int getScore();

	bool getMoving();
	bool getStoppedLeft();
	bool getStoppedRight();
	bool getStoppedUp();
	bool getStoppedDown();

	bool getIt();
	
	void accelerateLeft(float elapsed_time);
	void accelerateRight(float elapsed_time);
	void Slide(float elapsed_time);
	void Jump(float elapsed_time);
	void Launch(float elapsed_time);
	void Freeze();
	void Unfreeze();
	void resetSpeeds();

	void setMoving(bool boolean);
	void setStoppedLeft(bool boolean);
	void setStoppedRight(bool boolean);
	void setStoppedUp(bool boolean);
	void setStoppedDown(bool boolean);
	void setIt(bool boolean);
	void addScore(int amount);
	void setScore(int amount);

	void clearCollisions();
	void applyFriction();
	void applyGravity(float elapsed_time);
};