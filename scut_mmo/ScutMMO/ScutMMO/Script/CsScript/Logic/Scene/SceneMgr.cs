using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ZyGames.Framework.Common.Timing;

namespace GameServer.Script.Logic
{
    public class SceneMgr
    {
        private Dictionary<uint, Scene> m_MapScenes = new Dictionary<uint, Scene>();
        //private SyncTimer m_TickTimer = new SyncTimer():

        public Dictionary<uint, Scene> MapScenes
        {
            get { return m_MapScenes; }
        }

        private static SceneMgr _Inst;

        public static SceneMgr Inst()
        {
            if (_Inst == null)
            {
                _Inst = new SceneMgr();
            }
            return _Inst;
        }

        public bool Init()
        {
            foreach(KeyValuePair<uint, Map> item in MapMgr.Inst().MapInfoDict)
            {
                Map map = item.Value;
                if (map.MapId > 0 && map.MapConfig.mapType > 0)
                {
                    CreateScene(map.MapId);
                }
            }
            return true;
        }

        public Scene GetScene(uint sceneId)
        {
            Scene scene = null;
            MapScenes.TryGetValue(sceneId, out scene);
            return scene;
        }

        public Scene CreateScene(uint mapId)
        {
            uint sceneId = mapId;
            Map map = MapMgr.Inst().GetMap(mapId);
            if (map == null)
            {
                Console.WriteLine("CreateScene failed! mapId:{0} is not exist", mapId);
                return null;
            }

            if (map.MapType != (uint)MapMainType.DYNAMIC_MAP && map.MapType != (uint)MapMainType.NONE_MAP)
            {
                sceneId = mapId;
            }
            else
            {
                return null;
            }

            Scene scene = new Scene();
            bool ret = scene.Init(mapId, sceneId);
            if (ret == false)
            {
                Console.WriteLine("CreateScene failed! scene Init failed");
                return null;
            }

            MapScenes.Add(sceneId, scene);

            Console.WriteLine("create Scene:{0} -- {0}", scene.SceneId, scene.MapId);
            return scene;
        }

        public void RecyleScene(uint sceneId)
        {
            Scene scene;
            MapScenes.TryGetValue(sceneId, out scene);
            if (scene != null)
            {
                MapScenes.Remove(sceneId);
            }
        }
    }
}
