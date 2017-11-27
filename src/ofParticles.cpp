#include "ofParticles.h"


//--------------------------------------------------------------
void ofParticles::update(){
    //velocity += acceleration;
    position += velocity;
    
    if (position.x < 0 || position.x > ofGetWidth()) {
        velocity.x = velocity.x * -1;
    } else if (position.y < 0 || position.y > ofGetHeight()) {
        velocity.y = velocity.y * -1;
    }
}

//--------------------------------------------------------------
void ofParticles::draw(){
    ofDrawCircle(position, radius);
}





