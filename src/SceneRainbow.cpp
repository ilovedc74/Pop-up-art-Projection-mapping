#include "SceneRainbow.h"
#include "Settings.h"

void SceneRainbow::reset(){
    ofClear(0); // uncomment if you want canvas to be reset on the buffer when fbo source is called again
}

void SceneRainbow::setup(){

    name = "Scene Rainbow";
 
    allocate(700, 700);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(60);
    ofSetFrameRate(60);
    spacing = 20;
    dotNum = getWidth()/spacing;
    radius = 2;
    start = spacing / 2;
    lines = 20;
    int locX, locY, i, j;
    
    for (i = 0; i<10000; i++){
        noiseSeeds.push_back(ofRandom(10000));
    }
    for (i = 0; i < dotNum; i++) {
        for (j = 0; j < dotNum; j++){
            locX = start + spacing * i;
            locY = start + spacing * j;
            points.push_back(ofPoint(locX,locY));
        }
    }

}

void SceneRainbow::draw(){
    ofPushStyle();
    ofSetColor(255, 30);
    for (int i=0; i<dotNum*dotNum; i++) {
        ofDrawCircle(points[i], radius);
    }
    
    
    a = ofRandom(dotNum*dotNum);
    posX.push_back(points[a][0]);
    posY.push_back(points[a][1]);

    ofColor c0 = ofColor(153,206,199);
    ofColor c1 = ofColor(176,224,216);
    ofColor c2 = ofColor(250,218,189);
    ofColor c3 = ofColor(250,190,160);
    ofColor c4 = ofColor(207,155,161);
    
    vector<ofColor> colors = {c0, c1, c2, c3, c4};
    for (int i = 1; i < lines; i++){

        int color_index = 0;

    ofSetColor(colors[color_index].getLerped(c1, noiseSeeds[i]));


        noiseSeeds[i]+=0.01;

        ofSetLineWidth(2);
        
        ofDrawLine(posX[i-1], posY[i-1], posX[i], posY[i]);
    }
    
    float noise=ofNoise(ofGetElapsedTimef());
    ofSetColor(255,90);
    ofDrawCircle(getWidth()/2, getHeight()/2, 300*noise);
 
    
    if (posX.size() >= lines) {
        posX.erase(posX.begin());
        posY.erase(posY.begin());
    }
    
    ofPopStyle();




}
    

    



