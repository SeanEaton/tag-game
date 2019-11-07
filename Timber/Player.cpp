#include "stdafx.h"
#include "Player.h"
#include <math.h>

using namespace sf;

Player::Player(int number) {
	player_number = number;

	hspeed_p = INIT_HSPEED;
	maxhspeed_p = MAX_HSPEED;
	minhspeed_p = MIN_HSPEED;
	vspeed_p = INIT_VSPEED;
	grav_p = INIT_GRAV;
	accl_p = INIT_ACCL;
	fric_p = INIT_FRIC;

	score = INIT_SCORE;

	moving = false;
	stopped_left = false;
	stopped_right = false;
	stopped_up = false;
	stopped_down = false;
	it = false;
}

int Player::getPlayerNumber() {
	return player_number;
}

float Player::getHSpeed() {
	return hspeed_p;
}
float Player::getVSpeed() {
	return vspeed_p;
}
int Player::getScore() {
	return score;
}

bool Player::getMoving() {
	return moving;
}
bool Player::getStoppedLeft() {
	return stopped_left;
}
bool Player::getStoppedRight() {
	return stopped_right;
}
bool Player::getStoppedUp() {
	return stopped_up;
}
bool Player::getStoppedDown() {
	return stopped_down;
}
bool Player::getIt() {
	return it;
}

void Player::accelerateLeft(float elapsed_time) {
	//if our movement is not max left speed, start turning speed left (negative)
	if (hspeed_p >= minhspeed_p) {
		hspeed_p -= accl_p;
		if (hspeed_p >= minhspeed_p) {
			move((hspeed_p * elapsed_time), 0);
		}
		else {
			hspeed_p = minhspeed_p;
			move((hspeed_p * elapsed_time), 0);
		}
	}
	//if we are at max left speed, or are faster than it, just move at the current pace, no more acceleration
	else {
		hspeed_p = minhspeed_p;
		move((hspeed_p * elapsed_time), 0);
	}
}
void Player::accelerateRight(float elapsed_time) {
	//if our movement is not max right speed, start turning speed right (postive)
	if (hspeed_p <= maxhspeed_p) {
		hspeed_p += accl_p;
		if (hspeed_p <= maxhspeed_p) {
			move((hspeed_p * elapsed_time), 0);
		}
		else {
			hspeed_p = maxhspeed_p;
			move((hspeed_p * elapsed_time), 0);
		}
	}
	//if we are at max right speed, or are faster than it, just move at the current pace, no more acceleration
	else {
		hspeed_p = maxhspeed_p;
		move((hspeed_p * elapsed_time), 0);
	}
}
void Player::Slide(float elapsed_time) {
	if ((hspeed_p < 0) && (moving == false)) {
			hspeed_p += fric_p;
			move((hspeed_p * elapsed_time), 0);
			if (hspeed_p > 0) {
				hspeed_p = 0.f;
			}
	}
	if ((hspeed_p > 0) && (moving == false)) {
		hspeed_p -= fric_p;
		move((hspeed_p * elapsed_time), 0);
		if (hspeed_p < 0) {
			hspeed_p = 0.f;
		}
	}
}
void Player::Jump(float elapsed_time) {
	vspeed_p = -750.f;
}
void Player::Launch(float elapsed_time) {
	vspeed_p = -1200.f;
}
void Player::Freeze() {
	hspeed_p = 0.f;
	vspeed_p = 0.f;
	grav_p = 0.f;
	accl_p = 0.f;
}
void Player::Unfreeze() {
	hspeed_p = INIT_HSPEED;
	vspeed_p = INIT_VSPEED;
	grav_p = INIT_GRAV;
	accl_p = INIT_ACCL;
}
void Player::resetSpeeds() {
	hspeed_p = 0.f;
	vspeed_p = 0.f;
}

void Player::setMoving(bool boolean) {
	moving = boolean;
}
void Player::setStoppedLeft(bool boolean) {
	stopped_left = boolean;
	hspeed_p = 0.f;
}
void Player::setStoppedUp(bool boolean) {
	stopped_up = boolean;
	vspeed_p = 0.f;
}
void Player::setStoppedDown(bool boolean) {
	stopped_down = boolean;
	vspeed_p = 0.f;
}
void Player::setStoppedRight(bool boolean) {
	stopped_right = boolean;
	hspeed_p = 0.f;
}
void Player::setIt(bool boolean) {
	it = boolean;
}
void Player::addScore(int amount) {
	score += amount;
}
void Player::setScore(int amount) {
	score = amount;
}

void Player::clearCollisions() {
	stopped_left = false;
	stopped_right = false;
	stopped_up = false;
	stopped_down = false;
}
void Player::applyFriction() {
	if (moving == true) {
		if (fabs(hspeed_p) < maxhspeed_p) {
			hspeed_p += fric_p;
		}
		else {
			hspeed_p = maxhspeed_p;
		}
	}
	else if (moving == false) {
		if (fabs(hspeed_p) > 0) {
			hspeed_p -= fric_p;
		}
		else {
			hspeed_p = 0.f;
		}
	}
}
void Player::applyGravity(float elapsed_time) {
	vspeed_p += (grav_p * elapsed_time);
	move(0, (vspeed_p * elapsed_time));
}