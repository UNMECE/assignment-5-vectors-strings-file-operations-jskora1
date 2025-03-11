#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "pixel.h"
#include <vector>

using namespace std;
vector<Pixel> pixel_list;


// Function prototypes
 void read_pixels(const string &filename)
 {
    ifstream inputfile(filename);
    string line;

    while (getline(inputfile, line))
    {
        stringstream ss(line);
        string temp;
        Pixel pixel;

        // Parse x value
        getline(ss, temp, ',');
        pixel.x = stoi(temp);
        
        // Parse y value
        getline(ss, temp, ',');
        pixel.y = stoi(temp);
  
        // Parse r value
        getline(ss, temp, ',');
        pixel.r = stof(temp);

        // Parse g value
        getline(ss, temp, ',');
        pixel.g = stof(temp);
 
        // Parse b value
        getline(ss, temp, ',');
        pixel.b = stof(temp);
        
        // Add the pixel to the vector
        pixel_list.push_back(pixel);
    
    }
 }

 void average_colors(vector<Pixel> &pixel_list)
 {
    float sum_r = 0.0, sum_g = 0.0, sum_b = 0.0;
    int count = pixel_list.size();

    for (const auto &pixel : pixel_list)
    {
        sum_r += pixel.r;
        sum_g += pixel.g;
        sum_b += pixel.b;
    }

    float avg_r = sum_r / count;
    float avg_g = sum_g / count;
    float avg_b = sum_b / count;

    cout << "Average Red: " << avg_r << endl;
    cout << "Average Green: " << avg_g << endl;
    cout << "Average Blue: " << avg_b << endl;
 }

 void flip_vertically(vector<Pixel> &pixel_list)
 {
    int max_y = 255; // The y-range is from 0 to 255, based on the given input

    for (auto &pixel : pixel_list)
    {
        pixel.y = max_y - pixel.y;
    }
 }

 void save_flipped_pixels(const string &filename)
 {
    ofstream file(filename);

    for (const auto &pixel : pixel_list)
    {
        file << pixel.x << ","
             << pixel.y << ","
             << pixel.r << ","
             << pixel.g << ","
             << pixel.b << endl;
    }
 }

//
 int main(int argc, char *argv[])
 {
	Pixel *p = (Pixel *)malloc(sizeof(Pixel));
	p->r;
	p->g;
	p->b;
	//pixel_list.push_back(p);

     if (argc != 2)
     {
        cerr << "Usage: " << argv[0] << " <filename> " << endl;
        return 1;
     }

     string filename = argv[1];

     // Step 1: Read the pixels from the file
     read_pixels(filename);

     // Step 2: Calculate the average colors
     average_colors(pixel_list);

     // Step 3: Flip the image vertically
     flip_vertically(pixel_list);

     // Step 4: Save the flipped pixels to a new file
    save_flipped_pixels("flipped.dat");

    return 0;
}

