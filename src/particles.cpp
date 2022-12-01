#include "particles.h"


particles::particles() {
	attractPoints = NULL;
}

void particles::setAttractPoints(vector<glm::vec3>* attract) 
{
	attractPoints = attract;
}

void particles::setMode(int mode) {
	currMode = mode;
}

void particles::reset()
{
	//intitial position for particles
	pos.x = ofRandomWidth();
	pos.y = ofRandomHeight();
	pos.z = 0;

	vel.x = ofRandom(-3.5, 3.5);
	vel.y = ofRandom(-3.5, 3.5);
	vel.z = 0;

	frc = glm::vec3(0, 0, 0);
	mass = ofRandom(0.5, 3.0);

	scale = ofRandom(1, 1.3);
	radius = ofRandom(1.0, 3.0);
	drag = ofRandom(0.9, 0.998);

	color.g = mass * 85.0f;
	color.b = fmod(color.g, 200.0f);
	color.r = fmod(color.b, color.g);


}

void particles::update()
{
	if (attractPoints)
	{
		glm::vec3 closestPt;
		int closest = -1;
		float closestDist = 9999999;

		for (unsigned int i = 0; i < attractPoints->size(); i++)
		{
			float lenSq = glm::length2(attractPoints->at(i) - pos);
			if (lenSq < closestDist)
			{
				closestDist = lenSq;
				closest = i;


				if (closest != -1)
				{
					closestPt = attractPoints->at(closest);
					float dist = sqrt(closestDist);
					glm::vec3 dir = (closestPt - pos) / dist;

					frc = (1 / closestDist) * dir;
					if (dist < ofGetWidth()) {

						if (currMode == 1 && pos.x < (ofGetWidth() / 4))
						{
							//resisFrc *= 0;
							resisFrc = -6 * 3.14159 * vel * visc * radius;
							accsel = glm::normalize(frc + resisFrc) / mass;
						}
						else
						{
							accsel = glm::normalize(frc)/ mass;
						}
					}
					
					vel += accsel * deltaTime;

				}
			}
		}

		// Update position
		pos += vel * deltaTime;

		if (pos.x > ofGetWidth()) {
			pos.x = ofGetWidth();
			vel.x *= -1.0;
		}
		else if (pos.x < 0) {
			pos.x = 0;
			vel.x *= -1.0;
		}
		if (pos.y > ofGetHeight()) {
			pos.y = ofGetHeight();
			vel.y *= -1.0;
		}
		else if (pos.y < 0) {
			pos.y = 0;
			vel.y *= -1.0;
		}
	}
}

void particles::draw()
{
	ofSetColor(color.r, color.g, color.b);
	ofDrawCircle(pos.x, pos.y, scale * radius);
	
}
