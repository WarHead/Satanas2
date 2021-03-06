/*******************************************
 * Author: Michail Georgiou
 *  Last Modified: Time-stamp: <2014-06-11 13:54:21 mike_georgiou>
 *
 *
Binary_To_Ascii.cpp -- This program converts binary to Ascii.
It can convert  1,2,3-Dimensional arrays depending on the inputs that
will be given.

input 1 : name of the binary file (e.g"example.bin")
input 2 : name of the output file (e.g"example.dat")
input 3-5: number of elements in each dimension ( depending on the
number of inputs)
*
* Written on Friday,  6 June 2014.
********************************************/
#include<iostream>
#include <stdlib.h>     /* strtol */
#include<fstream>
#include<stdio.h>

using namespace std;

int main(int argc, char** argv) {

  char* input, *output;
  int N[3];

  // Reading the name of the input.bin and the output.dat
  if(argc==4)
    {
      input = argv[1];
      output = argv[2];

      //Reads the information about the grid domain.
      // strtol converts a  string into an integer
      N[0]=strtol(argv[3],NULL,0);

      ifstream input_file (input, ios::in | ios:: binary);
      if(!input_file)
        {
          cout << "Cannot open file for input.\n";
          return 1;
        }

      input_file.seekg (0, input_file.end);
      int length = input_file.tellg();
      input_file.seekg (0, input_file.beg);


      ofstream output_file(output, ios::out);
      if(!output_file)
        {
          cout << "Cannot open file for output.\n";
          return 1;
        }

      char value[8]; // Array that reads 8bytes
      double result; // Temporary saves the converted variable
      int safety_parameter=0;
      for(int i=0; i<N[0]; i++){

        input_file.read(value,8);
        result = *((double*) value);
        output_file<<result<<endl;

        safety_parameter+=8;
        if(safety_parameter>length)
          {
            cout << "Exceeded the length of the file. Please check your inputs.\n";
	    cout<<length<<" "<<safety_parameter<<endl;
            remove(output);
            return 1;
          }
      }
    }

  else if(argc ==5)
    {
      input = argv[1];
      output = argv[2];

      //Reads the information about the grid domain.
      // strtol converts a  string into an integer
      N[0]=strtol(argv[3],NULL,0); // Dimensions of array in X
      N[1]=strtol(argv[4],NULL,0); // Dimensions of array in Y


      ifstream input_file (input, ios::in | ios:: binary);
      if(!input_file)
        {
          cout << "Cannot open file for input.\n";
          return 1;
        }

      // Computing the length of the file
      // get length of file:
      input_file.seekg (0, input_file.end);
      int length = input_file.tellg();
      input_file.seekg (0, input_file.beg);


      ofstream output_file(output, ios::out);
      if(!output_file)
        {
          cout << "Cannot open file for output.\n";
          return 1;
        }



      char value[8]; // Array that reads 8bytes
      double result; // Temporary saves the converted variable
      int safety_parameter=0;

      for(int j=0; j<N[1]; j++){
        for(int i=0; i<N[0]; i++){


          input_file.read(value,8);
          result = *((double*) value);
          output_file<<result<<endl;

          safety_parameter+=8;
          if(safety_parameter>length)
            {
              cout << "Exceeded the length of the file. Please check your inputs.\n";
	      cout<<length<<" "<<safety_parameter<<endl;
              remove(output);
              return 1;
            }
        }
      }
    }

  else if(argc ==6)
    {
      input = argv[1];
      output = argv[2];

      //Reads the information about the grid domain.
      // strtol converts a  string into an integer
      N[0]=strtol(argv[3],NULL,0); // Dimensions of array in X
      N[1]=strtol(argv[4],NULL,0); // Dimensions of array in Y
      N[2]=strtol(argv[5],NULL,0); // Dimensions of array in Y

      ifstream input_file (input, ios::in | ios:: binary);
      if(!input_file)
        {
          cout << "Cannot open file for input.\n";
          return 1;
        }

      // Computing the length of the file
      // get length of file:
      input_file.seekg (0, input_file.end);
      int length = input_file.tellg();
      input_file.seekg (0, input_file.beg);


      ofstream output_file(output, ios::out);
      if(!output_file)
        {
          cout << "Cannot open file for output.\n";
          return 1;
        }



      char value[8]; // Array that reads 8bytes
      double result; // Temporary saves the converted variable
      int safety_parameter=0;

      for(int k=0; k<N[2]; k++){
        for(int j=0; j<N[1]; j++){
          for(int i=0; i<N[0]; i++){


            input_file.read(value,8);
            result = *((double*) value);
            output_file<<result<<endl;

            safety_parameter+=8;
            if(safety_parameter>length)
              {
                cout << "Exceeded the length of the file. Please check your inputs.\n";
		cout<<length<<" "<<safety_parameter<<endl;
                remove(output);
                return 1;
              }
          }
        }
      }
    }
  else{      
    cout << "Wrong number of input arguments( must be 4-6).\n";}

}
