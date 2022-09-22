//
// Created by ryanz on 9/17/2022.
//

#ifndef PHYSICSFORMULA_PLOTS_H
#define PHYSICSFORMULA_PLOTS_H
#include "pbPlots.hpp"
#include "supportLib.hpp"

class Plots {
public:
    static void drawScatterPlot(int width, int height, vector<double> *x,
                                vector<double> *y, const string& filename);

    static void drawScatterPlot(int width,
                                int height,
                                vector<double> *x,
                                vector<double> *y,
                                const string& filename,
                                vector<wchar_t> *title,
                                vector<wchar_t> *xLabel,
                                vector<wchar_t> *yLabel,
                                const string& lineType = "Solid",
                                int lineThickness = 2,
                                bool display = false);

    static void FreeAllocations();
}; //end class Plots


void Plots::drawScatterPlot(int width, int height, vector<double> *x,
                            vector<double> *y, const string& filename) {
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
    vector<wchar_t> *value = nullptr;
    StringReference *stringRef = CreateStringReference(value);
    DrawScatterPlot(imageRef, width, height, x, y, stringRef);

    vector<double> *pngData = ConvertToPNG(imageRef->image);
    WriteToFile(pngData, filename);
    DeleteImage(imageRef->image);
}

void Plots::drawScatterPlot(int width,
                            int height,
                            vector<double> *x,
                            vector<double> *y,
                            const string& filename,
                            vector<wchar_t> *title,
                            vector<wchar_t> *xLabel,
                            vector<wchar_t> *yLabel,
                            const string& lineType,
                            const int lineThickness,
                            bool display
                            )
{
    bool success;
    auto errorMessage = CreateStringReferenceLengthValue(0, L' ');
    RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();

    auto series = GetDefaultScatterPlotSeriesSettings();
    series->xs = x;
    series->ys = y;
    series->linearInterpolation = true;
    if(lineType == "Solid")
        series->lineType = toVector(L"Solid");
    else if(lineType == "Dashed")
        series->lineType = toVector(L"Dashed");
    else if(lineType == "Dotted")
        series->lineType = toVector(L"Dotted");
    else if(lineType == "DashDot")
        series->lineType = toVector(L"DashDot");
    else if(lineType == "DashDotDot")
        series->lineType = toVector(L"DashDotDot");
    else
        series->lineType = toVector(L"Solid");
    series->lineThickness = lineThickness;

    auto settings = GetDefaultScatterPlotSettings();
    settings->width = width;
    settings->height = height;
    settings->autoBoundaries = true;
    settings->autoPadding = true;
    settings->title = (vector<wchar_t> *) title;
    settings->xLabel = (vector<wchar_t> *) xLabel;
    settings->yLabel = (vector<wchar_t> *) yLabel;
    settings->scatterPlotSeries->push_back(series);

    success = DrawScatterPlotFromSettings(imageRef, settings, errorMessage);

    if (success)
    {
        vector<double> *pngData = ConvertToPNG(imageRef->image);
        WriteToFile(pngData, filename);
        DeleteImage(imageRef->image);
        if(display)
        {
            system(filename.c_str());
        }
    }
    else
    {
        cerr << "Error: ";
        for (wchar_t c : *errorMessage->string)
            wcerr << c;
        cerr << endl;
    }

    // free all allocated memory
    FreeAllocations();


}

void Plots::FreeAllocations() {

}


#endif //PHYSICSFORMULA_PLOTS_H
