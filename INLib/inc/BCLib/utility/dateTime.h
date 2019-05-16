//////////////////////////////////////////////////////////////////////
//  created:    2011/11/01
//  filename:   BCLib/utility/dateTime.h
//  author:     League of Perfect
/// @brief
///
//////////////////////////////////////////////////////////////////////
#ifndef __BCLIB_UTILITY_DATETIME_H__
#define __BCLIB_UTILITY_DATETIME_H__

#include <BCLib/utility/baseDef.h>
#include <time.h>
#include <chrono>
#ifndef _WIN32
#include <sys/time.h>
#else
#include <Winbase.h>
#include <time.h>
#define localtime_r(t, tm) localtime_s(tm, t)
#endif

namespace BCLib
{
namespace Utility
{
/// @brief �õ���ǰʱ��ĺ���ֵ
extern int64 getMilliseconds();

//////////////////////////////////////////////////////////////////////////
/// @brief ��װ������ʱ���࣬��ȷ���룬��õ�ʱ����
//////////////////////////////////////////////////////////////////////////
class BCLIB_UTILITY_API CDateTime
{
public:
    enum EWeekday
    {
        ESUNDAY,
        EMONDAY,
        ETUESDAY,
        EWEDNESDAY,
        ETHURSDAY,
        EFRIDAY,
        ESATURDAY,
    };

    CDateTime();
    CDateTime(time_t t);
    CDateTime(BCLib::uint32 time);
    CDateTime(const CDateTime& t);
    CDateTime(int year, int month, int day, int hour, int minute, int second);
    CDateTime(std::string strDateTime); // �������������ĸ�ʽ����2012-08-01 11:11:11��
    ~CDateTime();

    static CDateTime now();
    bool setSystemTime();

    void setTime(time_t timSec);
    void setTime(BCLib::uint32 time);
    void setTime(int year, int month, int day, int hour, int minute, int second);
    void setTime(std::string strDateTime); // �������������ĸ�ʽ����2012-08-01 11:11:11��

    time_t getTime() const;  // the seconds elapsed from 1970
    void getTime(int& year, int& month, int& day, int& hour, int& minute, int& second) const;
    //BCLib::uint32 getNumber() const;

    uint32 getYear() const;
    uint32 getMonth() const;
    uint32 getDay() const;
    uint32 getHour() const;
    uint32 getMinute() const;
    uint32 getSecond() const;

    EWeekday getWeekday() const;

    std::string toString() const;
    std::string toString(const char* pszFormat) const;

    CDateTime& operator=(const CDateTime& t);
    bool operator ==(const CDateTime& rhs) const;
    bool operator !=(const CDateTime& rhs) const;
    bool operator <(const CDateTime& rhs) const;
    bool operator <=(const CDateTime& rhs) const;
    bool operator >(const CDateTime& rhs) const;
    bool operator >=(const CDateTime& rhs) const;

    /// @brief ��ǰʱ������nYear����ʱ�䣬nYear�����Ǹ���
    CDateTime addYear(BCLib::int16 nYear);
    /// @brief ��ǰʱ������nMonth�º��ʱ�䣬nMonth�����Ǹ���
    CDateTime addMonth(BCLib::int16 nMonth);
    /// @brief ��ǰʱ������nDay����ʱ�䣬nDay�����Ǹ���
    CDateTime addDay(BCLib::int16 nDay);
    /// @brief ��ǰʱ������nHourʱ���ʱ�䣬nHour�����Ǹ���
    CDateTime addHour(BCLib::int16 nHour);
    /// @brief ��ǰʱ������nSecond�ֺ��ʱ�䣬nSecond�����Ǹ���
    CDateTime addMinute(BCLib::int16 nMinute);
    /// @brief ��ǰʱ������nSecond����ʱ�䣬nSecond�����Ǹ���
    CDateTime addSecond(BCLib::int16 nSecond);

    /// @brief ��������ʱ�������졢ʱ���֡��룬time ���Աȵ�ǰʱ���Ҳ���Աȵ�ǰʱ��С�����Ƿ�������
    void subTime(const CDateTime& time, BCLib::int32& day, BCLib::int32& hour, BCLib::int32& minute, BCLib::int32& second) const;
    /// @brief ��������ʱ�������룬time ���Աȵ�ǰʱ���Ҳ���Աȵ�ǰʱ��С�����Ƿ�������
    void subTime(const CDateTime& time, BCLib::int32& second) const;

public:
    //static uint32 getMilliseconds(); // the milliseconds elapsed from compute started

    static bool isExpired(int year, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);
    static bool isExpired(CDateTime dtExpired);
    static bool setSystemTime(int year, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);

    /// @brief ����start֮��num���Ӻ��ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpMinute(int num, uint32 start = now().getTime());

    /// @brief ����start֮��numСʱ���ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpHour(int num, uint32 start = now().getTime());

    /// @brief ����start֮��num����ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpDay(int num = 0, uint32 start = now().getTime());

    /// @brief ����start֮��num�ܺ��ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpWeek(int num = 0, uint32 start = now().getTime());

    /// @brief ����start֮��num�º��ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpMonth(int num = 0, uint32 start = now().getTime());

    /// @brief ����start֮��num����ʱ��
    /// @return uint32 ʱ���
    /// @param num
    /// @param start
    static uint32 sharpYear(int num = 0, uint32 start = now().getTime());

    /// @brief �ж�����ʱ����Ƿ�Ϊͬһ��
    /// @return bool
    /// @param time1
    /// @param time2
    static bool isSameDay(uint32 time1, uint32 time2);

private:
    time_t m_iSeconds;

    const static BCLib::uint32 ms_hour = 60;
    const static BCLib::uint32 ms_day = 24 * ms_hour;
    const static BCLib::uint32 ms_month = 31 * ms_day;
    const static BCLib::uint32 ms_year = 12 * ms_month;
};

//////////////////////////////////////////////////////////////////////////
/// @brief �򵥵�������(4 bytes) ���ȵ����ӣ������õ�ʱ����
/// @brief �ܹ���ʾ[0000/00/00 00:00 - 8017/12/31 23:59]
/// @brief �ܹ�������������֮����������/Сʱ/����
//////////////////////////////////////////////////////////////////////////
class BCLIB_UTILITY_API CSimpleTime
{
public:
    CSimpleTime();
    CSimpleTime(time_t t);
    CSimpleTime(BCLib::uint32 timeMin);
    CSimpleTime(const CSimpleTime& date);
    CSimpleTime(BCLib::uint32 year, BCLib::uint32 month, BCLib::uint32 day, BCLib::uint32 hour, BCLib::uint32 minute);
    CSimpleTime(std::string strDateTime); // �������������ĸ�ʽ����2012-08-01 11:11:11��
    CSimpleTime(const CDateTime& date);
    ~CSimpleTime();

    static CSimpleTime now();

    void setTime(time_t t);
    bool setTime(BCLib::uint32 timeMin);
    bool setTime(BCLib::uint32 year, BCLib::uint32 month, BCLib::uint32 day, BCLib::uint32 hour, BCLib::uint32 minute);
    void setTime(std::string strDateTime); // �������������ĸ�ʽ����2012-08-01 11:11:11��

    BCLib::uint32 getTime() const;
    void getTime(BCLib::uint32& year, BCLib::uint32& month, BCLib::uint32& day, BCLib::uint32& hour, BCLib::uint32& minute) const;

    BCLib::uint32 getYear() const;
    BCLib::uint32 getMonth() const;
    BCLib::uint32 getDay() const;
    BCLib::uint32 getHour() const;
    BCLib::uint32 getMinute() const;

    std::string toString() const;
    std::string toString(const char* pszFormat) const;

    CSimpleTime& operator=(const CSimpleTime& date);
    CSimpleTime& operator=(const CDateTime& date);
    bool operator ==(const CSimpleTime& date) const;
    bool operator !=(const CSimpleTime& date) const;
    bool operator <(const CSimpleTime& date) const;
    bool operator <=(const CSimpleTime& date) const;
    bool operator >(const CSimpleTime& date) const;
    bool operator >=(const CSimpleTime& date) const;

    /// @brief ��������ʱ�������졢ʱ���֣�time ���Աȵ�ǰʱ���Ҳ���Աȵ�ǰʱ��С�����Ƿ�������
    void subTime(const CSimpleTime& date, BCLib::int32& day, BCLib::int32& hour, BCLib::int32& minute) const;
    /// @brief ��������ʱ�������룬time ���Աȵ�ǰʱ���Ҳ���Աȵ�ǰʱ��С�����Ƿ�������
    void subTime(const CSimpleTime& date, BCLib::int32& minute) const;

private:
    BCLib::uint32 m_iMinutes;

    const static BCLib::uint32 ms_hour = 60;
    const static BCLib::uint32 ms_day = 24 * ms_hour;
    const static BCLib::uint32 ms_month = 31 * ms_day;
    const static BCLib::uint32 ms_year = 12 * ms_month;
};

//////////////////////////////////////////////////////////////////////////
/// @brief ������ʵʱ�䣬��ȷ������
//////////////////////////////////////////////////////////////////////////
template<class CLOCK_TYPE>
class CTemplateTime
{
public:
	typedef std::chrono::time_point<CLOCK_TYPE> TimePoint;
	typedef std::chrono::microseconds Microseconds;
	typedef std::chrono::milliseconds Milliseconds;
	typedef std::chrono::seconds Seconds;
	typedef std::chrono::minutes Minutes;
	typedef std::chrono::hours Hours;

	CTemplateTime(int delay = 0)
	{
		m_timePoint = CLOCK_TYPE::now();
        delayMilliseconds(delay);
	}

	void now()
	{
		m_timePoint = CLOCK_TYPE::now();
	}
	
    //����
    int64 getMicroseconds() const
    {
        return durationCast<Microseconds>();
    }
	//����
	int64 getMilliseconds() const
	{
		return durationCast<Milliseconds>();
	}
	//��
	int64 getSeconds() const
	{
		return durationCast<Seconds>();
	}
    //��
	int64 getMinutes() const
	{
		return durationCast<Minutes>();
	}
    //ʱ
	int64 getHours() const
	{
		return durationCast<Hours>();
	}

    //�ӳ����ٺ���
	void delayMilliseconds(int delay)
	{
        if (delay > 0)
        {
            m_timePoint += Milliseconds(delay);
        }
	}

	CTemplateTime& operator =(const CTemplateTime& rt)
	{
		m_timePoint = rt.m_timePoint; return *this;
	}
	CTemplateTime& operator +(const CTemplateTime& rt)
	{
		m_timePoint += rt.m_timePoint.time_since_epoch();
		return *this;
	}
	CTemplateTime& operator -(const CTemplateTime& rt)
	{
		m_timePoint -= rt.m_timePoint.time_since_epoch();
		return *this;
	}

	bool operator >(const CTemplateTime& rt)
	{
		return m_timePoint > rt.m_timePoint;
	}
	bool operator <(const CTemplateTime& rt)
	{
		return m_timePoint < rt.m_timePoint;
	}
	bool operator >=(const CTemplateTime& rt)
	{
		return m_timePoint >= rt.m_timePoint;
	}
	bool operator <=(const CTemplateTime& rt)
	{
		return m_timePoint <= rt.m_timePoint;
	}
	bool operator ==(const CTemplateTime& rt)
	{
		return m_timePoint == rt.m_timePoint;
	}

private:
	template<typename DurationType>
	int64 durationCast() const
	{
		return std::chrono::duration_cast<DurationType>(m_timePoint.time_since_epoch()).count();
	}

private:
	TimePoint m_timePoint;
};

// ϵͳʱ����
typedef CTemplateTime<std::chrono::system_clock> CSystemTime;
// �ϴ�������ʼ��ʱ�� �����Ա��޸ı���ʱ����Ӱ��
typedef CTemplateTime<std::chrono::steady_clock> CSteadyTime;
typedef CSteadyTime CRealTime; // ����֮ǰ����������������Ŀ���滻���ٳ���ȥ��

//////////////////////////////////////////////////////////////////////////
/// @brief ������ʵʱ�䣬��ȷ������
//////////////////////////////////////////////////////////////////////////
//class BCLIB_UTILITY_API CRealTime
//{
//public:
//    CRealTime(int delay = 0);
//
//    CRealTime(const CRealTime& rt)
//    {
//        m_milliseconds = rt.m_milliseconds;
//    }
//
//    /// @brief ���õ�ǰ�ĺ���
//    /// @return void
//    void now();
//
//    //void setMilliSeconds(int64 ms)
//    //{
//    //    m_milliseconds = ms;
//    //}
//
//    //����
//    int64 getMilliseconds() 
//    {
//        return m_milliseconds;
//    }
//
//    //��
//    int64 getSeconds() 
//    {
//        return m_milliseconds / 1000;
//    }
//
//    void delayMilliseconds(int delay)
//    {
//        m_milliseconds += delay;
//    }
//
//    CRealTime& operator =(const CRealTime& rt)
//    {
//        m_milliseconds = rt.m_milliseconds; return *this;
//    }
//    CRealTime& operator +(const CRealTime& rt)
//    {
//        m_milliseconds += rt.m_milliseconds; return *this;
//    }
//    CRealTime& operator -(const CRealTime& rt)
//    {
//        m_milliseconds -= rt.m_milliseconds; return *this;
//    }
//
//    bool operator >(const CRealTime& rt)
//    {
//        return m_milliseconds > rt.m_milliseconds;
//    }
//    bool operator <(const CRealTime& rt)
//    {
//        return m_milliseconds < rt.m_milliseconds;
//    }
//    bool operator >=(const CRealTime& rt)
//    {
//        return m_milliseconds >= rt.m_milliseconds;
//    }
//    bool operator <=(const CRealTime& rt)
//    {
//        return m_milliseconds <= rt.m_milliseconds;
//    }
//    bool operator ==(const CRealTime& rt)
//    {
//        return m_milliseconds == rt.m_milliseconds;
//    }
//
//private:
//#if defined(_WIN32)
//    static int64 m_frequency;
//#endif
//    int64 m_milliseconds;
//};

//////////////////////////////////////////////////////////////////////////
/// @brief ��ʱ��ʱ�����������Ķ�ʱ��������ȥ�ж��Ƿ�ʱ
//////////////////////////////////////////////////////////////////////////
class BCLIB_UTILITY_API CDelayTimer
{
public:
    CDelayTimer(int delay)
    :m_delay(delay)
    ,m_steadyTime(delay)
    {
    }

    CDelayTimer(int delay, const CSteadyTime& rt)
    :m_delay(delay)
    ,m_steadyTime(rt)
    {
        m_steadyTime.delayMilliseconds(delay);
    }

    /// @brief ���ö�ʱ��
    /// @return void
    /// @param delay �ӳ�ʱ��
    /// @param ct ��һ�γ�ʱ��ʱ��
    void reset(int delay, const CSteadyTime& ct)
    {
        m_delay = delay;
        m_steadyTime = ct;
        m_steadyTime.delayMilliseconds(delay);
    }

    /// @brief �����´γ�ʱʱ��
    /// @return void
    /// @param ct ct + m_delayΪ�´γ�ʱʱ��
    void next(const CSteadyTime& ct)
    {
        m_steadyTime = ct;
        m_steadyTime.delayMilliseconds(m_delay);
    }

    /// @brief ��ȡ�´γ�ʱʱ��(millisecond)
    /// @return int64
    int64 getExpireTimeInMS()
    {
        return m_steadyTime.getMilliseconds();
    }

    /// @brief �ж��Ƿ�ʱ
    /// @return bool
    /// @param ct ��ǰʱ��
    bool operator ()(const CSteadyTime& ct)
    {
        if(m_steadyTime <= ct)
        {
            m_steadyTime = ct;
            m_steadyTime.delayMilliseconds(m_delay);
            return true;
        }
        return false;
    }

private:
    int m_delay;
    //�´γ�ʱʱ��
    CSteadyTime m_steadyTime;
};

//void Sample()
//{
//    CSteadyTime steadyTime;
//    CDelayTimer delayTime(300);
//    while(true)
//    {
//        if(dalayTime(steadyTime)) {
//            //TODO
//        }
//        steadyTime.now();
//    };
//}

//////////////////////////////////////////////////////////////////////////
/// @brief ���ܲ��ԣ���ʱ��
//////////////////////////////////////////////////////////////////////////
class BCLIB_UTILITY_API CSurveyTimer
{
public:
    CSurveyTimer();

    /// @brief ���ü�ʱ��
    /// @return void
    void reset();

    /// @brief �����ϴ����õ����ھ���������
    /// @return BCLib::int64
    int64 seconds();

    /// @brief �����ϴ����õ����ھ����ĺ�����
    /// @return BCLib::int64
    int64 milliseconds();

    /// @brief �����ϴ����õ����ھ�����΢����
    /// @return BCLib::int64
    int64 microseconds();

private:
#if defined(_WIN32)
    LARGE_INTEGER m_lastTime;
    static int64 m_frequency;
#elif defined(_LINUX)
    timespec m_lastTime;
#endif
};

//void Sample()
//{
//    BCLib::Utility::CSurveyTimer surveyTimer;
//    surveyTimer.reset();
//    //TODO
//    BCLib::int64 tempMs = surveyTimer.milliseconds();
//    BCLIB_LOG_TRACE(BCLib::ELOGMODULE_DEFAULT, "TODO���ѵ�ʱ��[%d]", tempMs);
//}

}//Utility
}//BCLib

#endif//__BCLIB_UTILITY_DATETIME_H__