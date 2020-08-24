//============================================================================
// Name        : Wildlife.cpp
// Author      : Mathew Newton
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <array>
#include <jni.h>
#include <cmath>
using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=U:/ZooFileWriter/bin";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {

            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
     cin.get();
}
int i = 0;// A variable to get the indexes of an array or to use as an array size
string Array[1];//An array to store animals

void AddAnimal()
{

   Array[0] = {"Lion"};//animal name

   cout << "\nAnimal Inserted Successfully!";
}


void RemoveAnimal()
{
   Array->erase();//array will be erased completely
   cout << "\nArray Erased Successfully!";
}

void LoadDataFromFile()
{
   string file_name = "jni.txt";
   fstream file;
   file.open(file_name);//open the file
   if (file.fail())//if file address is wrong or if the file is not found then it will give an error warning
       cout << "file opening Error!";
   else
   {
       string line;//string to obtain line from the file
       while (getline(file,line ))//get the line from file until the end from the data file
       {
    	   Array[i] = line;//now the line will be stored to the array
    	              i++;
       }
       cout << "\nData Loaded From File Successful!";
   }

}

void SaveDataToFile()
{
   //you can change the address of the file or name what it was used here
   fstream file;
   string file_name = "data_file.txt";
   file.open(file_name);//open file
   if (file.fail())
       cout << "\nFile Opening Failed!";
   else
   {
       int array_size = 0;
       while (array_size<=i)
       {
    	   file << Array[array_size] << endl;//gathering data from the array and saving it to the file
           array_size++;
       }
       cout << "\nData on File Saved Successfully!";
   }
}

void DisplayMenu()
{
   int option;
   menu:
   cout << "\n\t\tMENU\n-------------------------------------\n-------------------------------------";
   cout << "\n\n1.Add Animal\n2.Remove Animal\n3.Load Data From File\n4.Save Data to File\n5.Exit\n\nENTER YOUR OPTION: ";
   cin >> option;
   switch (option)
   {
   case 1://if user press 1
       AddAnimal();//function will be called
       _getche();
       goto menu;
   case 2://if press 2
       RemoveAnimal();//function will be called
       _getche();
       goto menu;
   case 3://if press 3
       LoadDataFromFile();//function will be called
       _getche();
       goto menu;
   case 4://if press 4
       SaveDataToFile();//function will be called
       _getche();
       goto menu;
   case 5://if press 5
       return;//Stop execution of the program and it will end
   default://If user does not press the right option
       cout << "\nInvalid Option!";
       cout << "\nPress any key to continue...";
       _getche();
       goto menu;
   }
}

int main()
{
   GenerateData();
   return 1;
}
