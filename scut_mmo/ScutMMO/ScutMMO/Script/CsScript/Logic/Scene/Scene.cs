
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ZyGames.Framework.Common;
using ZyGames.Framework.Model;
using ZyGames.Framework.Cache.Generic;


namespace GameServer.Script.Logic
{
    public class Scene : MemoryEntity
    {
        public const UInt32 GRID_LENGTH = 10;

        public UInt32 MapId { get;  set; }

        public UInt32 SceneId { get;  set; }

        public Map Map { get; private set; }

        private Grid9Manager m_Grid9Manager = new Grid9Manager();


        public Grid9Manager Grid9Manager
        {
            get { return m_Grid9Manager; }
        }

        public Scene()
        {
            MapId = 0;
            SceneId = 0;
        }

        public virtual bool Init(UInt32 mapId, UInt32 sceneId)
        {
            Map = MapMgr.Inst().GetMap(mapId);
            if (Map == null)
            {
                return false;
            }

            Grid9Manager.InitGridSize(Map.Width, Map.Height);

            MapId = mapId;
            SceneId = sceneId;

            return true;
        }

        public virtual Grid EnterScene(Creature creature)
        {
            if (creature == null) return null;

            Grid grid = Grid9Manager.GetGrid(creature.Pos);
            if (grid == null)
            {
                Console.WriteLine("Creature:{0} EnterScene failed", creature.Cid);
                return null;
            }

            grid.AddCid(creature.Cid);

            return grid;
        }

        bool LeaveScene(Creature creature, Grid grid)
        {
            if (grid == null)
            {
                Console.WriteLine("LeaveScene failed");
                return false;
            }

            grid.RemoveCid(creature.Cid);

            return true;
        }
    }
}
