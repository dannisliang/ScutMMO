using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

using GameServer.Script.Logic;
using GameServer.Script.Model;
using ZyGames.Framework.Common.Log;

namespace GameServer.Script.Common
{
    public static class SystemGlobal
    {
        private static readonly object thisLock = new object();
        private static bool m_IsRunning;

        public static bool IsRunning
        {
            get { return m_IsRunning; }
        }

        public static void CloseRunState()
        {
            lock(thisLock)
            {
                m_IsRunning = false;
            }
        }

        static SystemGlobal()
        {
            m_IsRunning = false;
        }

        public static void  Start()
        {
            lock (thisLock)
            {
                m_IsRunning = false;
            }
            Stopwatch allWatch = new Stopwatch();
            allWatch.Start();

            {
                Stopwatch stopwatch = new Stopwatch();
                //加载配置
                stopwatch.Start();
                ConfigMgr.Inst().InitConfigMgr();
                stopwatch.Stop();

                TraceLog.ReleaseWrite("加载游戏execl配置文件完成，共花费时间 {0} ms", stopwatch.Elapsed.TotalMilliseconds);
            }

            {
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                MapMgr.Inst().Init();
                stopwatch.Stop();
                TraceLog.ReleaseWrite("加载游戏地图数据完成，共花费时间 {0} ms", stopwatch.Elapsed.TotalMilliseconds);
            }

            {
                Stopwatch stopwatch = new Stopwatch();
                stopwatch.Start();
                SceneMgr.Inst().Init();
                stopwatch.Stop();
                TraceLog.ReleaseWrite("创建场景完成，共花费时间 {0} ms", stopwatch.Elapsed.TotalMilliseconds);
            }


            allWatch.Stop();
            TraceLog.ReleaseWrite("加载全部配置，共花费时间 {0} ms", allWatch.Elapsed.TotalMilliseconds);
            
            lock (thisLock)
            {
                m_IsRunning = true;
            }
        }

        public static void Stop()
        {

        }
    }
}
