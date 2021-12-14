#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int l = 0; //Length of the input
int i = 0;
int numbers[5]; //Numbers of input 

int inpfile()
{

    FILE * inpf = fopen("input.txt", "r");

    if (inpf == NULL)
    {
        printf("File doesn't exists");
    }

    while (fscanf(inpf, "%d", &numbers[i]) != EOF)
    {
        i++;
    }

    numbers[i] = '\0';

    if (l > 5)
    {
        printf("Please enter 5 numbers");
    }

    // Check input to be all positive num
    for (int i = 0; i < l; i++)
    {
        if (numbers[i] < 0)
        {
            printf("Please enter non-negative number\n");
        }
    }

    // Check input to be all less than 30
    for (int i = 0; i < l; i++)
    {
        if (numbers[i] > 30)
        {
            printf("Please enter number below 30\n");
            break;
        }
    }

    fclose(inpf);
    return 0;
}


int main()
{
    // Take input
   inpfile();
    
    // Chart
    char filename[] = "svg.html";
    // Screen Size
    int w=1080, h=720;

    FILE *f = fopen(filename, "w");

    if (f == NULL)
    {
        printf("File doesn't exists");
    }

    //Strating of HTML file
    fprintf(f, "<html><body><h3>This Projects belongs to Suriya (Top) 64011643</h3> <svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\"\n");
    fprintf(f, " width=\"%dpx\" height=\"%dpx\"", 400, 400); // Size of svg
    fprintf(f, "<g transform=\"scale(1.0 -1.0)\">\n\n");

    //Fonts
    fprintf(f, "<style> .Arial { font:  %dpx arial; } </style>", 13);
    fprintf(f, "<style> .Georgia { font:  %dpx georgia; } </style>", 13);

    //Axes
    fprintf(f, "<polyline points=\"%lf,%lf %lf,%lf\"", 50.0, 50.0, 50.0, 350.0);
    fprintf(f, " style=\"fill:none;stroke:black;stroke-width:%lf\" />\n\n", 3.0);
    fprintf(f, "<polyline points=\"%lf,%lf %lf,%lf\"", 50.0, 50.0, 350.0, 50.0);
    fprintf(f, " style=\"fill:none;stroke:black;stroke-width:%lf\" />\n", 3.0);

    //Bars & Numbers
    if (numbers[0] <= 30)
    {
        fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:orange;\"/>\n",81.5,51.5, 30.0, numbers[0]*10.0);
        fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Georgia\"> %d </text>\n", 96.5, -31.5, 1.0, -1.0, 20.0, numbers[0]);
    }
    if (numbers[1] <= 30)
    {
        fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:red;\"/>\n",131.5,51.5, 30.0, numbers[1]*10.0);
        fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Georgia\"> %d </text>\n", 146.5, -31.5, 1.0, -1.0, 20.0, numbers[1]);
    }
    if (numbers[2] <= 30)
    {
        fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:green;\"/>\n",181.5,51.5, 30.0, numbers[2]*10.0);
        fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Georgia\"> %d </text>\n", 196.5, -31.5, 1.0, -1.0, 20.0, numbers[2]);
    }
    if (numbers[3] <= 30)
    {
        fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:blue;\"/>\n",231.5,51.5, 30.0, numbers[3]*10.0);
        fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Georgia\"> %d </text>\n", 246.5, -31.5, 1.0, -1.0, 20.0, numbers[3]);
    }
    if (numbers[4] <= 30)
    {
        fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:purple;\"/>\n",281.5,51.5, 30.0, numbers[4]*10.0);
        fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Georgia\"> %d </text>\n", 296.5, -31.5, 1.0, -1.0, 20.0, numbers[4]);
    }

    //Circle
    fprintf(f, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"black\"/>", 50.0, 50.0, 5.0);

    //Numbers on axes
    fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Arial\"> %d </text>\n", 30.0, -43.0, 1.0, -1.0, 20.0, 0);
    fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Arial\"> %d </text>\n", 30.0, -193.0, 1.0, -1.0, 20.0, 15);
    fprintf(f, "<text x=\"%lf\" y=\"%lf\" text-anchor=\"middle\" transform= \"scale(%lf, %lf)\" style=\" fill:black; font-size: %lfpx;\" class=\"Arial\"> %d </text>\n", 30.0, -343.0, 1.0, -1.0, 20.0, 30);

    //Limit lines
    fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:black;\"/>\n",350.0, 42.0, 3.0, 16.0);
    fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:black;\"/>\n",42.0, 200.0, 16.0, 3.0);
    fprintf(f, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height = \"%lf\" style=\"fill:black;\"/>\n",42.0, 350.0, 16.0, 3.0);

  
    //Ending HTML file
    fprintf(f, "\n\n</g></svg></body></html>\n");

    fclose(f);
}