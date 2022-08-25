

#include "Headers/Validate.h"



bool binarySearch(char arr[], int lo, int r, int x)
{
    int mid;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (r - lo > 1) {
        int mid = (r + lo) / 2;
        if (arr[mid] < x) {
            lo = mid + 1;
        }
        else {
            r = mid;
        }
    }
    if (arr[lo] == x) {

        return true;
    }
    else if (arr[r] == x) {

        return true;
    }
    else {

        return false;
    }
}


bool Validate::validate(string value, int type) {
    string allowedString;
    switch (type) {
        case 1: allowedString = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; break;
        case 2: allowedString = " ()+0123456789";break;
        case 3: allowedString = " \"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";break;
        case 4: allowedString = " \"#()+,./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";break;
    }

    int n = allowedString.length();
    char* char_array = new char[n + 1];
    char* values_array = new char[n+1];
    strcpy(char_array, allowedString.c_str());
    strcpy(values_array, value.c_str());
    for (int i = 0; i < value.length(); ++i) {
        if(!(binarySearch( char_array, 0, n-1, values_array[i])))
            return false;
    }
    return true;
    //check if 1st value of string is here
}