#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    timer = 0;
    ofSetVerticalSync(true);

    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    ofEnableDepthTest();

    ofLoadImage(fishcolor,"Beta Fish_ambicol.bmp");

    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();

    // loads the OF logo from disk
    mImage0.load("0.png");
    mImage1.load("1.jpg");
    mImage2.load("2.png");
    mImage3.load("3.png");
    mImage4.load("4.png");
    mImage5.load("5.png");
    mImage6.load("6.png");
    mImage7.load("7.png");
    mImage8.load("8.png");
    mImage9.load("9.png");
    mImage10.load("10.jpg");
    mImage11.load("11.png");
    mImage12.load("12.png");
    mImage13.load("13.png");
    mImage14.load("15.png");
    
    wave.load("giphy.gif");
    wave1.load("wave1.jpg");
    wave2.load("wave2.jpg");
    wave3.load("wave3.jpg");
    
    fish.loadModel("Beta_Fish.3ds");
    fish.setScale(0.2, 0.2, 0.2);
    
    bgm.load("sea.mp3");
    bgm.play();
    
    nTri = 1500; // the number of triangles
    nVert = nTri*3; //the number of vertices
    
    float Rad = 250; //the sphere's radius
    float rad = 25; //maximal triangle's "radius"
    
    //fill the vertices array
    vertices.resize(nVert);
    for(int i=0;i<nTri;i++){
        //generate the center of the triangle
        //as a random point on the sphere
        
        //take the random point from
        //cube [-1,1]x[-1,1]x[-1,1]
        
        ofPoint center(ofRandom(-1,1),ofRandom(-1,1),ofRandom(-1,1));
        
        center.normalize();//normalize vector's length to 1
        center *=Rad; //now the center vector has length rad
        
        //generate the triangle's vertices
        //as the center plus random point from [-1,1]x[-1,1]x[-1,1]
        
        for(int j=0;j<3;j++){
            vertices[i*3+j] = center + ofPoint(ofRandom(-rad,rad),ofRandom(-rad,rad),ofRandom(-rad,rad));
            
        }
        
        
        
    }
    
    //fill the array of triangles' colors
    colors.resize(nTri);
    for(int i=0;i<nTri;i++){
        //take a random color from black to red
        colors[i] = ofColor(ofRandom(0,255),0,0);
    }
    
    for(int i=0;i<nTri;i++){
        bets.push_back(roundf(ofRandom(0,15)));
        
    }
    
    ocean.load("ocean.mp4");
    //ocean.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    ocean.update();
    
    /*if(timer >= 0 && timer < 120)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
    }
    else if(timer >= 120 && timer < 240)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
    }
    else if(timer >= 240 && timer < 360)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
        
    }*/
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ocean.draw(20,20);
    ofEnableDepthTest(); //enable z buffering
    ofSetHexColor(0xffffff);
    //ocean.draw(0, 0, ofGetWidth(), ofGetHeight());


    //set a gradient bacground from white to gray
    //for adding an illusion of visual depth to screen
    ofBackgroundGradient(ofColor(54, 119, 169), ofColor(20, 16, 120));
    
    
    /*if(timer >= 0 && timer < 120)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
    }
    else if(timer >= 120 && timer < 240)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
    }
    else if(timer >= 240 && timer < 360)
    {
        for(int i=0;i<nTri;i++){
            bets.push_back(roundf(ofRandom(0,15)));
        }
        
    }
*/
    ofPushMatrix();


    cam.begin();
    //fishcolor.bind();
    fish.setPosition(0, 0, 0);
    //fish.drawFaces();
    fish.drawWireframe();
    //fishcolor.unbind();
    ofTranslate(-ofGetWidth()/ 2, -ofGetHeight()/ 2);

    ofPushMatrix();
    //move the coordinate center to screen center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);
    //allow mouse to toggle the view
    ofRotate(-ofGetMouseX(), 0, 1, 0);

    //calculate the rotation angle
    float time=ofGetElapsedTimef();
    float angle = time*10; //compute angle,
    //rotate at speed 10 degrees per second

    ofRotate(angle, 0,1,0);

    //draw the triangles
    for(int i=0;i<nTri;i++){

       //cout<<bets[i]<<endl;

        if(bets[i]==0){
            mImage0.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage0.unbind();

        }if(bets[i]==1){
            mImage1.bind();
            ofFill();
            ofSetColor(255);
            ofDrawSphere(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage1.unbind();

        }else if(bets[i]==2){
            mImage2.bind();
            ofFill();
            ofSetColor(255);
            ofDrawPlane(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10,10);
            mImage2.unbind();
        }else if(bets[i]==3){
            mImage3.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage3.unbind();
        }else if(bets[i]==4){
            mImage4.bind();
            ofFill();
            ofSetColor(255);
            ofDrawSphere(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage4.unbind();
        }else if(bets[i]==5){
            mImage5.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage5.unbind();
        }else if(bets[i]==6){
            mImage6.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage6.unbind();
        }else if(bets[i]==7){
            mImage7.bind();
            ofFill();
            ofSetColor(255);
            ofDrawSphere(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage7.unbind();
        }else if(bets[i]==8){
            mImage8.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage8.unbind();
        }else if(bets[i]==9){
            mImage9.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage9.unbind();
        }else if(bets[i]==10){
            mImage10.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage10.unbind();
        }else if(bets[i]==11){
            mImage11.bind();
            ofFill();
            ofSetColor(255);
            ofDrawSphere(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage11.unbind();
        }else if(bets[i]==12){
            mImage12.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage12.unbind();
        }else if(bets[i]==13){
            mImage13.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage13.unbind();
        }else{
            mImage14.bind();
            ofFill();
            ofSetColor(255);
            ofDrawBox(vertices[i*3].x,vertices[i*3].y,vertices[i*3].z,10);
            mImage14.unbind();
        }

    }
    
    
    if(timer >= 0 && timer < 120)
    {
        wave1.bind();
        ofFill();
        ofDrawSphere(0, 0, 500);
        wave1.unbind();
    }
    else if(timer >= 120 && timer < 240)
    {
        wave1.bind();
        ofFill();
        ofDrawSphere(0, 0, 500);
        wave1.unbind();
    }
    else if(timer >= 240 && timer < 360)
    {
        wave2.bind();
        ofFill();
        ofDrawSphere(0, 0, 500);
        wave3.unbind();
        
    }
    else if(timer >=360)
    {
        timer = 0;
    }
    
    

    ofPopMatrix();//restore the coordinate system
    
    ofPopMatrix();

    cam.end();
    timer++;
    //cout<<timer<<endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

