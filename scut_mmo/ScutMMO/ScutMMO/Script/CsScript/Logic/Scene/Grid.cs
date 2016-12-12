using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class Grid
    {
        private readonly List<UInt32> _CidLst = new List<UInt32>();
        private readonly UInt32 _GridX;
        private readonly UInt32 _GridZ;

        public List<UInt32> CidList { get { return _CidLst; } }

        public UInt32 GridX { get { return _GridX; } }

        public UInt32 GridY { get { return _GridZ; } }

        public Grid(UInt32 gridX, UInt32 gridZ)
        {
            _GridX = gridX;
            _GridZ = gridZ;
        }

        void AddCid(UInt32 cid)
        {
            foreach(UInt32 c in _CidLst)
            {
                if (c == cid)
                {
                    return;
                }
            }
            _CidLst.Add(cid);
        }

        void RemoveCid(UInt32 cid)
        {
            _CidLst.Remove(cid);
        }
    }
}
