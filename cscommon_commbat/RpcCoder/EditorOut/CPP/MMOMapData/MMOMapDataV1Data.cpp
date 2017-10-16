#include "MMOMapDataV1Data.h"
#include "MMOMapDataModule.h"


SyncDataMMOMapDataV1::SyncDataMMOMapDataV1()
{
	SetDataWraper( &m_syncDataUseless );
}

SyncDataMMOMapDataV1::~SyncDataMMOMapDataV1()
{
}

void SyncDataMMOMapDataV1::SendAllMembers(bool OnlyToClient)
{

}


