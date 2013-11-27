//
//  LayerLogin.cpp
//  Client
//
//  Created by bzx on 13-2-25.
//
//
//气泡对白  （365，320）
#include "LayerLogin.h"
#include "homePage.h"
#include "json.h"
#include "SocketClient.h"
#include "message.h"
#include "MessageQueue.h"
#include "xuanren.h"
#include "zhuangtaiLoad.h"
#include "startAnimate.h"
#include "Singleton.h"
#include "AnimatePacker.h"
#include "SocketManager.h"
#include "CData.h"
#include "CustomPop.h"



bool LayerLogin::init()
{
    if(!CCLayer::init())
    {
        return false;
    }
    
    
    
    CData::getCData()->setyinyue("bg.mp3");
    SocketManager::getInstance()->startSocket();
    
    loadRes();
    initUI();
    
    return true;
}

void LayerLogin::initUI()
{
    
//    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
    winSize = CCDirector::sharedDirector()->getWinSize();
    
    
    
    
    CCSprite *bg = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_bkg.png"));// CCSprite::create("login_bg.png");
    bg->setPosition(ccp(winSize.width*0.5,winSize.height*0.5));
    this->addChild(bg);
    this->zhenping();
    
    
    
    
    
  
//    
//     logo= CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_logo.png"));// CCSprite::create("logo.png");
//    logo->setTag(9021);
//    logo->setAnchorPoint(ccp(0.5, 1));
//    logo->setPosition(ccp(winSize.width*0.5, winSize.height));
//    this->addChild(logo);
//    logo->setScale(8);
//    logo->setOpacity(GLubyte(0));
//    
//    CCActionInterval * fadein=CCFadeIn::create(0.2);
//    logo->runAction(fadein);
//    CCActionInterval * setsmall=CCScaleTo::create(0.2, 1);
//    logo->runAction(setsmall);
//    CCActionInterval * moveto=CCMoveTo::create(0.2, ccp(winSize.width*0.5, winSize.height-100));
//    
//    CCCallFunc * func=CCCallFunc ::create(this, callfunc_selector(LayerLogin::zhenping));
//    CCFiniteTimeAction *playerAct=CCSequence::create(moveto,func,NULL);
//    logo->runAction(playerAct);

    
    
//    CCSprite* spName =  CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_name.png"));
//    spName->setAnchorPoint(ccp(0, 0));
//    spName->setPosition(ccp(70, 50));
//    logo->addChild(spName);

    
    sendData=denglu1;

}

void LayerLogin::loadRes()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("ui_login.plist");
}


void LayerLogin::zhenping(){
    
    
    pSpriteDialogLogin = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_input.png"));//CCSprite::create("login_bg_en.png");
    pSpriteDialogLogin->setPosition(ccp(winSize.width*0.5,winSize.height *0.5-100));
    this->addChild(pSpriteDialogLogin);
    
    
      
    
    
    CCMenuItemImage* btn_login = CCMenuItemImage::create();
    btn_login->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_login_1.png"));
    btn_login->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_login_2.png"));
    btn_login->setTarget(this, SEL_MenuHandler(&LayerLogin::menuItemCallbackLogin));
    
    CCMenu *pMenu = CCMenu::create();
    pMenu->alignItemsHorizontally();
    pMenu->addChild(btn_login);
    //pMenu->setPosition(pSpriteDialogLogin->getContentSize().width-75,pSpriteDialogLogin->getContentSize().height/2-10);
    pMenu->setPosition(ccp(winSize.width/2-30, winSize.height/2-460));
    pMenu->setTouchPriority(1);
    pSpriteDialogLogin->addChild(pMenu);
    
    
    CCScale9Sprite* editbkg = CCScale9Sprite::create();
    
    editBoxUsername = CCEditBox::create(CCSizeMake(210,50),editbkg);
    editBoxUsername->setReturnType(kKeyboardReturnTypeDone);
    //editBoxUsername->setFontSize(12);
    editBoxUsername->setText("");
    editBoxUsername->setFontColor(ccc3(158, 122, 83));
    editBoxUsername->setMaxLength(8);
    editBoxUsername->setPosition(ccp(winSize.width/2-10,96));//160,100
    pSpriteDialogLogin->addChild(editBoxUsername,2);
    
    CCScale9Sprite* editbkg1 = CCScale9Sprite::create();
    editBoxPassword = CCEditBox::create(CCSizeMake(185, 50),editbkg1);
    editBoxPassword->setReturnType(kKeyboardReturnTypeDone);
    editBoxPassword->setInputFlag(kEditBoxInputFlagPassword);
    editBoxPassword->setFontColor(ccc3(158, 122, 83));
    editBoxPassword->setMaxLength(8);
  //  editBoxPassword->setFontSize(12);
    editBoxPassword->setText("");
    editBoxPassword->setPosition(ccp(winSize.width/2-17,45));//160,60
    
    pSpriteDialogLogin->addChild(editBoxPassword,2);
    
//    CCSprite* bs = CCSprite::createWithSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_bs.png"));
//    bs->setPosition(ccp(pSpriteDialogLogin->getContentSize().width, 0));
//    pSpriteDialogLogin->addChild(bs);
//    logo->setAtlasIndex(0);
//    CCScene * f = CCDirector::sharedDirector()->getRunningScene();
//    CCPoint size =ccp(308, 756);
//    CCActionInterval * left1 = CCMoveTo::create(0.05,ccp(size.x+5,size.y));
//    CCActionInterval * right1 = CCMoveTo::create(0.05,ccp(size.x-5,size.y));
//    CCActionInterval * top1 = CCMoveTo::create(0.05,ccp(size.x,size.y+5));
//    CCActionInterval * rom1 = CCMoveTo::create(0.05,ccp(size.x,size.y-5));
//    CCFiniteTimeAction* action3 = CCSequence::create(left1,right1,top1,rom1,NULL);
//    f->getChildByTag(2807)->getChildByTag(9021)->runAction(CCRepeat::create(action3, 1));
}

void LayerLogin::onExit()
{
    CCLog("LayerLogin onExit");
    CCLayer::onExit();
}

LayerLogin::~LayerLogin()
{
    CCLog("LayerLogin destroy");
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile("ui_login.plist");
    CCTextureCache::sharedTextureCache()->removeTextureForKey("ui_login.png");
}


void LayerLogin::menuItemCallbackLogin(CCObject* pSender)
{
//    CCString* nameString=CCString::create(editBoxUsername->getText());
//    CCString* passwordString=CCString::create(editBoxPassword->getText());
//    if ((nameString->length()!=0)&&(passwordString->length()!=0)){
    if(strcmp(editBoxUsername->getText(), "")&&strcmp(editBoxPassword->getText(), "")){
        
        load=Loading::create();
        addChild(load,9999);
        const char  *  userName=editBoxUsername->getText();
        const char *   password=editBoxPassword->getText();
        Json::FastWriter  writer;
        Json::Value person;
        person["username"]=userName;
        person["password"]=password;
        std::string  json_file=writer.write(person);//192.168.1.210   114.252.70.61  183.60.243.195
        CCLog("%s",json_file.c_str());
        SocketManager::getInstance()->sendMessage(json_file.c_str(), 101);
        this->schedule(schedule_selector(LayerLogin::receiveLoginData), 0.2);
        
        
    }
    else{
        CustomPop::show("帐号或密码不能为空！~");
    }
}
void LayerLogin::receiveLoginData(){
    Message* revMsg2 = (Message *)CData::getCData()->m_dictionary->objectForKey(101);
    CCLOG("%s",revMsg2);
    CData::getCData()->m_dictionary->removeObjectForKey(101);
    
    
    
    if(revMsg2){
        
        
        this->unschedule(schedule_selector(LayerLogin::receiveLoginData));
        
        char * denglu=revMsg2->data;
        CData::getCData()->setSendVal(denglu1);
        printf("%s\n",denglu);
        Json::Reader read;
        Json::Value root;
        bool result;
        Json::Value data;
        if(denglu){
            if (read.parse(denglu, root)) {
                Json::Value data=root["data"];
                std::string message=root["message"].asString();
                result=root["result"].asBool();
                if(result){
                    CData::getCData()->setCharactorId(data["characterId"].asInt());
                     hasRole=data["hasRole"].asBool();
                    CData::getCData()->setUserId(data["userId"].asInt());
                    if(hasRole){
                        CData::getCData()->setfirstLogin(2);
                        this->schedule(schedule_selector(LayerLogin::sendPersonalData), 0.2);
                    }
                    else {
                        CData::getCData()->setfirstLogin(1);
//                        CCScene * scene=beginAni::scene();
//                        CCDirector::sharedDirector()->replaceScene(scene);
                        CCScene *scene=CCScene::create();
                        CCLayer *slayer=startAnimate::create();
                        scene->addChild(slayer);
                        CCDirector::sharedDirector()->replaceScene(scene);
//                        CCScene * scene=CCScene::create();
//                        CCLayer *xr=xuanren::create();
//                        scene->addChild(xr);
//                        CCDirector::sharedDirector()->replaceScene(scene);
                        // CCScene * se=homePage::scene();//homePage  secondScene
                        //CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2, xr));
                        
                        
                    }
                }else{
                    CustomPop::show(message.c_str());
                    load->removeFromParent();
                }
                
                // }
                
            }
        }
    }
}
void LayerLogin::sendPersonalData(){
    this->unschedule(schedule_selector(LayerLogin::sendPersonalData));
    
    this->schedule(schedule_selector(LayerLogin::receivePersonalData), 0.2);
    Json::FastWriter  write;
    
    Json::Value person1;
    
    person1["userId"]= CData::getCData()->getUserId();
    person1["characterId"]=CData::getCData()->getCharactorId();
    
    std::string  json_file1=write.write(person1);
    
    SocketManager::getInstance()->sendMessage(json_file1.c_str(), 103);
    
    
    Json::Value citymsg;
    citymsg["userId"] = CData::getCData()->getUserId();
    citymsg["characterId"] = CData::getCData()->getCharactorId();
    citymsg["index"] = 0;
    std::string json_file_city = write.write(citymsg);
    
       
    
    return;
    
    SocketManager::getInstance()->sendMessage(json_file_city.c_str(), 4500);
    
    
    this->schedule(schedule_selector(LayerLogin::receiveCityData), 0.2);
    
    
}

void LayerLogin::receiveCityData()
{
    
    Message* msg = (Message*)CData::getCData()->m_dictionary->objectForKey(4500);
    CData::getCData()->m_dictionary->removeObjectForKey(4500);
    if(msg)
    {
        this->unschedule(schedule_selector(LayerLogin::receiveCityData));
        
//        {"message": "", "data": {"cityid": 1000, "citylist": []}, "result": true}
        CData::getCData()->cityData = msg->data;
        printf("%s\n",CData::getCData()->cityData);

        this->schedule(schedule_selector(LayerLogin::receivePersonalData), 0.2);
    }
    
}


void LayerLogin::receivePersonalData(){
    
    Message* revMsg1 = (Message *)CData::getCData()->m_dictionary->objectForKey(103);
    CData::getCData()->m_dictionary->removeObjectForKey(103);
    if(revMsg1){
        this->unschedule(schedule_selector(LayerLogin::receivePersonalData));
//        editBoxUsername->removeFromParent();
//        editBoxPassword->removeFromParent();
        denglu1=revMsg1->data;
        CData::getCData()->setSendVal(denglu1);
        printf("------%s\n",denglu1);
        
        
        
        
        pSpriteDialogLogin->removeFromParent();
        
        
        load->removeFromParent();
//        CCSprite *pSpriteselector = CCSprite::createWithSpriteFrameName("button_bg.png");// CCSprite::create("button_bg.png");
//        CCMenuItemSprite *pMenuItemSelector = CCMenuItemSprite::create(pSpriteselector, pSpriteselector, this,SEL_MenuHandler(&LayerLogin::menuItemCallbackStart));
//        pMenuItemSelector->setPosition(0, 130);
        
//        CCMenuItemImage *pMenuItemStart = CCMenuItemImage::create("start_up.png", "start_down.png", this,SEL_MenuHandler(&LayerLogin::menuItemCallbackStart));
        CCMenuItemImage *pMenuItemStart = CCMenuItemImage::create();
        pMenuItemStart->setNormalSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_start_1.png"));
        pMenuItemStart->setSelectedSpriteFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("login_start_2.png"));
        pMenuItemStart->setTarget(this, SEL_MenuHandler(&LayerLogin::menuItemCallbackStart));
        CCMenu *pMenu = CCMenu::create(pMenuItemStart,NULL);
        this->addChild(pMenu,2);
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        pMenu->setPosition(winSize.width/2, 180);
        
    }
}
void LayerLogin::removeLoader(){
}


void LayerLogin::menuItemCallbackStart(CCObject *pSender)
{   
    CCLog("start");
    
    CCScene *container=CCScene::create();//homepage  beginAni
    homePage * homePage = homePage::create();
    container->addChild(homePage);
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2, container));

    
}
void LayerLogin::menuItemCallbackSelector(CCObject *pSender)
{
    
}
//bool LayerLogin::ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
//{
//    // 因为回调调不到了，所以resume写在了这里
//    CCLog("login layer");
//    return true;
//}
//void LayerLogin::ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
//{
//    
//}
//void LayerLogin::ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event)
//{
//    
//}
