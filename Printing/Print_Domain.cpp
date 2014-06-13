/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-06-11 19:04:04 mike_georgiou>
 *
 *
Print_Domain.cpp -- This function will save the domain
information into three separated binary files.
*
* Written on Wednesday, 11 June 2014.
********************************************/

#include<iostream>
#include<fstream>

using namespace std;

void Print_Domain(double dx, double* dy, double dz,
                  int ldx, int ldy, int ldz)
{

  ofstream  outfile_x, outfile_y, outfile_z;
  outfile_x.open("./Printing/Postprocessing/x.bin",ios::out | ios::binary);
  outfile_y.open("./Printing/Postprocessing/y.bin",ios::out | ios::binary);
  outfile_z.open("./Printing/Postprocessing/z.bin",ios::out | ios::binary);


  // Writing the X coordinantes
  double x_local=0.;
  for (int i = 0; i < ldx; i++)
    {
      x_local+=dx/2.;
      outfile_x.write( (char*)&x_local,sizeof(double));
      x_local+=dx/2.;
    }

  // Writing the Y coordinates
  double y_local=0.;
  for (int j = 0; j < ldy; j++)
    {
      y_local+=dy[j];
      outfile_y.write( (char*)&y_local,sizeof(double));
      y_local+=dy[j];
    }


  //Writing the  Z coordinates
  double z_local=0.;
  for (int k = 0; k < ldz; k++)
    {
      z_local+=dz/2.;
      outfile_z.write( (char*)&z_local,sizeof(double));
      z_local+=dz/2.;
    }




}
