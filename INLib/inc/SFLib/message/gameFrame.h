//////////////////////////////////////////////////////////////////////
//  created:    2011/11/01
//  filename:   SFLib/message/gameFrame.h
//  author:     League of Perfect
/// @brief
///
//////////////////////////////////////////////////////////////////////
#ifndef __SFLIB_MESSAGE_GAMEFRAME_H__
#define __SFLIB_MESSAGE_GAMEFRAME_H__

#include <SFLib/commonDefine/baseDef.h>
#include <SFLib/message/message.h>
#include <BCLib/utility/dateTime.h>

namespace SFLib
{

#define SFLIB_ACCOUNT_SERVER_ID 8000
#define SFLIB_NAME_SERVER_ID 8001

enum EErrorType
{
    EERROR_OK = 0,
    EERROR_VESION,              //�汾ƥ��
    EERROR_ACCOUNT,             //�˺��������
    EERROR_EXIST_PEER,          //peer�Ѿ�����
    EERROR_NON_EXIST_PEER,      //peer������
    EERROR_EXIST_SERVER,        //server����
    EERROR_NON_EXIST_SERVER,    //server������
    EERROR_EMPTY_MEMORY,        //�ڴ治��
    EERROR_RUNNING,             //�Ѿ��ڽ�����
    EERROR_SERVER_ID,           //��������Ŵ���
    EERROR_SERVER_TYPE,         //���������ʹ���
	EERROR_NO_AUTHORITY,        //����Ȩ�޲���
};

enum EMsgIDGameFrame
{
    EMID_XX2XX_NTF_ERROR_TYPE = 1,
    EMID_LC2LC_NTF_ERROR_TYPE,

    EMID_XX2XS_NTF_SERVER_TYPE,
    EMID_MS2XS_NTF_LOGIC_SERVER_LIST,
    EMID_MS2XS_NTF_EXTERNAL_SERVER_LIST,
    EMID_MS2XS_NTF_VERIFY_SUCCESS,
    EMID_MS2XS_REQ_ACCEPT,
    EMID_XS2MS_RES_ACCEPT,
    EMID_MS2XS_NTF_SERVER_ACTIVE,
    EMID_XS2MS_NTF_SHAKE_HANDS,
    EMID_XS2MS_NTF_SERVER_INITED,
    EMID_MS2XS_NTF_SERVER_INITED,

    EMID_XX2XX_NTF_TRANSFORM_MSG,
    EMID_XX2XX_NTF_SINGLETON_DBG,

    EMID_XS2GC_NTF_RANDKEY,
    EMID_XS2MS_REQ_VALID_RANDKEY,
    EMID_MS2XS_RES_VALID_RANDKEY,

    EMID_MS2XS_NTF_REMOVE_SERVER,
    EMID_LC2LC_NTF_REMOVE_CLIENT,

    EMID_MS2XS_REQ_SERVER_SAVE,
    EMID_XS2MS_ACK_SERVER_SAVE,
    EMID_MS2XS_NTF_SERVER_CLOSE,

    EMID_LC2LC_NTF_SERVER_TERMINATE,

    //////////////////////////////////////////////////////////////////////////
    // ֮ǰֻ�� C++ �ͻ��˻��õ���Ŀǰͳһ�ᵽ�߼��㴦��
    //////////////////////////////////////////////////////////////////////////
    //EMID_GC2LG_REQ_RECONNECT,
    //EMID_GC2GW_REQ_RECONNECT,

    //////////////////////////////////////////////////////////////////////////
    // Peer��¼������Ϣ��ͨ�� Master ��ת��
    //////////////////////////////////////////////////////////////////////////
    EMID_XS2MS_REQ_APPLY_FOR_PEERID,           /// ĳ�߼�������MS����Peer��ͨ������������ҵ�¼�ɹ����������
    EMID_MS2XS_RES_APPLY_FOR_PEERID,           /// MS�ڴ�������������̺󣬻ظ�����߼��������Ľ��
    EMID_MS2XS_REQ_CREATE_PEERID,              /// MS�������������������Ӧ��Peer 
    EMID_XS2MS_RES_CREATE_PEERID,              /// ���������ظ�MS����Peer�Ľ��
    EMID_MS2XS_NTF_INIT_PEERID,                /// MS֪ͨ������������ʼ����ӦPeer������Ҫ�����������ʼ����ظ�
    EMID_XS2GC_NTF_SELF_PEER_ID,               /// ĳ�߼���֪ͨ�ͻ��ˣ���C++��Ŀͻ��ˣ�

    //////////////////////////////////////////////////////////////////////////
    // Peer�����߼�����������Ϣ��ͨ�� Master ��ת��
    //////////////////////////////////////////////////////////////////////////
    EMID_XS2MS_REQ_ENTER_SERVER,               /// Peer����MS����ĳ������
    EMID_MS2XS_RES_ENTER_SERVER,               /// MS�ظ�����ĳ���������
    EMID_MS2XS_REQ_ENTER_SERVER_CREATE_PEERID, /// MS��ΪPeer������������󴴽�PeerID
    EMID_XS2MS_RES_ENTER_SERVER_CREATE_PEERID, /// �ظ�MS����PeerID���

    //////////////////////////////////////////////////////////////////////////
    // Peer�뿪�߼�����������Ϣ��ͨ�� Master ��ת��
    //////////////////////////////////////////////////////////////////////////
    EMID_XS2MS_REQ_LEAVE_SERVER,               /// Peer����MS�˳�ĳ������
    EMID_MS2XS_RES_LEAVE_SERVER,               /// MS�ظ��뿪ĳ���������
    EMID_MS2XS_REQ_LEAVE_SERVER_REMOVE_PEERID, /// MS��ΪPeer�뿪��������������PeerID
    EMID_XS2MS_RES_LEAVE_SERVER_REMOVE_PEERID, /// �ظ�MS����PeerID���

    //////////////////////////////////////////////////////////////////////////
    // Peer�˳�������Ϣ��ͨ�� Master ��ת��
    //////////////////////////////////////////////////////////////////////////
    EMID_XS2MS_REQ_LEAVE_PEERID,
    EMID_MS2XS_REQ_LEAVE_PEERID,
    EMID_XS2MS_ACK_LEAVE_PEERID,
    EMID_MS2XS_NTF_REMOVE_PEERID,

    //////////////////////////////////////////////////////////////////////////
    // Peer ����/�뿪 �߼�����������Ϣ��ͨ�� ֱ�� ��ʽ��
    //////////////////////////////////////////////////////////////////////////
    EMID_XS2XS_REQ_ENTER_SERVER,               /// Peer�������ĳ�߼���
    EMID_XS2XS_RES_ENTER_SERVER,               /// ĳ�߼����ظ�������
    
    EMID_XS2XS_SET_ENTER_SERVER,               /// ���� Peer �������֮��Ĺ���

    EMID_XS2XS_REQ_LEAVE_SERVER,               /// Peer�����뿪ĳ�߼���
    EMID_XS2XS_RES_LEAVE_SERVER,               /// ĳ�߼����ظ��뿪���
};

namespace Message
{

#ifdef WIN32
#pragma pack (push, 1)
#else
#pragma pack (1)
#endif

SFLIB_MSGDEBUG(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_ERROR_TYPE);
struct SMsgXX2XXNtfErrorType : public SNetMessage
{
public:
    EErrorType m_errorType;

    SMsgXX2XXNtfErrorType() : SNetMessage(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_ERROR_TYPE)
    {
        m_errorType = EERROR_OK;
    }
};

SFLIB_MSGDEBUG(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_ERROR_TYPE);
struct SMsgLC2LCNtfErrorType : public SNetMessage
{
public:
    EErrorType m_errorType;

    SMsgLC2LCNtfErrorType() : SNetMessage(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_ERROR_TYPE)
    {
        m_errorType = EERROR_OK;
    }
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_XX2XS_NTF_SERVER_TYPE);
struct SMsgXX2XSNtfServerType : public SNetMessage
{
public:
    char m_version[SFLIB_VERSION_TEXT_MAX+1];
    ServerType m_serverType;
    ServerID m_serverID;

    SMsgXX2XSNtfServerType() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_XX2XS_NTF_SERVER_TYPE)
    {
        memset(m_version, 0, sizeof(m_version));
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
    }
};

struct SServerInfo
{
    GroupID m_groupID;
    ServerID m_serverID;
    ServerType m_serverType;
    BCLib::Network::ENetType m_acceptNetType;
    char m_acceptIP[SFLIB_IP_TEXT_MAX+1];
    BCLib::uint16 m_acceptPort;
    char m_outerIP[SFLIB_IP_TEXT_MAX+1];
    BCLib::uint16 m_outerPort;
    char m_innerIP[SFLIB_IP_TEXT_MAX+1];

	SServerInfo()
	{
        m_groupID = INVALID_GROUP_ID;
		m_serverID = INVALID_SERVER_ID;
		m_serverType = INVALID_SERVER_TYPE;
		m_acceptNetType = BCLib::Network::ENetType::NETT_NULL;
		memset(m_acceptIP, 0, sizeof(m_acceptIP));
		m_acceptPort = 0;
		memset(m_outerIP, 0, sizeof(m_outerIP));
		m_outerPort = 0;
		memset(m_innerIP, 0, sizeof(m_outerPort));
	}
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_LOGIC_SERVER_LIST);
struct SMsgMS2XSNtfLogicServerList : public SNetMessage
{
public:
    BCLib::uint8 m_count;
    SServerInfo m_serverInfos[1];
    SMsgMS2XSNtfLogicServerList() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_LOGIC_SERVER_LIST)
    {
        m_count = 0;
    }

    int getSize() { return sizeof(SMsgMS2XSNtfLogicServerList) - sizeof(SServerInfo) + m_count * sizeof(SServerInfo); }
    int getSize(int count) { return sizeof(SMsgMS2XSNtfLogicServerList) - sizeof(SServerInfo) + count * sizeof(SServerInfo); }
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_EXTERNAL_SERVER_LIST);
struct SMsgMS2XSNtfExternalServerList : public SNetMessage
{
public:
    BCLib::uint8 m_count;
    SServerInfo m_serverInfos[1];
    SMsgMS2XSNtfExternalServerList() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_EXTERNAL_SERVER_LIST)
    {
        m_count = 0;
    }

    int getSize() { return sizeof(SMsgMS2XSNtfExternalServerList) - sizeof(SServerInfo) + m_count * sizeof(SServerInfo); }
    int getSize(int count) { return sizeof(SMsgMS2XSNtfExternalServerList) - sizeof(SServerInfo) + count * sizeof(SServerInfo); }
};

struct SServerAcceptInfo
{
    GroupID m_groupID; // ֻ���߼�������Ч
    ServerID m_serverID;
    BCLib::Network::ENetType m_acceptNetType;
	char m_acceptIP[SFLIB_IP_TEXT_MAX + 1];
    BCLib::uint16 m_acceptPort;

	SServerAcceptInfo()
	{
        m_groupID = INVALID_GROUP_ID;
		m_serverID = INVALID_SERVER_ID;
		m_acceptNetType = BCLib::Network::ENetType::NETT_NULL;
		memset(m_acceptIP, 0, sizeof(m_acceptIP));
		m_acceptPort = 0;
	}
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_VERIFY_SUCCESS);
struct SMsgMS2XSNtfVerifySuccess : public SNetMessage
{
public:
    SMsgMS2XSNtfVerifySuccess() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_VERIFY_SUCCESS)
    {
        m_nMasterTime = BCLib::Utility::CDateTime::now().getTime();
    }

    BCLib::int64 m_nMasterTime;
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_REQ_ACCEPT);
struct SMsgMS2XSReqAccept : public SNetMessage
{
public:
    SServerAcceptInfo m_acceptInfo;
    SMsgMS2XSReqAccept() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_REQ_ACCEPT)
    {
        ;
    }
};

SFLIB_MSGDEBUG(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_RES_ACCEPT);
struct SMsgXS2MSResAccept : public SNetMessage
{
public:
    SMsgXS2MSResAccept() : SNetMessage(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_RES_ACCEPT)
    {
        m_result = 0;
    }

    BCLib::int8 m_result;
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_ACTIVE);
struct SMsgMS2XSNtfServerActive : public SNetMessage
{
public:
    ServerType m_serverType;
    ServerID m_serverID;
    bool m_needConnection;  ///according to the config file

    SMsgMS2XSNtfServerActive() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_ACTIVE)
    {
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
        m_needConnection = false;
    }
};

enum EShakeHands
{
    SHAKEHANDS_UNKNOW,
    SHAKEHANDS_ERROR,
    SHAKEHANDS_SUCCESS,
};

SFLIB_MSGDEBUG(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_NTF_SHAKE_HANDS);
struct SMsgXS2MSNtfShakeHands : public SNetMessage
{
public:
    EShakeHands m_nFlag;
    ServerID m_srcServerID;
    ServerID m_dstServerID;

    SMsgXS2MSNtfShakeHands() : SNetMessage(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_NTF_SHAKE_HANDS)
    {
        m_nFlag = SHAKEHANDS_UNKNOW;
        m_srcServerID = INVALID_SERVER_ID;
        m_dstServerID = INVALID_SERVER_ID;
    }
};

SFLIB_MSGDEBUG(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_NTF_SERVER_INITED);
struct SMsgXS2MSNtfServerInited : public SNetMessage
{
public:
    ServerType m_serverType;
    ServerID m_serverID;

    SMsgXS2MSNtfServerInited() : SNetMessage(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_NTF_SERVER_INITED)
    {
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
    }
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_INITED);
struct SMsgMS2XSNtfServerInited : public SNetMessage
{
public:
    ServerType m_serverType;
    ServerID m_serverID;

    SMsgMS2XSNtfServerInited() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_INITED)
    {
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
    }
};

//ת����Ϣ
SFLIB_MSGDEBUG(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_TRANSFORM_MSG);
struct SMsgXX2XXNtfTransformMsg : public SNetMessage
{
public:
    PeerID m_peerID;
    int m_bufSize;
    char m_buf[1];

    SMsgXX2XXNtfTransformMsg() : SNetMessage(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_TRANSFORM_MSG)
    {
        m_bufSize = 0;
    }

    BCLib::uint32 getSize() { return sizeof(SMsgXX2XXNtfTransformMsg) - sizeof(char) + m_bufSize * sizeof(char); }
};

SFLIB_MSGDEBUG(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_SINGLETON_DBG);
struct SMsgXX2XXNtfSingletonDbg : public SNetMessage
{
public:
    struct SSFCallback
    {
        enum ESFCALLBACK {
            ESFC_INVALID,
            ESFC_SERVER_ENTER,
            ESFC_SERVER_INIT,
            ESFC_SERVER_LEAVE,
            ESFC_PEER_CREATE,
            ESFC_PEER_ENTER,
            ESFC_PEER_REENTER,
            ESFC_PEER_LEAVE,
            ESFC_PEER_REMOVE,
            ESFC_PEER_PEER_ENTER_SCENE_SERVER,
            ESFC_PEER_PEER_LEAVE_SCENE_SERVER,
            ESFC_PEER_SET_PEER_SCENE_SERVER,
        };
        ESFCALLBACK m_eCallback;
        ServerID m_serverID;
        PeerID m_peerID;
        ServerType m_serverType;
        ServerID m_sceneServerID;
        bool m_result;

        SSFCallback()
        {
            m_eCallback = ESFC_INVALID;
            m_serverID = INVALID_SERVER_ID;
            m_peerID = INVALID_PEER_ID;
            m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
            m_sceneServerID = INVALID_SERVER_ID;
            m_result = false;
        }
    };

    bool m_bSFCallback;
    PeerID m_peerID;
    int m_bufSize;
    char m_buf[1];

    SMsgXX2XXNtfSingletonDbg() : SNetMessage(ESERVER_ANYXX, EFUNC_GAMEFRAME, EMID_XX2XX_NTF_SINGLETON_DBG)
    {
        m_bSFCallback = false;
        m_peerID = INVALID_PEER_ID;
        m_bufSize = 0;
    }

    BCLib::uint32 getSize() const { return sizeof(SMsgXX2XXNtfSingletonDbg) - sizeof(char) + m_bufSize * sizeof(char); }
    SSFCallback* getSFCallback() const { return (SSFCallback*)m_buf; }
};

//
SFLIB_MSGDEBUG(ESERVER_GAMECLIENT, EFUNC_GAMEFRAME, EMID_XS2GC_NTF_RANDKEY);
struct SMsgXS2GCNtfRandKey : public SNetMessage
{
public:
    BCLib::uint32 m_uRandKey;

    SMsgXS2GCNtfRandKey() : SNetMessage(ESERVER_GAMECLIENT, EFUNC_GAMEFRAME, EMID_XS2GC_NTF_RANDKEY)
    {
        m_uRandKey = 0;
    }
};

SFLIB_MSGDEBUG(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_REQ_VALID_RANDKEY);
struct SMsgXS2MSReqValidRandKey : public SNetMessage
{
public:
    SMsgXS2MSReqValidRandKey() : SNetMessage(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_REQ_VALID_RANDKEY)
    {
        m_bReenter = false;
        m_peerID = INVALID_PEER_ID;
        m_uRandKey = 0;
        m_stubID = BCLib::Network::INVALID_TCPSTUBID;
    }

    bool m_bReenter;
    PeerID m_peerID;
    BCLib::uint32 m_uRandKey;
    BCLib::Network::TcpStubID m_stubID;
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_RES_VALID_RANDKEY);
struct SMsgMS2XSResValidRandKey : public SNetMessage
{
public:
    SMsgMS2XSResValidRandKey() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_RES_VALID_RANDKEY)
    {
        m_bReenter = false;
        m_errorID = 0;
        m_peerID = INVALID_PEER_ID;
        m_stubID = BCLib::Network::INVALID_TCPSTUBID;
    }

    bool m_bReenter;
    BCLib::int32 m_errorID;
    PeerID m_peerID;
    BCLib::Network::TcpStubID m_stubID;
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_REMOVE_SERVER);
struct SMsgMS2XSNtfRemoveServer : public SNetMessage
{
public:
    ServerType m_serverType;
    ServerID m_serverID;

    SMsgMS2XSNtfRemoveServer() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_REMOVE_SERVER)
    {
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
    }
};

SFLIB_MSGDEBUG(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_REMOVE_CLIENT);
struct SMsgLC2LCNtfRemoveClient : public SNetMessage
{
public:
    ServerType m_serverType;
    ServerID m_serverID;

    SMsgLC2LCNtfRemoveClient() : SNetMessage(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_REMOVE_CLIENT)
    {
        m_serverType = (BCLib::uint8)ESERVER_UNKNOW;
        m_serverID = INVALID_SERVER_ID;
    }
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_REQ_SERVER_SAVE);
struct SMsgMS2XSReqServerSave : public SNetMessage
{
public:
    SMsgMS2XSReqServerSave() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_REQ_SERVER_SAVE)
    {
		m_groupID = INVALID_GROUP_ID;
    }
	GroupID m_groupID;
};

SFLIB_MSGDEBUG(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_ACK_SERVER_SAVE);
struct SMsgXS2MSAckServerSave : public SNetMessage
{
public:
    SMsgXS2MSAckServerSave() : SNetMessage(ESERVER_MASTER, EFUNC_GAMEFRAME, EMID_XS2MS_ACK_SERVER_SAVE)
    {
		m_groupID = INVALID_GROUP_ID;
        m_serverID = INVALID_SERVER_ID;
        m_result = 0;
    }

	GroupID m_groupID;
    ServerID m_serverID;
    BCLib::int8 m_result;
};

SFLIB_MSGDEBUG(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_CLOSE);
struct SMsgMS2XSNtfServerClose : public SNetMessage
{
public:
    SMsgMS2XSNtfServerClose() : SNetMessage(ESERVER_ANYXS, EFUNC_GAMEFRAME, EMID_MS2XS_NTF_SERVER_CLOSE)
    {
		m_groupID = INVALID_GROUP_ID;
    }
	GroupID m_groupID;
};

SFLIB_MSGDEBUG(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_SERVER_TERMINATE);
struct SMsgLC2LCNtfServerTerminate : public SNetMessage
{
public:
    EGCServerType m_serverType;
    SMsgLC2LCNtfServerTerminate() : SNetMessage(ESERVER_LOCAL, EFUNC_GAMEFRAME, EMID_LC2LC_NTF_SERVER_TERMINATE)
    {
    }
};

/// ֮ǰֻ�� C++ �ͻ��˻��õ���Ŀǰͳһ�ᵽ�߼��㴦��
//SFLIB_MSGDEBUG(ESERVER_LOGIN, EFUNC_GAMEFRAME, EMID_GC2LG_REQ_RECONNECT);
//struct SMsgGC2LGReqReconnect : public SNetMessage
//{
//public:
//    SMsgGC2LGReqReconnect() : SNetMessage(ESERVER_LOGIN, EFUNC_GAMEFRAME, EMID_GC2LG_REQ_RECONNECT)
//    {
//        m_peerID = INVALID_PEER_ID;
//        m_uRandKey = 0;
//    }
//
//    PeerID m_peerID;
//    BCLib::uint32 m_uRandKey;
//};
//
//SFLIB_MSGDEBUG(ESERVER_GATEWAY, EFUNC_GAMEFRAME, EMID_GC2GW_REQ_RECONNECT);
//struct SMsgGC2GWReqReconnect : public SNetMessage
//{
//public:
//    SMsgGC2GWReqReconnect() : SNetMessage(ESERVER_GATEWAY, EFUNC_GAMEFRAME, EMID_GC2GW_REQ_RECONNECT)
//    {
//        m_peerID = INVALID_PEER_ID;
//        m_uRandKey = 0;
//    }
//
//    PeerID m_peerID;
//    BCLib::uint32 m_uRandKey;
//};

#ifdef WIN32
#pragma pack (pop)
#else
#pragma pack ()
#endif

}//Message

}//SFLib

#endif//__SFLIB_MESSAGE_GAMEFRAME_H__
