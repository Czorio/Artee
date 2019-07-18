using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    abstract class Light
    {
        private protected Vec3 origin;
        private protected float intensity;

        public float Intensity { get => intensity; set => intensity = value; }

        public abstract Ray GetShadowRay(Vec3 point);
        public abstract float DistanceFrom(Vec3 point);
    }

    class PointLight : Light
    {
        public PointLight(Vec3 origin, float intensity)
        {
            this.origin = origin;
            this.intensity = intensity;
        }

        public override float DistanceFrom(Vec3 point)
        {
            Vec3 v = point - origin;
            return v.GetLength();
        }

        public override Ray GetShadowRay(Vec3 point)
        {
            Vec3 rayDirection = Vec3.Normalize(origin - point);
            Vec3 rayOrigin = point + rayDirection * (float)1e-6;
            return new Ray(rayOrigin, rayDirection);
        }
    }
}
