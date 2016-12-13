using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class MonsterManager
    {
        private readonly Dictionary<uint, Monster> m_Monsters = new Dictionary<uint,Monster>();

        public Dictionary<uint, Monster> Monsters
        {
            get { return m_Monsters; }
        }

        public Monster GetMonster(uint cid)
        {
            Monster monster = null;
            Monsters.TryGetValue(cid, out monster);
            return monster;
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
    }
}
