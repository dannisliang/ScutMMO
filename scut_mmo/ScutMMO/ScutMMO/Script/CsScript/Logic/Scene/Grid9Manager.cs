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
        public UInt32 _GridSizeX = 0;
        public UInt32 _GridSizeZ = 0;
        public readonly List<List<Grid>> _GridLst = new List<List<Grid>>();

        public UInt32 GrideSizeX
        {
            get { return _GridSizeX; }
        }

        public UInt32 GrideSizeZ
        {
            get { return _GridSizeZ; }
        }

        public List<List<Grid>> GridLst
        {
            get { return _GridLst; }
        }

        public Grid9Manager()
        {

        }

        public void InitGridSize(UInt32 width, UInt32 height)
        {
            _GridSizeX = width / Scene.GRID_LENGTH + 1;
            _GridSizeZ = height / Scene.GRID_LENGTH + 1;
            for(UInt32 i = 0; i < _GridSizeX; i++)
            {
                List<Grid> lst = new List<Grid>();
                
                for (UInt32 j = 0; j < _GridSizeZ; j++)
                {
                    lst.Add(new Grid(i, j));
                }

                _GridLst.Add(lst);
            }
        }

        public Grid GetGrid(Vector3 pos)
        {
            UInt32 gridX = (UInt32)(pos.X / Scene.GRID_LENGTH);
            UInt32 gridZ = (UInt32)(pos.Z / Scene.GRID_LENGTH);

            if (gridX >= _GridSizeX || gridZ >= _GridSizeZ)
            {
                return null;
            }

            return _GridLst[(int)gridX][(int)gridZ];
        }

    }
}
