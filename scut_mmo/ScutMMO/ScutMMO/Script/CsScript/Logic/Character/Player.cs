using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class Player : Creature
    {
        public Player()
        {
            CreatureType = (uint)CreatureTypeEnum.CREATURE_PLAYER;
        }
    }
}
