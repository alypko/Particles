#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup();

	gui.add(viscSlider.setup("Viscosity Slider", 1.0e-2, 1.0e-4, 0.1));
	gui.add(deltTimeSlider.setup("Delta Time Slider", 0.15, 0.001, 0.5));

	ofSetVerticalSync(true);
	int num = 1000;
	p.assign(num, particles());

	resetParticles();
}

void ofApp::resetParticles()
{
	mode = 0;
	attractPoints.clear();
	//attractPoints.push_back(glm::vec3(ofGetWidth() / 2, ofGetHeight() / 2, 0));

	/*attractPointsWithMovement = attractPoints;*/

	for (unsigned int i = 0; i < p.size(); i++) {
		p[i].setAttractPoints(&attractPoints);
		p[i].reset();
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (unsigned int i = 0; i < p.size(); i++) {
		p[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));
	if (mode == 1) {
		ofEnableAlphaBlending();
		ofSetColor(135, 206, 235, 127);
		ofFill();
		ofDrawRectangle(0, 0, ofGetWidth() / 4, ofGetHeight());
	}

	for (unsigned int i = 0; i < p.size(); i++) {
		p[i].visc = viscSlider;
		p[i].deltaTime = deltTimeSlider;
		p[i].draw();
		p[i].setMode(mode);
	}

	ofSetColor(255, 0, 0);
	for (unsigned int i = 0; i < attractPoints.size(); i++) {
		ofNoFill();
		ofDrawCircle(attractPoints[i], 15);
		ofFill();
		ofDrawCircle(attractPoints[i], 8);
	}
	ofSetColor(230);
	ofDrawBitmapString("Spacebar to reset. \nKey R - to remove last added attract point.\nKey F - to add/remove fluid resistance. ", 220, 20);

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		resetParticles();
	}
	else if (key == 'r') {
		if (attractPoints.size() > 0)
		{
			attractPoints.pop_back();
		}
	}
	else if (key == 'f') {
		mode = mode == 1 ? mode = 0 : mode = 1;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (button == 0)
	{
		attractPoints.push_back(glm::vec3(x, y, 0));

		for (unsigned int i = 0; i < p.size(); i++) {
			p[i].setAttractPoints(&attractPoints);
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
