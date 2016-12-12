
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GameServer.Script.Logic
{
    public class Scene
    {
        public const UInt32 GRID_LENGTH = 10;

        public UInt32 MapId { get;  set; }

        public UInt32 SceneId { get;  set; }

        public PlayerManager PlayerMgr { get ; set; }

        public MonsterManager MonsterMgr { get; set; }

        public NpcManager NpcMgr { get; set; }

        public Grid9Manager Grid9Mgr { get; set; }

        public Scene()
        {
            MapId = 0;
            SceneId = 0;
            PlayerMgr = new PlayerManager();
            MonsterMgr = new MonsterManager();
            NpcMgr = new NpcManager();
            Grid9Mgr = new Grid9Manager();
        }

        public virtual bool Init(UInt32 mapId, UInt32 sceneId)
        {
            Map pMap = MapMgr.Inst().GetMap(mapId);
            if (pMap == null)
            {
                return false;
            }

            Grid9Mgr.InitGridSize(pMap.Width, pMap.Height);

            MapId = mapId;
            SceneId = sceneId;

            return true;
        }
    }
}
