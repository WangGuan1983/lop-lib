//////////////////////////////////////////////////////////////////////
//  created:    2011/11/01
//  filename:   SFLib/logicServer/netPeer.h
//  author:     League of Perfect
/// @brief
///
//////////////////////////////////////////////////////////////////////
#ifndef __SFLIB_LOGICSERVER_NETPEER_H__
#define __SFLIB_LOGICSERVER_NETPEER_H__

#include <SFLib/commonServer/netPeer.h>
#include <SFLib/commonServer/tcpStub.h>
#include <SFLib/commonServer/netClient/masterClient.h>
#include <SFLib/message/peerMsg.h>

namespace SFLib
{
namespace Logic
{
class CNetPeer : public SFLib::CommonServer::CNetPeer
{
public:
    CNetPeer();
    CNetPeer(PeerID peerID, ServerID gatewayServerID, BCLib::Network::TcpStubID gameClientStubID);
    virtual ~CNetPeer();

    /// @brief �����뿪
    /// @return bool
    /// @param notifyMaster �Ƿ�ͨ�� Master ת������ȫ������
    /// @param nReason : 1 ����������ң�2 �����¼����
    virtual bool reqLeave(bool notifyMaster, EPeerLeaveReason nReason);

    /// @brief �����뿪
    /// @return void
    /// @param notifyMaster �Ƿ�ͨ�� Master ת������ȫ������
    virtual void ackLeave(bool notifyMaster);

    virtual void terminate();

    bool sendMsgToGC(const SFLib::Message::CNetMessage* msg);
    bool sendMsgToMS(const SFLib::Message::CNetMessage* msg);
    virtual bool sendMsgByType(ServerType serverType, const SFLib::Message::CNetMessage* msg);

    bool sendMsgToGC(const SFLib::Message::SNetMessage* msg, const BCLib::uint32 msgSize);
    bool sendMsgToMS(const SFLib::Message::SNetMessage* msg, const BCLib::uint32 msgSize);
    virtual bool sendMsgByType(ServerType serverType, const SFLib::Message::SNetMessage* msg, const BCLib::uint32 msgSize);

	//
    void setGatewayServerID(ServerID gatewayServerID) { m_gatewayServerID = gatewayServerID; }
    ServerID getGatewayServerID() { return m_gatewayServerID; }

    void setGameClientStubID(BCLib::Network::TcpStubID gameClientStubID);
    BCLib::Network::TcpStubID getGameClientStubID() { return m_gameClientStubID; }

	SFLib::CommonServer::CTcpStubPtr getGameClientStub() { return m_gameClientStub;	}

    void setOfflineTime(BCLib::Utility::CDateTime dtOffline) { m_dtOffline = dtOffline; }
    BCLib::Utility::CDateTime getOfflineTime() { return m_dtOffline; }

    ServerID getServerIDByType(EServerType serverType);

	BCLib::uint32 getPingValue();

    /// @brief �������ĳ���߼�������
    /// @return bool
    /// @param serverType ����������
    /// @param notifyMaster �Ƿ�ͨ�� Master ת������ȫ���������Ϊ true ʱ��ֻ�����������Ϸ�������
    bool enterLogicServer(ServerID serverID, bool notifyMaster);

    /// @brief �����뿪ĳ���߼�������
    /// @return bool
    /// @param serverType ����������
    /// @param notifyMaster �Ƿ�ͨ�� Master ת������ȫ���������Ϊ true ʱ��ֻ�����������Ϸ�������
    bool leaveLogicServer(EServerType serverType, bool notifyMaster, EPeerLeaveReason nReason);

	/// @brief �������ĳ���ⲿ������
	/// @return bool
	/// @param serverType ����������
	bool enterExternalServer(ServerID serverID);

	/// @brief �������ĳ���ⲿ������
	/// @return bool
	/// @param serverType ����������
	bool enterExternalServer(EServerType serverType);

	/// @brief �����뿪ĳ���ⲿ������
	/// @return bool
	/// @param serverType ����������
	bool leaveExternalServer(EServerType serverType, EPeerLeaveReason nReason);

    virtual bool serializeTo(BCLib::Utility::CStream& stream) const;
    virtual bool serializeFrom(BCLib::Utility::CStream& stream);

protected:
    virtual void _setLogicServerInfo(EServerType serverType, ServerID serverID);
    virtual void _delLogicServerInfo(EServerType serverType, ServerID serverID);
    BCLib::uint8 _getLogicServerInfo(SFLib::Message::SPeerServerInfo* serverList);

    virtual void _setExternalServerInfo(EServerType serverType, ServerID serverID);
    virtual void _delExternalServerInfo(EServerType serverType, ServerID serverID);
    BCLib::uint8 _getExternalServerInfo(SFLib::Message::SPeerServerInfo* serverList);

private:
    bool _sendMsgToGW(const SFLib::Message::SNetMessage* msg, const BCLib::uint32 msgSize);

private:
    ServerID m_gatewayServerID;
    BCLib::Network::TcpStubID m_gameClientStubID;
    SFLib::CommonServer::CTcpStubPtr m_gameClientStub;

    BCLib::Utility::CDateTime m_dtOffline;

    std::map<EServerType, ServerID> m_logicServerTypeMap;
    BCLib::Utility::CMutex  m_mutexLogicServerTypeMap;

	std::map<EServerType, ServerID> m_externalServerTypeMap;
	BCLib::Utility::CMutex  m_mutexExternalServerTypeMap;

	//
    friend class CMasterClient;
    friend class CLogicStub;
    friend class CLogicClient;
    friend class CLogicServer;
};
typedef BCLib::Utility::CSPointer<CNetPeer> CNetPeerPtr;
}//Logic
}//SFLib

#endif//__SFLIB_LOGICSERVER_NETPEER_H__
