#include <iostream>
#include <cmath>        //for the use of the power function and e
#include <iomanip>      //for the use of fixed and set precision
using namespace std;

int main()
{
 double approx = 1.0;   //approximation will always be atleast one
 double exponent;       //the exponent provided by the user
 double denominator = 1;
 int series_num;        //series number is provided by the user
 int i=1;       //i counter keep track of the placement in the term of the series
 int j=1;       //j counter keep track of the factorial for the denominator in the series
 double display;        //used to displays the actualy sum of the number in the series
 double e_val;
 double error_approx;
 cout <<"This program approximates e^x using a n-term power series expansion."<<endl;
 cout <<"Enter the value of x>";
 cin >>exponent;
 cout <<"How many terms do you wish to use in this approximation?";
 cin >>series_num;
 if (series_num > 0)    //tests for valid series input
  {
    cout <<"e^"<< fixed << setprecision(6) <<exponent<<" = 1";
  }
 if (series_num < 0)    //tests for invalid series input
  {
   cout <<series_num<<" is an invalid number of terms."<<endl;
  }
 while(i < series_num && series_num > 0)        //While nested loop computes the series to approximate e
   {
   denominator = denominator * j;       //Updates the factorial in the denominator
   display = (pow(exponent,i))/denominator ;    //computes the terms in the series

   if(i%2 != 0 && exponent < 0 )        //displays negative terms in an alternating series
   {
    display = abs(display);
    cout<<" - "<<fixed<<setprecision(6)<<display;
    approx = approx - display;  //adds the current term to the total approximation

  }
   else         //displays the positive terms in the series.
   {
    cout <<" + "<<fixed<<setprecision(6)<<display;
    approx = approx + display;
   }
   j++;         //updates the counter for the factorial
   i++;         //updates the counter for the series
  }
if (series_num > 0)     //displays the approximation, actual value, and error
 {
 e_val = exp (exponent);
 cout <<" = "<<fixed<<setprecision(15)<<approx<<endl;
 cout <<"The exact value of e^"<< fixed << setprecision(15) << exponent <<" is "<<fixed<<setprecision(15)<<e_val<<endl;
 error_approx = e_val - approx;
 cout <<"Approximation error is "<<fixed<<setprecision(15)<<error_approx<<"."<<endl;
 }
 return 0;
}
