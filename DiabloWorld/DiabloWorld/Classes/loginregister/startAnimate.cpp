//
//  startAnimate.cpp
//  zd
//
//  Created by jie on 13-7-22.
//
//

#include "startAnimate.h"
#include "xuanren.h"

bool startAnimate::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    CCSize winSize=CCDirector::sharedDirector()->getWinSize();
    str1=CCSprite::create("bgk1.png");
    str1->setPosition(ccp(winSize.width/2, winSize.height/2));
    this->addChild(str1);
    
    str2=CCSprite::create("words.png");
    str2->setPosition(ccp(winSize.width/2-60, winSize.height/2+160));
    str2->setVisible(false);
    this->addChild(str2);
    
    str3=CCSprite::create("words1.png");
    str3->setPosition(ccp(winSize.width/2-10, winSize.height/2+90));
    str3->setVisible(false);
    this->addChild(str3);
    
    str4=CCSprite::create("bgk2.png");
    str4->setPosition(ccp(winSize.width/2, winSize.height/2));
    str4->setVisible(false);
    this->addChild(str4);
    
    str7=CCSprite::create("words2.png");
    str7->setPosition(ccp(winSize.width/2-60, winSize.height/2+160));
    str7->setVisible(false);
    this->addChild(str7);
    
    str5=CCSprite::create("bgk3.png");
    str5->setPosition(ccp(winSize.width/2, winSize.height/2));
    str5->setVisible(false);
    this->addChild(str5);
    
    str8=CCSprite::create("words3.png");
    str8->setPosition(ccp(winSize.width/2-60, winSize.height/2+160));
    str8->setVisible(false);
    this->addChild(str8);
    
    str6=CCSprite::create("bgk4.png");
    str6->setPosition(ccp(winSize.width/2, winSize.height/2));
    str6->setVisible(false);
    this->addChild(str6);
    
    CCMenuItemImage *item=CCMenuItemImage::create("start_xr.png", "start_xr1.png", this, SEL_MenuHandler(&startAnimate::menuItemCallbackXr));
    CCMenu *menu=CCMenu::create();
    menu->addChild(item);
    menu->setPosition(ccp(winSize.width/2, 70));
    this->addChild(menu);
    round=0;
    
    CCActionInterval *fadein=CCFadeIn::create(1.5);
    CCCallFunc * func=CCCallFunc::create(this, callfunc_selector(startAnimate::animateDesc));
    CCFiniteTimeAction * final=CCSequence::create(fadein,func,NULL);
    str1->runAction(final);

    return true;
}
void startAnimate::kong()
{
    str1->setVisible(true);
}
void startAnimate::animateDesc()
{
    
    if(round==0)
    {   
        str2->setVisible(true);
        CCActionInterval *fin=CCFadeIn::create(2);
        str2->runAction(fin);
        CCActionInterval *fadeout=CCFadeOut::create(0.7);
        CCActionInterval *delay=CCDelayTime::create(0.7);
        CCActionInterval *moveTo=CCMoveTo::create(0.7, ccp(str2->getPosition().x, str2->getPosition().y));
        CCCallFunc * func=CCCallFunc::create(this, callfunc_selector(startAnimate::animateDesc));

        CCFiniteTimeAction * final=CCSequence::create(delay,moveTo,fadeout,func,NULL);
        
        str2->runAction(final);
    }
    else if(round==1)
    {
        CCActionInterval * fadeout=CCFadeOut::create(0.1);
        str3->setVisible(true);
        CCActionInterval * delay=CCDelayTime::create(1.5);
        CCActionInterval * moveto=CCMoveTo::create(0.7, ccp(str3->getPosition().x, str3->getPosition().y));
        CCCallFunc * func=CCCallFunc::create(this, callfunc_selector(startAnimate::animateTwo));
        CCFiniteTimeAction * final=CCSequence::create(delay,moveto,fadeout,func,NULL);
        str3->runAction(final);
    }
    round++;
}
void startAnimate::animateTwo()
{
    CCFadeOut *out=CCFadeOut::create(1.0);
    str1->runAction(out);
    str4->setVisible(true);
    CCActionInterval *fadein=CCFadeIn::create(1);
    str4->runAction(fadein);
    
    CCActionInterval *fadeout=CCFadeOut::create(1.5);
    CCActionInterval *delay=CCDelayTime::create(1.5);
    str7->setVisible(true);
    CCActionInterval *moveTo=CCMoveTo::create(0.7, ccp(str7->getPosition().x, str7->getPosition().y));
    CCCallFunc * func=CCCallFunc::create(this, callfunc_selector(startAnimate::animateThree));
    CCFiniteTimeAction * final=CCSequence::create(delay,moveTo,fadeout,func,NULL);
    str7->runAction(final);

}
void startAnimate::animateThree()
{
    CCFadeOut *out=CCFadeOut::create(1.0);
    str4->runAction(out);
    str5->setVisible(true);
    CCFadeIn *fadein=CCFadeIn::create(2.5);
    str5->runAction(fadein);
    str8->setVisible(true);
    CCFadeIn *in=CCFadeIn::create(1.0);
    str8->runAction(in);
    CCActionInterval * fadeout=CCFadeOut::create(2);
    CCActionInterval * delay=CCDelayTime::create(1.5);

    CCCallFunc * func=CCCallFunc::create(this, callfunc_selector(startAnimate::animateFour));
    CCFiniteTimeAction * final=CCSequence::create(delay,fadeout,func,NULL);
    str8->runAction(final);
}
void startAnimate::animateFour()
{
    CCFadeOut *out=CCFadeOut::create(2.0);
    str5->runAction(out);
    str6->setVisible(true);
    CCFadeIn *fadein=CCFadeIn::create(1.0);
    str6->runAction(fadein);
    CCFadeOut *fadeout=CCFadeOut::create(2.5);
    CCActionInterval *delay=CCDelayTime::create(2);
    CCCallFunc *func=CCCallFunc::create(this, callfunc_selector(startAnimate::menuItemCallbackXr));
    CCFiniteTimeAction *final=CCSequence::create(delay,fadeout,func,NULL);
    str6->runAction(final);
}
void startAnimate::menuItemCallbackXr(CCObject *pSender)
{
    CCScene *scene=CCScene::create();
    CCLayer *xr=xuanren::create();
    scene->addChild(xr);
    CCDirector::sharedDirector()->replaceScene(scene);
}
startAnimate::~startAnimate()
{
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bgk1.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("words.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("words1.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("words2.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("words3.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bgk2.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bgk3.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("bgk4.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("start_xr.png");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("start_xr1.png");
}
