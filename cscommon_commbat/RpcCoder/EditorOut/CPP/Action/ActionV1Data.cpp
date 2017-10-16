#include "ActionV1Data.h"
#include "ActionModule.h"


SyncDataActionV1::SyncDataActionV1()
{
	SetDataWraper( &m_syncDataUseless );
}

SyncDataActionV1::~SyncDataActionV1()
{
}

void SyncDataActionV1::SendAllMembers(bool OnlyToClient)
{

}


