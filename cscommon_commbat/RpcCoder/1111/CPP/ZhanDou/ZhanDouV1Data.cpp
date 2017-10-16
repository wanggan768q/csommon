#include "ZhanDouV1Data.h"
#include "ZhanDouModule.h"


SyncDataZhanDouV1::SyncDataZhanDouV1()
{
	SetDataWraper( &m_syncDataUserData );
}

SyncDataZhanDouV1::~SyncDataZhanDouV1()
{
}

void SyncDataZhanDouV1::SendAllMembers(bool OnlyToClient)
{

}


