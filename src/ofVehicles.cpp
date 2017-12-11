#include "ofVehicles.h"


void ofVehicles::vehicle() {
    prevX = x;
    prevY = y;
}

void ofVehicles::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void ofVehicles::adjustSpeed(float speedChange) {
    speed += speedChange;
}

void ofVehicles::move() {
    prevX = x;
    prevY = y;
    
    x += speed * cos(glm::radians(heading));
    y += speed * sin(glm::radians(heading));
}

//void ofVehicles::setHeading(float degrees) {
//    heading = degrees;
//    heading = (int) heading % 360;
//    heading += 360;
//    heading = (int) heading % 360;
//}
//
//void ofVehicles::adjustHeading(float degrees) {
//    heading += degrees;
//    heading = (int) heading % 360;
//    heading += 360;
//    heading = (int) heading % 360;
//}

void ofVehicles::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
}

void ofVehicles::rotateTowards(float targetX, float targetY, float amount) {
    float targetHeadingX = targetX-x;
    float targetHeadingY = targetY-y;
    float targetHeading = glm::degrees(atan2(targetHeadingY, targetHeadingX));
    
    float diff = ofWrap((targetHeading - heading), 0, 360);
    cout << "Diff: " << diff << endl;
    
    float absDiff = abs(diff);
    float otherDiff = 360 - absDiff;
    
    if (absDiff < abs(otherDiff)) {
        heading += diff * amount;
    } else {
        heading += otherDiff * amount;
    }
    
    heading += 360;
    heading = ofWrap(heading, 0, 360);
    
    cout << "Heading: " << heading << endl;
}





