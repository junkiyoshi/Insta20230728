#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 300;
	auto deg_param = ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, 45, 180);
	for (int deg = 0; deg < 360; deg += 5) {

		auto location_1 = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		auto location_2 = glm::vec2((radius * 1.05) * cos((deg + deg_param) * DEG_TO_RAD), (radius * 1.05) * sin((deg + deg_param) * DEG_TO_RAD));

		ofDrawCircle(location_1, 3);
		ofDrawCircle(location_2, 3);
		ofDrawLine(location_1, location_2);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}