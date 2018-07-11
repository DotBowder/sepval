# sepval
A C++ program designed or ingest or egress, sepparated value files, like tsv, or csv.

Latest Commit: July 11, 2018
First Commit: July 11, 2018

*** Note, before compiling and running this, without uncommenting code, by default the program will create an array of size 100x100 of strings and then exit. ***

To Compile:
  g++ sepval.cpp -o sepval



Syntax:
  sepval filename delimiter
  
  eg:
    sepval myfile.tsv \\t
    sepval myfile.csv ,
