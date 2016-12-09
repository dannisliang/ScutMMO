using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
using System.IO;

using Detour;
using ProtoBuf;
using GameServer.Script.Model;

public class NavMeshInfo
{
    public NavMesh pdtNavMesh { get; set; }
    public NavMeshQuery pdtNavMeshQuery { get; set; }
};


//用来解析JSON文件
class JsonMap
{
    public NavMeshParams Param { get; set; }

    public List<NavMeshBuilder> NavMeshBuilders { get; set; } 
}

namespace GameServer.Script.Logic
{
    public class Map
    {
        public const string ConfigFileDir = "./Data/Map/";
        public string Name
        {
            get { return MapConfig.mapResources; }
        }
        public uint MapId
        {
            get { return (uint)MapConfig.mapId; }
        }

        public uint Width
        {
            get { return (uint)MapConfig.mapWide; }
        }

        public uint Height
        {
            get { return (uint)MapConfig.mapHeight; }
        }

        public uint MapType
        {
            get { return (uint)MapConfig.mapType; }
        }

        public uint MapSubType
        {
            get { return (uint)MapConfig.mapSubType; }
        }

        public MapMapConfig MapConfig { get; private set; }

        private NavMesh _MapNavMesh;
        private NavMeshQuery _MapNavMeshQuery;
        private QueryFilter _MapQueryFilter;
        private long[] _PathPolys = new long[(int)MapDefine.MAX_NAV_POLYS];
        private float[] _StraightPathPoints = new float[(int)MapDefine.MAX_NAV_POINT_VALUE];

        public NavMesh MapNavMesh 
        { 
            get {return _MapNavMesh;} 
        }

        public NavMeshQuery MapNavMeshQuery 
        { 
            get { return _MapNavMeshQuery;} 
        }

        public QueryFilter MapQueryFilter
        {
            get { return _MapQueryFilter; }
        }

        public Map()
        {

        }

        public bool Init(uint mapId)
        {
            MapConfig = ConfigMgr.GetMapMapCfg((int)mapId);
            if (MapConfig == null)
            {
                Console.WriteLine("the map:{0} is not exist!", mapId);
                return false;
            }

            _MapQueryFilter = new QueryFilter();
            _MapQueryFilter.IncludeFlags = 0;
            _MapQueryFilter.IncludeFlags = _MapQueryFilter.IncludeFlags | (int)SamplePolyFlags.SAMPLE_POLYFLAGS_WALK;
            _MapQueryFilter.ExcludeFlags = 0;

            bool retCode = LoadNavMesh(MapConfig.mapResources);
            if (retCode == false)
            {
                Console.WriteLine("LoadNavMesh {0} failed", MapConfig.mapResources);
            }

            return retCode;
        }

        public void UnInit()
        {

        }

        public bool FindNearestPos(Vector3 srcPos, Vector3 dstPos)
        {
            return FindNearestPos(srcPos.X, srcPos.Y, srcPos.Z, ref dstPos.X, ref dstPos.Y, ref dstPos.Z);
        }

        public bool FindNearestPos(Vector3 srcPos, Vector3 dstPos, ref long polyRef)
        {
            return FindNearestPos(srcPos.X, srcPos.Y, srcPos.Z, ref dstPos.X, ref dstPos.Y, ref dstPos.Z, ref polyRef);
        }

        public bool FindNearestPos(float posX, float posY, float posZ, ref float rsPosX, ref float rsPosY, ref float rsPosZ)
        {
            long polyRef = 0;
            return FindNearestPos(posX, posY, posZ, ref rsPosX, ref rsPosY, ref rsPosZ, ref polyRef);
        }

        public bool FindNearestPos(float posX, float posY, float posZ, ref float rsPosX, ref float rsPosY, ref float rsPosZ, ref long polyRef)
        {
            bool result = false;
            polyRef = (long)MapDefine.INVALID_NAVMESH_POLYREF;
            float[] extents = {0.5f, 4.0f, 0.5f};
            float[] nearPoint = { 0.0f, 0.0f, 0.0f };

            polyRef = GetNearestPoly(posX, posY, posZ, extents, nearPoint);
            if (polyRef == (long)MapDefine.INVALID_NAVMESH_POLYREF)
            {
                return false;
            }

            rsPosX = nearPoint[0];
            rsPosY = nearPoint[1];
            rsPosZ = nearPoint[2];
            return result;
        }

        public long GetNearestPoly(float posX, float posY, float posZ, float[] extents, float[] nearPoint)
        {
            long polyRef = (long)MapDefine.INVALID_NAVMESH_POLYREF;
            float[] startPos = { 0.0f, 0.0f, 0.0f };

            extents[1] = 2000.0f;

            startPos[0] = posX;
            startPos[1] = posY;
            startPos[2] = posZ;

            if (posY == 0.0f)
            {

            }

            _MapNavMeshQuery.FindNearestPoly(startPos, extents, _MapQueryFilter, ref polyRef, ref nearPoint);

            return polyRef;
        }

//         public long GetNearestPoly2D(float posX, float posZ, float[] extents, float[] nearestPt)
//         {
//             long nearestRef = (long)MapDefine.INVALID_NAVMESH_POLYREF;
//             float[] center = { 0.0f, 0.0f, 0.0f };
//             long nearest = 0;
//             float nearestDistanceSqr = 
//         }

        bool GetNavPath(Vector3 srcPos, Vector3 dstPos, List<Vector3> path, List<int> flgs)
        {
            if (srcPos == null || dstPos == null)
            {
                return false;
            }

            bool retCode = false;

            int nPolys = 0;
            int nStraightPoints = 0;
            long[] straightPathPolys = new long[(int)MapDefine.MAX_NAV_POLYS];
            short[] straightPathFlags = new short[(int)MapDefine.MAX_NAV_POLYS];


            long startRef = (long)MapDefine.INVALID_NAVMESH_POLYREF;
            long endRef = (long)MapDefine.INVALID_NAVMESH_POLYREF;



            float[] nearStartPos = { 0.0f, 0.0f, 0.0f };
            float[] nearEndPos = { 0.0f, 0.0f, 0.0f };

            retCode = FindNearestPos(srcPos.X, srcPos.Y, srcPos.Z, ref nearStartPos[0], ref nearStartPos[1], ref nearStartPos[2], ref startRef);
            if (retCode == false)
            {
                return false;
            }

            retCode = FindNearestPos(dstPos.X, dstPos.Y, dstPos.Z, ref nearEndPos[0], ref nearEndPos[1], ref nearEndPos[2], ref endRef);
            if (retCode == false)
            {
                return false;
            }

            Status status = _MapNavMeshQuery.FindPath(startRef, endRef, nearStartPos, nearEndPos, _MapQueryFilter, ref _PathPolys, ref nPolys, (int)MapDefine.MAX_NAV_POLYS);
            if (status != Status.Success && nPolys <= 0)
            {
                return false;
            }

            float[] epos = { 0.0f, 0.0f, 0.0f };
            epos[0] = nearEndPos[0];
            epos[1] = nearEndPos[1];
            epos[2] = nearEndPos[2];

            if (_PathPolys[nPolys - 1] != endRef)
            {
                _MapNavMeshQuery.ClosestPointOnPoly(_PathPolys[nPolys-1], nearEndPos, ref epos);
            }

            status = _MapNavMeshQuery.FindStraightPath(nearStartPos, epos, _PathPolys, nPolys, ref _StraightPathPoints,
                ref straightPathFlags, ref straightPathPolys, ref nStraightPoints, (int)MapDefine.MAX_NAV_POLYS);
            if (status != Status.Success)
            {
                return false;
            }

            path.Clear();
            flgs.Clear();

            for (int i = 0, j = 0; i < nStraightPoints * 3; i+=3, j++)
            {
                path[j].X = _StraightPathPoints[i + 0];
                path[j].Y = _StraightPathPoints[i + 1];
                path[j].Z = _StraightPathPoints[i + 2];
                flgs[j] = straightPathFlags[j];
            }

            return true;
        }

        public bool LoadNavMesh(string mapName)
        {
            bool retCode = false;
            string path = ConfigFileDir + mapName + ".bytes";

            NavMeshInfo navInfo = MapMgr.Inst().GetNavMeshInfo(mapName);
            if (navInfo == null)
            {
                retCode = LoadNavMeshByJsonFile(path, ref _MapNavMesh);
                if (MapNavMesh == null || retCode == false)
                {
                    Console.WriteLine("LoadNavMeshByJsonFile {0} failed", path);
                    return false;
                }

                _MapNavMeshQuery = new NavMeshQuery();

                _MapNavMeshQuery.Init(MapNavMesh, (int)MapDefine.MAX_NAV_POLYS);

                NavMeshInfo newNavInfo = new NavMeshInfo();
                newNavInfo.pdtNavMesh = MapNavMesh;
                newNavInfo.pdtNavMeshQuery = MapNavMeshQuery;

                MapMgr.Inst().AddNavMeshInfo(mapName, newNavInfo);
            }
            else
            {
                _MapNavMesh = navInfo.pdtNavMesh;
                _MapNavMeshQuery = navInfo.pdtNavMeshQuery;
            }
          
            return true;
        }

        public static bool LoadNavMeshByJsonFile(string filePath, ref NavMesh navMesh)
        {
            navMesh = null;
            if (string.IsNullOrEmpty(filePath))
            {
                return false;
            }

            if (File.Exists(filePath) == false)
            {
                Console.WriteLine("LoadNavMeshByJsonFile:{0} is not exist", filePath);
                return false;
            }

            using (FileStream fsRead = new FileStream(filePath, FileMode.Open))
            {
                int fsLen = (int)fsRead.Length;
                byte[] heByte = new byte[fsLen];
                fsRead.Read(heByte, 0, heByte.Length);

                string jsonString = System.Text.Encoding.UTF8.GetString(heByte);
                //var ms = new MemoryStream(heByte);
                //JsonMap jsonMap = (JsonMap)new DataContractJsonSerializer(typeof(JsonMap)).ReadObject(ms);

                JsonMap jsonMap = (JsonMap)JsonConvert.DeserializeObject(jsonString, typeof(JsonMap));
                if (jsonMap == null)
                {
                    Console.WriteLine("JsonConvert.DeserializeObject ==> {0} failed", filePath);
                    return false;
                }

                navMesh = new NavMesh();

                Status status = navMesh.Init(jsonMap.Param);
                if (status != Status.Success)
                {
                    Console.WriteLine("NavMesh init failed");
                    return false;
                }

                for (int i = 0; i < jsonMap.NavMeshBuilders.Count; i++)
                {
                    NavMeshBuilder builder = jsonMap.NavMeshBuilders[i];
                    long result = 0;
                    Status ss = navMesh.AddTile(builder, NavMesh.TileFreeData, 0, ref result);
                    if (ss != Status.Success)
                    {
                        Console.WriteLine("NavMesh AddTile failed! result = {0}", result);
                    }
                }
            }
            
            return true;
        }

    }
}
