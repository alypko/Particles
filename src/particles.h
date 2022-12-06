#pragma once
#include "ofMain.h"

class particles
{
public:
	particles();

	void setAttractPoints(vector <glm::vec3>* attract);
	void setMode(int mode);

	void reset();
	void update();
	void draw();

	glm::vec3 pos;
	glm::vec3 vel;
	glm::vec3 frc;
	glm::vec3 accsel;
	glm::vec3 resisFrc;

	float drag;
	float scale;
	float mass;
	float radius;
	float visc;
	float deltaTime;
	int currMode;
	float attractorMass;


	vector <glm::vec3>* attractPoints;
	ofColor color;
};

