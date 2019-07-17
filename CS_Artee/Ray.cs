using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee
{
    /// <summary>
    /// Represents a ray, as used in a raytracer/pathtracer.
    /// </summary>
    class Ray
    {
        private Vec3 origin, direction;

        public Vec3 Origin { get => origin; set => origin = value; }
        public Vec3 Direction { get => direction; set => direction = value; }

        /// <summary>
        /// Default constructor for Ray. Initializes everything to 0.0f.
        /// </summary>
        public Ray()
        {
            origin = new Vec3();
            direction = new Vec3();
        }

        /// <summary>
        /// Constructor for ray.
        /// </summary>
        /// <param name="origin">The origin of the ray</param>
        /// <param name="direction">The direction of the ray</param>
        public Ray(Vec3 origin, Vec3 direction)
        {
            this.origin = origin;
            this.direction = direction;
        }

        /// <summary>
        /// Calculates the point on the ray at distance t.
        /// </summary>
        /// <param name="t">the distance along the ray</param>
        /// <returns>The point on the ray at distance t</returns>
        public Vec3 At(float t)
        {
            return origin + direction * t;
        }
    }
}
