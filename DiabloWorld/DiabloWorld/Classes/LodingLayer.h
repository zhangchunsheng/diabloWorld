//
//  LodingLayer.h
//  client1
//
//  Created by lh on 13-3-23.
//
//

#ifndef __client1__LodingLayer__
#define __client1__LodingLayer__

#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <limits>
using namespace cocos2d;
using namespace CocosDenshion;
class Loading:public CCLayerColor{
public:
    virtual bool init();
    virtual void  registerWithTouchDispatcher();
    
    virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
    virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    ~Loading();
    CREATE_FUNC(Loading);
};
#endif /* defined(__client1__LodingLayer__) */
