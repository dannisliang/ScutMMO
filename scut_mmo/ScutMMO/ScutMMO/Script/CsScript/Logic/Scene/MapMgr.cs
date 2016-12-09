using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class MapMgr
    {
        private static MapMgr _Inst;

        public static MapMgr Inst()
        {
            if (_Inst == null)
            {
                _Inst = new MapMgr();
            }
            return _Inst;
        }

        public Dictionary<uint, Map>  MapInfoDict { get; private set; }
        public Dictionary<string, NavMeshInfo> NavMeshMap { get; private set; }

        public bool Init()
        {
            MapInfoDict = new Dictionary<uint, Map>();
            NavMeshMap = new Dictionary<string, NavMeshInfo>();

            bool retCode = false;

            retCode = LoadConfig();
            if (retCode == false)
            {
                Console.WriteLine("MapMgr LoadConfig failed!");
                return false;
            }

            Console.WriteLine("Load Map success!");
            return true;
        }

        public void UnInit()
        {
            MapInfoDict.Clear();
            NavMeshMap.Clear();
        }

        public Map GetMap(uint mapId)
        {
            if (MapInfoDict.ContainsKey(mapId))
            {
                return MapInfoDict[mapId];
            }
            return null;
        }

        public void AddNavMeshInfo(string navName, NavMeshInfo navInfo)
        {
            if (NavMeshMap.ContainsKey(navName) || navInfo == null)
            {
                Console.WriteLine("{0} is exist in the MapMgr!", navName);
                return;
            }

            NavMeshMap[navName] = navInfo;
        }

        public NavMeshInfo GetNavMeshInfo(string navName)
        {
            if (string.IsNullOrEmpty(navName))
            {
                return null;
            }

            if (NavMeshMap.ContainsKey(navName))
            {
                return NavMeshMap[navName];
            }
            return null;
        }

        public bool LoadConfig()
        {
            foreach(KeyValuePair<int, MapMapConfig> itemMap in ConfigMgr.Inst().MapMap.configs)
            {
                uint mapId = (uint)itemMap.Key;
                Map map = new Map();
                if (map.Init(mapId))
                {
                    AddMap(mapId, map);
                }
                else
                {
                    Console.WriteLine("load map {0} failed!", mapId);
                }
            }
            return true;
        }

        public bool AddMap(uint mapId, Map map)
        {
            if (MapInfoDict.ContainsKey(mapId) || map == null)
            {
                Console.WriteLine("{0} is exist in the MapMgr!", mapId);
                return false;
            }

            MapInfoDict[mapId] = map;
            return true;
        }

        public void DelMap(uint mapId)
        {
            MapInfoDict.Remove(mapId);
        }
    }
}
