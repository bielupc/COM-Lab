#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

//#define DEBUG


void gen_plot_header(std::string columnheader, float height, float min, float max);
void gen_plot_footer(std::string columnheader);
void gen_line(int inix, int iniy, int endx, int endy, int r, int g, int b, int w);
void gen_text(int inix, int iniy, std::string text, char * color);

int main(int argc, char * argv [])
{
   std::ifstream file;
   if (argc > 1) {
      file.open(argv[1], std::ifstream::in);
   }
   else {
      std::cerr << "Us: " << argv[0] << " <file.txt>" << std::endl;
      return 1;
   }

   std::string header;
   file >> header;

   std::cerr << "Computing statistics on " << header << std::endl;

   float minimum = 1e10;
   float maximum = 0.0;
   float sum = 0.0;
   int count = 0;

   float v;
   file >> v;
   while (!file.eof()) {

      // modify the minimum value if required
      if (v < minimum) minimum = v;

      // modify the maximum value if required
      if (v > maximum) maximum = v;

      // sum v to "sum" to later compute the average
      sum = sum + v;

    count++;
    file >> v;
   }
   std::cerr << "Read a total of " << count << " values" << std::endl;
   std::cerr << "Min: " << minimum << std::endl;
   std::cerr << "Avg: " << sum/count << std::endl;
   std::cerr << "Max: " << maximum << std::endl;

   if (minimum > 0.0f) minimum = 0.0;

   minimum = -5;
   maximum = 5;

   float height = ceil (maximum - minimum + 0.2);

#define INIX 50
#define FINIX 50



   // reopen file
   file.close();
   file.open(argv[1], std::ifstream::in);
   file >> header;

   std::cerr << "Generating HTML for " << header << std::endl;

   gen_plot_header(header, height, minimum, maximum);

   file >> v;
   int i = 1;
   int inix = 0 + FINIX;
   int iniy = 600 - (v-minimum)*600/height;   //- (0-min)*600/height;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
   while (!file.eof()) {
      
      int endx = i + FINIX;
      int endy = (int) (600 - (v-minimum)*600/height); //- (0-min)*600/height;

#ifdef DEBUG
      std::cerr << endx << " " << endy << " " << v << " " 
                << (v-minimum)*600/height << std::endl;
#endif

      gen_line(inix, iniy, endx, endy, 255, 0, 0, 1);

      inix = endx;
      iniy = endy;

      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
      file >> v;
    file >> v;
    ++i;
   }

   file.close();
   gen_plot_footer(header);
   return 0;
}


void gen_plot_header(std::string columnheader, float height, float min, float max)
{
   int i;
   int h = (int) (600 /*height*/ - 0.0*600/height);
   int inix = 10 + INIX;
   int iniy = 30;
   int endx = 10 + INIX;
   int endy = h /*575*/;
   std::cout
<< "<html>" << std::endl
<< "<!-- Acknowlegements: https://www.w3schools.com/ -->" << std::endl
<< "<title> Plot </title>" << std::endl
<< "<body>" << std::endl

<< "<h1>Plot</h1>" << std::endl

<< "<svg width=\"850\" height=\"650\">" << std::endl;

   inix = INIX;
   endx = INIX;

   // gen Y axis
   gen_line(inix, iniy, endx, endy, 0, 0, 255, 2);
   float value;
   //float step = 0.5;
   //float step = (max*10 - min*10) / 10;
   //step = ceil(step)/ 10;
   //float step = ceil ((max - min)*10) / 100;
   //float step = (ceil(max) - ceil(min)) / 10;
   float step = ceil((ceil(max) - ceil(min))) / 10;
   //if (step < 0.5) step = 0.5;
   //for (value = 0.0; value < height; value += step /*height/10*/) {
   for (value = min; value < max; value += step /*height/10*/) {
      std::ostringstream mtext;
      h = (int) (600 /*height*/ - (value-min)*600/height);
#ifdef DEBUG
      std::cerr << h << " " << value << " "
                << (value-min)*600/height << std::endl;
#endif
      gen_line(INIX-10, h, INIX, h, 0, 0, 255, 1);
      mtext << value;
      gen_text(0, h, mtext.str(), "blue");
   }

   iniy = endy = 600 - (0-min)*600/height;
   endx = endx + 790;

   gen_line(inix, iniy, endx, endy, 0, 0, 255, 2);

   for (i = 0; i < 790; i += 50) {
      std::ostringstream mtext;
      gen_line(INIX+i,   iniy,    INIX+i, iniy+10, 0, 0, 255, 1);
      mtext << i;
      int offs = mtext.str().length()*2;
#ifdef DEBUG
      std::cerr << i << " " << mtext.str() << " " 
                << mtext.str().length() << " ";
#endif
      gen_text(INIX+i-4-offs, iniy+24, mtext.str(), "blue");
   }
}

void gen_line(int inix, int iniy, int endx, int endy, int r, int g, int b, int w)
{
   std::cout
<< "<line x1=\"" << inix <<"\" y1=\"" << iniy << "\" "
<< "x2=\"" << endx <<"\" y2=\"" << endy << "\" "
<< "style=\"stroke:rgb(" << r << "," << g << "," << b
<< ");stroke-width=" << w << "\" />" << std::endl;
}

void gen_plot_footer(std::string columnheader)
{
   int inix = 50;
   int iniy = 10;
   int endx = 100;
   int endy = 10;

   gen_line(inix, iniy, endx, endy, 255, 0, 0, 1);
   gen_text(0, iniy+2, columnheader, "blue");

   std::cout
<< "</svg>" << std::endl
<< "</body>" << std::endl
<< "</html>" << std::endl;
}

void gen_text(int inix, int iniy, std::string text, char * color)
{
   std::cout
<< "<text x=\"" << inix << "\" y=\"" << iniy << "\" fill=\" << color << \">" 
<< text << "</text>" << std::endl;
}
