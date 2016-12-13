using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class OtherCreatureManaget
    {
        private readonly Dictionary<uint, Creature> m_Creatures = new Dictionary<uint, Creature>();
        public Dictionary<uint, Creature> Creatures
        {
            get { return m_Creatures; }
        }

        Creature GetCreature(uint cid)
        {
            Creature creature = null;
            Creatures.TryGetValue(cid, out creature);
            return creature;
        }

        public void AddCreature(Creature creature)
        {
            if (creature != null)
            {
                Creatures.Add(creature.Cid, creature);
            }
        }

        public bool RemoveCreature(uint cid)
        {
            return Creatures.Remove(cid);
        }
    }
}
