#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SceneLaser : public ofx::piMapper::FboSource {
	public:
		void setup();
		void update();
		void draw();
        void setName(string _name);
        void reset();
    vector <int> posX, posY;
    int spacing;
    float dotNum;
    int radius;
    float start;
    int locX, locY;
    int a,b; //dummy 4
    vector <ofPoint> points;
    vector <float> noiseSeeds;
		
};
