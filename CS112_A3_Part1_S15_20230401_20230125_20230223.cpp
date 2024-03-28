// File: CS112_A3_Part1_S15_20230401_20230125_20230223.cpp
// Authors Details:
//     Author1 And His Section And His Email : Mostafa Sobhy Fathy , (S15), smmm95607@gmail.com
//     Author2 And His Section And His Email : Hussein khaled fahim hamed , (S15), hk3648345@gmail.com
//     Author3 And His Section And His Email : Abdullah Ibrahim fathi mahmoud , (S15), body02924@gmail.com
// IDs And What each team member did:
//     ID1: 20230401  - (Mostafa Sobhy:  write filter 3 and Collecting codes and handling errors) 
//     ID2: 20230125  - (hussein Khaled : write filter 1, 7)  
//     ID3: 20230223  - (Abdullah Ibrahim: write filter 2, 5)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream> 
#include "Image_Class.h" 
using namespace std;


// Function To Check the Validity of Extension
bool isValidExtension(const string & filename) {
    string extension = filename.substr(filename.find_last_of(".") + 1);
    return (extension == "jpg" || extension == "bmp" || extension == "png" || extension == "tga");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Convert Colored Image To Grayscale
void Grayscale() {
    string name_image;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, name_image);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(name_image);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, name_image);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }

    Image image(name_image);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        getline(cin,x);
        if (x=="1"){
           output_image = name_image;
           break;
        }
        else if (x=="2")
        {
        cout << "Please enter the name of the new image to store (with extension .jpg, .bmp, .png, .tga): ";
        getline(cin, output_image);
        break;
        }
        else{
            cout<<"please enter a valid choice: ";
            continue;
        }
        }

        if (!isValidExtension(output_image)) {
            cout << "Invalid extension. "<<endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Increase or Decrease brightness of image
void brightness(double huss) {
    string name_image;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin , name_image); // Read input directly into name_image variable

    // Check if file exists
    while (true) {
        ifstream file_check(name_image);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin , name_image); // Read new input if file not found
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    Image image(name_image);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int new_value = static_cast<int>(huss * image(i, j, k));
                if (new_value > 255) {
                    new_value = 255;
                }
                image(i, j, k) = new_value;
            }
        }
    }
    
    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        getline(cin,x);
        if (x=="1"){
           output_image = name_image;
           break;
        }
        else if (x=="2")
        {
        cout << "Please enter the name of the new image to store (with extension .jpg, .bmp, .png, .tga): ";
        getline(cin, output_image);
        break;
        }
        else{
            cout<<"please enter a valid choice: ";
            continue;
        }
        }

        if (!isValidExtension(output_image)) {
            cout << "Invalid extension. "<<endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Invert Colors of Image
void invert() {
    string name_image;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin, name_image);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(name_image);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, name_image);
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    Image image(name_image);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int new_value = (int)(255 - image(i, j, k)); // Increase brightness by a negative value
                if (new_value < -255) {
                    new_value = -255; // Make sure pixel value doesn't go below -255
                } else if (new_value > 255) {
                    new_value = 255; // Make sure pixel value doesn't go below -255
                }
                image(i, j, k) = new_value;
            }
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        getline(cin,x);
        if (x=="1"){
           output_image = name_image;
           break;
        }
        else if (x=="2")
        {
        cout << "Please enter the name of the new image to store (with extension .jpg, .bmp, .png, .tga): ";
        getline(cin, output_image);
        break;
        }
        else{
            cout<<"please enter a valid choice: ";
            continue;
        }
        }

        if (!isValidExtension(output_image)) {
            cout << "Invalid extension. "<<endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}    

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Flip Image Horizontally or Vertically
void flip() {
    string filename;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin , filename);

    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin , filename);
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    cout << endl;
    Image image(filename);
    Image flippedImage(image.width, image.height);

    
    
    while(true){
    
    cout << "What do you want:" << endl;
    cout << "1. Horizontal Flip" << endl;
    cout << "2. Vertical Flip" << endl;
    cout << "Enter your choice: ";   
    string choice;
    getline(cin, choice);
    cout<<endl;
    if (choice == "1") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    flippedImage(i, j, k) = image(image.width - i - 1, j, k);
                }
            }
        }
        break;
    }

    if (choice == "2") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    flippedImage(i, j, k) = image(i, image.height - j - 1, k);
                }
            }
        }
        break;
    }
    else{
        cout<<"Invalid Choice! " <<endl;
        continue;
    }
    break;
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        getline(cin,x);
        if (x=="1"){
           output_image = filename;
           break;
        }
        else if (x=="2")
        {
        cout << "Please enter the name of the new image to store (with extension .jpg, .bmp, .png, .tga): ";
        getline(cin, output_image);
        break;
        }
        else{
            cout<<"please enter a valid choice: ";
            continue;
        }
        }

        if (!isValidExtension(output_image)) {
            cout << "Invalid extension. "<<endl;
            continue;
        }
        break;
    }

    flippedImage.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Convert Colored Image To Black And White
void black_white() {
    string filename;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin , filename);

    while (true) {
        // Check if file exists in the folder
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin , filename);
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    unsigned int threshold = 128;
    Image image(filename);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            unsigned int color = (avg > threshold) ? 255 : 0;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = color;
            }
        }
    }
    
    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        getline(cin,x);
        if (x=="1"){
           output_image = filename;
           break;
        }
        else if (x=="2")
        {
        cout << "Please enter the name of the new image to store (with extension .jpg, .bmp, .png, .tga): ";
        getline(cin, output_image);
        break;
        }
        else{
            cout<<"please enter a valid choice: ";
            continue;
        }
        }

        if (!isValidExtension(output_image)) {
            cout << "Invalid extension. "<<endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
while (true)
{
    cout<<endl;
    cout<<endl;
    cout<<"==========================================";    
    string enter;
    cout<<endl<<"what do you want: "<<endl;
    cout<<"1.Grayscale Conversion "<<endl;
    cout<<"2.Darken and Lighten Image"<<endl;
    cout<<"3.Invert color of Image"<<endl;
     cout<<"4.flip Image "<<endl;
     cout<<"5.black and white Image "<<endl;
     cout<<"6.end "<<endl;
    cout<<"enter your choice: ";
    while(true)
    {
    getline(cin,enter);
    if (enter=="1")
    {
        Grayscale();
        break;
    }
    if (enter=="2")
    {
        string choice;
        cout<<endl<<"what do you want: "<<endl;
        cout<<"1.Lighten Image "<<endl;
        cout<<"2.Darken Image"<<endl;
        cout<<"enter your choice: ";
        while(true)
        {
            getline(cin,choice);
            if (choice=="1")
             {
                brightness(1.5);
                break;
             }
            if (choice=="2")
            {
               brightness(0.5);
               break;
            }
            else
            {
               cout<<"please enter a valid choice: ";
                continue;
            }
        }
           break; 

            
    }
    if (enter=="3")
    {

        invert();
        break;
    }
    if (enter=="4")
    {
        flip();
        break;
    }
    if (enter=="5")
    {
        black_white();
        break;
    }
    if (enter == "6")
    {
        break;
    }
    else
        {
            cout<<"please enter a valid choice: ";
            continue;
        }
    }
    if (enter == "6")
    {
        cout<<endl;
        cout<<"program ending..........................";
        break;
    }
    else
    {
        continue;
    }
}
   }
