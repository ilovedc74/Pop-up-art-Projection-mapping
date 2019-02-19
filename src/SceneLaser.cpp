#include "SceneLaser.h"
#include "Settings.h"


void SceneLaser::reset(){
   
    ofClear(0); // uncomment if you want canvas to be reset on the buffer when fbo source is called again
}

void SceneLaser::setup(){

    name = "Scene Laser";

    allocate(700, 700);

    ofSetCircleResolution(60);
    ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    spacing = 20;
    dotNum = getWidth()/spacing;
    radius = 2;
    start = spacing/2;
    for (int i = 1; i<10000; i++){
        noiseSeeds.push_back(ofRandom(10000));
    }
    for (int i=0; i < dotNum; i++) {
        for (int j=0 ; j < dotNum; j++){
  
            int locX = start + spacing * i;
            int locY = start + spacing * j;
  
            points.push_back(ofPoint(locX,locY));
            
        }
    }
    
    draw();

    

}

void SceneLaser::setName(string _name){
    name = _name;
}


//--------------------------------------------------------------
void SceneLaser::update(){
    
    
}

//--------------------------------------------------------------
void SceneLaser::draw(){
    ofPushStyle();
    ofSetColor(255);
    for (int i=0; i<dotNum*dotNum; i++) {
        ofDrawCircle(points[i], radius);
    }
    
    a = ofRandom(dotNum*dotNum);
    posX.push_back(points[a][0]);
    posY.push_back(points[a][1]);

    ofColor c0 = ofColor(255);
    ofColor c1 = ofColor(200,0,0);
    ofColor c2 = ofColor(0,0,200);
    ofColor c3 = ofColor(0,200,0);
    ofColor c4 = ofColor(0);
    for (int i = 1; i<1000; i++){

        if (i<500) {
            ofSetColor(c0.getLerped(c1, noiseSeeds[i]));
        } else {
            ofSetColor(c1.getLerped(c2, noiseSeeds[i]));
        }

        noiseSeeds[i]+=0.01;

        ofSetLineWidth(5);
        ofDrawLine(posX[i-1], posY[i-1], posX[i], posY[i]);
    }
    float noise=ofNoise(ofGetElapsedTimef());
    ofSetColor(255,90);
    ofDrawCircle(fbo->getWidth()/2, fbo->getHeight()/2, 300*noise);

    ofPopStyle();
    
    
    }
    

    


