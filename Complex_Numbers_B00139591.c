/**********************************************************************
Name: Deirdre Deeney
Student Number: B00139591

Description: Complex Numbers, Program to convert
                from rectangular to polar and then back to rectangular
************************************************************************/

/**********************************************************************
    Header Files
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************
    Declaring Global Variables
************************************************************************/
void comp_Polar();      //Function for computing Polar & Rectangular
float a;                //Inputted Real Number
float b;                //Inputted Imaginary
float R;                //Outputted Radius
float theta;            //Calculated Angle in degrees
float num1;             //Calculated opp/adj
float rad;              //Angle in Radians
float angle;            //Angle when 180 is added or subtracted
float real;             //Calculated Real for Polar Form
float imagin;           //Calculated Imaginary for Polar Form

/**********************************************************************
    Main Function describes to the user what the program will do
     and calls the comp_Polar function
************************************************************************/
int main()
{
    printf("Convert from Rectangular to Polar Form \n\n");
    printf("This program will\n1.Ask for the user to input Real and Imaginary Numbers\n");
    printf("2.Convert these to Polar Form \n");
    printf("3.Determine the quadrant the point is on the Complex Plane\n");
    printf("4.Convert the Polar back to Rectangular form\n\n\n");
    comp_Polar();


    return 0;
}

/****************************************************************************
    comp_Polar Function to convert complex numbers from rectangular to polar
     and then back to rectangular.
*****************************************************************************/

void comp_Polar(){

    printf("Please input value for Real Number\n");
    scanf("%f",&a);
    printf("Please input value for Imaginary Number\n");
    scanf("%f",&b);
    if (b>=0){                                                              // if the Imaginary number is positive, print a plus 'a+jb'
        printf("\n1.The Complex Number you inputted is %.2f+%.2fj \n",a,b);
    }
    else{                                                                  // if the Imaginary number is NOT positive, omit a plus 'a-jb'
        printf("\n1.The Complex Number you inputted is %.2f%.2fj \n",a,b);
    }
    printf("\n2.The Rectangular Form is:\n");
    R=sqrt(pow(a,2)+pow(b,2));              //Equation to obtain the Radius
    printf("\tRadius = %f \n",R);

    num1=b/a;                               // divides the opposite by the adjacent
    rad = atan(num1);                       // inverse tan of opposite/adjacent
    //printf("%f radians\n", rad);          // testing maths is calculating correctly - not needed in normal operation
    theta = rad*(180/M_PI);                 // converts from radians to degrees

    if((a>=0.0)&&(b>=0.0)){                         //Real and Imaginary are positive, point in 1st quadrant
        angle = theta;                              // No change to angle in the 1st quadrant
        printf("\tAngle = %.0f degrees\n\n",angle);
        printf("3.Your point is in the 1st Quadrant \n\n");
    }

    if ((a<0)&&(b>=0)){                             //Real is negative & Imaginary is positive, point in 2nd quadrant
        angle = theta+180;                          // Add 180 degrees as angle is in 2nd quadrant
        rad= angle*(M_PI/180);                      // Convert angle back to radians to use for finding Rectangular Form
        printf("\tAngle = %.0f degrees\n\n",angle);
        printf("3.Your point is in the 2nd Quadrant \n\n");
    }

    if ((a<0)&&(b<0)){                             //Real and Imaginary are negative, point in 3rd quadrant
        angle = theta-180;                         // Minus 180 degrees as angle is in 3rd quadrant
        rad= angle*(M_PI/180);                     // Convert angle back to radians to use for finding Rectangular Form
        printf("\tAngle = %.0f degrees or %.0f degrees\n\n",angle,angle+360); // Angle comes out minus, angle+360 finds angle in opposite direction
        printf("3.Your point is in the 3rd Quadrant \n\n");
    }

    if ((a>=0)&&(b<0)){                             //Real is positive & Imaginary is negative, point in 4th quadrant
        angle = theta;                              //No change to angle in the 4th quadrant
        printf("\tAngle = %.0f degrees or %.0f degrees\n\n",angle,angle+360); // Angle comes out minus, angle+360 finds angle in opposite direction
        printf("3.Your point is in the 4th Quadrant \n\n");
    }

    real = R*cos(rad);                              //Formula to obtain Real Number
    imagin = R*sin(rad);                            //Formula to obtain Imaginary Number

    if (b<0){
        printf("4.Rectangular form is %.2f%.2fj \n\n",real,imagin);         // if the Imaginary number is negative, omit a plus 'a-jb'
    }

    else{
        printf("4.Rectangular form is %.2f+%.2fj \n\n",real,imagin);        // if the Imaginary number is NOT negative, omit a plus 'a-jb'
    }
}
