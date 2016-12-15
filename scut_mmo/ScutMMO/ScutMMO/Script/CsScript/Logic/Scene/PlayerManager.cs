using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ZyGames.Framework.Cache.Generic;
using ZyGames.Framework.Common;
using ZyGames.Framework.Game.Runtime;

namespace GameServer.Script.Logic
{
    public class PlayerManager
    {
        private CacheDictionary<uint, Player> m_Players = new CacheDictionary<uint, Player>();
        private VersionConfig m_PlayerCids;

        public PlayerManager()
        {
            int minCount = GameEnvironment.ProductServerId * 100000000 + (int)CreatureTypeEnum.CREATURE_PLAYER * 1000000;
            int maxCount = GameEnvironment.ProductServerId * 100000000 + ((int)CreatureTypeEnum.CREATURE_PLAYER + 1) * 2000000 - 1;
            m_PlayerCids = new VersionConfig(minCount, maxCount);
        }

        public CacheDictionary<uint, Player> Players
        {
            get { return m_Players; }
        }

        public int NewPlayerCid
        {
            get { return m_PlayerCids.NextId; }
        }

        Player GetPlayer(uint cid)
        {
            Player player = null;
            if (Players.TryGetValue(cid, out player))
            {
                return player;
            }
            return null;
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
