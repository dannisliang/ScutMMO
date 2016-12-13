using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class PlayerManager
    {
        private readonly Dictionary<uint, Player> m_Players = new Dictionary<uint, Player>();
        public Dictionary<uint, Player> Players
        {
            get { return m_Players; }
        }

        Player GetPlayer(uint cid)
        {
            Player player = null;
            Players.TryGetValue(cid, out player);
            return player;
        }

        public void AddPlayer(Player player)
        {
            if (player != null)
            {
                Players.Add(player.Cid, player);
            }
        }

        public bool RemovePlayer(uint cid)
        {
            return Players.Remove(cid);
        }
    }
}
