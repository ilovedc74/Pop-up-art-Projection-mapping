#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SceneTangle : public ofx::piMapper::FboSource {
    public:
		void setup();
		void update();
		void draw();
        void reset();

    private:
        ofPolyline createLine(int i, int rectLength, int canvasWidth, int canvasHeight);
        void restartLines();
    
        ofPoint pos;
        float lightPoints;
        int RECT_LENGTH;
        int CANVAS_WIDTH;
        int CANVAS_HEIGHT;
        int currLineIndex;
        vector <ofPolyline> lines;
};
