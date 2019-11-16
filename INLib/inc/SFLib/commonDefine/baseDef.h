//////////////////////////////////////////////////////////////////////
//  created:    2011/11/01
//  filename:   SFLib/commonDefine/baseDef.h
//  author:     League of Perfect
/// @brief
///
//////////////////////////////////////////////////////////////////////
#ifndef __SFLIB_COMMONDEFINE_BASEDEF_H__
#define __SFLIB_COMMONDEFINE_BASEDEF_H__

#include <BCLib/utility/baseDef.h>

#ifdef SFLIB_EXPORTS
#    define SFLIB_SF_API _declspec(dllexport)
#elif defined(SFLIB_IMPORTS)
#    define SFLIB_SF_API _declspec(dllimport)
#else
#    define SFLIB_SF_API
#endif

namespace SFLib
{
typedef BCLib::uint8 ServerType;
const ServerType INVALID_SERVER_TYPE = 0;

typedef BCLib::uint16 ServerID;
const ServerID INVALID_SERVER_ID = 0;

typedef BCLib::uint64 GroupID;
const GroupID INVALID_GROUP_ID = 0;

typedef BCLib::uint64 PeerID;
const PeerID INVALID_PEER_ID = 0;

typedef BCLib::uint64 EntityID;
const EntityID INVALID_ENTITY_ID = 0;

const BCLib::uint8 SFLIB_IP_TEXT_MAX = 63;

enum EPeerEnterReason
{
    EPEERENTERREASON_UNKNOW,        // δ֪ԭ��
    EPEERENTERREASON_LOGIN,         // ��¼����
    EPEERENTERREASON_RECONNECT,     // ��������
};

enum EPeerLeaveReason
{
    EPEERLEAVEREASON_UNKNOW,        // δ֪ԭ��
    EPEERLEAVEREASON_CLEAR_PLAYERS, // �������
    EPEERLEAVEREASON_TOP_OFF,       // ��¼����
    EPEERLEAVEREASON_LOG_OUT,       // �����˳�
    EPEERLEAVEREASON_KICK_PLAYER,   // ��������
    EPEERLEAVEREASON_EXTEND,        // �ϲ���չ
};

}//SFLib

#endif//__SFLIB_COMMONDEFINE_BASEDEF_H__
