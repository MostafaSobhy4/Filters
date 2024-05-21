// File: CS112_A3_Part2_S15_20230401_20230125_20230223.cpp
// Authors Details:
//     Author1 And His Section And His Email : Mostafa Sobhy Fathy , (S15), smmm95607@gmail.com
//     Author2 And His Section And His Email : Hussein khaled fahim hamed , (S15), hk3648345@gmail.com
//     Author3 And His Section And His Email : Abdullah Ibrahim fathi mahmoud , (S15), body02924@gmail.com
// IDs And What each team member did:
//     ID1: 20230401  - (Mostafa Sobhy:  write filter 3, 6, 9, 12 and Collecting codes and handling errors) 
//     ID2: 20230125  - (hussein Khaled : write filter 1, 4, 7, 10)  
//     ID3: 20230223  - (Abdullah Ibrahim: write filter 2, 5, 8, 11)
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream> 
#include <random>
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
    string filename;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }

    Image image(filename);
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
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
    string filename;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin , filename); // Read input directly into name_image variable

    // Check if file exists
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin , filename); // Read new input if file not found
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    Image image(filename);
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The grayscale image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Invert Colors of Image
void invert() {
    string filename;
    cout <<endl<< "Please enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }

    Image image(filename);
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The inverted image has been stored....";
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    flippedImage.saveImage(output_image);
    cout<<endl<<"The flipped image has been stored....";
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout<<endl<<"The black and white image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to blur the image
void blur() {
    string filename;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, filename);

    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
    
    Image image(filename);
    Image blurImage(image.width, image.height);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int summation = 0;
                int cou = 0;
                
                for (int a = -10; a <= 10; ++a) {
                    for (int b = -10; b <= 10; ++b) {
                        if (i + a >= 0 && i + a < image.width && j + b >= 0 && j + b < image.height) {
                            summation += image(i + a, j + b, k);
                            cou++;
                        }
                    }
                }
                blurImage(i, j, k) = summation / cou;
            }
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    blurImage.saveImage(output_image);
    cout << endl << "The blurred image has been stored....";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to rotate the image 90 or 180 or 270 degrees
void rotateImage() {
    string filename;
    cout <<endl<<"Enter the name of the image: ";
    getline(cin, filename);

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
    
    int z = 0;
    string angle;

    while (true) {
        cout << "Enter the angle of rotation (90, 180, or 270): ";
        cin >> angle;
        cout << endl;

        if (angle != "90" && angle != "180" && angle != "270") {
            cout << "Invalid angle! Please enter 90, 180, or 270." << endl;
            continue;
        } else {
            break;
        }
    }

    Image image(filename);
    Image rotatedImage1(image.width, image.height);
    Image rotatedImage2(image.height, image.width);

    if (angle == "90") {
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotatedImage2(image.height - 1 - j, i, k) = image(i, j, k);
                }
            }
        }
       z=2;
    }

    else if (angle == "180") {        
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotatedImage1(image.width - i - 1, image.height - j - 1, k) = image(i, j, k);
            }
        }
    } 
      z=1;
    }
    else if (angle == "270") {      
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    rotatedImage2(j, image.width - 1 - i, k) = image(i, j, k);
                }
            }
        }
      z=2;
    }

   
    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cin.ignore();
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    if(z==1){
    rotatedImage1.saveImage(output_image);
    cout << "The rotated image has been stored." << endl;}

    if(z==2){
    rotatedImage2.saveImage(output_image);
    cout << "The rotated image has been stored." << endl;}


}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Add Sample Frame Or Decorated Frame On Image
void addFrame() {
    string filename;
    cout <<endl<< "Enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }


    string Frame_Color;
    int color1, color2, color3;  // c1 => red ; c2 => green ; c3 => blue
    while (true) {
        cout << "Enter the frame color from the folowing colors:"<<endl;
        cout << "1- red"<<endl;
        cout << "2- green"<<endl;
        cout << "3- blue"<<endl;
        cout << "4- white"<<endl;
        cout << "5- black"<<endl;
        cout << "6- yellow"<<endl;
        cout << "Enter your choice: ";  
        getline(cin, Frame_Color);
        cout<<endl;

        if (Frame_Color == "1") {
            color1 = 255;
            color2 = 0;
            color3 = 0;
        } else if (Frame_Color == "2") {
            color1 = 0;
            color2 = 255;
            color3 = 0;
        } else if (Frame_Color == "3") {
            color1 = 0;
            color2 = 0;
            color3 = 255;
        } else if (Frame_Color == "4") {
            color1 = 255;
            color2 = 255;
            color3 = 255;
        } else if (Frame_Color == "5") {
            color1 = 0;
            color2 = 0;
            color3 = 0;
        } else if (Frame_Color == "6") {
            color1 = 255;
            color2 = 255;
            color3 = 0;
        } else {
            cout << "Invalid frame color. please enter a valid color from the list" << endl;
            continue;
        }
        break;
    }

    int frame_Size1 = 7;
    int frame_Size2 = 6;


    Image image(filename);


    string Frame_Type;
    while (true) {
    cout<<"Which type you need:"<<endl;
    cout<<"1- Sample frame."<<endl;
    cout<<"2- Decorated frame."<<endl;
    cout << "Enter your choice: ";
    getline(cin, Frame_Type);
    cout<<endl;
    
    if(Frame_Type == "1"){
    
    // Apply frame to the left edge
    for (int i = 0; i < frame_Size1; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.height && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the right edge
    for (int i = image.width - frame_Size1; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the top edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < frame_Size1; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the bottom edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - frame_Size1; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }
    }

    else if(Frame_Type == "2") {

    // Apply the first frame 
    // Apply frame to the left edge
    for (int i = 0; i < frame_Size1; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.height && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the right edge
    for (int i = image.width - frame_Size1; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the top edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < frame_Size1; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }

    // Apply frame to the bottom edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - frame_Size1; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = color1;
                image(i, j, 1) = color2;
                image(i, j, 2) = color3;
            }
        }
    }




    // Apply the second frame 
    // Apply frame to the left edge
    for (int i = frame_Size1+5; i < 2*(6)+5; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }

    // Apply frame to the right edge
    for (int i = image.width - (frame_Size1+5+5); i < image.width - (frame_Size1+5); ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }

    // Apply frame to the top edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = frame_Size1+5; j < frame_Size1+5+5; ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }

    // Apply frame to the bottom edge
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - (frame_Size1+5+5) ; j < image.height - (frame_Size1+5); ++j) {
            if (i < image.width && j < image.height) {
                image(i, j, 0) = 255;
                image(i, j, 1) = 255;
                image(i, j, 2) = 255;
            }
        }
    }        
 
   }
   
    else if (Frame_Type != "1" && Frame_Type != "2") {
        cout << "Invalid frame type. Please enter a valid type from the choices." << endl;
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout <<endl<< "The image with the frame has been stored.... "<< endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Merge Two Images In One Image 
void Merge_Images() {
    string filename, filename1;
    cout <<endl<< "Please enter the first image name: ";
    getline(cin, filename);
    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            break;
        }
    }
    cout << "Please enter the second image name: ";
    getline(cin, filename1);
    while (true) {
        ifstream file_check(filename1);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename1);
        } else {
            file_check.close();
            cout<<endl;
            break;
        }
    }
    Image image(filename);
    Image image1(filename1);

    // Determine the common width and height
    int common_width = min(image.width, image1.width);
    int common_height = min(image.height, image1.height);

    // Create new images with the same size
    Image new_image(common_width, common_height);
    Image new_image1(common_width, common_height);

    // Copy pixels from the original images to the new images
    for (int i = 0; i < common_width; ++i) {
        for (int j = 0; j < common_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                new_image(i, j, k)= image(i, j, k);
                new_image1(i, j, k)= image1(i, j, k);
            }
        }
    }

    // Perform any operations needed with images having the same dimensions
    // For example, here we're adding pixel values from both images
    for (int i = 0; i < common_width; ++i) {
        for (int j = 0; j < common_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int new_value = 0.5*new_image(i, j, k) + 0.5*new_image1(i, j, k);
                if (new_value > 255) {
                    new_value = 255;
                }
                new_image(i, j, k)=(new_value);
            }
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    new_image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Detect Image Edges 
void  Grand_Competition() {
    string filename;
    cout << endl <<"Please enter the colored image filename: ";
    getline(cin, filename);

    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
    Image image(filename);

    int row_def, column_def;
    for (int i = 0; i < image.width - 1; ++i) {
        for (int j = 0; j < image.height - 1; ++j) {
            row_def = column_def = 0;
            for (int k = 0; k < image.channels; ++k) {
                row_def += abs(image(i, j, k) - image(i + 1, j, k));
                column_def += abs(image(i, j, k) - image(i, j + 1, k));
            }
            row_def /= 3;
            column_def /= 3;
            for (int k = 0; k < 3; k++) {
                if ((row_def >= 35) || (column_def >= 35))
                    image(i, j, k) = 0; // Black color
                else
                    image(i, j, k) = 255; // White color
            }
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }


    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Function To Crop Image 
void crop() {
    string filename;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
  
    Image img1(filename);

    // تحقق من أبعاد الصورة الأصلية
    int original_width = img1.width;
    int original_height = img1.height;

    // تحديد الإحداثيات والأبعاد للجزء المراد قصه
    int x , y , width , height ;

     //التأكد من أن الأبعاد المحددة لا تتجاوز أبعاد الصورة الأصلية
    while (true){
        cout<<"enter dimensions (width,height)"<<endl;
        cin>>width>>height;
         cout<<"enter center (x,y)"<<endl;
        cin>>x>>y;
        cout<<endl;

       if (x + width > original_width || y + height > original_height) {
        cout << "The specified dimensions exceed the original image dimensions." << endl;
        continue;
       }
       else{
        break;
       }
    }
    // إنشاء صورة جديدة بالأبعاد المحددة
    Image img2(width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < 3; k++) {
                img2(i, j, k) = img1(x + i, y + j, k);
            }
        }
    }

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    img2.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Convert Colored Image To Sunlight Image
void sunlight_image() {
    string filename;
    cout <<endl<<"Please enter the image name: ";
    getline(cin, filename);

    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
    Image image(filename);

    // Assuming width, height, and channels are public members of Image class
    int channels = image.channels; // Assuming all images have the same number of channels
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < channels; ++k) {
                int new_value = image(i, j, k);
                if (k == 0) { // Red channel
                    new_value = min(new_value + 50, 255); // Increase red
                } else if (k == 1) { // Green channel
                    new_value = min(new_value + 50, 255); // Increase green
                } else { // Blue channel
                    new_value = max(new_value - 50, 0); // Decrease blue
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
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }


    image.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
}   

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Function To Resize Image Dimension
void resize() {
    string filename;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
  
    Image img(filename);
    int x ,y;
    cout<<"enter width and height "<<endl;
    cin>>x>>y;
    Image img2(x, y);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < 3; k++) {
                img2(i, j, k) = img((i * img.width)/ x, (j * img.height )/ y, k);
            }
        }
    }
   

    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }


    img2.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
  
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Convert Colored image To infrared image
void infrared() {
    string filename;
    cout << endl << "Please enter the name of the image: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            cout << endl;
            break;
        }
    }
  
    Image img1(filename);
    int width = img1.width;
    int height = img1.height;
    Image img2(width, height);
   for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
            unsigned int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += img1(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average
            // Set all channels to the average value
            img1(i, j, 0) =  avg;
            img1(i, j, 1) =  avg;
            img1(i, j, 2) =  avg;
        }
    }
    

    for (int i = 0; i < img1.width; ++i) {
        for (int j = 0; j < img1.height; ++j) {
           
            img2(i, j, 0) =  255;
            img2(i, j, 1) = 255-  img1(i, j, 1);
            img2(i, j, 2) = 255-  img1(i, j, 2);
        }
    }
 
    string output_image;
    while (true) {
        cout<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }


    img2.saveImage(output_image);
    cout<<endl<<"The new image has been stored....";
  
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function To Convert Colored Image To Old TV Image
random_device noi; 
mt19937 noise(noi()); 

int randomInRange(int min, int max) { 
    uniform_int_distribution<> dis(min, max); 
    return dis(noise); 
}


void old_tv_image()
{
    string filename;
    cout << endl << "Please enter the image name: ";
    getline(cin, filename);

    // Check if file exists in the folder
    while (true) {
        ifstream file_check(filename);
        if (!file_check.good()) {
            cout << "File not found! Please enter the correct filename: ";
            getline(cin, filename);
        } else {
            file_check.close();
            break;
        }
    }

    Image image(filename);

    // Get dimensions of the current image
    int image_width = image.width;
    int image_height = image.height;


    // Create noise image with specified dimensions
    Image noise_image(image_width, image_height);

    // Generate random noise and set it to the noise image
    for (int i = 0; i < image_width; ++i) {
        for (int j = 0; j < image_height; ++j) {
            for (int k = 0; k < noise_image.channels; ++k) {
                noise_image(i, j, k) = randomInRange(0, 255);
            }
        }
    }

    for (int i = 0; i < image_width; ++i) {
        for (int j = 0; j < image_height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int new_value = 0.8 * image(i, j, k) + 0.2 * noise_image(i, j, k);
                if (new_value > 255) {
                    new_value = 255;
                }
                image(i, j, k) = new_value;
            }
        }
    }

    string output_image;
    while (true) {
        cout<<endl<<"If do you want to save image in the same image press 1 else press 2 ."<<endl;
        string x;
        while (true)
        {
        cout << "Enter your choice: ";         
        getline(cin,x);
        cout<<endl;
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
            cout << "Invalid extension. " << endl;
            continue;
        }
        break;
    }

    image.saveImage(output_image);
    cout << endl << "The new image has been stored." << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
    while (true) {
        cout << endl << "==========================================" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1. Grayscale Conversion" << endl;
        cout << "2. Black and White Image" << endl;
        cout << "3. Invert color of Image" << endl;
        cout << "4. Merge Image" << endl;        
        cout << "5. Flip Image" << endl;
        cout << "6. Rotate Image" << endl; 
        cout << "7. Darken and Lighten Image" << endl;
        cout << "8. Crop Images" << endl;
        cout << "9. Adding a Frame to the Image" << endl;
        cout << "10. Detect Image Edges" << endl;
        cout << "11. Resizing Images" << endl;
        cout << "12. Blur Image" << endl;
        cout << "13. Sun light" << endl;
        cout << "14. Image with infrared" << endl;
        cout << "15. Old tv image" << endl;        
        cout << "16. End" << endl;
        cout << "Enter your choice: ";


        string choice;
        getline(cin, choice);

        if (choice == "1") {
            Grayscale();
        } else if (choice == "2") {
            black_white();
        } else if (choice == "3") {
            invert();
        } else if (choice == "4") {
            Merge_Images();
        } else if (choice == "5") {
            flip();
        } else if (choice == "6") {
            rotateImage();
        } else if (choice == "7") {
            string brightness_choice;
            cout << endl << "What do you want:" << endl;
            cout << "1. Lighten Image" << endl;
            cout << "2. Darken Image" << endl;
            cout << "Enter your choice: ";
        while (true)
        {
            getline(cin, brightness_choice);
            if (brightness_choice == "1") {
                brightness(1.5);
                break;
            } else if (brightness_choice == "2") {
                brightness(0.5);
                break;
            } else {
                cout << "please enter a valid choice : " ;
                continue;
            } 
        }

        } else if (choice == "8") {
            crop();
        } else if (choice == "9") {
            addFrame();
        } else if (choice == "10") {
            Grand_Competition();
        } else if (choice == "11") {
            resize();
        } else if (choice == "12") {
            blur();
        } else if (choice == "13") {
            sunlight_image();
        }else if (choice=="14"){
           infrared();
        }else if (choice=="15"){
           old_tv_image(); 
        } else if (choice == "16") {
            cout << "Program ending..." << endl;
            break; 
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

}


