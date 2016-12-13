
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

        private PlayerManager m_PlayerManager = new PlayerManager();

        private MonsterManager m_MonsterManager = new MonsterManager();

        private NpcManager m_NpcManager = new NpcManager();

        private Grid9Manager m_Grid9Manager = new Grid9Manager();

        private OtherCreatureManaget m_OtherCreatureManaget = new OtherCreatureManaget();

        public PlayerManager PlayerManager
        {
            get { return m_PlayerManager; }
        }

        public MonsterManager MonsterManager
        {
            get { return m_MonsterManager; }
        }

        public NpcManager NpcManager
        {
            get { return m_NpcManager; }
        }

        public Grid9Manager Grid9Manager
        {
            get { return m_Grid9Manager; }
        }

        public OtherCreatureManaget OtherCreatureManaget
        {
            get { return m_OtherCreatureManaget; }
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

            if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_PLAYER)
            {
                Player player = (Player)creature;
                PlayerManager.AddPlayer(player);
            }
            else if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_MONSTER)
            {
                Monster monster = (Monster)creature;
                MonsterManager.AddMonster(monster);
            }
            else if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_NPC)
            {
                NPC npc = (NPC)creature;
                NpcManager.AddNPC(npc);
            }
            else
            {
                OtherCreatureManaget.AddCreature(creature);
            }

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

            bool flag = false;

            if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_PLAYER)
            {
                flag = PlayerManager.RemovePlayer(creature.Cid);
            }
            else if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_MONSTER)
            {
                flag = MonsterManager.RemoveMonster(creature.Cid);
            }
            else if (creature.CreatureType == (uint)CreatureTypeEnum.CREATURE_NPC)
            {
                flag = NpcManager.RemoveNPC(creature.Cid);
            }
            else
            {
                flag = OtherCreatureManaget.RemoveCreature(creature.Cid);
            }

            if (flag == false)
            {
                Console.WriteLine("Scene::LeaveScene, m_scenePlayers cannt find, cid:{0}", creature.Cid);
            }

            return flag;
        }
    }
}
