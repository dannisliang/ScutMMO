using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GameServer.Script.Logic
{
    public class Grid
    {
        private readonly List<uint> m_CidLst = new List<uint>();
        private readonly uint m_GridX;
        private readonly uint m_GridZ;

        public List<uint> CidList { get { return m_CidLst; } }

        public uint GridX { get { return m_GridX; } }

        public uint GridZ { get { return m_GridZ; } }

        public Grid(uint gridX, uint gridZ)
        {
            m_GridX = gridX;
            m_GridZ = gridZ;
        }

        public void AddCid(uint cid)
        {
            foreach (uint c in m_CidLst)
            {
                if (c == cid)
                {
                    return;
                }
            }
            m_CidLst.Add(cid);
        }

        public void RemoveCid(uint cid)
        {
            m_CidLst.Remove(cid);
        }
    }
}
