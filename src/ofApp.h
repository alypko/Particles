#pragma once

#include "ofMain.h"
#include "particles.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();
		void drawResis();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		int mode;
		vector <particles> p;
		vector<glm::vec3> attractPoints;
		vector <glm::vec3> attractPointsWithMovement;

		ofxPanel gui;
		ofxFloatSlider viscSlider;
		ofxFloatSlider deltTimeSlider;


		
};
