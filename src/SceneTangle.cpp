#include "SceneTangle.h"
#include "Settings.h"

void SceneTangle::reset(){
    ofClear(0); // uncomment if you want canvas to be reset on the buffer when fbo source is called again
    restartLines();
}

//--------------------------------------------------------------
void SceneTangle::setup(){
    name = "Scene Tangle";
    allocate(700, 700);
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    RECT_LENGTH = 35;
    CANVAS_WIDTH = ofGetWidth();
    CANVAS_HEIGHT = ofGetHeight();
    lightPoints = 0;
    currLineIndex = 0;

    // TODO: store 10 in somewhere
    for (int i = 0; i < 10; i += 2) {
        lines.push_back(createLine(i, RECT_LENGTH, CANVAS_WIDTH, CANVAS_HEIGHT));
    }

}

void SceneTangle::update(){
    if (currLineIndex < lines.size()) {
        if (lightPoints < 1) {
            pos = lines[currLineIndex].getPointAtPercent(lightPoints);
            lightPoints += 0.001f;
        } else {
            currLineIndex++;
            lightPoints = 0;
        }
    }
}

void SceneTangle::draw(){
    ofPushStyle();
    ofSetColor(255);
    ofDrawRectangle(pos,RECT_LENGTH,RECT_LENGTH);
    ofPopStyle();
}

void SceneTangle::restartLines() {
    currLineIndex = 0;
    lightPoints = 0;
}

ofPolyline SceneTangle::createLine(int i, int rectLength, int canvasWidth, int canvasHeight) {
    int topLeft = i * rectLength;
    int topRight = canvasWidth - (i + 1) * rectLength;
    int bottomRight = canvasHeight - (i + 1) * rectLength;
    ofPolyline line;
    line.addVertex(topLeft,topLeft);
    line.addVertex(topRight,topLeft);
    line.addVertex(topRight,bottomRight);
    line.addVertex(topLeft,bottomRight);
    line.addVertex(topLeft,topLeft);
    return line;
}
