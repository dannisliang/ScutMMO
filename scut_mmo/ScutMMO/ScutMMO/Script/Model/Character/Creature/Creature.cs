using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using ProtoBuf;

namespace GameServer.Script.Model
{
    [Serializable, ProtoContract]
    public class Creature
    {
        public uint SceneId { get; set; }

        public uint MapID { get; set; }

        public uint Cid { get; set; }


    }
}
