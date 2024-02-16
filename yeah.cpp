#include <iostream> //Preprocessor directive, tells compiler to include the iostream file, like a including a header file in C.
#include <string>
#include <sstream>
#include <iomanip> //For setw
#include <conio.h> //for getche

using namespace std;    //"using" directive, so we won't have to call std::cout, etc. everytime.

void fizzbuzz(bool threeOnly, bool fiveOnly);

void overloadedFunction();
void overloadedFunction(int a);
void overloadedFunction(int st, int ring);

int x;
int& setNum();

inline void doit(bool happyLanding);

void rulersOfFrance(string="Philip Augustus", string="King"); //default value

struct helloThere {
    int ObiWan;
    int Anakin;
    bool highGround;
};

string SWDuel(helloThere combatants);

void intfrac(float n, float& intp, float& fracp);

enum daysOfTheWeek {Mon, Tues, Wed, Thurs, Fri, Sat, Sun};

int main() {
    int var1;   //Individual lines also called "statements."
    int var2;
    var1=20;
    var2=var1+10;
    cout<<"var1+10 is ";
    cout<<var2<<endl;
    cout<<"I like the Mets!\n";

    //Static variables stay the same even after a function ends, at which point all other functions would be destroyed.

    char charvar1='A';
    char charvar2='\t';
    cout<<charvar1;
    cout<<charvar2;
    charvar1='B';
    cout<<charvar1;
    cout<<'\n';
    cout<<"\"Run, Spot, run,\" said Jane."<<endl;

    //Fahrenheiht to Celsius.
    int ftemp;
    cout<<"Enter temperature in Fahrenheit: ";
    //cin>>ftemp;
    ftemp=50;
    int ctemp=(ftemp-32)*5/9;
    cout<<"Temperature in Celsius: "<<ctemp<<'\n';

    //Use setw for print width
    long pop1=2425785, pop2=47, pop3=9761;
    cout<<setw(8)<<"Location"<<setw(12)<<"Population"<<endl;
    cout<<setw(8)<<"Portcity"<<setw(12)<<pop1<<endl;
    cout<<setw(8)<<"Hightown"<<setw(12)<<pop2<<endl;
    cout<<setw(8)<<"Lowville"<<setw(12)<<pop3<<endl;

    //Using bools
    int num;
    cout<<"Enter a num: ";
    //cin>>num;
    num=5;
    cout<<num<<endl;
    cout<<"num<10 is "<<(num<10)<<endl;
    cout<<"num==10 is "<<(num==10)<<endl;
    cout<<"num>10 is "<<(num>10)<<endl;

    //For loop without {brakets}; only works for one line in the for
    for (int i=0; i<10; i++) 
        cout<<i<<" ";
    cout<<endl;

    int cube;
    cout<<setw(4)<<"Num"<<setw(6)<<"Cube"<<endl;
    for (int x=1; x<11; x++) {
        cout<<setw(4)<<x;
        cube=x*x*x;
        cout<<setw(6)<<cube<<endl;
    }

    //do loop runs the loop's code at least once before checking the parameters for completion!
    num=10;
    do {
        cout<<num<<" ";
        num--;
    }
    while (num>0);
    cout<<endl;
    
    //switch statement in C++!
    int speed;
    cout<<"Enter a number: ";
    //cin>>speed;
    speed=15;
    switch(speed) {
        case 10:
            cout<<"Speed is 10."<<endl;
            break;
        case 11:
            cout<<"Speed is 11."<<endl;
            break;
        case 12:
            cout<<"Speed is 12."<<endl;
            break;
        default:
            cout<<"Not 10, 11, or 12!"<<endl;
            break;
    }

    /*Conditional operator:
    Turn this:
    if (alpha<beta) {
        min=alpha;
    }
    else {
        min=beta
    }
    Into this: */
    int alpha=5;
    int beta=12;

    int min=(alpha<beta) ? alpha: beta;
    (min==alpha) ? cout<<"Min is alpha"<<endl, cout<<"hi"<<endl: cout<<"Min is beta"<<endl;
    //In Python: min=alpha if alpha<beta else beta
    //           print("Min is alpha") if alpha<beta else print("Min is beta")

    //Continue statement goes back to the top of the loop
    for (int i=0; i<10; i++) {
        if (i==5) {
            cout<<i<<" ";
            i++;
            continue;
        }
        //When i becomes 5, it prints 5 above, increments to six, and goes back to the loop instead of printing here.
        cout<<i<<" ";
    }
    cout<<endl;

    //fizzbuzz(false, true);
    //cout<<endl;

    //Struct stuff
    helloThere duel;
    duel.ObiWan=10;
    duel.Anakin=10;
    duel.highGround=true;
    //Alternately:
    duel={10,10,true};
    if (duel.highGround) {
        if (duel.ObiWan*2>duel.Anakin) {
            cout<<"It's over Anakin! I have the High Ground!"<<endl;
            cout<<"You underestimate my power!"<<endl;
            cout<<"Don't try it!"<<endl;
            cout<<"*Anakin gets cut up*"<<endl;
        }
    }
    else {
        cout<<"Well then you are lost!"<<endl;
    }

    //Enum stuff
    daysOfTheWeek day1, day2;
    day1=Tues;
    day2=Sat;
    int diff=day2-day1;
    cout<<"Days between "<<day1<<" and "<<day2<<": "<<diff<<endl;
    if (day1<day2) {
        cout<<"Day 1 comes before day 2"<<endl;
    }
    else {
        cout<<"Day 2 comes before day 1"<<endl;
    }
    //Enums are really integers, from 0 onwards.

    cout<<SWDuel(duel)<<endl;

    float a, b, c;
    a=5.0;
    //intFrac has b and c passed as float& references. The & makes the variable refer (like an alias) to another variable.
    intfrac(a, b, c);

    void order(int&, int&);
    int a1=5, b1=3;
    order(a1, b1);
    cout<<b1<<" "<<a1<<endl;

    //Overloaded Functions:
    overloadedFunction();
    overloadedFunction(5);
    overloadedFunction(1, 2);

    void diffType(int, int);
    void diffType(string, string);

    diffType(5, 6);
    diffType("I like ", "the Mets");

    //Inline function doit is faster to call than a normal function
    doit(true);

    //Call function without entering an input and it'll use the user-defined default value:
    rulersOfFrance();
    rulersOfFrance("Napoleon", "Emperor");

    //Ooh, function on the left side of the equal side! x is a global variable defined above.
    setNum()=5;
    cout<<x<<endl;

    return 0;
}

void fizzbuzz(bool threeOnly, bool fiveOnly) {
    bool printNumber=false;
    int limit;
    int start;
    cout<<"Enter the max number: ";
    cin>>limit;
    cout<<"Enter the min number: ";
    cin>>start;
    for (int i=start; i<=limit; i++) {
        printNumber=true;
        if (i%3==0) {
            if (i%5!=0 || !fiveOnly) {
                cout<<"Fizz";
                printNumber=false;
            }
            
        }
        if (i%5==0) {
            if (i%3!=0 || !threeOnly) {
                cout<<"Buzz";
                printNumber=false;
            }
        }
        if (printNumber) {
            cout<<i;
        }
        cout<<endl;
    }
}

string SWDuel(helloThere combatants) {
    if (combatants.highGround) {
        return "Obi Wan crushes Anakin";
    }
    return "Oh I don't think so";
}

//Standard variables create a copy of inputted variable, reference (&) variable uses that variable directly. Thus you can alter an
//inputted variable in the function without doing something like a=func(a) and the changes made to the variable in the function will
//apply to the rest of the code (ex. a=5, func(a) {a++} will lead to a=6).
void intfrac(float n, float& intp, float& fracp) {
    long temp=static_cast<long>(n);
    cout<<"Temp: "<<temp<<endl;
    intp=static_cast<float>(temp);
    cout<<"intp: "<<intp<<endl;
    fracp=n+intp;
    cout<<"fracp: "<<fracp<<endl;
}

void order(int& a, int& b) {
    if (a<b) {
        int temp=a;
        a=b;
        b=temp;
    }
}

void overloadedFunction() {
    cout<<"Hello there!"<<endl;
}
void overloadedFunction(int a) {
    cout<<"Num: "<<a<<endl;
}
void overloadedFunction(int st, int ring) {
    cout<<st+ring<<endl;
}

void diffType(int a, int b) {
    cout<<a*b<<endl;
}
void diffType(string an, string bt) {
    cout<<an+bt<<endl;
}

void doit(bool happyLanding) {
    if (happyLanding) {
        cout<<"Another happy landing"<<endl;
    }
    else {
        cout<<"Oh no, I'm not brave enough for politics"<<endl;
    }
}

void rulersOfFrance(string name, string title) {
    cout<<name<<", "+title+" of France"<<endl;
}

int& setNum() {
    return x;
}