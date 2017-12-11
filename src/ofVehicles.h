#pragma once

#include "ofMain.h"

class ofVehicles : public ofBaseApp{

//  Implemented from code created during ARTTECH 3037-001 Object Oriented Programming with Jacob Tonski. This example is originally written by Jacob in JAVA with Processing.
    
    /*
    things you can tell a vehicle to do:
    (here, assuming your vehicle variable is called myVehicle)
     
    //directly set the vehicle's position [0-width, 0-height]
    myVehicle.setPosition(x, y);
     
    //directly set the direciton the vehicle is pointing, [0-360]
    myVehicle.setHeading(angle);
     
    //directly set the speed the vehicle is moving at [pixels per update]
    myVehicle.setSpeed(speed);
     
    //change the speed the vehicle is moving at [pixels per update]
    myVehicle.adjustSpeed(speed);
     
    //adjust the heading - this means add this angle to the current heading
    [-360 - +360]
    myVehicle.adjustHeading(angleChange);
     
    //rotate some amount towards a target
    [targetX, targetY, 0-1]
    myVehicle.rotateTowards(x, y, percentage);
     
    //you always have to call this function to update position based on heading:
    myVehicle.move();
    */
    
public:
    void vehicle();
    void setSpeed(float newSpeed);
    void adjustSpeed(float speedChange);
    void move();
    //void setHeading(float degrees);
    //void adjustHeading(float degrees);
    void setPosition(float newX, float newY);
    
    void rotateTowards(float targetX, float targetY, float amount);
    
    float heading = 0;
    float speed = 0;
    float x = 0;
    float y = 0;
    float prevX = 0;
    float prevY = 0;
    
    
};
