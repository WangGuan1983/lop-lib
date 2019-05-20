﻿using System;
using System.IO;

namespace Proto2Code
{
    public class CGeneration : CSLib.Utility.CSingleton<CGeneration>
    {
        public bool Analysis(string[] args)
        {
            string[] arrResult = null;

            for (int i = 0; i < args.Length; ++i)
            {
                arrResult = args[i].Split('=');

                if (arrResult[0] == "-GenType") m_strGenType = arrResult[1];

                else if (arrResult[0] == "-EnumName") m_strEnumName = arrResult[1];
                else if (arrResult[0] == "-EnumValue") m_strEnumValue = arrResult[1];
                else if (arrResult[0] == "-EnumDesc") m_strEnumDesc = arrResult[1];

                else if (arrResult[0] == "-DescPath") m_strDescPath = arrResult[1];
                else if (arrResult[0] == "-DescFile") m_strDescFile = arrResult[1];
                else if (arrResult[0] == "-Language") m_strLanguage = arrResult[1];

                else if (arrResult[0] == "-ProtoPath") m_strProtoPath = arrResult[1];
                else if (arrResult[0] == "-PBSrcPath") m_strPBSrcPath = arrResult[1];
                else if (arrResult[0] == "-PBSrcFile") m_strPBSrcFile = arrResult[1];

                else if (arrResult[0] == "-DataPath") m_strDataPath = arrResult[1];
                else if (arrResult[0] == "-DataFile") m_strDataFile = arrResult[1];

                else if (arrResult[0] == "-OutputPath") m_strOutputPath = arrResult[1];
                else if (arrResult[0] == "-OutputFile") m_strOutputFile = arrResult[1];
            }

            if(m_strLanguage != "")
            {
                m_strLanguage = m_strLanguage.ToLower();
            }
            //
            if (m_strOutputPath != "")
            {
                DirectoryInfo tmpDirectoryInfo = new DirectoryInfo(m_strOutputPath);
                if (!tmpDirectoryInfo.Exists)
                {
                    try
                    {
                        tmpDirectoryInfo.Create();
                    }
                    catch (IOException ex)
                    {
                        CSLib.Utility.CDebugOut.LogException(ex);
                        return false; // 目录创建失败
                    }
                }
            }

            if (m_strOutputFile != "")
            {
                FileInfo tmpFileInfo = new FileInfo(m_strOutputFile);
                DirectoryInfo tmpDirectoryInfo = new DirectoryInfo(tmpFileInfo.DirectoryName);
                if (!tmpDirectoryInfo.Exists)
                {
                    try
                    {
                        tmpDirectoryInfo.Create();
                    }
                    catch (IOException ex)
                    {
                        CSLib.Utility.CDebugOut.LogException(ex);
                        return false; // 目录创建失败
                    }
                }
            }

            return true;
        }

        public int Generation(bool bSync)
        {
            if (m_strGenType == "Enum")
            {
                return _Gen4Enum();
            }
            else if (m_strGenType == "Proto")
            {
                return _Gen4Proto();
            }
            else if (m_strGenType == "Pbsrc")
            {
                return _Gen4Pbsrc(bSync);
            }
            else if (m_strGenType == "Binary")
            {
                return _Gen4Binary();
            }else if(m_strGenType == "Msg")
            {
                return _Gen4Msg();
            }else if(m_strGenType == "LuaConfig")
            {
                return _Gen4LuaConfig();
            }

            return 0;
        }

        private int _Gen4Enum()
        {
            if ((m_strDataFile == "") || (m_strOutputFile == "") || (m_strEnumName == "") || (m_strEnumValue == "") || (m_strEnumDesc == ""))
            {
                CSLib.Utility.CDebugOut.LogError(string.Format("有参数为空字符"));
                return 1; // 参数不对
            }

            FileInfo fileInfo = new FileInfo(m_strOutputFile);
            if (fileInfo.Extension != ".proto")
            {
                CSLib.Utility.CDebugOut.LogError(string.Format("后缀名不是 proto"));
                return 4; // 文件后缀名不正确
            }

            if (!Program.IsNewFile(m_strDataFile) && File.Exists(m_strOutputFile))return 0;
            Program.SetFileNew(m_strOutputFile);
            
            CSLib.Generation.CDesTmpl.EnumName = m_strEnumName;
            CSLib.Generation.CDesTmpl.EnumValue = m_strEnumValue;
            CSLib.Generation.CDesTmpl.EnumDesc = m_strEnumDesc;

            CSLib.Generation.CDesTable.Clear();
            if (!CSLib.Generation.CDesTable.Instance.LoadTable(m_strDataFile, null))
            {
                CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDataFile));
                return 3; // 文件加载失败
            }

            CSLib.Generation.CGenerateEnum.Generate(m_strDataFile, m_strOutputFile);
            return 0;
        }

        private int _Gen4Proto()
        {
            if ((m_strDescPath != "") && (m_strOutputPath != ""))
            {
                DirectoryInfo descDirectoryInfo = new DirectoryInfo(m_strDescPath);
                DirectoryInfo outputDirectoryInfo = new DirectoryInfo(m_strOutputPath);

                foreach (FileInfo tmpFileInfo in descDirectoryInfo.GetFiles("*.xlsx"))
                {
                    if (tmpFileInfo.Name.StartsWith("~$")) continue;
                    m_strDescFile = tmpFileInfo.FullName;
                    m_strOutputFile = m_strOutputPath + tmpFileInfo.Name;
                    m_strOutputFile = m_strOutputFile.Replace(".xlsx", ".proto");

                    if (!Program.IsNewFile(m_strDescFile) && File.Exists(Program.FirstCharToLower(m_strOutputFile))) continue;
                    Program.SetFileNew(Program.FirstCharToLower(m_strOutputFile));

                    CSLib.Generation.CProTable.Clear();
                    if (!CSLib.Generation.CProTable.Instance.LoadTable(m_strDescFile, null))
                    {
                        CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDescFile));
                        continue;
                    }

                    CSLib.Generation.CGenerateProtobuf.Generate(m_strDescFile, m_strOutputFile);
                    CSLib.Generation.CGenerateProtoext.Generate(m_strDescFile, m_strOutputFile, m_strLanguage);
                }
            }
            else if ((m_strDescFile != "") && (m_strOutputFile != "") && (Program.IsNewFile(m_strDescFile) || !File.Exists(m_strOutputFile)))
            {
                if (!CSLib.Generation.CProTable.Instance.LoadTable(m_strDescFile, null))
                {
                    CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDescFile));
                    return 3; // 文件加载失败
                }
                Program.SetFileNew(m_strOutputFile);
                CSLib.Generation.CGenerateProtobuf.Generate(m_strDescFile, m_strOutputFile);
                CSLib.Generation.CGenerateProtoext.Generate(m_strDescFile, m_strOutputFile, m_strLanguage);
            }
            return 0;
        }

        private int _Gen4Pbsrc(bool bSync)
        {
            if ((m_strProtoPath != "") && (m_strOutputPath != "") &&(m_strLanguage != ""))
            {
                DirectoryInfo protoDirectoryInfo = new DirectoryInfo(m_strProtoPath);
                DirectoryInfo outputDirectoryInfo = new DirectoryInfo(m_strOutputPath);
                Environment.CurrentDirectory = protoDirectoryInfo.FullName;

                FileInfo fileInfo = null;
                FileInfo luafileInfo = null;
                if (m_strLanguage == "c++")
                {
                    fileInfo = new FileInfo(Environment.CurrentDirectory + "/../../../EXLib/protobuf/bin/protoc.exe");
                    if (!Directory.Exists(outputDirectoryInfo.FullName + "/C++/"))
                        Directory.CreateDirectory(outputDirectoryInfo.FullName + "/C++/");
                }
                else if (m_strLanguage == "python")
                {
                    fileInfo = new FileInfo(Environment.CurrentDirectory + "/../../../EXLib/protobuf/bin/protoc.exe");
                    if (!Directory.Exists(outputDirectoryInfo.FullName + "/Python/"))
                        Directory.CreateDirectory(outputDirectoryInfo.FullName + "/Python/");
                }
                else if (m_strLanguage == "c#")
                {
                    fileInfo = new FileInfo(Environment.CurrentDirectory + "/../../../EXLib/csharp/Protobuf-net/bin/protogen.exe");
                    if (!Directory.Exists(outputDirectoryInfo.FullName + "/C#/"))
                        Directory.CreateDirectory(outputDirectoryInfo.FullName + "/C#/");
                }
                else if (m_strLanguage == "lua")
                {
                    fileInfo = new FileInfo(Environment.CurrentDirectory + "/../../../EXLib/protobuf/bin/protoc.exe");
                    luafileInfo = new FileInfo(Environment.CurrentDirectory + "/../../../EXLib/protobuf-lua/protoc-gen-lua.bat");
                    if (!Directory.Exists(outputDirectoryInfo.FullName + "/Lua/"))
                        Directory.CreateDirectory(outputDirectoryInfo.FullName + "/Lua/");
                }
                if(null == fileInfo)
                {
                    CSLib.Utility.CDebugOut.LogError(string.Format("未识别的语言类型{0}",m_strLanguage));
                    return 1;
                }

                foreach (FileInfo tmpFileInfo in protoDirectoryInfo.GetFiles("*.proto"))
                {
                    System.Diagnostics.ProcessStartInfo Info = new System.Diagnostics.ProcessStartInfo();
                    Info.WorkingDirectory = protoDirectoryInfo.FullName;
                    Info.FileName = fileInfo.FullName;
                    Info.WindowStyle = System.Diagnostics.ProcessWindowStyle.Hidden;
                    if (m_strLanguage == "c++")
                    {
                        string ccFile = outputDirectoryInfo.FullName + "/C++/" + tmpFileInfo.Name;
                        if (!Program.IsNewFile(tmpFileInfo.FullName) && File.Exists(ccFile.Replace(".proto", ".pb.cc")) && File.Exists(ccFile.Replace(".proto", ".pb.h")))
                            continue;
                        Info.Arguments = "--cpp_out=" + outputDirectoryInfo.FullName + "/C++      " + tmpFileInfo.Name;
                    }
                    else if (m_strLanguage == "python")
                    {
                        string pythonFile = outputDirectoryInfo.FullName + "/Python/" + tmpFileInfo.Name;

                        if(!Program.IsNewFile(tmpFileInfo.FullName) && File.Exists(pythonFile.Replace(".proto", "_pb2.py")))
                            continue;
                        Info.Arguments = "--python_out=" + outputDirectoryInfo.FullName + "/Python      " + tmpFileInfo.Name;
                    }
                    else if (m_strLanguage == "c#")
                    {
                        string csFile = outputDirectoryInfo.FullName + "/C#/" + tmpFileInfo.Name.Replace(".proto", ".pb.cs");

                        if (!Program.IsNewFile(tmpFileInfo.FullName) && File.Exists(csFile))
                            continue;
                        Info.Arguments = "-i:" + tmpFileInfo.Name + "       -o:" + outputDirectoryInfo.FullName + "/C#/" + tmpFileInfo.Name.Replace(".proto", ".pb.cs");
                    }
                    else if (m_strLanguage == "lua")
                    {
                        string luaFile = outputDirectoryInfo.FullName + "/Lua/" + tmpFileInfo.Name.Replace(".proto", "_pb.lua");
                        if (!Program.IsNewFile(tmpFileInfo.FullName) && File.Exists(luaFile))
                            continue;

                        string luaOut = Path.Combine(outputDirectoryInfo.FullName, "Lua\\");
                        string _args = "--plugin=protoc-gen-lua=" + luafileInfo.FullName + " --lua_out=" + luaOut + " " + tmpFileInfo.Name;
                        Info.Arguments = _args;
                    }
                    try
                    {
                        Info.UseShellExecute = false;
                        if(bSync)
                        {
                            var proc = System.Diagnostics.Process.Start(Info);
                            proc.WaitForExit();
                        }
                        else
                        {
                            System.Diagnostics.Process.Start(Info);
                        }
                    }
                    catch (System.ComponentModel.Win32Exception e)
                    {
                        Console.WriteLine("系统找不到指定的程序文件。\r{0}", e);
                    }
                }
            }
            return 0;
        }

        private int _Gen4Binary()
        {
            if ((m_strDataPath != "") && (m_strDescPath != "") && (m_strPBSrcPath != "") && (m_strOutputPath != ""))
            {
                Environment.CurrentDirectory = Environment.CurrentDirectory + "/../01_TableGeneration/";
                DirectoryInfo dataDirectoryInfo = new DirectoryInfo(m_strDataPath);
                DirectoryInfo descDirectoryInfo = new DirectoryInfo(m_strDescPath);
                DirectoryInfo pbsrcDirectoryInfo = new DirectoryInfo(m_strPBSrcPath);
                DirectoryInfo outputDirectoryInfo = new DirectoryInfo(m_strOutputPath);

                foreach (FileInfo tmpFileInfo in dataDirectoryInfo.GetFiles("*.xlsx"))
                {
                    if (tmpFileInfo.Name.StartsWith("~$")) continue;
                    if (!Program.IsNewFile(tmpFileInfo.FullName) && File.Exists(Program.FirstCharToLower((m_strOutputPath + tmpFileInfo.Name).Replace(".xlsx", ".txt")))) continue;
                    if (File.Exists(Program.FirstCharToLower((m_strOutputPath + tmpFileInfo.Name).Replace(".xlsx", ".txt"))))
                        File.Delete(Program.FirstCharToLower((m_strOutputPath + tmpFileInfo.Name).Replace(".xlsx", ".txt")));
                    m_strDataFile = tmpFileInfo.FullName;
                    m_strDescFile = m_strDescPath + tmpFileInfo.Name;

                    m_strPBSrcFile = m_strPBSrcPath + tmpFileInfo.Name;
                    m_strPBSrcFile = m_strPBSrcFile.Replace("xlsx", "pb.cs");

                    m_strOutputFile = m_strOutputPath + tmpFileInfo.Name;
                    m_strOutputFile = m_strOutputFile.Replace(".xlsx", ".txt");

                    CSLib.Generation.CProTable.Clear();
                    CSLib.Generation.CDesTable.Clear();

                    if (!CSLib.Generation.CProTable.Instance.LoadTable(m_strDescFile, null))
                    {
                        CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDescFile));
                        continue;
                    }

                    if(!File.Exists(m_strPBSrcFile))
                    {
                        CSLib.Utility.CDebugOut.LogError(string.Format("pb文件不存在{0}", m_strPBSrcFile));
                        continue;
                    }
                    if (!CSLib.Generation.CSerializationFile.Instance.DynamicCompileProtobufCsharpFile(m_strPBSrcFile))
                    {
                        CSLib.Utility.CDebugOut.LogError(string.Format("动态编译{0}失败", m_strPBSrcFile));
                        continue;
                    }

                    CSLib.Generation.CSerializationFile.Instance.SetClassName(m_strDataFile);

                    if (!CSLib.Generation.CSerializationFile.Instance.LoadTable(m_strDataFile, null))
                    {
                        CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDataFile));
                        continue;
                    }
                    CSLib.Generation.CSerializationFile.Instance.GenerateSerializationFile(m_strOutputFile);
                }
            }
            else if ((m_strDataFile != "") && (m_strDescFile != "") && (m_strPBSrcFile != "") && (m_strOutputFile != "") 
                && (Program.IsNewFile(m_strDataFile) || !File.Exists(m_strOutputFile)))
            {
                 if (File.Exists(Program.FirstCharToLower(m_strOutputFile)))
                     File.Delete(Program.FirstCharToLower(m_strOutputFile));
                    
                if (!CSLib.Generation.CProTable.Instance.LoadTable(m_strDescFile, null))
                {
                    CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDescFile));
                    return 3; // 文件加载失败
                }

                if (!CSLib.Generation.CSerializationFile.Instance.DynamicCompileProtobufCsharpFile(m_strPBSrcFile))
                {
                    CSLib.Utility.CDebugOut.LogError(string.Format("动态编译{0}失败", m_strPBSrcFile));
                    return 3; // 文件加载失败
                }

                CSLib.Generation.CSerializationFile.Instance.SetClassName(m_strDataFile);

                if (!CSLib.Generation.CSerializationFile.Instance.LoadTable(m_strDataFile, null))
                {
                    CSLib.Utility.CDebugOut.LogError(string.Format("加载{0}失败", m_strDataFile));
                    return 3; // 文件加载失败
                }

                CSLib.Generation.CSerializationFile.Instance.GenerateSerializationFile(m_strOutputFile);
            }
            return 0;
        }

        private int _Gen4Msg()
        {
            if((m_strDataPath != "") && (m_strOutputPath != "") && (m_strLanguage != ""))
            {
                DirectoryInfo dataDirectoryInfo = new DirectoryInfo(m_strDataPath);
                DirectoryInfo outputDirectoryInfo = new DirectoryInfo(m_strOutputPath);
                
                CProtoFileGen.Generate(new string[] { dataDirectoryInfo.FullName, outputDirectoryInfo.FullName , m_strLanguage });


                //FileInfo FileInfo = new FileInfo(Environment.CurrentDirectory + "/../04_ProtoFileGen/ProtoFileGen.exe");

                System.Diagnostics.ProcessStartInfo Info = new System.Diagnostics.ProcessStartInfo();
                    
                //Info.WorkingDirectory = dataDirectoryInfo.FullName;
                    
                //Info.FileName = FileInfo.FullName;
                //%src_proto_path% %gen_files_path% %create_files_type%
                Info.Arguments = dataDirectoryInfo.FullName + "     "+ outputDirectoryInfo.FullName + "     " + m_strLanguage;
                try
                {
                    //System.Diagnostics.Process.Start(Info);
                }
                catch (System.ComponentModel.Win32Exception e)
                {
                    Console.WriteLine("系统找不到指定的程序文件。\r{0}", e);
                }
            }
            return 0;
        }

        private int _Gen4LuaConfig()
        {
            if ((m_strDataPath != "") && (m_strOutputPath != ""))
            {
                CGenerateLuaConfig glc = new CGenerateLuaConfig();
                glc.Start(m_strDataPath, m_strOutputPath);
            }
            return 0;
        }

        //
        private string m_strEnumName = "";
        private string m_strEnumValue = "";
        private string m_strEnumDesc = "";

        private string m_strGenType = "";

        private string m_strDescPath = "";
        private string m_strDescFile = "";
        private string m_strLanguage = "";

        private string m_strProtoPath = "";
        private string m_strPBSrcPath = "";
        private string m_strPBSrcFile = "";

        private string m_strDataPath = "";
        private string m_strDataFile = "";
        private string m_strOutputPath = "";
        private string m_strOutputFile = "";
    }
}
