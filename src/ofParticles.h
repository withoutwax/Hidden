#pragma once

#include "ofMain.h"

class ofParticles : public ofBaseApp{

public:
    void update() override;
    void draw() override;

    
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    
    float radius = 4;
    
    int minHeight = ofGetWindowHeight()*.333;
    int maxHeight = ofGetWindowHeight()*.666;
    int minWidth = (ofGetWindowWidth()/2)-(minHeight/2);
    int maxWidth = (ofGetWindowWidth()/2)+(minHeight/2);
    
};
