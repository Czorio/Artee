using System.Collections.Generic;
using SixLabors.ImageSharp;
using SixLabors.ImageSharp.PixelFormats;
using System.IO;
using System.Text;

using CS_Artee.Scene;

namespace CS_Artee
{
    class Renderer
    {
        private Camera camera;
        private List<IIntersectable> sceneObjects;
        private Vec3[,] imageBuffer;
        private int imageWidth, imageHeight;

        public Renderer(int width, int height)
        {
            imageWidth = width;
            imageHeight = height;
            camera = new Camera(new Vec3(), new Vec3(1, 0, 0), new Vec3(0, 1, 0), imageWidth, imageHeight, 1);
            sceneObjects = new List<IIntersectable>();

            Material material = new Material(new Vec3(1, 0, 0), 0);
            sceneObjects.Add(new Sphere(new Vec3(2, 0, 0), 1.0f, material));

            imageBuffer = new Vec3[imageWidth, imageHeight];
        }

        public void RenderFrame()
        {
            for (int x = 0; x < imageWidth; x++)
            {
                for (int y = 0; y < imageHeight; y++)
                {
                    Ray r = camera.GetRayFor(x, y);

                    HitRecord closestHit = new HitRecord();
                    foreach (IIntersectable obj in sceneObjects)
                    {
                        HitRecord hit = obj.Hit(r);

                        if (hit.t < closestHit.t)
                        {
                            closestHit = hit;
                        }
                    }

                    if (closestHit.type != 0)
                    {
                        imageBuffer[x, y] = closestHit.Color;
                    }
                    else
                    {
                        imageBuffer[x, y] = new Vec3();
                    }
                }
            }
        }

        public char[,,] GetOutput()
        {
            char[,,] byteBuffer = new char[imageWidth, imageHeight, 3];

            for (int x = 0; x < imageWidth; x++)
            {
                for (int y = 0; y < imageHeight; y++)
                {
                    // RGB from XYZ
                    // TODO: Gamma Correction
                    byteBuffer[x, y, 0] = (char)(imageBuffer[x, y].X * 255);
                    byteBuffer[x, y, 1] = (char)(imageBuffer[x, y].Y * 255);
                    byteBuffer[x, y, 2] = (char)(imageBuffer[x, y].Z * 255);
                }
            }

            return byteBuffer;
        }
    }
}
