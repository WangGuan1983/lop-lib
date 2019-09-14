//////////////////////////////////////////////////////////////////////
//  created:    2011/11/01
//  filename:   SFLib/logicServer/logicServer.h
//  author:     League of Perfect
/// @brief
///
//////////////////////////////////////////////////////////////////////
#ifndef __SFLIB_LOGICSERVER_LOGICSERVER_H__
#define __SFLIB_LOGICSERVER_LOGICSERVER_H__

#include <SFLib/commonServer/commonServer2Master.h>
#include <BCLib/network/udp/udpServer.h>

namespace SFLib
{
namespace Logic
{
class CLogicServer : public SFLib::CommonServer::CCommonServer2Master
{
public:
    CLogicServer(const std::string& name);
    virtual ~CLogicServer();

	bool sendMsgToMS(PeerID peerID, const SFLib::Message::CNetMessage* msg);
	bool sendMsgToMS(PeerID peerID, const SFLib::Message::SNetMessage* msg, const BCLib::uint32 msgSize);

    /// @brief ����PeerID
    /// @return bool
    /// @param peerID ����ָ����PeerID�����Ϊ0�����������
    /// @param gatewayServerID ������������ص�ServerID
    /// @param gameClientStubID ��������������ϣ���Ӧ�Ŀͻ���StubID
    bool requestPeerID(PeerID peerID, ServerID gatewayServerID, BCLib::Network::TcpStubID gameClientStubID);

    /// @brief requestPeerID����Ļص�����
    /// @return void
    /// @param peerID ���뵽��PeerID
    virtual void cbRespondPeerID(PeerID peerID, ServerID gatewayServerID, BCLib::Network::TcpStubID gameClientStubID) {}

protected:
    virtual bool _init();

    virtual BCLib::Network::CTcpStubSPtr _cbNewStub(const BCLib::Network::CTcpConnectionSPtr& connPtr);

    virtual SFLib::CommonServer::CTcpClientPtr _createMasterClient();
    virtual SFLib::CommonServer::CCommonClientPtr _createLogicClient(SFLib::Message::SServerInfo& serverInfo);

    /// @brief ���Ҫ��P2P���ܣ����Կ���UDP����
    /// @return bool
    bool _initUdpServer();
    virtual BCLib::Network::CUdpProxy* _createUdpProxy();

protected:
    virtual bool _createMsgExecPtr(BCLib::uint16 type, BCLib::uint16 id, BCLib::Framework::CMsgExecPtr& msgExecPtr);

private:
    BCLib::Network::CUdpServer m_udpSrv;
};
}//Logic
}//SFLib

#endif//__SFLIB_LOGICSERVER_LOGICSERVER_H__
