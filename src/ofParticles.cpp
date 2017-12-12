#include "ofParticles.h"


//--------------------------------------------------------------
void ofParticles::update(){
    velocity += acceleration;
    position += velocity;
    
    if (position.x < 0 || position.x > ofGetWidth()) {
        velocity.x = velocity.x * -1;
    } else if (position.y < 0 || position.y > ofGetHeight()) {
        velocity.y = velocity.y * -1;
    }
    
    
    // Acceleration control for Horizontal movement
    if (position.x < minWidth) {
        acceleration.x = .05;
    } else if (position.x > maxWidth) {
        acceleration.x = -.05;
    } else if (position.x > minWidth && position.x < maxWidth) {
        acceleration.x = 0;
    }
    
    // Acceleration control for Vertical movement
    if (position.y < minHeight) {
        acceleration.y = .05;
    } else if (position.y > maxHeight) {
        acceleration.y = -.05;
    } else if (position.y > minHeight && position.y < maxHeight) {
        acceleration.y = 0;
    }
}

//--------------------------------------------------------------
void ofParticles::draw(){
    ofDrawCircle(position, radius);
    
    cout << "minHeight: " << minHeight << endl;
    cout << "maxHeight: " << maxHeight << endl;
}





