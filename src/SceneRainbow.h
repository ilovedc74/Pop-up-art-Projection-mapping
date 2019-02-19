#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SceneRainbow : public ofx::piMapper::FboSource {
public:
		void setup();
		void draw();
        void reset();

    

    
    vector <int> posX, posY;
    int spacing;
    float dotNum;
    int radius;
    float start;
    int locX, locY;
    int a,b; //dummy 4
    int lines;
    vector <ofPoint> points;
    vector <float> noiseSeeds;
		
};
