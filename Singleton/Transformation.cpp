//
// Created by senne on 12/15/18.
//

#include "Transformation.h"

std::pair<double, double> Transformation::Transform(std::pair<double, double> input)
{
        std::pair<double, double> result;
        double x = input.first;
        x = x + 4;
        x = x / 8;
        double resultx = x * Screensize.first;

        double y = input.second;
        y = y - 3;
        y = y / (-6);
        double resulty = y * Screensize.second;

        return {resultx, resulty};
}

std::pair<double, double> Transformation::ReverseTransform(std::pair<double, double> input)
{
        std::pair<double, double> result;

        float x = input.first / Screensize.first;
        float y = input.second / Screensize.second;
        x = x * 8;
        y = y * (-6);
        x = x - 4;
        y = y + 3;

        return {x, y};
}

void Transformation::setScreensize(const std::pair<int, int>& Screensize) { Transformation::Screensize = Screensize; }

double Transformation::heightReverse(double in) { return (in / Screensize.second) * 6; }

double Transformation::widthReverse(double in) { return (in / Screensize.first) * 8; }
