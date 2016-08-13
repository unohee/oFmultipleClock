#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    tempo = 120;
    ticksPerBeat = 4;
    
    m.setTempo(tempo);
    m.setTicks(3);
    m.index = 0;
    eight.push_back(m);
    
    n.index = 1;
    n.setTempo(tempo);
    n.setTicks(8);
    eight.push_back(n);
    
    bps = (tempo / 60.) * ticksPerBeat;
    
    //Audio Setup
    ofSoundStreamSetup(2, 0, this, 44100, 1024, 4);
    ofAddListener(globalPlayHead, this, &ofApp::clockPlayed); //add listener that maxiClock's variable
    ofSoundStreamStop(); //in initial state, soundstream is stopped.
    isPlay = false; //and its boolean
    ofAddListener(globalPlayHead, this, &ofApp::clockPlayed); //add listener that maxiClock's variable
    for(int i=0;i < eight.size(); i++){
        ofAddListener(eight[i].individualPlayHead, this, &ofApp::multipleClocks);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}
//--------------------------------------------------------------
void ofApp::audioOut(float *output, int bufferSize, int nChannels){
    for(int i = 0; i < bufferSize; i++){
        m.ticker();
        for(auto &x:eight)
            x.ticker();
        
        currentCount=(int)clock.phasor(bps);
        
        if (lastCount!=currentCount){
            ofNotifyEvent(globalPlayHead, playHead, this);
            playHead++;//iterate the playhead
            lastCount=0;//reset the metrotest
        }
        //THIS DOES NOT SEND ANY AUDIO SIGNAL.
    }
}
//--------------------------------------------------------------
void ofApp::clockPlayed(int &eventArgs){
    int playHeadIn = eventArgs;
//    cout<<playHeadIn;
}
//--------------------------------------------------------------
void ofApp::multipleClocks(ClockOut &e){
    
    for(auto &x:eight){
        if(x.index == e.index){
            cout<<"Clock "<<e.index<<" "<<
            "PlayHead :"<<e.playHead<<" "<<ofGetElapsedTimef()<<endl;
        }
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key ==32){
        isPlay = !isPlay;
    }
    if(isPlay == true){
        ofSoundStreamStart();
    }
    else{
        ofSoundStreamStop();
        playHead = 0;
        m.playHead =0 ;
        
        for(auto &x:eight)
            x.playHead = 0;
    }

}
//--------------------------------------------------------------
void ofApp::exit(){
    ofSoundStreamClose();
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
