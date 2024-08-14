#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outFile("image.ppm");
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }


    int image_width = 256;
    int image_height = 256;

    outFile << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; i++)
        {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            outFile << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\rDone.                 \n";


    if (outFile.fail())
    {
        std::cerr << "Error writing to file" << std::endl;
    }
    outFile.close();
    return 0;
}
