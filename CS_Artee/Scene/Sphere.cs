using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    class Sphere : Primitive
    {
        float radius, radius2;
        Vec3 origin;

        public Sphere(Vec3 origin, float radius, Material material)
        {
            this.origin = origin;
            this.radius = radius;
            radius2 = radius * radius;
            this.material = material;
        }

        public override HitRecord Hit(Ray r)
        {
            HitRecord hit = new HitRecord();

            Vec3 C = origin - r.Origin;
            float t = C.Dot(r.Direction);
            Vec3 Q = C - t * r.Direction;
            float p2 = Q.Dot(Q);

            if (radius2 < p2)
            {
                // No hit
                return hit;
            }
            else
            {
                t -= (float)Math.Sqrt(radius2 - p2);
                if (t > 0.0f)
                {
                    hit.t = t;
                    hit.type = 1;
                    hit.Intersection = r.At(t);
                    hit.Normal = Vec3.Normalize(hit.Intersection - origin);
                    hit.Color = material.Color;
                }
            }

            return hit;
        }
    }
}
