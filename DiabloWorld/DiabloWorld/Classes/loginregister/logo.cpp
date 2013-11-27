//
//  logo.cpp
//  tsDemo
//
//  Created by jie on 13-8-9.
//
//

#include "logo.h"
#include "LayerLogin.h"

bool logo::init()
{
    bool flag=false;
    if(!CCLayer::init())
    {
        return false;
    }
    flag=true;
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    CCSprite *sprite=CCSprite::create("Default.png");
    sprite->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(sprite);
    CCFadeOut *out=CCFadeOut::create(2.0f);
    CCCallFunc *call=CCCallFunc::create(this, SEL_CallFunc(&logo::replace));
    CCFiniteTimeAction *finite=CCSequence::create(out,call,NULL);
    sprite->runAction(finite);
    return flag;
}

void logo::replace()
{
    CCScene *scene=CCScene::create();
    CCLayer *layer=LayerLogin::create();
    scene->addChild(layer);
    CCDirector::sharedDirector()->replaceScene(scene);
}