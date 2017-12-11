#include "ofApp.h"
#include "ofxPS3EyeGrabber.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    
    //grabber.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    
    grabber.setup(640, 480);
    tracker.setup();
    
    //screenSaver.load("screensaver.mp4");
    //screenSaver.play();
    
    
    
    
    // Drawing 01 - Particle Triangle ===============================
    ofParticles p;
    
    for (int i = 0; i < numOfParticles; i++) {
        p.position.x = ofRandom(0, ofGetWidth());
        p.position.y = ofRandom(0, ofGetHeight());
        
        p.velocity.x = ofRandom(-1, 1);
        p.velocity.y = ofRandom(-1, 1);
        
        particles.push_back(p);
        particles01.push_back(p);
        particles02.push_back(p);
    }
    cout << particles01.size();

    
    
    
    // Drawing 02 - Perlin Noise ===============================
    cols = w / scl;
    rows = h / scl;
    
    ofEnableAlphaBlending();
    
}



//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    if (grabber.isFrameNew()) {
        tracker.update(toCv(grabber));
    }
   //screenSaver.update();
    
    if(tracker.getFound()) {
        if (alpha > 1) {
            alpha = alpha * .5;
        } else if (alpha < 1) {
            alpha = alpha * 0;
        }
    } else if (tracker.getFound() == false) {
        if (alpha <= 255) {
            alpha = alpha * 2;
        }
    }
    
    // Drawing 01 - Particle Triangle
    for (ofParticles& a: particles) {
        a.update();
    }
    for (ofParticles& b: particles01) {
        b.update();
    }
    for (ofParticles& c: particles02) {
        c.update();
    }
}




//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    grabber.draw(0, 0);
    tracker.draw();

    ofSetColor(0, 0, 0);
    ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    ofDrawBitmapString(alpha, 10, 70);


    float fadeTime = 0.5;

    if (tracker.getFound()) {
        tracking = true;
        // TRACKING IS TRUE
        // THERE IS FACE ON THE SCREEN

       ofDrawBitmapString("TRUE", 10, 50);

    } else {
        tracking = false;
        // TRACKING IS FALSE
        // THERE IS NO FACE ON THE SCREEN

        ofDrawBitmapString("FALSE", 10, 50);

    }
    ofSetColor(255, 255, 255, alpha);
    //screenSaver.draw(640, 0, 640, 480);

    //DRAWINGS

    drawing01();
//    drawing02();
}






// Drawing 01 - Particle Triangle ===================================
void ofApp::drawing01() {
    drawParticles();
    drawLines();
}

void ofApp::drawParticles() {
    ofSetColor(0, 0, 0, alpha);
    for (ofParticles& b: particles) {
        b.draw();
    }
//    for (ofParticles& b: particles01) {
//        ofSetColor(ofColor::red);
//        b.draw();
//    }
//    for (ofParticles& b: particles02) {
//        ofSetColor(ofColor::blue);
//        b.draw();
//    }
}

void ofApp::drawLines() {
    
    
    for (int i = 0; i < particles01.size(); i++) {
        for (int j = 0; j < particles02.size(); j++) {
            float distX = abs(particles01[i].position.x - particles02[j].position.x);
            float distY = abs(particles01[i].position.y - particles02[j].position.y);
            
            float dist = sqrt((distX*distX) + (distY*distY));

            if (dist < 100) {
                ofSetLineWidth(1);
                ofDrawLine(particles01[i].position.x, particles01[i].position.y, particles02[j].position.x, particles02[j].position.y);
            }
        }
    }
}




// Drawing 02 - Perlin Noise ====================================
void ofApp::drawing02() {
    perlinDraw();
}

void ofApp::perlinDraw() {
    float terrain[cols][rows];
    
    ofSetColor(0, 0, 0, alpha);
    ofNoFill();
    
    flying -= 0.05;
    
    float xOff = flying;
    
    for (int x = 0; x < cols; x++) {
        float yOff = 0;
        for (int y = 0; y < rows; y++) {
            terrain[x][y] = ofMap(ofNoise(xOff, yOff), 0, 1, -30, 30);
            xOff += 0.1;
        }
        yOff += 0.1;
    }
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateX(50);
    ofTranslate(-w/2, -h/2);
    
    for (int x = 0; x < cols; x++) {
        ofBeginShape();
        for (int y = 0; y < rows - 1; y++) {
            int randomX = ofRandom(10);
            ofVertex((x+1)*scl, y*scl, terrain[x+1][y]);
            ofVertex(x*scl, y *scl, terrain[x][y]);
            ofVertex(x*scl, (y+1)*scl, terrain[x][y+1]);
            ofVertex((x+1)*scl, y*scl, terrain[x+1][y]);
        }
        ofEndShape();
    }
}



// Drawing 04 = Diffuse Limited Aggregation
void ofApp::drawing04() {
    
}



