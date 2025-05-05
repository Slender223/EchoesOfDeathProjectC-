#pragma once
using namespace std;
#include <cmath>

template<typename T>
static void MoveTarget(int lBound, int rBound, T* target, bool& movingLeft, int dir, int speed) {

	if (target->getPosition().x >= lBound && !movingLeft) {
		dir = 1;
		if (target->getPosition().x >= rBound) {
			movingLeft = true;
			dir = 0;

		}
	}
	else if (target->getPosition().x <= rBound && movingLeft) {
		dir = 0;
		if (target->getPosition().x <= lBound) {
			movingLeft = false;
			dir = 1;
		}
	}

	if (dir == 0) {
		target->move(-speed, 0);
	}
	else {
		target->move(speed, 0);
	}

}

template<typename T>
static void ProjectileMov(int mouseX, int mouseY, T* projectile, bool isShot) {

	double r = sqrt(pow(mouseX + 840, 2) + pow(mouseY + 1320, 2));
	double x;
	x = mouseX - 840;
	double y = 1320 - mouseY;

	double rateX = x / r;
	double rateY = y / r;

	if (!isShot) {
		projectile->setPosition(840.0f, 1320.0f);
	}
	else {
		projectile->move(rateX * 15, -rateY * 15);
	}
}

template<typename T, typename U>
static bool checkCollision(T* projectile, U* target) {
	bool collision;
	if (projectile->getGlobalBounds().intersects(target->getGlobalBounds())) {
		collision = true;
	}
	else {
		collision = false;
	}
	return collision;
}



