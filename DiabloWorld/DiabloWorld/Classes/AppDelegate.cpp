//
//  client1AppDelegate.cpp
//  client1
//
//  Created by lh on 13-3-6.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "LayerLogin.h"
#include "logo.h"
#include "SocketManager.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(480, 800, kResolutionShowAll);
    CCDirector::sharedDirector()->setDepthTest(false);
    // turn on display FPS
//   pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = CCScene::create();
    
    //pScene->addChild(LayerLogin::create());
    pScene->addChild(logo::create());
   // CCScene *pScene=HelloWorld::scene();
   // CCScene *pScene=xuanren::scene();
    // run 
    pDirector->runWithScene(pScene); 

    
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
