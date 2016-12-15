using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ZyGames.Framework.Cache.Generic;
using ZyGames.Framework.Common;
using ZyGames.Framework.Game.Runtime;
using GameServer.Script.Model;

namespace GameServer.Script.Logic
{
    public class MonsterManager
    {
        private CacheDictionary<uint, Monster> m_Monsters = new CacheDictionary<uint, Monster>();
        private VersionConfig m_MonsterCids;

        public CacheDictionary<uint, Monster> Monsters
        {
            get { return m_Monsters; }
        }

        public uint NewMonsterCid
        {
            get { return (uint)m_MonsterCids.NextId; }
        }

        public Monster GetMonster(uint cid)
        {
            Monster monster = null;
            if (Monsters.TryGetValue(cid, out monster))
            {
                return monster;
            }
            return null;
        }

        public void AddMonster(Monster monster)
        {
            if (monster != null)
            {
                Monsters.Add(monster.Cid, monster);
            }
        }

        public bool RemoveMonster(uint cid)
        {
            return Monsters.Remove(cid);
        }

        public bool RemoveMonster(Monster monster)
        {
            if (monster != null)
            {
                return Monsters.Remove(monster.Cid);
            }
            return false;
        }

        bool Init()
        {
            Monsters.Clear();
            return true;
        }

        bool UnInit()
        {
            return true;
        }

        Monster CreateMonster(uint monsterId, uint sceneId, Vector3 bornPos)
        {
            Monster monster = new Monster();

            return monster;
        }
    }
}
