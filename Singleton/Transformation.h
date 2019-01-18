//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H

#include <iostream>

class Transformation
{

private:
        std::pair<int, int> Screensize;

public:
        /**
         * Transforms the position of the logic to the window size
         * @param input
         * @return
         */
        std::pair<double, double> Transform(std::pair<double, double> input);

        /**
         * Transforms the position from the window to the logic
         * @param input
         * @return
         */
        std::pair<double, double> ReverseTransform(std::pair<double, double> input);

        /**
         * Reverse a height to logic
         * @param in
         * @return
         */
        double heightReverse(double in);

        /**
         * Reverse a width to logic
         * @param in
         * @return
         */
        double widthReverse(double in);

        /**
         * Set the screenzie
         * @param Screensize
         */
        void setScreensize(const std::pair<int, int>& Screensize);

public:
        static Transformation& getInstance(int x, int y)
        {
                static Transformation instance(x, y);
                return instance;
        }

private:
        Transformation(int x, int y) { Screensize.first = x, Screensize.second = y; };

        Transformation(Transformation const&);
        void operator=(Transformation const&);
};

#endif // ROADFIGHTER_TRANSFORMATION_H
