#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;

double evaluate(double x) {
    double pi=3.141592653589793;
    x=sin(pi*x/256);
    return x;
}

double eval2(double x) {
    double pi=3.141592653589793;
    return pow(2, -2*pow((x-0.1)/0.9, 2))*pow(sin(5*pi*x), 6);
}

double perturb(double x) {
    if (x==0) {
        x++;
    }
    else if (x==255) {
        x--;
    }
    else {
        if (rand()%2==0) {
            x++;
        }
        else {
            x--;
        }
    }
    return x;
}

double perturb2(double x) {
    double multiple=0.01;
    multiple*=rand()%10;
    if (x<=0) {    
        x+=0.01;
    }
    else if (x>=1) {
        x-=0.01;
    }
    else {
        rand()%2==0 ? x+=multiple: x-=multiple;
    }
    if (x>1) {
        x=1;
    }
    if (x<0) {
        x=0;
    }
    return x;
}

double perturb3(double x) {
    if (x>1) {
        return 1;
    }
    if (x<0) {
        return 0;
    }
    return x+=0.01;
}

int hillClimbing(int maxIt, int g, function<double(double)> fn, function<double(double)> pertFn, bool eval1) {
    double x;
    if (eval1) {
        x=rand()%256;
    }
    else {
        x=rand()%100;
        x/=100;
    }
    cout<<"x start: "<<x<<endl;
    int t=1;
    while (t<maxIt && fn(x)!=g) {
        //cout<<"t: "<<t<<endl;
        double xPrime=pertFn(x);
        if (fn(xPrime)>fn(x)) {
            //cout<<"go up from "<<x<<" to "<<xPrime<<endl;
            x=xPrime;
        }
        t+=1;
    }
    if (t<maxIt) {
        cout<<"Reached top!: "<<fn(x)<<endl;
    }
    else {
        cout<<"Final stop: "<<fn(x)<<endl;
    }
    return x;
}

//Iterative Hill Climbing
int IHC(int nStart, int maxIt, int g, function<double(double)> fn, function<double(double)> pertFn, bool eval1) {
    double best;
    if (eval1) {
        best=rand()%256;
    }
    else {
        best=rand()%100;
        best/=100;
    }
    int t1=1;
    while (t1<nStart && best!=g) {
        double x=hillClimbing(maxIt, g, fn, pertFn, eval1);
        t1+=1;
        if (x>best) {
            best=x;
        }
    }
    cout<<"Best: "<<best<<endl;
    return best;
}

//Stochastic Hill Climbing
int SHC(int maxIt, int T, int g, function<double(double)> fn, function<double(double)> pertFn, bool eval1) {
    double x;
    if (eval1) {
        x=rand()%256;
    }
    else {
        x=rand()%100;
        x/=100;
    }
    cout<<"SHC x: "<<x<<endl;
    int t=1;
    double rnd;
    while (t<maxIt && x!=g) {
        double xPrime=pertFn(x);
        //cout<<"calc: "<<(1/(1+exp(fn(x)-fn(xPrime))/T))<<endl;
        rnd=rand()%100;
        rnd/=100;
        if (rnd<(1/(1+exp(fn(x)-fn(xPrime))/T))) {
            x=xPrime;
            //cout<<"update x: "<<x<<endl;
        }
        t+=1;
    }
    cout<<"final t: "<<t<<endl;
    cout<<"final x: "<<x<<endl;
    return x;
}

int main() {
    //With evaluate(), x must be 128 for the function to return 1; in eval2, x must be 0.1 to return 1. 
    srand(time(0));
    IHC(25, 257, 1, evaluate, perturb, true);
    IHC(25, 257, 1, eval2, perturb2, false);
    SHC(257, 6, 1, evaluate, perturb2, false);
    int finishedCount;
    double current;
    for (int i=0; i<256; i++) {
        current=SHC(257, 6, 1, eval2, perturb2, false);
        if (current==1) {
            finishedCount++;
        }
    }
    cout<<"Total number of x's ending as 1: "<<finishedCount<<endl;
    

    /*
    double a;
    double b;
    double pi=3.141592653589793;
    for (double x=0; x<=1; x+=0.01) {
        //b=rand()%2==0 ? 0.01: -0.01;
        //a=(1/(1+exp(eval2(x)-eval2(x+b))/10));
        cout<<"x: "<<x<<endl;
        a=eval2(x);
        cout<<a<<endl;
    }
    cout<<"hi"<<endl;
    */
    //hillClimbing(257, 1);
    return 0;
}