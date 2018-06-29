#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    vector<ofPoint> vertices;
    vector<ofColor> colors;
    int nTri;  // the number of triangles
    int nVert;  // the number of vertices
    
    ofLight light;
    ofEasyCam cam;
    
    ofShader mShader;
    ofImage mImage0;
    ofImage mImage1;
     ofImage mImage2;
     ofImage mImage3;
    ofImage mImage4;
    ofImage mImage5;
    ofImage mImage6;
    ofImage mImage7;
    ofImage mImage8;
    ofImage mImage9;
    ofImage mImage10;
    ofImage mImage11;
    ofImage mImage12;
    ofImage mImage13;
    ofImage mImage14;
    
    ofVideoPlayer ocean;
    ofImage wave;
    ofImage wave1;
    ofImage wave2;
    ofImage wave3;
    
    int timer;
    
    ofSoundPlayer bgm;

    
    ofxAssimpModelLoader fish;
    ofTexture fishcolor;
    
    //list to store which one to store
    vector<float> bets;
    
};

