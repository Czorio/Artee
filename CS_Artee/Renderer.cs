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
        // Scene
        private Camera camera;
        private List<IIntersectable> sceneObjects;
        private List<Light> sceneLights;

        // Render output
        private Vec3[,] imageBuffer;
        private int imageWidth, imageHeight;

        public Renderer(int width, int height)
        {
            imageWidth = width;
            imageHeight = height;
            camera = new Camera(new Vec3(), new Vec3(1, 0, 0), new Vec3(0, 1, 0), imageWidth, imageHeight, 1);
            sceneObjects = new List<IIntersectable>();
            sceneLights = new List<Light>();

            Material material = new Material(new Vec3(1, 0, 0), 0);
            sceneObjects.Add(new Sphere(new Vec3(2, 0, 0), 1.0f, material));

            sceneLights.Add(new PointLight(new Vec3(0, 1, 1), 10.0f));

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
                        Vec3 color = closestHit.Color;

                        float lightIntensity = 0.0f;
                        foreach (Light light in sceneLights)
                        {
                            Ray shadowRay = light.GetShadowRay(closestHit.Intersection);
                            float distance = light.DistanceFrom(closestHit.Intersection);

                            bool isVisible = true;
                            foreach (IIntersectable intersectable in sceneObjects)
                            {
                                HitRecord hit = intersectable.Hit(shadowRay);
                                if (hit.type != 0 && hit.t < distance)
                                {
                                    isVisible = false;
                                    break;
                                }
                            }

                            if (isVisible)
                            {
                                lightIntensity += light.Intensity / (distance * distance);
                            }
                        }

                        imageBuffer[x, y] = color * lightIntensity;
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
                    byteBuffer[x, y, 0] = Clamp(imageBuffer[x, y].X * 255);
                    byteBuffer[x, y, 1] = Clamp(imageBuffer[x, y].Y * 255);
                    byteBuffer[x, y, 2] = Clamp(imageBuffer[x, y].Z * 255);
                }
            }

            return byteBuffer;
        }

        private static char Clamp(float f)
        {
            if (f > 255)
            {
                return (char)255;
            }
            else if (f < 0)
            {
                return (char)0;
            }
            else
            {
                return (char)(f * 255);
            }
        }
    }
}
