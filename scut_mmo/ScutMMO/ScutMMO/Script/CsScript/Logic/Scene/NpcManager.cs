using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class NpcManager
    {
        private readonly Dictionary<uint, NPC> m_NPCs = new Dictionary<uint, NPC>();

        public Dictionary<uint, NPC> NPCs
        {
            get { return m_NPCs; }
        }

        public NPC GetNPC(uint cid)
        {
            NPC npc = null;
            NPCs.TryGetValue(cid, out npc);
            return npc;
        }

        public void AddNPC(NPC npc)
        {
            if (npc != null)
            {
                NPCs.Add(npc.Cid, npc);
            }
        }

        public bool RemoveNPC(uint cid)
        {
            return NPCs.Remove(cid);
        }
    }
}
