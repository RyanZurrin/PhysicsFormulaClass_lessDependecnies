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

};

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


#endif //PHYSICSFORMULA_PLOTS_H
