﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Proto2Code
{
    public class CGenerateModuleMessageCSharp
    {
        private CNameUnit m_nameUnit;
        private string m_writePath;

        private FileStream m_file;
        private StreamWriter m_write;

        public CGenerateModuleMessageCSharp(CNameUnit nameUnit, string writeRoot)
        {
            m_nameUnit = nameUnit;
            m_writePath = writeRoot + char.ToUpper(m_nameUnit.MoudleSysName[0])+m_nameUnit.MoudleSysName.Substring(1) + "Msg.cs";
        }

        public void StartWrite(List<SMsgID> systemList)
        {
            m_file = new FileStream(m_writePath, FileMode.OpenOrCreate);
            m_write = new StreamWriter(m_file,Encoding.UTF8);

            WriteHead();
            WriteEnum(systemList);
            WriteFunc(systemList);
            WriteEnd();
            m_write.Close();
        }

        private void WriteHead()
        {
            m_write.WriteLine("/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            m_write.WriteLine("*  <autogenerated>");
            m_write.WriteLine("*  This code was generated by a tool.");
            m_write.WriteLine("*  Changes to this file may cause incorrect behavior and will be lost if the code is regenerated.");
            m_write.WriteLine("*  </autogenerated>");
            m_write.WriteLine("* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */");

            m_write.WriteLine("using System;");
            m_write.WriteLine("using System.Collections.Generic;");
            m_write.WriteLine("using CSLib.Utility;");
            m_write.WriteLine("using CSLib.Framework;");
            m_write.WriteLine("using UDLib.Network;");
            m_write.WriteLine("using PTBuf;");
        }

        private void WriteEnum(List<SMsgID> systemList)
        {
            m_write.WriteLine(string.Format("public enum EMsgID{0}",char.ToUpper(m_nameUnit.MoudleSysName[0]))+m_nameUnit.MoudleSysName.Substring(1));
            m_write.WriteLine("{");

            string lastMsg = "";
            foreach(var v in systemList)
            {
                int _index = -1;
                int _count = 0;
                for(int i = 0;i<v.enumName.Length;i++)
                {
                    if(v.enumName[i] == '_')
                    {
                        _count++;
                        if(_count == 3)
                        {
                            _index = i;
                            break;
                        }
                    }
                }
                if(_index > -1)
                {
                    string tempStr = v.enumName.Substring(_index);
                    if (tempStr != lastMsg && !string.IsNullOrEmpty(lastMsg))
                    {
                        m_write.WriteLine();
                    }
                    lastMsg = tempStr;
                }
                m_write.WriteLine("     "+v.enumName+"," + "     //"+v.enumPTBuf+"     //"+v.annotation);
            }
            m_write.WriteLine("};");
        }

        private void WriteFunc(List<SMsgID> systemList)
        {
            string funcType = m_nameUnit.MoudleSysName.ToUpper();
            string msgID = char.ToUpper(m_nameUnit.MoudleSysName[0]) + m_nameUnit.MoudleSysName.Substring(1);
            foreach (var v in systemList)
            {
                string[] clips = v.enumName.Split('_');
                if(clips == null || clips.Length <= 2)
                {
                    continue;
                }
                if(clips[1] == "GC2CT" || clips[1] == "CT2GC")
                {
                    m_write.WriteLine();
                    m_write.WriteLine("[Serializable]");
                    string className = "CMsg" + clips[1];
                    for(int i  = 2;i<clips.Length;i++)
                    {
                        className += CHelper.ToCaptilize(clips[i].ToLower());
                    }
                    string buf = v.enumPTBuf;
                    if(buf.Contains(","))
                    {
                        buf = buf.Split(',')[1];
                    }
                    buf.Replace("::",".");
                    buf = buf.Trim();
                    m_write.WriteLine("public class "+className+ string.Format(": CBufMessage<{0}>", buf));
                    m_write.WriteLine("{");

                    m_write.WriteLine("     public "+className+"()");
                    string serverType = "";
                    if(clips[1] == "GC2CT")
                    {
                        serverType = "ESERVER_CENTER";
                    }
                    else if(clips[1] == "CT2GC")
                    {
                        serverType = "ESERVER_GAMECLIENT";
                    }
                    m_write.WriteLine(string.Format("        :base((byte)EServerType.{0}, (byte)EFuncType.EFUNC_{1}, (ushort)EMsgID{2}.{3})",serverType, funcType, msgID, v.enumName));
                    m_write.WriteLine("     {");
                    m_write.WriteLine("     }");
                    m_write.WriteLine("};");
                }
            }
        }

        private void WriteEnd()
        {
            m_write.WriteLine("// 不要忘记定义好消息，立马到 CMsgFactory 类中去添加对应的创建函数。");
        }
    }
}
