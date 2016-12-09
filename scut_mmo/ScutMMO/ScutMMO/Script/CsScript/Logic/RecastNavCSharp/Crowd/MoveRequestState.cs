namespace RecastNavCSharp.Crowd
{
    public enum MoveRequestState
    {
        TargetNone,
        TargetFailed,
        TargetValid,
        TargetRequesting,
        TargetWaitingForQueue,
        TargetWaitingForPath,
        TargetVelocity
    }
}