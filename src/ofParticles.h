#pragma once

#include "ofMain.h"

class ofParticles : public ofBaseApp{

public:
    void update() override;
    void draw() override;

    
    ofVec3f position;
    ofVec3f velocity;
    // ofVec3f acceleration;
    
    float radius = 5;
};
