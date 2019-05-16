// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------

#include "projectServer.pe.h"
#include <BCLib/utility/convert.h>
#include <BCLib/utility/logFile.h>

namespace PTExt
{

CProjectServer::CProjectServer()
{
}

CProjectServer::CProjectServer(const PTBuf::CProjectServer& ptBuf)
{
    m_ptBuf = ptBuf;
}

CProjectServer::~CProjectServer()
{
}

PTBuf::CProjectServer& CProjectServer::getBuf()
{
    return m_ptBuf;
}

void CProjectServer::dumpInfo()
{
    BCLIB_LOG_TRACE(BCLib::ELOGMODULE_DEFAULT, "DumpInfo : projectid = %llu, platformname = %s, channelname = %s, devicetype = %u, version = %s, serverid = %u, servername = %s, serveraddr = %s, servertype = %u, serverstate = %u, serverindex = %u, whiteaddr = %s, openstate = %u, members = %s", m_ptBuf.projectid(), m_ptBuf.platformname().c_str(), m_ptBuf.channelname().c_str(), m_ptBuf.devicetype(), m_ptBuf.version().c_str(), m_ptBuf.serverid(), m_ptBuf.servername().c_str(), m_ptBuf.serveraddr().c_str(), m_ptBuf.servertype(), m_ptBuf.serverstate(), m_ptBuf.serverindex(), m_ptBuf.whiteaddr().c_str(), m_ptBuf.openstate(), m_ptBuf.members().c_str());
}

bool CProjectServer::isValidity(PTBuf::CProjectServer& ptBuf)
{
    std::string strValue = "";

    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.platformname());
    if (strValue.size() > 64) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.channelname());
    if (strValue.size() > 64) return false;
    // byte
    if (ptBuf.devicetype() > BCLIB_UINT8_MAX) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.version());
    if (strValue.size() > 64) return false;
    // ushort
    if (ptBuf.serverid() > BCLIB_UINT16_MAX) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.servername());
    if (strValue.size() > 64) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.serveraddr());
    if (strValue.size() > 64) return false;
    // byte
    if (ptBuf.servertype() > BCLIB_UINT8_MAX) return false;
    // byte
    if (ptBuf.serverstate() > BCLIB_UINT8_MAX) return false;
    // ushort
    if (ptBuf.serverindex() > BCLIB_UINT16_MAX) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.whiteaddr());
    if (strValue.size() > 1024) return false;
    // byte
    if (ptBuf.openstate() > BCLIB_UINT8_MAX) return false;
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.members());
    if (strValue.size() > 4096) return false;

    return true;
}

bool CProjectServer::makeValidity(PTBuf::CProjectServer& ptBuf)
{
    std::string strValue = "";

    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.platformname());
    if (strValue.size() > 64) strValue = strValue.substr(0, 64);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_platformname(strValue);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.channelname());
    if (strValue.size() > 64) strValue = strValue.substr(0, 64);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_channelname(strValue);
    // byte
    if (ptBuf.devicetype() > BCLIB_UINT8_MAX) ptBuf.set_devicetype(BCLIB_UINT8_MAX);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.version());
    if (strValue.size() > 64) strValue = strValue.substr(0, 64);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_version(strValue);
    // ushort
    if (ptBuf.serverid() > BCLIB_UINT16_MAX) ptBuf.set_serverid(BCLIB_UINT16_MAX);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.servername());
    if (strValue.size() > 64) strValue = strValue.substr(0, 64);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_servername(strValue);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.serveraddr());
    if (strValue.size() > 64) strValue = strValue.substr(0, 64);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_serveraddr(strValue);
    // byte
    if (ptBuf.servertype() > BCLIB_UINT8_MAX) ptBuf.set_servertype(BCLIB_UINT8_MAX);
    // byte
    if (ptBuf.serverstate() > BCLIB_UINT8_MAX) ptBuf.set_serverstate(BCLIB_UINT8_MAX);
    // ushort
    if (ptBuf.serverindex() > BCLIB_UINT16_MAX) ptBuf.set_serverindex(BCLIB_UINT16_MAX);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.whiteaddr());
    if (strValue.size() > 1024) strValue = strValue.substr(0, 1024);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_whiteaddr(strValue);
    // byte
    if (ptBuf.openstate() > BCLIB_UINT8_MAX) ptBuf.set_openstate(BCLIB_UINT8_MAX);
    // string
    strValue = "";
    BCLib::Utility::CConvert::utf8ToGB2312(strValue, ptBuf.members());
    if (strValue.size() > 4096) strValue = strValue.substr(0, 4096);
    BCLib::Utility::CConvert::gb2312ToUTF8(strValue, strValue);
    ptBuf.set_members(strValue);

    return true;
}

bool CProjectServer::canUpdate(PTBuf::CProjectServer& oldBuf, PTBuf::CProjectServer& newBuf)
{
    return true;
}

BCLIB_SINGLETON_DEFINE(CProjectServerOwner)

CProjectServerOwner::CProjectServerOwner()
{
}

CProjectServerOwner::~CProjectServerOwner()
{
}

bool CProjectServerOwner::addObject(BCLib::uint64 key, const PTBuf::CProjectServer& ptBuf)
{
    if (m_hashMap.find(key) != m_hashMap.end()) return false;

    PTExt::CProjectServer tmpBuf(ptBuf);
    m_hashMap.setValue(key, tmpBuf);
    return true;
}

bool CProjectServerOwner::addObject(BCLib::uint64 key, const PTExt::CProjectServer& ptBuf)
{
    if (m_hashMap.find(key) != m_hashMap.end()) return false;

    m_hashMap.setValue(key, ptBuf);
    return true;
}

PTExt::CProjectServer* CProjectServerOwner::getObject(BCLib::uint64 entityID)
{
    if (entityID == 0) return NULL;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        return &it->second;
    }

    return NULL;
}

bool CProjectServerOwner::delObject(BCLib::uint64 entityID)
{
    if (entityID == 0) return false;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        m_hashMap.erase(it);
        return true;
    }

    return true;
}

void CProjectServerOwner::dumpInfo(BCLib::uint64 entityID)
{
    if (entityID == 0) return;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        it->second.dumpInfo();
    }
}


CProjectServerList::CProjectServerList()
{
}

CProjectServerList::CProjectServerList(const PTBuf::CProjectServerList& ptList)
{
    m_List = ptList;
}

CProjectServerList::~CProjectServerList()
{
}

void CProjectServerList::dumpInfo()
{
    for(int i = 0; i < m_List.objects_size(); i++)
    {
        CProjectServer tmpBuf(m_List.objects(i));
        tmpBuf.dumpInfo();
    }
}

PTBuf::CProjectServerList& CProjectServerList::getList()
{
    return m_List;
}


BCLIB_SINGLETON_DEFINE(CProjectServerListCtrl)

CProjectServerListCtrl::CProjectServerListCtrl()
{
}

CProjectServerListCtrl::~CProjectServerListCtrl()
{
}


BCLIB_SINGLETON_DEFINE(CProjectServerListOwner)

CProjectServerListOwner::CProjectServerListOwner()
{
}

CProjectServerListOwner::~CProjectServerListOwner()
{
}

bool CProjectServerListOwner::addObject(BCLib::uint64 entityID, const PTBuf::CProjectServerList& ptList)
{
    if (m_hashMap.find(entityID) != m_hashMap.end()) return false;

    PTExt::CProjectServerList tmpList(ptList);
    m_hashMap.setValue(entityID, tmpList);
    return true;
}

bool CProjectServerListOwner::addObject(BCLib::uint64 entityID, const PTExt::CProjectServerList& ptList)
{
    if (m_hashMap.find(entityID) != m_hashMap.end()) return false;

    m_hashMap.setValue(entityID, ptList);
    return true;
}

PTExt::CProjectServerList* CProjectServerListOwner::getObject(BCLib::uint64 entityID)
{
    if (entityID == 0) return NULL;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        return &it->second;
    }

    return NULL;
}

bool CProjectServerListOwner::delObject(BCLib::uint64 entityID)
{
    if (entityID == 0) return false;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        m_hashMap.erase(it);
        return true;
    }

    return true;
}

void CProjectServerListOwner::dumpInfo(BCLib::uint64 entityID)
{
    if (entityID == 0) return;

    THashMap::iterator it = m_hashMap.find(entityID);
    if (it != m_hashMap.end())
    {
        it->second.dumpInfo();
    }
}


} // namespace PTExt