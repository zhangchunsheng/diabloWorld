//
//  goodsItem.cpp
//  client1
//
//  Created by guoyahui on 13-6-4.
//
//

#include "goodsItem.h"
#include "CData.h"

bool goodsItem::init()
{
   
    if (!CCSprite::init()) {
        return false;
    }
    
    
    itemdata = NULL;
    
    bkg = CCSprite::create("common_item_bkg.png");
    bkg->setAnchorPoint(ccp(0, 0));
    this->addChild(bkg);
    
    this->setContentSize(bkg->getContentSize());
    
    
    return true;
}



void goodsItem::setData(hcitemdata *obj)
{
    bkg->removeChild(datasp,true);
    
    itemdata = obj;
    if(itemdata == NULL)
    {
        return;
    }
    
    configGoodsItem* goodsitem = CData::getCData()->getConfigOfGoods(obj->tempid);
    
    char itemicon[40]="";
    sprintf(itemicon, "item_%d.png",goodsitem->icon);
    datasp = CCSprite::create(itemicon);
    
    CCSize sz = bkg->getContentSize();
    datasp->setPosition(ccp(sz.width/2, sz.height/2));
    bkg->addChild(datasp);

   
}

void goodsItem::clData()
{
    setData(NULL);
}


//void goodsItem::onExit()
//{
//    CCLog("goodsItem onExit");
//}

goodsItem::~goodsItem()
{
    CCLog("goodsItem destroy");
}


