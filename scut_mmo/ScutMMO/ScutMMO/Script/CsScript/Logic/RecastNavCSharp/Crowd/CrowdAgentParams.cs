namespace RecastNavCSharp.Crowd
{
    public class CrowdAgentParams
    {
        public float Radius;
        public float Height;
        public float MaxAcceleration;
        public float MaxSpeed;

        public float CollisionQueryRange;
        public float PathOptimizationRange;

        public float SeparationWeight;
        public UpdateFlags UpdateFlags;
        public short ObstacleAvoidanceType;
        // userData
    }
}