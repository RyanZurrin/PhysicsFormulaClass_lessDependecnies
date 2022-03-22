//
// Created by Ryan.Zurrin001 on 1/22/2022.
//

#ifndef PHYSICSFORMULA_CALCULUS_H
#define PHYSICSFORMULA_CALCULUS_H
#include<iostream>
#include<string.h>
#include<cmath>
#define _USE_MATH_DEFINES
float pi = M_PI;
using namespace std;

float sine(){
    float low_lim_sine,upp_lim_sine;
    float anti_der_low_sine, anti_der_upp_sine,integral_sine;
    cout << "What is the Lower Limit of your sinousidal curve? Please enter below in No. Values"<<endl;
    cin >> low_lim_sine;
    cout << "Enter Upper Limit"<<endl;
    cin >> upp_lim_sine;

    if (((upp_lim_sine)-(low_lim_sine))<=pi){
        cout << "(d/dx) of sine x = -cos x"<<endl<<"(d/dx) of cos x = sin x"<<endl;
        anti_der_upp_sine = -cos(upp_lim_sine); // the antiderivative of sin(x) = -cos(x)
        anti_der_low_sine = -cos(low_lim_sine); // the antiderivative of cos(x) = sin(x)
        integral_sine = (anti_der_upp_sine)-(anti_der_low_sine);
        cout << "The integral of the graph f(x) = sin x, for the lower limit "<< low_lim_sine << " and the upper limit of "<< upp_lim_sine << " is "<<endl
             << integral_sine << " + C"<< endl;
    }

    else if(((upp_lim_sine)-(low_lim_sine))>pi){
        cout << "You are trying to find the area of 2 different wavelengths, this not possible because more than one integral will have to be integrated more than once!!!!!"<<endl;
    }
}

float cosine(){
    float low_lim_cos,upp_lim_cos;
    float anti_der_low_cos, anti_der_upp_cos,integral_cos;
    cout << "What is the Lower Limit of your cosine curve? Please enter below in No. Values"<<endl;
    cin >> low_lim_cos;
    cout << "Enter Upper Limit"<<endl;
    cin >> upp_lim_cos;
    if (((upp_lim_cos)-(low_lim_cos))<=pi){
        cout << "(d/dx) of sine x = -cos x"<<endl<<"(d/dx) of cos x = sin x"<<endl;
        anti_der_upp_cos = sin(upp_lim_cos); // the antiderivative of sin(x) = -cos(x)
        anti_der_low_cos = sin(low_lim_cos); // the antiderivative of cos(x) = sin(x)
        integral_cos = (anti_der_upp_cos)-(anti_der_low_cos);
        cout << "The integral of the graph f(x) = cos x, for the lower limit "<< low_lim_cos << " and the upper limit of "<< upp_lim_cos << " is "<<endl
             << integral_cos << " + C"<<endl;

        return integral_cos;
    }
    else if (((upp_lim_cos)-(low_lim_cos))>pi){
        cout << "You are trying to find the area of 2 different wavelengths, this not possible because more than one integral will have to be integrated more than once!!!!!"<<endl;
    }
}


float exponential(){
    float dx_a, low_lim_exp, upp_lim_exp,base,exponent,a,root_power,integral_exp,integral_exp1,integral_exp2;
    float anti_derv1,anti_derv2,continuation,continue_on;
    float n,base1,base2,exponent1,exponent2;


    cout << "Welcome to Integration of Exponential graphs"<<endl;
    cout << "Enter the value of a in the expression a^x" <<endl;
    cin >> a;


    cout << "Enter the Lower Limit"<< endl;
    cin >> low_lim_exp;
    cout << "Enter the upper limit"<<endl;
    cin >> upp_lim_exp;

    cout << "Press 1 to continue"<<endl;
    cin >> continuation;

    if (continuation==1){
        exponent1 = upp_lim_exp;
        base1 = a;
        anti_derv1= pow(base1,exponent1);
        integral_exp1 = (anti_derv1)/log(a);
        cout << "The total antiderivative of an exponential curve for the upper limit is "<< integral_exp1 <<endl;
        cout << "Press 1. to continue!"<<endl;
        cin >> continue_on;
        if (continue_on==1){
            exponent2 = low_lim_exp;
            base2=a;
            anti_derv2 = pow(base2,exponent2);
            integral_exp2 = (anti_derv2)/log(a);
            cout << "The total antiderivative of an exponential curve for the lower limit is "<< integral_exp2 <<endl;
        }
    }
    cout << "Area under curve = " << ((integral_exp1)-(integral_exp2));
}

// end of exponential integration


// start of quadratic integration
float quadratic(){
    float a,b,c;
    int n1=2;
    int n2=1;
    int n3=0;
    float low_lim_quad, upp_lim_quad;
    float dydx_xSq, dydx_x, dydx_c,integral_quad;
    float dx_quad,root1,root2,root3,base1,base2,base3,exp1,exp2,exp3,x,x2,x3;
    float go_in,go_out,dx_quad1,dx_quad2;

    cout << "Welcome to Quadratic Integration!!"<<endl;
    cout << "Enter the coefficient of x^2"<<endl;
    cin >> a;
    cout << "Enter the coefficient of x"<<endl;
    cin >> b;
    cout << "Enter the y-intercept"<<endl;
    cin >> c;
    cout << "Enter the lower limit of the curve:" <<endl;
    cin >> low_lim_quad;
    cout << "Enter the upper limit of the curve:"<<endl;
    cin >> upp_lim_quad;

    cout << "So your function is: f(x)= " << a << "x^2+" << b << "x+" << c << endl;


    cout << "Press enter to substitute Upper limit for x"<<endl;
    cin.get();

    if (cin.get()){
        x = upp_lim_quad;
        cout << "x is now appointed as upper limit"<<endl;
        // start of calculating the antiderivative of x^2
        base1 = x;
        exp1=(n1+1);
        root1= pow(base1,exp1);
        dydx_xSq = (a*(root1))/(n1+1);

        // start of calculating the antiderivative of x
        base2 = x;
        exp2 = (n2+1);
        root2 = pow(base2,exp2);
        dydx_x = (b*(root2))/(n2+1);

        // start of calculating the antiderivative of c ; formula dy/dx = (ax^(n+1))/(n+1)
        base3 = x;
        exp3 = (n3+1);
        root3 = pow(base3,exp3);
        dydx_c = (c*(root3))/(n3+1);

        dx_quad1 = (dydx_xSq + dydx_x + dydx_c); // total of antiderivatives for further calculations
        // end of antiderivative calculations

        cout << "Now the antiderivative total of Upper limit is " << dx_quad1<<endl;

        // done with substituting upper limit for x

        cout << "Press enter again to substitute Lower limit for x"<<endl;

        if(cin.get()){
            x= low_lim_quad;

            cout << "x is now appointed as lower limit"<<endl;
            // start of calculating the antiderivative of x^2
            base1 = x;
            exp1=(n1+1);
            root1= pow(base1,exp1);
            dydx_xSq = (a*(root1))/(n1+1);

            // start of calculating the antiderivative of x
            base2 = x;
            exp2 = (n2+1);
            root2 = pow(base2,exp2);
            dydx_x = (b*(root2))/(n2+1);

            // start of calculating the antiderivative of c ; formula dy/dx = (ax^(n+1))/(n+1)
            base3 = x;
            exp3 = (n3+1);
            root3 = pow(base3,exp3);
            dydx_c = (c*(root3))/(n3+1);

            dx_quad2 = (dydx_xSq + dydx_x + dydx_c); // total of antiderivatives for further calculations
            // end of antiderivative calculations

            cout << "The total value of antiderivatives when substituting lower limit value for x is: " << dx_quad2<<endl;

            cout << "The final area under the chosen curve of lower limit " << low_lim_quad << " and upper limit "<< upp_lim_quad<< " is " <<
                 (dx_quad1-dx_quad2);
        }
        else if (go_out==0){
            cout << "Program ended here! Press any key to exit terminal"<<endl;
        }
    }
    else if (go_in == 0){
        cout << "Program ended here! Press any key to exit terminal"<<endl;
    }
}

// start of differential calculus

float diff_quad(){
    float a2,b2,c2,diff1,diff2,diff3;
    cout << "Welcome to Differentiation!!"<<endl;
    cout << "Enter the coefficient of x^2"<<endl;
    cin >> a2;
    cout << "Enter the coefficient of x"<<endl;
    cin >> b2;
    cout << "Enter the y-intercept"<<endl;
    cin >> c2;

    diff1=(2*a2);
    diff2=(b2);
    diff3=(0);
    cout << "So your function is: f(x)= " << a2 << "x^2+" << b2 << "x+" << c2 << endl;

    cout << "The derivative of the function abouve is: " << diff1<<"x + "<< diff2<<" + "<<diff3<<endl;
}

//
//int main(){
//    // variables
//    int choice;
//    string type_calc;
//
//    cout << "Integration or Differentiation?"<<endl;
//    cin >> type_calc;
//
//    if (type_calc=="Integration"){
//
//        cout << "Welcome to integration!!"<<endl;
//        cout << "What type of graph are you integrating on?"<<endl;
//        cout << "1.Sinousidal"<<endl<<"2.Cosine"<<endl<< "4.Exponential"<<endl<<"5.Quadratic"<<endl;
//        cin>> choice;
//
//        switch(choice){
//            case 1:
//                sine();
//                break;
//            case 2:
//                cosine();
//                break;
//            case 4:
//                exponential();
//                break;
//            case 5:
//                quadratic();
//                break;
//        }
//    }
//
//    else if (type_calc=="Differentiation"){
//        cout << "Welcome to differentiation!!"<<endl;
//        diff_quad();
//    }
//    return 0;
//}
#endif //PHYSICSFORMULA_CALCULUS_H
