#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "INF_Clock.h"



typedef INF_Clock Metro;

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
    void exit();
    
    void audioOut(float * output, int bufferSize, int nChannels);
    void clockPlayed(int &e);
    void multipleClocks(ClockOut &e);
    int currentCount, lastCount, playHead;
    int tempo, ticksPerBeat;
    double bps;
    bool isPlay;
    maxiOsc clock;
    
    ofEvent<int>globalPlayHead;
    
    Metro m, n;
    vector<Metro> eight;
};
