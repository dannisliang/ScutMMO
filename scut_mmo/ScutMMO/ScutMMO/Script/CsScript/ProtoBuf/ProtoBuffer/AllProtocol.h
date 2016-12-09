
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4267) //conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable:4100) //未引用的形参
#pragma warning(disable:4102)
#pragma warning(disable:4512) //assignment operator could not be generated
#pragma warning(disable:4244) //conversion from '__int64' to 'int', possible loss of data
#pragma warning(disable:4267) //conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable:4127) //conditional expression is constant
#pragma warning(disable:4189)
#endif

#include "Common/ComDefine.pb.h"
#include "ComProtocol.pb.h"

#include "ClientToServerCmd.pb.h"
#include "ServerToClientCmd.pb.h"
#include "ServerInternalCmd.pb.h"
#include "ServerInternalProtocol.pb.h"
#include "DBProxyProtocol.pb.h"

#include "Chat.pb.h"
#include "Duplicate.pb.h"
#include "Mission.pb.h"
#include "Package.pb.h"
#include "Relation.pb.h"
#include "Camp.pb.h"
#include "LogicToClient.pb.h"
#include "ClientToLogic.pb.h"
#include "Mail.pb.h"
#include "Achievement.pb.h"
#include "Deputy.pb.h"
#include "Mall.pb.h"


#ifdef _MSC_VER
#pragma warning(pop)
#endif


using namespace ProtoBuf;