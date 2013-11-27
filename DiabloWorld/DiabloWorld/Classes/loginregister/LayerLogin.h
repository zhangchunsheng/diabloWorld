//
//  LayerLogin.h
//  Client
//
//  Created by bzx on 13-2-25.
//
//

#ifndef Client_LayerLogin_h
#define Client_LayerLogin_h
#include"cocos2d.h"
#include"cocos-ext.h"
#include "SocketClient.h"
#include "CData.h"
#include "LodingLayer.h"
#include "TeXiao.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
class LayerLogin:public CCLayer
{
    
public:
    
    CREATE_FUNC(LayerLogin);
    virtual bool init();
    virtual void onExit();
    ~LayerLogin();
    
    CCSprite * texiao;
    bool hasRole;
    Loading * load;

    CCSprite * logo;
    CCSize winSize;
    
    char * denglu1;
    
    void removeLoader();
   
    void receiveLoginData();
    void sendPersonalData();
    void receivePersonalData();
    
    void receiveCityData();
    
    
    void zhenping();
    char * sendData;
private:
    
    void initUI();
    void loadRes();
    
    // bool init();
   
    void menuItemCallbackLogin(CCObject* pSender);
    void menuItemCallbackStart(CCObject* pSender);
    void menuItemCallbackSelector(CCObject* pSender);
    CCSprite *pSpriteDialogLogin;
    CCEditBox* editBoxUsername;
    CCEditBox* editBoxPassword;
    
};
#endif
