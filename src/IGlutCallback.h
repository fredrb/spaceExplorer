//
// Created by VitorVRS on 10/7/16.
//

#ifndef STAR_EXPLORER_IGLUTCALLBACK_H
#define STAR_EXPLORER_IGLUTCALLBACK_H

class IGlutCallback {

public:
    virtual ~IGlutCallback() {};
    virtual void display() {};
    virtual void update(int value) {};
    virtual void mouse() {};
    virtual void specialKeys(int key, int x, int y) {};
    virtual void keyboard(unsigned char key, int x, int y) {};

};


#endif // STAR_EXPLORER_IGLUTCALLBACK_H
