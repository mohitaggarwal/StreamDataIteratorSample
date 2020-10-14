// StreamDataIteratorSample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "StreamDataEnumerator.h"

using namespace StreamDataIteratorSample;

void printDataType(StreamDataType dataType);

int main()
{
    cout << "StreamDataResponse file read..." << endl;
    std::ifstream is("testsamples\\StreamDataResponse.txt", std::ios::binary);

    // Read the stream
    StreamDataEnumerator dataEnumerator = StreamDataEnumerator(is.rdbuf());
    while (dataEnumerator.moveNext()) {
        printDataType(dataEnumerator.getDataType());
        string data = dataEnumerator.current();
        cout << data << endl;
    }

    is.close();

    cout << "===============================================" << endl;

    cout << "StreamDataResponseWithoutDataMarker file read..." << endl;
    std::ifstream isSec("testsamples\\StreamDataResponseWithoutDataMarker.txt", std::ios::binary);

    // Read the stream
    StreamDataEnumerator dataEnumeratorSec = StreamDataEnumerator(isSec.rdbuf());
    while (dataEnumeratorSec.moveNext()) {
        printDataType(dataEnumeratorSec.getDataType());
        cout << dataEnumeratorSec.current() << endl;
        cout << "Current called again without calling MoveNext(): " << dataEnumeratorSec.current() << endl;
    }

    isSec.close();
}

void printDataType(StreamDataType dataType) {
    switch (dataType)
    {
    case StreamDataType::Data:
        cout << "Data type is 'data'" << endl;
        break;
    case StreamDataType::Error:
        cout << "Data type is 'error'" << endl;
        break;
    default:
        break;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
