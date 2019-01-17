//
// Created by senne on 12/15/18.
//

#ifndef ROADFIGHTER_TRANSFORMATION_H
#define ROADFIGHTER_TRANSFORMATION_H

#include <iostream>

class Transformation {

private:
    std::pair<int,int> Screensize;
public:
    std::pair<double,double> Transform(std::pair<double,double>input);

    std::pair<double,double> ReverseTransform(std::pair<double,double> input);

    double heightReverse(double in);

    double widthReverse(double in);

    void setScreensize(const std::pair<int, int> &Screensize);


public:
    static  Transformation& getInstance(int x,int y){
        static Transformation instance(x,y);
        return instance;
    }

private:
    Transformation(int x, int y) {Screensize.first = x, Screensize.second = y;};

    Transformation(Transformation const&);
    void operator=(Transformation const&);
};


#endif //ROADFIGHTER_TRANSFORMATION_H
