#include "TestModuleV1Data.h"
#include "TestModuleModule.h"


SyncDataTestModuleV1::SyncDataTestModuleV1()
{
	SetDataWraper( &m_syncDataUseless );
}

SyncDataTestModuleV1::~SyncDataTestModuleV1()
{
}

void SyncDataTestModuleV1::SendAllMembers(bool OnlyToClient)
{

}


