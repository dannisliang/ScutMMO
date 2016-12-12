using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using GameServer.Script.Model;

namespace GameServer.Script.Logic
{
    // 计算屏幕方式的九宫格的矩形
    public class Grid9Manager
    {
        public uint m_GridSizeX = 0;
        public uint m_GridSizeZ = 0;
        public readonly List<List<Grid>> m_GridLst = new List<List<Grid>>();

        public UInt32 GrideSizeX
        {
            get { return m_GridSizeX; }
        }

        public UInt32 GrideSizeZ
        {
            get { return m_GridSizeZ; }
        }

        public List<List<Grid>> GridLst
        {
            get { return m_GridLst; }
        }

        public Grid9Manager()
        {

        }

        public void InitGridSize(uint width, uint height)
        {
            m_GridSizeX = width / Scene.GRID_LENGTH + 1;
            m_GridSizeZ = height / Scene.GRID_LENGTH + 1;
            for (uint i = 0; i < m_GridSizeX; i++)
            {
                List<Grid> lst = new List<Grid>();

                for (uint j = 0; j < m_GridSizeZ; j++)
                {
                    lst.Add(new Grid(i, j));
                }

                m_GridLst.Add(lst);
            }
        }

        public Grid GetGrid(Vector3 pos)
        {
            uint gridX = (uint)(pos.X / Scene.GRID_LENGTH);
            uint gridZ = (uint)(pos.Z / Scene.GRID_LENGTH);

            if (gridX >= m_GridSizeX || gridZ >= m_GridSizeZ)
            {
                return null;
            }

            return m_GridLst[(int)gridX][(int)gridZ];
        }

    }
}
