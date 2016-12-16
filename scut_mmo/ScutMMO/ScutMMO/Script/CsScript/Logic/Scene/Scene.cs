
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ZyGames.Framework.Common;
using ZyGames.Framework.Model;
using ZyGames.Framework.Cache.Generic;

using GameServer.Script.Model;


namespace GameServer.Script.Logic
{
    public class Scene : MemoryEntity
    {
        public const UInt32 GRID_LENGTH = 10;

        public UInt32 MapId { get;  set; }

        public UInt32 SceneId { get;  set; }

        public Map Map { get; private set; }

        private Grid9Manager m_Grid9Manager;
        private CacheDictionary<uint, Creature> m_MapSceneOtherCreature;
        private CacheDictionary<uint, Player> m_MapScenePlayer;

        public CacheDictionary<uint, Creature> MapSceneOtherCreature
        {
            get { return m_MapSceneOtherCreature; }
        }

        public CacheDictionary<uint, Player> MapScenePlayer
        {
            get { return m_MapScenePlayer; }
        }

        public Grid9Manager Grid9Manager
        {
            get { return m_Grid9Manager; }
        }

        public Scene()
        {
            MapId = 0;
            SceneId = 0;
            m_MapScenePlayer = new CacheDictionary<uint, Player>();
            m_MapSceneOtherCreature = new CacheDictionary<uint,Creature>();
            m_Grid9Manager = new Grid9Manager();
        }

        public virtual bool Init(UInt32 mapId, UInt32 sceneId)
        {
            m_MapScenePlayer.Clear();
            m_MapSceneOtherCreature.Clear();
            m_Grid9Manager.Clear();

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

        public virtual bool EnterScene(Creature creature, Vector3 pos)
        {
            if (creature == null || pos == null) return false;

            Grid grid = Grid9Manager.GetGrid(pos);
            if (grid == null)
            {
                Console.WriteLine("Creature:{0} EnterScene failed", creature.Cid);
                return false;
            }

            grid.AddCid(creature.Cid);

            if (creature.CreatureType != CreatureTypeEnum.CREATURE_PLAYER)
            {
                MapSceneOtherCreature.Add(creature.Cid, creature);
            }
            else
            {
                Player player = (Player)creature;
                m_MapScenePlayer.Add(player.Cid, player);
            }

            return true;
        }

        public bool LeaveScene(Creature creature)
        {
            Grid grid = Grid9Manager.GetGrid(creature.Pos);
            if (grid == null)
            {
                Console.WriteLine("LeaveScene failed");
                return false;
            }

            grid.RemoveCid(creature.Cid);

            if (MapSceneOtherCreature.ContainsKey(creature.Cid))
            {
                MapSceneOtherCreature.Remove(creature.Cid);
            }
            else
            {
                if (MapScenePlayer.ContainsKey(creature.Cid))
                {
                    MapScenePlayer.Remove(creature.Cid);
                }
                else
                {
                    Console.WriteLine("LeaveScene can't find the cid:"+creature.Cid);
                    return false;
                }
            }

            return true;
        }

        public void UpdateSeeLst(Creature creature)
        {

        }

        public List<uint> FindCreatureInSceneFrom9Grid(Vector3 srcPos, uint viewLayer)
        {
            return Grid9Manager.Get9GridCreature(srcPos, viewLayer);
        }

        public Creature GetCreature(uint cid)
        {
            if (MapSceneOtherCreature.ContainsKey(cid))
            {
                return MapSceneOtherCreature[cid];
            }
            else
            {
                if (MapScenePlayer.ContainsKey(cid))
                {
                    return MapScenePlayer[cid];
                }
            }
            return null;
        }
    }
}
