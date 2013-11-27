//
//  UserData.cpp
//  client1
//
//  Created by guoyahui on 13-5-28.
//
//

#include "UserDataModel.h"



UserData* UserData::instance = NULL;

UserData::UserData()
{
    
    characterId = 100;

}
UserData* UserData::getInstance()
{
    if(instance == NULL)
    {
        instance = new UserData();
    }
    return instance;
}

int UserData::test()
{
    return -1;
}
