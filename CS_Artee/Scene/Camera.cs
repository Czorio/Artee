using System;
using System.Collections.Generic;
using System.Text;

namespace CS_Artee.Scene
{
    class Camera
    {
        private Vec3 origin, forward, up, right;
        private float ratio, fov;
        private int width, height;

        /// <summary>
        /// The default constructor for a camera. Up is a guide, and will be recalculated.
        /// </summary>
        /// <param name="forward">The forward vector of the camera</param>
        /// <param name="up">The upguide, the actual up will be recalculated</param>
        public Camera(Vec3 origin, Vec3 forward, Vec3 up, int width, int height, float fov)
        {
            this.origin = origin;

            this.forward = forward;
            right = forward.Cross(up);
            this.up = forward.Cross(right);

            this.width = width;
            this.height = height;

            ratio = width / (float)height;
            this.fov = fov;
        }

        /// <summary>
        /// Creates and returns a Ray for pixel [x, y]
        /// </summary>
        /// <param name="x">Screen-space x coordinate</param>
        /// <param name="y">Screen-space y coordinate</param>
        /// <returns>A Ray associated with [x, y]</returns>
        public Ray GetRayFor(int x, int y)
        {
            float camX = x / (float)width - 0.5f;
            float camY = y / (float)height - 0.5f;

            Vec3 p = origin + forward * fov + camX * right * ratio + camY * up;
            Vec3 direction = Vec3.Normalize(p - origin);

            return new Ray(origin, direction);
        }
    }
}
