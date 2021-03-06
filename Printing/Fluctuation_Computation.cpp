/*******************************************
 * Author: Michail Georgiou 
*  Last Modified: Time-stamp: <2014-06-11 17:24:28 mike_georgiou>   
*
*
Fluctuation_Computation.cpp -- This program computes the fluctuations for
the turbulent pipe flow.
*
* Written on Wednesday, 11 June 2014.
********************************************/

#include <fstream>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;
void Fluctuation_Computation(double*** velocity_x,
			     double*** velocity_y,
			     double*** velocity_z,
			     int ldx, int ldy, int ldz,
			     int time_index)
{

  // Creating the output files
  string name[6];
  name[0]="fluctuations_x";
  name[1]="fluctuations_y";
  name[2]="fluctuations_z";

  name[3]="mean_x";
  name[4]="mean_y";
  name[5]="mean_z";


  stringstream ss;
  string directory = "./Printing/Postprocessing/";
  string format = ".bin";
  string finalName[6];
  ofstream  outfile[6];


  for(int vi=0; vi<6; vi++)
    {
      ss<<directory<<name[vi]<<time_index<<format;
      finalName[vi]= ss.str();
      outfile[vi].open(finalName[vi],ios::out | ios::binary);
      ss.str("");
    }

  //Computing <U>
  double u_mean[ldy];
  double v_mean[ldy];
  double w_mean[ldy];

  double sum[3];


    for (int j = 0; j < ldy; j++){
      //initializing the sums
      sum[0]=0.; sum[1]=0.; sum[2]=0.;
      for (int k = 0; k < ldz; k++){
	for (int i = 0; i < ldx; i++){

	  //computing u_mean 
	  sum[0] += velocity_x[k][j][i];
	  sum[1] += velocity_y[k][j][i];
	  sum[2] += velocity_z[k][j][i];
	  
      }
    }	    

      u_mean[j] = sum[0]/(ldx*ldz);
      v_mean[j] = sum[1]/(ldx*ldz);
      w_mean[j] = sum[2]/(ldx*ldz);
  }   






  for (int k = 0; k < ldz; k++){
    for (int j = 0; j < ldy; j++){
      for (int i = 0; i < ldx; i++){


	double fluct_x=(velocity_x[k][j][i]-u_mean[j]);
	double fluct_y=(velocity_y[k][j][i]-v_mean[j]);
	double fluct_z=(velocity_z[k][j][i]-w_mean[j]);

	outfile[0].write( (char*)&fluct_x,sizeof(double));
	outfile[1].write( (char*)&fluct_y,sizeof(double));
	outfile[2].write( (char*)&fluct_z,sizeof(double));
      }
    }	    
  }   
  

  for(int j=0; j<ldy; j++)
    {
	//saving the mean velocity profiles
	outfile[3].write( (char*)&u_mean[j],sizeof(double));
	outfile[4].write( (char*)&v_mean[j],sizeof(double));
	outfile[5].write( (char*)&w_mean[j],sizeof(double));
    }


}
