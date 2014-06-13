/*  Last Modified Time-stamp: <2014-06-12 13:37:28 mike_georgiou> */ 
//d Program that the problems constant's will be defined 
/* const identifier must be placed in order for the variables to be read only once */


// General contants

#ifndef Constants
#define Constants


// Non-Dimensional Numbers and quatities of my problem
const double Reynolds = 180.;//*18.333333;   // Re_o  case
const double Pressure_Gradient = -1.;//*2.97e-3; // Re_o case

const double Prandtl  = 0.8;
const double Richardson  = 0.002;
#endif


#ifndef Boundary_Conditions
#define Boundary_Conditions

const double temperature_top = 1.;
const double temperature_bottom = 1.;

const double temperature_gradient_top = 0.;
const double temperature_gradient_bottom = 0.;

const double rho_top = 1.;
const double rho_bottom = 1.;

const double rho_gradient_top = 0.;
const double rho_gradient_bottom = 0.;

const double pressure_gradient_top = 0.;
const double pressure_gradient_bottom = 0.;

const double velocity_x_top=0.;
const double velocity_x_bottom=0.;

const double velocity_y_top=0.;
const double velocity_y_bottom=0.;

const double velocity_z_top=0.;
const double velocity_z_bottom=0.;

#endif
